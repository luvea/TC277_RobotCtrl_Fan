################################################################################
# Automatically-generated file. Do not edit!
################################################################################

PROJ 	= TC277_RobotCtrl_ADCQueue
PRODDIR = R:\Program Files\TASKING\TriCore v6.2r2\ctc\eclipse\plugins\com.tasking.ctc.debug.win32.x86_1.8.0.0\ctc

-include "..\makefile.init"

all :

-include "subdir.mk"
-include "Asw\subdir.mk"
-include "Aurix_MC-ISAR\adc_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\can_17_mcanp_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\dio_infineon_tricore\src\subdir.mk"
-include "Aurix_MC-ISAR\ecum_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\icu_17_gtmccu6_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\integration_general\src\subdir.mk"
-include "Aurix_MC-ISAR\irq_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\mcu_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\port_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\pwm_17_gtm_infineon_tricore\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\tricore_general\ssc\src\subdir.mk"
-include "Aurix_MC-ISAR\uart_infineon_tricore\ssc\src\subdir.mk"
-include "Hal_Sensor\subdir.mk"
-include "output\generated\src\subdir.mk"
-include "PWM3Ph\subdir.mk"
-include "Qspi\subdir.mk"
-include "TestCode\Adc3ph_Test\subdir.mk"
-include "TestCode\Adc_Test\subdir.mk"
-include "TestCode\Can_Test\subdir.mk"
-include "TLE_9180_Drive\subdir.mk"
-include "UART_Test\subdir.mk"
-include "..\makefile.defs"

PCP_FILES :=
EXT_LIBRARIES =

all : "TC277_RobotCtrl_ADCQueue.elf"

"TC277_RobotCtrl_ADCQueue.elf" : $(OBJ_FILES) $(EXT_LIBRARIES) ".TC277_RobotCtrl_ADCQueue.elf.opt"
	@echo Linking to ${@F}
	@"${PRODDIR}\bin\cctc" -f ".TC277_RobotCtrl_ADCQueue.elf.opt"

".TC277_RobotCtrl_ADCQueue.elf.opt" : .refresh
	@argfile ".TC277_RobotCtrl_ADCQueue.elf.opt" -o "TC277_RobotCtrl_ADCQueue.elf" $(OBJ_FILES) $(EXT_LIBRARIES) $(PCP_FILES)  -Ctc27xc --lsl-core=vtc -t -I"W:\AURIX\Robot\TC277_RobotCtrl_ADCQueue_zhaojing\Tasking\TC277_RobotCtrl_ADCQueue" -Wl-o"${PROJ}.hex":IHEX:4 --hex-format=s "..\TC277_RobotCtrl_ADCQueue.lsl" -Wl-OtxycL -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g --fp-model=3 -Wl--dep-file=".TC277_RobotCtrl_ADCQueue.elf.d" -Wl--make-target="TC277_RobotCtrl_ADCQueue.elf"
DEPENDENCY_FILES += ".TC277_RobotCtrl_ADCQueue.elf.d"
-include $(DEPENDENCY_FILES)

$(EXT_LIBRARIES) : .dummy

GENERATED_FILES += "TC277_RobotCtrl_ADCQueue.elf" "TC277_RobotCtrl_ADCQueue*.sre" "TC277_RobotCtrl_ADCQueue*.hex" "TC277_RobotCtrl_ADCQueue.map*" "TC277_RobotCtrl_ADCQueue.mdf" ".TC277_RobotCtrl_ADCQueue.elf.opt" ".TC277_RobotCtrl_ADCQueue.elf.d"
-include "..\makefile.targets"


clean : ".clean.opt"
	@echo Cleaning
	@rm -f -m ".clean.opt"

".clean.opt" : .refresh
	@argfile ".clean.opt" $(GENERATED_FILES) $(OPTIONAL_FILES)

GENERATED_FILES += ".clean.opt"
OPTIONAL_FILES +=  "*.pre" "*.lst" "*.p.o" "*.p.a"


.PHONY : .dummy .refresh
