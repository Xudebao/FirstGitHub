#include "stm32f10x.h"  // �൱��51��Ƭ���е�  #include <reg52.h>
#include "bsp_led.h"

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M
	LED_GPIO_Config(); // LED�ƶ˿ڳ�ʼ��
	while(1)
	{		
   /*��ˮ�ƣ�������ʾ*/		
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
		
//	LED_BLACK;     // �ر����еƣ���Ϩ��
//	Delay(0xFFFFF);
	}
}


