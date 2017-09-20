#include "stm32f10x.h"  // 相当于51单片机中的  #include <reg52.h>
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M
	LED_GPIO_Config();
	while(1)
	{
		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		LED_G(ON); // 带参数的宏定义,如果为ON，相当于执行GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		Delay(0xFFFFF);
		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		LED_G(OFF);	// 带参数的宏定义，如果为OFF，相当于执行GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		Delay(0xFFFFF);
	}
}


