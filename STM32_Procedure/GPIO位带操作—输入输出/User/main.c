#include "stm32f10x.h"  // �൱��51��Ƭ���е�  #include <reg52.h>
#include "bsp_led.h"
#include "bsp_key.h"

#define GPIOB_ODR_Addr    (GPIOB_BASE + 0x0C) // ODR�Ĵ����Ļ���ַ = GPIOB����ַ+�Ĵ���ƫ�Ƶ�ַ

/*���κ궨��PBout(n)��ת���õ����ű����ĵ�ַ������nָ���ǣ���ODR�Ĵ����ĵ�nλ���в���*/ 
#define PBout(n)  *(unsigned int *)((GPIOB_ODR_Addr & 0xF0000000) + 0x02000000 + ((GPIOB_ODR_Addr & 0x00FFFFFF) << 5) + (n << 2))
	
#define GPIOA_IDR_Addr    (GPIOA_BASE + 0x08) // ͬ��

/*����ͬ��*/
#define PAin(n)   *(unsigned int *)((GPIOA_IDR_Addr & 0xF0000000) + 0x02000000 + ((GPIOA_IDR_Addr & 0x00FFFFFF) << 5) + (n << 2))

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M
	LED_GPIO_Config();
  KEY_GPIO_Config(); 
#if 0	
		while(1)
		{
			PBout(1) = 1; // �� PB1 Ϊ1
			Delay(0xFFFFF);
			PBout(1) = 0;
			Delay(0xFFFFF);
		}
#else
		while(1)
		{
			if (PAin(0) == KEY_ON)	// �� PA0 ΪKEY_ON
			{
				while(PAin(0) == KEY_ON);// ���ּ��
				LED_G_TOGGLE;
			}
		}
#endif
}


