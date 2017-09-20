#include "stm32f10x.h"  // �൱��51��Ƭ���е�  #include <reg52.h>
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M
	LED_GPIO_Config();
	while(1)
	{
		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		LED_G(ON); // �������ĺ궨��,���ΪON���൱��ִ��GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		Delay(0xFFFFF);
		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		LED_G(OFF);	// �������ĺ궨�壬���ΪOFF���൱��ִ��GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
		Delay(0xFFFFF);
	}
}


