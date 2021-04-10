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
section_layout :vtc:linear
{
	group ramdataload (ordered,contiguous, load_addr = mem:mpe:pflash0)
	{
		select "*.data.*";
	}
	group {//core0
		group pwmramcode0 (ordered,copy,run_addr = mem:mpe:pspr0)
		{
			 select ".text.*Core0.*";

		}
		

		group ramdata0 (ordered,attributes=rw,run_addr = mem:mpe:dspr0)
		{
			select ".data.*Core0.*";
			select ".bss.*Core0.*";
			
		}
	}
	group {//core1
		group pwmramcode1 (ordered,copy,run_addr = mem:mpe:pspr1)
		{
			select ".text.*Core1.*";
		}
		

		group ramdata1 (ordered,attributes=rw,run_addr = mem:mpe:dspr1)
		{
			select ".data.*Core1.*";
			select ".bss.*Core1.*";
			
		}
	}
	group {//core2
		group pwmramcode2 (ordered,copy,run_addr = mem:mpe:pspr2)
		{
			select ".text.*Core2.*";
		}
		
	
		group ramdata2 (ordered,attributes=rw,run_addr = mem:mpe:dspr2)
		{
			select ".data.*Core2.*";
			select ".bss.*Core2.*";			
		}
		
	}
}
section_layout :vtc:abs18
{
	group
	{
		group ramzdata0 (ordered,contiguous, attributes=rw,run_addr = mem:mpe:dspr0)
		{
			select "*.zdata.*Core0.*";
			select "*.zbss.*Core0.*";
			
		}
	}
	group
	{
		group ramzdata1 (ordered,contiguous, attributes=rw,run_addr = mem:mpe:dspr1)
		{
			select "*.zdata.*Core1.*";
			select "*.zbss.*Core1.*";
			
		}
	}
	
	group
	{
		group ramzdata2 (ordered,contiguous, attributes=rw,run_addr = mem:mpe:dspr2)
		{
			select "*.zdata.*Core2.*";
			select "*.zbss.*Core2.*";
			
		}
	}

}  
#else
#include <cpu.lsl>
#endif
