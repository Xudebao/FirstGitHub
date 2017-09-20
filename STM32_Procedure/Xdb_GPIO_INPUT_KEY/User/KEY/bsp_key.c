#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct; // ��ʼ��һ���ṹ��
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE); // ���ó�ʼ�����������������д�뵽RCC�У���ʱ�ӣ�
	
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN; // ��GPIO_InitStruct����ṹ���еĳ�Ա�����Ҫ���ƵĲ���
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;  // ģʽ(��������)
		
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);// ���ó�ʼ�����������������д�뵽CRL��
}

uint8_t Key_Scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin)  // ���������βΣ�һ����Ҫɨ��Ķ˿ڣ�һ���Ƕ˿ڵ�����
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		// ���ּ��
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
		return KEY_ON;
	}
	else return KEY_OFF;
}

