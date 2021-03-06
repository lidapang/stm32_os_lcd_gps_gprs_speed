#include "app_sys.h"

__asm void SystemReset(void) 
{ 
	MOV R0, #1           //;  
	MSR FAULTMASK, R0    //; 清除FAULTMASK 禁止一切中断产生 
	LDR R0, =0xE000ED0C  //; 
	LDR R1, =0x05FA0004  //; 
	STR R1, [R0]         //; 系统软件复位    

deadloop 
	B deadloop        //; 死循环使程序运行不到下面的代码 
}

static void app_sys_reboot_pre(void)
{

}

void app_sys_reboot(void)
{
	app_sys_reboot_pre();

	SystemReset();
}
