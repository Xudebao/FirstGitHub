#include "stm32f10x_gpio.h"

void GPIO_SetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
// GPIO��λ���������Ҷ�������������һ���������ö˿�ѡ��(��GPIOB)��һ��������������(����1)
{
	GPIOB->BSRR = GPIO_Pin ;// �ԼĴ���BSRR(�˿�λ��������Ĵ���)���в���
}

// GPIO��λ���������Ҷ�������������һ���������ö˿�ѡ��(��GPIOB)��һ�������������ݣ�������Ϊ1ʱ���˿�����͵�ƽ
void GPIO_ResetBits(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	GPIOB->BRR = GPIO_Pin;
}


