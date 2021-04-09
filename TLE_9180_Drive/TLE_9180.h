
#ifndef TLE9180_H_
#define TLE9180_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include	"Std_Types.h"
#include	"IfxQspi_reg.h"
#include	"IfxStm_reg.h"
#include	"AuirxQspi.h"

#include	"TLE9180_Callout.h"
#include	"Test_Time.h"
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define		TLE_CONFIG					0x01
#define		TLE9180_FRAME_CRC_SEED		0x05
#define		TLE9180_FRAME_CRC_POLY		0x0B

#define		TLE9180_REG_READ_VALID		0x01
#define		TLE9180_REG_WRITE_VALID		0x10


#define		TLE9180_REG_AMOUNT			0x68
//configuration register
/*配置寄存器*/  //每个2byte  8bit
#define		TLE9180_CONF_SIG			0x00                               //Conf_Sig
#define		TLE9180_CONF_GEN_1			0x01                               //Conf_Gen_1  (1、过温检测阀值；2、输入模式监控；3、spi窗口看门狗；4，limp Home Mode激活；5、VCC监控；6、VCC监控阀值。
#define		TLE9180_CONF_GEN_2			0x02                               //Conf_Gen_2  (1、过流检测阀值；2、禁用OV BSx；3、禁用OV LD；4、禁用VDHP；5、启用三个VDHx引脚检测；6、使能电流检测放大器3；7、使能电流检测放大器2；8、使能电流检测放大器1；)
#define		TLE9180_CONF_GEN_3			0x03                               //Conf_Gen_3  (1、保留；2、使能ART pin；3、APC定时激活；4、APC输出信号配置；5、ART模式下短路检测的故障行为)
#define		TLE9180_CONF_WWD			0x04                               //Window Watchdog
#define		TLE9180_TL_VS				0x05
#define		TLE9180_TL_VDH				0x06
#define		TLE9180_TL_CBVCC			0x07
#define		TLE9180_FM_1				0x08
#define		TLE9180_FM_2				0x09
#define		TLE9180_FM_3				0x0A
#define		TLE9180_FM_4				0x0B
#define		TLE9180_FM_5				0x0C
#define		TLE9180_DT_HS				0x0D
#define		TLE9180_DT_LS				0x0E
#define		TLE9180_FT_1				0x0F
#define		TLE9180_FT_2				0x10
#define		TLE9180_FT_3				0x11
#define		TLE9180_FT_4				0x12
#define		TLE9180_FM_6				0x13

//control register
/*控制寄存器*/
#define		TLE9180_OP_GAIN_1			0x20
#define		TLE9180_OP_GAIN_2			0x21
#define		TLE9180_OP_GAIN_3			0x22
#define		TLE9180_OP_0CL				0x23
#define		TLE9180_OP_CON				0x24
#define		TLE9180_SC_LS_1				0x25
#define		TLE9180_SC_LS_2				0x26
#define		TLE9180_SC_LS_3				0x27
#define		TLE9180_SC_HS_1				0x28
#define		TLE9180_SC_HS_2				0x29
#define		TLE9180_SC_HS_3				0x2A
#define		TLE9180_LI_CTR				0x2B
#define		TLE9180_MISC_CTR			0x2C
#define		TLE9180_ART_TLP				0x2D
#define		TLE9180_ART_TLA				0x2E
#define		TLE9180_ART_FI				0x2F
#define		TLE9180_ART_ACC				0x30
#define		TLE9180_ART_ENTRY			0x31
#define		TLE9180_NOP					0x32
#define		TLE9180_DREV_MARK			0x33
#define		TLE9180_DS_MARK				0x34

//self test register
#define		TLE9180_SEL_ST_1			0x35                              //Sel_st_1
#define		TLE9180_SEL_ST_2			0x36                              //Sel_st_2
#define		TLE9180_EN_ST				0x37                              //En_st

//read register
#define		TLE9180_OM_OVER				0x40
#define		TLE9180_ERR_OVER			0x41
#define		TLE9180_SER					0x42
#define		TLE9180_ERR_I_1				0x43
#define		TLE9180_ERR_I_2				0x44
#define		TLE9180_ERR_E				0x45
#define		TLE9180_ERR_SD				0x46
#define		TLE9180_ERR_SCD				0x47
#define		TLE9180_ERR_INDIAG			0x48
#define		TLE9180_ERR_OSF				0x49
#define		TLE9180_ERR_SPICONF			0x4A
#define		TLE9180_ERR_OP_12			0x4B
#define		TLE9180_ERR_OP_3			0x4C
#define		TLE9180_ERR_OUTP			0x4D
#define		TLE9180_DSM_LS1				0x4E
#define		TLE9180_DSM_LS2				0x4F
#define		TLE9180_DSM_LS3				0x50
#define		TLE9180_DSM_HS1				0x51
#define		TLE9180_DSM_HS2				0x52
#define		TLE9180_DSM_HS3				0x53
#define		TLE9180_RDM_LS1				0x54
#define		TLE9180_RDM_LS2				0x55
#define		TLE9180_RDM_LS3				0x56
#define		TLE9180_RDM_HS1				0x57
#define		TLE9180_RDM_HS2				0x58
#define		TLE9180_RDM_HS3				0x59
#define		TLE9180_TEMP_LS1			0x5A
#define		TLE9180_TEMP_LS2			0x5B
#define		TLE9180_TEMP_LS3			0x5C
#define		TLE9180_TEMP_HS1			0x5D
#define		TLE9180_TEMP_HS2			0x5E
#define		TLE9180_TEMP_HS3			0x5F
#define		TLE9180_WWLC				0x60
#define		TLE9180_RES_CC1				0x61
#define		TLE9180_RES_CC2				0x62
#define		TLE9180_RES_CC3				0x63
#define		TLE9180_RES_VCC				0x64
#define		TLE9180_RES_CB				0x65
#define		TLE9180_RES_VS				0x66
#define		TLE9180_RES_VDH				0x67

/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef enum	TLE9180_STATE
{
	TLE9180_SLEEP = 0,
	TLE9180_IDLE_CHECK_SPI,
	TLE9180_IDLE_CHECK_ERR_REG,

	TLE9180_IDLE_CHECK_STEP1,
	TLE9180_IDLE_CHECK_STEP2,
	TLE9180_IDLE_CHECK_STEP3,
	TLE9180_IDLE_CHECK_COMPLETED,

	TLE9180_ENA_RESET,
	TLE9180_CONFIG,
	TLE9180_POWERUP_END,
	TLE9180_FAULT,
}e_TLE9180StateType;

typedef enum	TLE9180_FAULT
{
	TLE9180_NO_FAULT = 0,
	TLE9180_IDLE_ERR_PIN_DETECTED,
	TLE9180_SPI_FRAME_ERR,
	TLE9180_SPI_FRAME_ERR_TWICE,
	TLE9180_NOP_REG_READ_FAILED,
	TLE9180_NOT_IDLE,
	TLE9180_NOT_NORMAL,
	TLE9180_UNACCEPTABLE_ERR,

}e_TLE9180FaultType;

/*******************************************************************************
**                  Global Variables With Extern Linkage               		  **
*******************************************************************************/
extern uint8 ui8_CRC8Table[256];
extern e_TLE9180StateType e_TLE9180State;
extern e_TLE9180StateType e_TLE9180CheckErrState;
extern e_TLE9180StateType e_TLE9180Fault;
extern void TLE9180_GetFrameCRC3bit(uint32 *pui32_FrameData);
extern void TLE9180_GetArrayCRC8bit(uint8 *pui8_Array, uint8 ui8_Length, uint8 *pui8_CRC8bit);
extern Std_ReturnType TLE9180_RegRangeCheck(uint8 ui8_StartAddr, uint8 ui8_EndAddr);
extern void TLE9180_Init(void);
extern void TLE9180_PowerupSequence(void);

#endif
