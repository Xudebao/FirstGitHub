// bsp:�弶֧�ְ���������������Ҫ��ָ���߿������Ӧ��
#include "bsp_led.h"  // �ڴ�֮��Ҫָ��bsp_led.h��·��,���������������ҵ����ͷ�ļ�����ÿ���½�һ��ͷ�ļ�����Ҫָ������·��

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct; // ��ʼ��һ���ṹ��
	
	RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK|LED_B_GPIO_CLK, ENABLE); // ���ó�ʼ�����������������д�뵽RCC�У���ʱ�ӣ�
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN; // ��GPIO_InitStruct����ṹ���еĳ�Ա�����Ҫ���ƵĲ���
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // ģʽ
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;// �ٶ�
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);// ���ó�ʼ�����������������д�뵽CRL��
	
	GPIO_InitStruct.GPIO_Pin = LED_B_GPIO_PIN;
	GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStruct);
	GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);
}
