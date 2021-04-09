#include "TLE_9180.h"

uint32 ui32_SendBuffer[50];
uint32 ui32_SendBuffer2[50];
uint32 ui32_SendBuffer3[50];
uint32 ui32_SendBuffer4[50];

uint32 ui32_ReceiveBuffer[50];
uint32 ui32_ReceiveBuffer2[50];
uint32 ui32_ReceiveBuffer3[50];
uint32 ui32_ReceiveBuffer4[50];

e_TLE9180StateType e_TLE9180State;
e_TLE9180StateType e_TLEStateHistory[20];
e_TLE9180StateType e_TLE9180CheckErrState;
e_TLE9180StateType e_TLE9180Fault;
uint16 ui16_DelayCnt;
boolean b_PreviousSpiFailed;
uint8 b_Test9180Initflag;
uint8 TLEInitCnt;

uint8 ui8_TLE9180RegReadBuf[TLE9180_REG_AMOUNT];
uint8 ui8_TLE9180RegReadStatus[TLE9180_REG_AMOUNT];
uint8 ui8_TLE9180RegWriteBuf[TLE9180_REG_AMOUNT];
uint8 ui8_TLE9180RegWriteStatus[TLE9180_REG_AMOUNT];

static void TLE9180_CheckErrReg(void);
static void TLE9180_WriteConfigReg(void);
static Std_ReturnType TLE9180_ReadReg(uint8 ui8_StartAddr, uint8 ui8_EndAddr);
static Std_ReturnType TLE9180_WriteReg(uint8 ui8_StartAddr, uint8 ui8_EndAddr);

void TLE9180_Init(void) {
	uint8 ui8_Cnt = 0;
	b_Test9180Initflag = 0;
	e_TLE9180State = TLE9180_SLEEP;							//initialize state
	e_TLE9180CheckErrState = TLE9180_IDLE_CHECK_STEP1;//initialize check err state
	e_TLE9180Fault = TLE9180_NO_FAULT;						//initialize fault
	ui16_DelayCnt = 0;
	b_PreviousSpiFailed = FALSE;

	//Edit by guan
	TLEInitCnt = 0;
	//Edit by guan

	//set 0xFF for reserved register address 0x14~0x1A, unused address
	for (ui8_Cnt = (TLE9180_FM_6 + 1); ui8_Cnt < TLE9180_OP_GAIN_1; ui8_Cnt++) {
		ui8_TLE9180RegReadBuf[ui8_Cnt] = 0xFF;
		ui8_TLE9180RegReadStatus[ui8_Cnt] = 0xFF;
		ui8_TLE9180RegWriteBuf[ui8_Cnt] = 0xFF;
		ui8_TLE9180RegWriteStatus[ui8_Cnt] = 0xFF;
	}
	//set 0xFF for reserved register address 0x38~0x3A, unused address
	for (ui8_Cnt = (TLE9180_EN_ST + 1); ui8_Cnt < TLE9180_OM_OVER; ui8_Cnt++) {
		ui8_TLE9180RegReadBuf[ui8_Cnt] = 0xFF;
		ui8_TLE9180RegReadStatus[ui8_Cnt] = 0xFF;
		ui8_TLE9180RegWriteBuf[ui8_Cnt] = 0xFF;
		ui8_TLE9180RegWriteStatus[ui8_Cnt] = 0xFF;
	}
}

/*******************************************************************************
 ** Function Name	: TLE9180_PowerupSequence
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: TLE9180启动状态机
 *******************************************************************************/
void TLE9180_PowerupSequence(void) {
	uint8 ui8_Tmp = 0;

	switch (e_TLE9180State) {
	case TLE9180_SLEEP:		//sleep state
	{
		//Edit by guan
		e_TLEStateHistory[TLEInitCnt] = e_TLE9180State;
		TLEInitCnt++;
		//Edit by guan

		TLE9180_WriteINH_N(STD_LOW);
		TLE9180_WriteSOFF_N(STD_LOW);
		TLE9180_WriteENA(STD_LOW);

		if (TLE9180_ReadERR_N() == STD_ON)		//no err detected
		{
			b_PreviousSpiFailed = FALSE;
			ui16_DelayCnt = 0;
			e_TLE9180State = TLE9180_IDLE_CHECK_SPI;
			TLE9180_WriteINH_N(STD_HIGH);
			break;
		}
		if (ui16_DelayCnt >= 5)					//can not read no err signal
		{
			ui16_DelayCnt = 0;
			e_TLE9180Fault = TLE9180_IDLE_ERR_PIN_DETECTED;		//record fault
			e_TLE9180State = TLE9180_FAULT;
		}
		//disable INH SOFF, enable ENA

		TLE9180_WriteINH_N(STD_HIGH);
		TLE9180_WriteSOFF_N(STD_HIGH);
		TLE9180_WriteENA(STD_HIGH);
		ui16_DelayCnt++;
		break;
	}
	case TLE9180_IDLE_CHECK_SPI:	//check spi in idle state
	{
		//Edit by guan
		e_TLEStateHistory[TLEInitCnt] = e_TLE9180State;
		TLEInitCnt++;
		//Edit by guan


		ui8_Tmp = TLE9180_ReadReg(TLE9180_NOP, TLE9180_NOP);//read nop register err
		//read register err and previous spi fail had detected
		if ((ui8_Tmp == E_NOT_OK)) {					//communication err
			if (b_PreviousSpiFailed == TRUE) {		//cheak Previous_Spi_Fail
				e_TLE9180Fault = TLE9180_SPI_FRAME_ERR_TWICE;	//record fault
				e_TLE9180State = TLE9180_FAULT;
				break;
			}
			//read register err and no previous spi fail had detected
			if (b_PreviousSpiFailed == FALSE) {		//cheak Previous_Spi_Fail
				b_PreviousSpiFailed = TRUE;					//record spi failed
				e_TLE9180State = TLE9180_ENA_RESET;
				break;
			}
		}
		e_TLE9180State = TLE9180_IDLE_CHECK_ERR_REG;//read nop register completed
		break;
	}
	case TLE9180_IDLE_CHECK_ERR_REG:	//check err register in idle state
	{
		//Edit by guan
		e_TLEStateHistory[TLEInitCnt] = e_TLE9180State;
		TLEInitCnt++;
		//Edit by guan

		TLE9180_CheckErrReg();		//check err register state machine function
		if (e_TLE9180CheckErrState == TLE9180_FAULT)//check err register fault
				{
			e_TLE9180State = TLE9180_FAULT;	//fault had recorded in check err register state
			break;
		}
		if (e_TLE9180CheckErrState == TLE9180_IDLE_CHECK_COMPLETED)	//check err register completed
				{
			e_TLE9180State = TLE9180_CONFIG;
			break;
		}
		break;
	}
	case TLE9180_ENA_RESET:		//ENA reset
	{
		//Edit by guan
		e_TLEStateHistory[TLEInitCnt] = e_TLE9180State;
		TLEInitCnt++;
		//Edit by guan

		TLE9180_WriteENA(STD_LOW);
		for (ui16_DelayCnt = 0; ui16_DelayCnt < 5; ui16_DelayCnt++)      
			;	//delay for at least 3.8us
		TLE9180_WriteENA(STD_HIGH);
		e_TLE9180State = TLE9180_IDLE_CHECK_SPI;
		break;
	}
	case TLE9180_CONFIG: {
		//Edit by guan
		e_TLEStateHistory[TLEInitCnt] = e_TLE9180State;
		TLEInitCnt++;
		//Edit by guan
		TLE9180_WriteSOFF_N(STD_HIGH);
		ui8_Tmp = TLE9180_ReadReg(TLE9180_CONF_GEN_1, TLE9180_FM_6);//read all config register
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180State = TLE9180_FAULT;
		}
		TLE9180_WriteConfigReg();
		ui8_Tmp = TLE9180_WriteReg(TLE9180_CONF_GEN_1, TLE9180_FM_6);
		ui8_Tmp = TLE9180_WriteReg(TLE9180_OP_GAIN_1, TLE9180_OP_CON);     /* 写入相电流采样的寄存器值    */
		ui8_Tmp = TLE9180_WriteReg(TLE9180_CONF_SIG, TLE9180_CONF_SIG);
		ui8_Tmp = TLE9180_WriteReg(TLE9180_MISC_CTR, TLE9180_MISC_CTR);
		ui8_Tmp = TLE9180_ReadReg(TLE9180_OP_GAIN_1, TLE9180_OP_CON);
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180State = TLE9180_FAULT;
		}
		ui8_Tmp = TLE9180_ReadReg(TLE9180_OM_OVER, TLE9180_OM_OVER);//read OM register
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180State = TLE9180_FAULT;
			break;
		}
		if ((ui8_TLE9180RegReadBuf[TLE9180_OM_OVER] & 0x80) != 0x80)//operation mode is not normal mode
				{
			e_TLE9180Fault = TLE9180_NOT_NORMAL;				//record fault
			e_TLE9180State = TLE9180_FAULT;
			break;
		}
		e_TLE9180State = TLE9180_POWERUP_END;
		TLE9180_WriteENA(STD_HIGH);
		break;
	}
	case TLE9180_POWERUP_END: {
		ui8_Tmp = TLE9180_ReadReg(TLE9180_SER, TLE9180_ERR_OUTP);
//		ui8_Tmp = TLE9180_ReadReg(TLE9180_OP_GAIN_1, TLE9180_OP_CON);
		break;
	}
	case TLE9180_FAULT: {
		//Edit by guan
		e_TLEStateHistory[TLEInitCnt] = e_TLE9180State;
		TLEInitCnt++;
		//Edit by guan
		//enable INH SOFF, disable ENA
		if(b_Test9180Initflag < 5)
		{
			e_TLE9180State = TLE9180_SLEEP;
			b_Test9180Initflag++;
			TLE9180_WriteINH_N(STD_LOW);
			TLE9180_WriteSOFF_N(STD_LOW);
			TLE9180_WriteENA(STD_LOW);
		}
		else
		{
			ui8_Tmp = TLE9180_ReadReg(TLE9180_NOP, TLE9180_NOP);
			TLE9180_WriteINH_N(STD_LOW);
			TLE9180_WriteSOFF_N(STD_LOW);
			TLE9180_WriteENA(STD_LOW);
		}
		break;
	}
	default: {
		e_TLE9180State = TLE9180_FAULT;
		break;
	}
	}
}

/*******************************************************************************
 ** Function Name	: TLE9180_MainFunction
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: TLE9180主状态机
 *******************************************************************************/
void TLE9180_MainFunction(void) {

}

/*******************************************************************************
 ** Function Name	: TLE9180_CheckErrReg
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: TLE9180错误校验状态机
 *******************************************************************************/
static void TLE9180_CheckErrReg(void) {
	uint8 ui8_Tmp = 0;

	switch (e_TLE9180CheckErrState) {
	case TLE9180_IDLE_CHECK_STEP1:		//check read register step1
	{
		ui8_Tmp = TLE9180_ReadReg(TLE9180_SER, TLE9180_ERR_OUTP);//read err register 0x42-0x4D twice
		ui8_Tmp = TLE9180_ReadReg(TLE9180_SER, TLE9180_ERR_OUTP);
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		ui8_Tmp = TLE9180_ReadReg(TLE9180_OM_OVER, TLE9180_OM_OVER);//read OM register twice
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		if ((ui8_TLE9180RegReadBuf[TLE9180_OM_OVER] & 0x01) != 0x01)//operation mode is not idle mode
				{
			e_TLE9180Fault = TLE9180_NOT_IDLE;					//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		//check err register
		//TLE9180_ERR_I_2: err_cp1 err_cp2
		//TLE9180_ERR_SD: sd_cp1 sd_ot sd_ov_cp
		if (((ui8_TLE9180RegReadBuf[TLE9180_ERR_I_2] & 0x18) != 0x00)
				|| ((ui8_TLE9180RegReadBuf[TLE9180_ERR_SD] & 0x86) != 0x00)) {
			e_TLE9180CheckErrState = TLE9180_ENA_RESET;
			break;
		}
		//no spi fail, no OM err, no err bit set, transfer next check state
		e_TLE9180CheckErrState = TLE9180_IDLE_CHECK_STEP2;
		break;
	}
	case TLE9180_IDLE_CHECK_STEP2:		//check read register step2
	{
		//check err register
		//TLE9180_ERR_SD: sd_uv_cb
		if ((ui8_TLE9180RegReadBuf[TLE9180_ERR_SD] & 0x10) != 0x00) {
			e_TLE9180CheckErrState = TLE9180_IDLE_CHECK_STEP1;
			break;
		}
		//no err bit set, transfer next check state
		e_TLE9180CheckErrState = TLE9180_IDLE_CHECK_STEP3;
		break;
	}
	case TLE9180_IDLE_CHECK_STEP3:		//check read register step3
	{
		ui8_Tmp = TLE9180_ReadReg(TLE9180_SER, TLE9180_ERR_OUTP);//read err register 0x42-0x4D twice
		ui8_Tmp = TLE9180_ReadReg(TLE9180_SER, TLE9180_ERR_OUTP);
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		ui8_Tmp = TLE9180_ReadReg(TLE9180_OM_OVER, TLE9180_OM_OVER);//read OM register twice
		if (ui8_Tmp == E_NOT_OK)		//spi failed
		{
			e_TLE9180Fault = TLE9180_SPI_FRAME_ERR;				//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		if ((ui8_TLE9180RegReadBuf[TLE9180_OM_OVER] & 0x01) != 0x01)//operation mode is not idle mode
				{
			e_TLE9180Fault = TLE9180_NOT_IDLE;					//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		//check err register, constrained unaccepted err bit
		//TLE9180_SER: gtm
		//TLE9180_ERR_I_1: err_ov_reg6
		//TLE9180_ERR_I_2: err_cp1 err_cp2
		//TLE9180_ERR_SD: sd_ot sd_ov_cp sd_cp1 sd_uv_cb
		if (((ui8_TLE9180RegReadBuf[TLE9180_SER] & 0x10) != 0x00)
				|| ((ui8_TLE9180RegReadBuf[TLE9180_ERR_I_1] & 0x08) != 0x00)
				|| ((ui8_TLE9180RegReadBuf[TLE9180_ERR_I_2] & 0x18) != 0x00)
				|| ((ui8_TLE9180RegReadBuf[TLE9180_ERR_SD] & 0x96) != 0x00)) {
			e_TLE9180Fault = TLE9180_UNACCEPTABLE_ERR;			//record fault
			e_TLE9180CheckErrState = TLE9180_FAULT;
			break;
		}
		e_TLE9180CheckErrState = TLE9180_IDLE_CHECK_COMPLETED;
		break;
	}
	case TLE9180_IDLE_CHECK_COMPLETED: {
		ui8_Tmp = TLE9180_ReadReg(TLE9180_SER, TLE9180_ERR_OUTP);
		break;
	}
	case TLE9180_ENA_RESET: {
		TLE9180_WriteENA(STD_LOW);
		for (ui8_Tmp = 0; ui8_Tmp < 5; ui8_Tmp++)
			;
		TLE9180_WriteENA(STD_HIGH);
		e_TLE9180CheckErrState = TLE9180_IDLE_CHECK_STEP2;
		break;
	}
	case TLE9180_FAULT: {
		TLE9180_WriteINH_N(STD_LOW);
		TLE9180_WriteSOFF_N(STD_LOW);
		TLE9180_WriteENA(STD_LOW);
		break;
	}
	default: {
		e_TLE9180CheckErrState = TLE9180_FAULT;
		break;
	}
	}
}
/*******************************************************************************
 ** Function Name	: TLE9180_WriteConfigReg
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: TLE9180初始化配置
 *******************************************************************************/
static void TLE9180_WriteConfigReg(void) {
	uint8 ui8_LoopCnt=0;
	for (ui8_LoopCnt=TLE9180_CONF_SIG;ui8_LoopCnt<=TLE9180_FM_6;ui8_LoopCnt++)
	{
		ui8_TLE9180RegWriteBuf[ui8_LoopCnt]=ui8_TLE9180RegReadBuf[ui8_LoopCnt];
	}
	ui8_TLE9180RegWriteBuf[TLE9180_CONF_GEN_1] = 0x81;//set Vcc 5V
	ui8_TLE9180RegWriteBuf[TLE9180_CONF_GEN_2] = 0x07;//Active 3 CSA
#if (TLE_CONFIG == 1)
	ui8_TLE9180RegWriteBuf[TLE9180_FM_1] = 0x20;//set no shutdown of output stages,if CB undervoltage
	ui8_TLE9180RegWriteBuf[TLE9180_FM_2] = 0x00;//close window watchdog time-out error latched
	ui8_TLE9180RegWriteBuf[TLE9180_FM_3] = 0x00;//close VS undervoltage detection
	ui8_TLE9180RegWriteBuf[TLE9180_FM_4] = 0x00;//close VS overvoltage detection
	ui8_TLE9180RegWriteBuf[TLE9180_FM_5] = 0x00;//close short circuit detection error latched
#else
	ui8_TLE9180RegWriteBuf[TLE9180_CONF_GEN_2] = 0x0F;
	ui8_TLE9180RegWriteBuf[TLE9180_TL_VS] = 0x27;
#endif
	ui8_TLE9180RegWriteBuf[TLE9180_DT_HS] = 0x19;//HS death time : (0xa0+3)*(1/28Mhz)   /*死区配置*/
	ui8_TLE9180RegWriteBuf[TLE9180_DT_LS] = 0x19;//LS death time : (0xa0+3)*(1/28Mhz)


	/*  相电流采样配置  CSA   */
	ui8_TLE9180RegWriteBuf[TLE9180_OP_GAIN_1] = 0x0;    //15.71
	/*Current Sense Amplifier 1&2 - Gain 1   reset：33H*/
	ui8_TLE9180RegWriteBuf[TLE9180_OP_GAIN_2] = 0x0;    //15.71
	/*Current Sense Amplifier 1&2 - Gain 2   reset：55H*/
	ui8_TLE9180RegWriteBuf[TLE9180_OP_GAIN_3] = 0x0;    //gain2: 15.71    gain1: 15.71
	/*Current Sense Amplifier 3 - Gain 1&2   reset：53H*/
	ui8_TLE9180RegWriteBuf[TLE9180_OP_0CL] = 0xBF;       //9f    2.5V
	/*Current Sense Amplifier Zero Current Offset  reset：5FH*/
	ui8_TLE9180RegWriteBuf[TLE9180_OP_CON] = 0xE0;      //  07
	/*Current Sense Amplifier Configuration  reset：07H*/


//	ui8_TLE9180RegWriteBuf[TLE9180_MISC_CTR] = 0x00;



	TLE9180_GetArrayCRC8bit(&ui8_TLE9180RegWriteBuf[TLE9180_CONF_GEN_1], TLE9180_FM_6,
			&ui8_TLE9180RegWriteBuf[TLE9180_CONF_SIG]); //calculate configuration register crc8 result

}

/*******************************************************************************
 ** Function Name	: TLE9180_RegRangeCheck
 ** Parameter[in] 	: None
 ** Parameter[out] 	: None
 ** Return Value	: Std_ReturnType ui8_Return
 ** Note			: None
 ** Description	  	: TLE9180寄存器范围校验
 *******************************************************************************/
Std_ReturnType TLE9180_RegRangeCheck(uint8 ui8_StartAddr, uint8 ui8_EndAddr) {
	Std_ReturnType ui8_Return = E_OK;

	if (ui8_StartAddr <= ui8_EndAddr) {
		if ((ui8_StartAddr <= (uint8) TLE9180_FM_6)
				&& (ui8_EndAddr <= (uint8) TLE9180_FM_6)) {
			ui8_Return = E_OK;
		} else if ((ui8_StartAddr >= (uint8) TLE9180_OP_GAIN_1)
				&& (ui8_StartAddr <= (uint8) TLE9180_DS_MARK)
				&& (ui8_EndAddr >= (uint8) TLE9180_OP_GAIN_1)
				&& (ui8_EndAddr <= (uint8) TLE9180_DS_MARK)) {
			ui8_Return = E_OK;
		} else if ((ui8_StartAddr >= (uint8) TLE9180_SEL_ST_1)
				&& (ui8_StartAddr <= (uint8) TLE9180_EN_ST)
				&& (ui8_EndAddr >= (uint8) TLE9180_SEL_ST_1)
				&& (ui8_EndAddr <= (uint8) TLE9180_EN_ST)) {
			ui8_Return = E_OK;
		} else if ((ui8_StartAddr >= (uint8) TLE9180_OM_OVER)
				&& (ui8_StartAddr <= (uint8) TLE9180_RES_VDH)
				&& (ui8_EndAddr >= (uint8) TLE9180_OM_OVER)
				&& (ui8_EndAddr <= (uint8) TLE9180_RES_VDH)) {
			ui8_Return = E_OK;
		} else {
			ui8_Return = E_NOT_OK;
		}
	} else {
		ui8_Return = E_NOT_OK;
	}

	return (ui8_Return);
}

/*******************************************************************************
 ** Function Name	: TLE9180_ReadReg
 ** Parameter[in] 	: uint8 ui8_StartAddr, uint8 ui8_EndAddr
 ** Parameter[out] 	: None
 ** Return Value	: Std_ReturnType ui8_Return
 ** Note			: None
 ** Description	  	: TLE9180读寄存器
 *******************************************************************************/
uint8 readRegdebugg[4];
static Std_ReturnType TLE9180_ReadReg(uint8 ui8_StartAddr, uint8 ui8_EndAddr) {
	Std_ReturnType ui8_Return = E_OK;
	uint8 ui8_Cnt = 0;
	uint8 ui8_Amount = 0;
	uint32 ui32_Tmp = 0;
	uint32 ui32_Tmp2 = 0;
	uint32 ui32_Tmp3 = 0;
	uint32 ui32_Tmp4 = 0;
	boolean b_SpiErr = FALSE;

	if (TLE9180_RegRangeCheck(ui8_StartAddr, ui8_EndAddr) == E_OK) //range check valid
	{
		ui8_Amount = ui8_EndAddr - ui8_StartAddr + 1; //get read registers amount
		for (ui8_Cnt = 0; ui8_Cnt < ui8_Amount; ui8_Cnt++) {
			//load address info to buffer
			ui32_Tmp = (uint32) (ui8_StartAddr + ui8_Cnt);
			ui32_Tmp = (uint32) (ui32_Tmp << 16) & 0x007F0000;
			ui32_SendBuffer[ui8_Cnt] = ui32_Tmp;
			ui32_SendBuffer2[ui8_Cnt] = ui32_Tmp;
			ui32_SendBuffer3[ui8_Cnt] = ui32_Tmp;
			ui32_SendBuffer4[ui8_Cnt] = ui32_Tmp;

			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer[ui8_Cnt]);	//get frame CRC
			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer2[ui8_Cnt]);
			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer3[ui8_Cnt]);
			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer4[ui8_Cnt]);

		}
		ui32_SendBuffer[ui8_Amount] = 0x00320003;//read nop register, has got frame CRC
		ui32_SendBuffer2[ui8_Amount] = 0x00320003;
		ui32_SendBuffer3[ui8_Amount] = 0x00320003;
		ui32_SendBuffer4[ui8_Amount] = 0x00320003;

		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180, &ui32_SendBuffer[0], &ui32_ReceiveBuffer[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180);
		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180_1, &ui32_SendBuffer2[0],&ui32_ReceiveBuffer2[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180_1);
		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180_2, &ui32_SendBuffer3[0],&ui32_ReceiveBuffer3[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180_2);
		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180_3, &ui32_SendBuffer4[0],&ui32_ReceiveBuffer4[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180_3);



		//receive data check
		for (ui8_Cnt = 0; ui8_Cnt < ui8_Amount; ui8_Cnt++)
		{
			if (((ui32_ReceiveBuffer[ui8_Cnt + 1] & 0x00100000) == 0)&&
					((ui32_ReceiveBuffer2[ui8_Cnt + 1] & 0x00100000) == 0)&&
					((ui32_ReceiveBuffer3[ui8_Cnt + 1] & 0x00100000) == 0)&&
					((ui32_ReceiveBuffer4[ui8_Cnt + 1] & 0x00100000) == 0))//bit 20 no SPI-Error
			{
				ui32_Tmp = ((uint32) (ui32_ReceiveBuffer[ui8_Cnt + 1] << 4) & 0x007F0000);
				ui32_Tmp2 = ((uint32) (ui32_ReceiveBuffer2[ui8_Cnt + 1] << 4) & 0x007F0000);
				ui32_Tmp3 = ((uint32) (ui32_ReceiveBuffer3[ui8_Cnt + 1] << 4) & 0x007F0000);
				ui32_Tmp4 = ((uint32) (ui32_ReceiveBuffer4[ui8_Cnt + 1] << 4) & 0x007F0000);

				if ((ui32_Tmp == (ui32_SendBuffer[ui8_Cnt] & 0x007F0000))&&
						(ui32_Tmp2 == (ui32_SendBuffer2[ui8_Cnt] & 0x007F0000))&&
						(ui32_Tmp3 == (ui32_SendBuffer3[ui8_Cnt] & 0x007F0000))&&
						(ui32_Tmp4 == (ui32_SendBuffer4[ui8_Cnt] & 0x007F0000)))//send reg address equal receive reg address
				{
					//data is valid and save data
					ui8_TLE9180RegReadStatus[ui8_StartAddr + ui8_Cnt] = TRUE;
					ui8_TLE9180RegReadBuf[ui8_StartAddr + ui8_Cnt] =  (uint8)((uint32)(ui32_ReceiveBuffer[ui8_Cnt + 1] >> 4) & 0x000000FF);
				}
				else
				{
					ui8_TLE9180RegReadStatus[ui8_StartAddr + ui8_Cnt] = FALSE;//data is invalid
					b_SpiErr = TRUE;
					readRegdebugg[3] = 1;
				}
			}
			else
			{
				ui8_TLE9180RegReadStatus[ui8_StartAddr + ui8_Cnt] = FALSE;//data is invalid
				b_SpiErr = TRUE;
				readRegdebugg[2] = 1;
			}
		}
		if (b_SpiErr == FALSE)
		{
			ui8_Return = E_OK;
		}
		else
		{
			ui8_Return = E_NOT_OK;
			readRegdebugg[1] = 1;
		}
	}
	else
	{
		ui8_Return = E_NOT_OK;
		readRegdebugg[0] = 1;
	}

	return (ui8_Return);
}

/*******************************************************************************
 ** Function Name	: TLE9180_WriteReg
 ** Parameter[in] 	: uint8 ui8_StartAddr, uint8 ui8_EndAddr
 ** Parameter[out] 	: None
 ** Return Value	: Std_ReturnType ui8_Return
 ** Note			: None
 ** Description	  	: TLE9180写寄存器
 *******************************************************************************/
static Std_ReturnType TLE9180_WriteReg(uint8 ui8_StartAddr, uint8 ui8_EndAddr) {
	Std_ReturnType ui8_Return = E_OK;
	uint8 ui8_Cnt = 0;
	uint8 ui8_Amount = 0;
	uint32 ui32_Tmp = 0;
	uint32 ui32_Tmp2 = 0;
	uint32 ui32_Tmp3 = 0;
	uint32 ui32_Tmp4 = 0;
	boolean b_SpiErr = FALSE;

	if (TLE9180_RegRangeCheck(ui8_StartAddr, ui8_EndAddr) == E_OK)//range check valid
	{
		ui8_Amount = ui8_EndAddr - ui8_StartAddr + 1;//get read registers amount
		for (ui8_Cnt = 0; ui8_Cnt < ui8_Amount; ui8_Cnt++) {
			//load address info to buffer
			ui32_Tmp = (uint32) (ui8_StartAddr + ui8_Cnt);
			ui32_SendBuffer[ui8_Cnt] = (uint32) (ui32_Tmp << 16) & 0x007F0000;
			ui32_SendBuffer2[ui8_Cnt] = (uint32) (ui32_Tmp << 16) & 0x007F0000;
			ui32_SendBuffer3[ui8_Cnt] = (uint32) (ui32_Tmp << 16) & 0x007F0000;
			ui32_SendBuffer4[ui8_Cnt] = (uint32) (ui32_Tmp << 16) & 0x007F0000;

			//load data info to buffer
			ui32_Tmp = (uint32) ui8_TLE9180RegWriteBuf[ui8_StartAddr + ui8_Cnt];
			ui32_SendBuffer[ui8_Cnt] |= (uint32) (ui32_Tmp << 8) & 0x0000FF00;
			ui32_SendBuffer2[ui8_Cnt] |= (uint32) (ui32_Tmp << 8) & 0x0000FF00;
			ui32_SendBuffer3[ui8_Cnt] |= (uint32) (ui32_Tmp << 8) & 0x0000FF00;
			ui32_SendBuffer4[ui8_Cnt] |= (uint32) (ui32_Tmp << 8) & 0x0000FF00;

			//set the command bit
			ui32_SendBuffer[ui8_Cnt] |= 0x00800000;
			ui32_SendBuffer2[ui8_Cnt] |= 0x00800000;
			ui32_SendBuffer3[ui8_Cnt] |= 0x00800000;
			ui32_SendBuffer4[ui8_Cnt] |= 0x00800000;

			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer[ui8_Cnt]);//get frame CRC
			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer2[ui8_Cnt]);
			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer3[ui8_Cnt]);
			TLE9180_GetFrameCRC3bit(&ui32_SendBuffer4[ui8_Cnt]);
		}
		ui32_SendBuffer[ui8_Amount] = 0x00320003;//read nop register
		ui32_SendBuffer2[ui8_Amount] = 0x00320003;
		ui32_SendBuffer3[ui8_Amount] = 0x00320003;
		ui32_SendBuffer4[ui8_Amount] = 0x00320003;

		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180, &ui32_SendBuffer[0],&ui32_ReceiveBuffer[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180);
		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180_1, &ui32_SendBuffer2[0],&ui32_ReceiveBuffer2[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180_1);
		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180_2, &ui32_SendBuffer3[0],&ui32_ReceiveBuffer3[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180_2);
		AurixQspi_ChannelCfg(Aurix_Spi_Ch_Sq_Num_9180_3, &ui32_SendBuffer4[0],&ui32_ReceiveBuffer4[0], (ui8_Amount + 1));
		AurixQspi_Transmit(Aurix_Spi_Ch_Sq_Num_9180_3);
		//response data check
		for (ui8_Cnt = 0; ui8_Cnt < ui8_Amount; ui8_Cnt++)
		{
			if (((ui32_ReceiveBuffer[ui8_Cnt + 1] & 0x00100000) == 0)&&
					((ui32_ReceiveBuffer2[ui8_Cnt + 1] & 0x00100000) == 0)&&
					((ui32_ReceiveBuffer3[ui8_Cnt + 1] & 0x00100000) == 0)&&
					((ui32_ReceiveBuffer4[ui8_Cnt + 1] & 0x00100000) == 0)) //bit 20 no SPI-Error
			{
				ui32_Tmp = ((uint32) (ui32_ReceiveBuffer[ui8_Cnt + 1] << 4) & 0x007F0000);
				ui32_Tmp2 = ((uint32) (ui32_ReceiveBuffer2[ui8_Cnt + 1] << 4) & 0x007F0000);
				ui32_Tmp3 = ((uint32) (ui32_ReceiveBuffer3[ui8_Cnt + 1] << 4) & 0x007F0000);
				ui32_Tmp4 = ((uint32) (ui32_ReceiveBuffer4[ui8_Cnt + 1] << 4) & 0x007F0000);

				if ((ui32_Tmp == (ui32_SendBuffer[ui8_Cnt] & 0x007F0000))&&
						(ui32_Tmp2 == (ui32_SendBuffer2[ui8_Cnt] & 0x007F0000))&&
						(ui32_Tmp3 == (ui32_SendBuffer3[ui8_Cnt] & 0x007F0000))&&
						(ui32_Tmp4 == (ui32_SendBuffer4[ui8_Cnt] & 0x007F0000)))//send reg address equal receive reg address
				{
					ui8_TLE9180RegWriteStatus[ui8_StartAddr + ui8_Cnt] = TRUE;//write completed
				}
				else
				{
					ui8_TLE9180RegWriteStatus[ui8_StartAddr + ui8_Cnt] = FALSE;	//write error
					b_SpiErr = TRUE;
				}
			}
			else
			{
				ui8_TLE9180RegWriteStatus[ui8_StartAddr + ui8_Cnt] = FALSE;	//write error
				b_SpiErr = TRUE;
			}
		}
		if (b_SpiErr == FALSE) {
			ui8_Return = E_OK;
		} else {
			ui8_Return = E_NOT_OK;
		}
	} else {
		ui8_Return = E_NOT_OK;
	}

	return (ui8_Return);
}

/*******************************************************************************
 ** Function Name	: TLE9180_GetArrayCRC8bit
 ** Parameter[in] 	: uint8 *pui8_Array, uint8 ui8_Length
 ** Parameter[out] 	: uint8 *pui8_CRC8bit
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: TLE9180_CRC8计算
 *******************************************************************************/
void TLE9180_GetArrayCRC8bit(uint8 *pui8_Array, uint8 ui8_Length,
		uint8 *pui8_CRC8bit) {
	uint8 ui8_Cnt = 0;
	uint8 ui8_CalcData = 0;

	for (ui8_Cnt = 0; ui8_Cnt < ui8_Length; ui8_Cnt++) {
		ui8_CalcData = ui8_CRC8Table[pui8_Array[ui8_Cnt] ^ ui8_CalcData];
	}
	*pui8_CRC8bit = ui8_CalcData;
}

/*******************************************************************************
 ** Function Name	: TLE9180_GetFrameCRC3bit
 ** Parameter[in] 	: None
 ** Parameter[out] 	: uint32 *pui32_FrameData
 ** Return Value	: None
 ** Note			: None
 ** Description	  	: TLE9180_CRC3计算
 *******************************************************************************/
void TLE9180_GetFrameCRC3bit(uint32 *pui32_FrameData) {
	uint8 ui8_Cnt = 0;
	uint8 ui8_CalcData = 0;
	uint32 ui32_Tmp = 0;
	uint32 ui32_FrameData = 0;

	ui32_FrameData = *pui32_FrameData;
	ui32_FrameData &= 0x00FFFFFF;					//get 0~23 bit

	ui32_FrameData ^= 0x00800000;					//23 bit reverse

	ui8_CalcData = (uint8) ((uint32) (ui32_FrameData >> 20) & 0x0000000F);//get high 4 bit 24~27 bit

	for (ui8_Cnt = 0; ui8_Cnt < 20; ui8_Cnt++)		//shift 24 times
			{
		if ((ui8_CalcData & 0x08) == 0x08)			//XOR if bit4 == 1
				{
			ui8_CalcData ^= (uint8) TLE9180_FRAME_CRC_POLY;
		}
		//shift left and clear lowest bit, fill in 23~0 bit on loop
		ui8_CalcData = ((uint8) (ui8_CalcData << 1)) & 0x0F;
		ui8_CalcData |= (uint8) ((uint32) (ui32_FrameData >> (19 - ui8_Cnt))
				& 0x00000001);
	}
	if ((ui8_CalcData & 0x08) == 0x08)				//XOR if bit4 == 1
			{
		ui8_CalcData ^= (uint8) TLE9180_FRAME_CRC_POLY;
	}

	ui32_Tmp = (uint32) ui8_CalcData;				//get CRC
	ui32_FrameData |= (ui32_Tmp & 0x00000007);		//XOR 0~2bit
	ui32_FrameData ^= 0x00800000;					//23 bit reverse
	*pui32_FrameData = ui32_FrameData;
}
