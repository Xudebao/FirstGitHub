#include "stm32f10x.h"  // 相当于51单片机中的  #include <reg52.h>
#include "bsp_led.h"
#include "bsp_key.h"

#define GPIOB_ODR_Addr    (GPIOB_BASE + 0x0C) // ODR寄存器的基地址 = GPIOB基地址+寄存器偏移地址

/*带参宏定义PBout(n)，转换得到引脚别名的地址，其中n指的是，对ODR寄存器的第n位进行操作*/ 
#define PBout(n)  *(unsigned int *)((GPIOB_ODR_Addr & 0xF0000000) + 0x02000000 + ((GPIOB_ODR_Addr & 0x00FFFFFF) << 5) + (n << 2))
	
#define GPIOA_IDR_Addr    (GPIOA_BASE + 0x08) // 同上

/*作用同上*/
#define PAin(n)   *(unsigned int *)((GPIOA_IDR_Addr & 0xF0000000) + 0x02000000 + ((GPIOA_IDR_Addr & 0x00FFFFFF) << 5) + (n << 2))

void Delay(uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M
	LED_GPIO_Config();
  KEY_GPIO_Config(); 
#if 0	
		while(1)
		{
			PBout(1) = 1; // 若 PB1 为1
			Delay(0xFFFFF);
			PBout(1) = 0;
			Delay(0xFFFFF);
		}
#else
		while(1)
		{
			if (PAin(0) == KEY_ON)	// 若 PA0 为KEY_ON
			{
				while(PAin(0) == KEY_ON);// 松手检测
				LED_G_TOGGLE;
			}
		}
#endif
}


