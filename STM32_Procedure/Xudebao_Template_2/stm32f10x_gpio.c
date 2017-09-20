#include "stm32f10x_gpio.h"

void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
// GPIO置位函数，并且定义两个参数，一个参数设置端口选择(如GPIOB)，一个参数设置数据(如置1)
{
	GPIOB->BSRR = GPIO_Pin ;// 对寄存器BSRR(端口位设置清楚寄存器)进行操作
}

// GPIO复位函数，并且定义两个参数，一个参数设置端口选择(如GPIOB)，一个参数设置数据，当数据为1时，端口输出低电平
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOB->BRR = GPIO_Pin;
}


