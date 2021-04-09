// TASKING VX-toolset for TriCore
// Eclipse project linker script file
// 
#if defined(__PROC_TC27XC__)
#include "tc27xc.lsl"
derivative my_tc27xc extends tc27xc
{
}

section_layout mpe:vtc:linear
{
	group BMI (ordered,run_addr = 0xA0000000)
	{
		section "BMI_Header" (blocksize=0x20, attributes=r,fill=0x0)
		{
			select ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED";
			
		}
	}
	

}
#else
#include <cpu.lsl>
#endif
