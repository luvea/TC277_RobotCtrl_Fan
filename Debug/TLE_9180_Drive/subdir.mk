################################################################################
# Automatically-generated file. Do not edit!
################################################################################

C_FILES += "..\TLE_9180_Drive\TLE9180_Callout.c"
OBJ_FILES += "TLE_9180_Drive\TLE9180_Callout.o"
"TLE_9180_Drive\TLE9180_Callout.o" : "..\TLE_9180_Drive\TLE9180_Callout.c" "TLE_9180_Drive\.TLE9180_Callout.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "TLE_9180_Drive\.TLE9180_Callout.o.opt"

"TLE_9180_Drive\.TLE9180_Callout.o.opt" : .refresh
	@argfile "TLE_9180_Drive\.TLE9180_Callout.o.opt" -o "TLE_9180_Drive\TLE9180_Callout.o" "..\TLE_9180_Drive\TLE9180_Callout.c" -Ctc27xc --lsl-core=vtc -t -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue" -Wa-H"sfr/regtc27xc.def" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 -D_TASKING_C_TRICORE_ -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\.settings" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Asw" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\dio_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\dio_infineon_tricore\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\dio_infineon_tricore\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\compiler" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\inc\TC27xC" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\inc\TC27xC\SupportDocuments" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\integration_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\integration_general\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\integration_general\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\lib" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\obj" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Asw" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\adc_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\adc_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\adc_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\dio_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\dio_infineon_tricore\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\ecum_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\ecum_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\ecum_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\integration_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\integration_general\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\irq_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\irq_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\irq_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\mcu_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\mcu_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\mcu_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\port_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\port_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\port_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\tricore_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\tricore_general\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\tricore_general\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\uart_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\uart_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\uart_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Hal_Sensor" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\output" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\output\generated" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\output\generated\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\PWM3Ph" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Qspi" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode\Adc_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode\Adc3ph_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode\Can_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TLE_9180_Drive" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\UART_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Hal_Sensor" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\Demo_Aurix" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\mak" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\PWM3Ph" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Qspi" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode\Adc_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode\Adc3ph_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode\Can_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TLE_9180_Drive" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\UART_Test" --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=2 --compact-max-size=200 -g --error-limit=42 --source -c --dep-file="TLE_9180_Drive\.TLE9180_Callout.o.d" -Wc--make-target="TLE_9180_Drive\TLE9180_Callout.o"
DEPENDENCY_FILES += "TLE_9180_Drive\.TLE9180_Callout.o.d"

C_FILES += "..\TLE_9180_Drive\TLE_9180.c"
OBJ_FILES += "TLE_9180_Drive\TLE_9180.o"
"TLE_9180_Drive\TLE_9180.o" : "..\TLE_9180_Drive\TLE_9180.c" "TLE_9180_Drive\.TLE_9180.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "TLE_9180_Drive\.TLE_9180.o.opt"

"TLE_9180_Drive\.TLE_9180.o.opt" : .refresh
	@argfile "TLE_9180_Drive\.TLE_9180.o.opt" -o "TLE_9180_Drive\TLE_9180.o" "..\TLE_9180_Drive\TLE_9180.c" -Ctc27xc --lsl-core=vtc -t -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue" -Wa-H"sfr/regtc27xc.def" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 -D_TASKING_C_TRICORE_ -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\.settings" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Asw" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\adc_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\dio_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\dio_infineon_tricore\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\dio_infineon_tricore\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\ecum_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\compiler" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\inc\TC27xC" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\general\tricore\inc\TC27xC\SupportDocuments" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\integration_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\integration_general\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\integration_general\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\irq_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\mcu_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\port_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\lib" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\obj" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\tricore_general\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore\ssc\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Aurix_MC-ISAR\uart_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Asw" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\adc_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\adc_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\adc_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\dio_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\dio_infineon_tricore\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\ecum_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\ecum_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\ecum_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\integration_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\integration_general\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\irq_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\irq_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\irq_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\mcu_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\mcu_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\mcu_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\port_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\port_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\port_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\tricore_general" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\tricore_general\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\tricore_general\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\uart_infineon_tricore" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\uart_infineon_tricore\ssc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Aurix_MC-ISAR\uart_infineon_tricore\ssc\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Hal_Sensor" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\output" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\output\generated" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\output\generated\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\PWM3Ph" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\Qspi" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode\Adc_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode\Adc3ph_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TestCode\Can_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\TLE_9180_Drive" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Debug\UART_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Hal_Sensor" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\Demo_Aurix" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\inc" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\mak" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\output\generated\src" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\PWM3Ph" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\Qspi" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode\Adc_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode\Adc3ph_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TestCode\Can_Test" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\TLE_9180_Drive" -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue\UART_Test" --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=8 --default-a0-size=0 --default-a1-size=0 -O2 --tradeoff=2 --compact-max-size=200 -g --error-limit=42 --source -c --dep-file="TLE_9180_Drive\.TLE_9180.o.d" -Wc--make-target="TLE_9180_Drive\TLE_9180.o"
DEPENDENCY_FILES += "TLE_9180_Drive\.TLE_9180.o.d"


GENERATED_FILES += "TLE_9180_Drive\TLE9180_Callout.o" "TLE_9180_Drive\.TLE9180_Callout.o.opt" "TLE_9180_Drive\.TLE9180_Callout.o.d" "TLE_9180_Drive\TLE9180_Callout.src" "TLE_9180_Drive\TLE9180_Callout.lst" "TLE_9180_Drive\TLE_9180.o" "TLE_9180_Drive\.TLE_9180.o.opt" "TLE_9180_Drive\.TLE_9180.o.d" "TLE_9180_Drive\TLE_9180.src" "TLE_9180_Drive\TLE_9180.lst"
