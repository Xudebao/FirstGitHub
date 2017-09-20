#include "stm32f10x.h"  // 相当于51单片机中的  #include <reg52.h>
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M
	LED_GPIO_Config(); // LED灯端口初始化
	while(1)
	{		
   /*流水灯，轮流显示*/		
		LED_GREEN; 
		Delay(0xFFFFF);
		
		LED_RED	
		Delay(0xFFFFF);
		
		LED_WHITE;
		Delay(0xFFFFF);
		
		LED_BLUE;
		Delay(0xFFFFF);
		
		LED_YELLOW;
		Delay(0xFFFFF);
	
	  LED_CYAN;
		Delay(0xFFFFF);
		
		LED_PURPLE;
		Delay(0xFFFFF);
		
//	LED_BLACK;     // 关闭所有灯（即熄灭）
//	Delay(0xFFFFF);
	}
}


