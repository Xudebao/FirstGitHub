#include "bsp_exti.h"

static void EXIT_NVIC_Config(void)  // �ж����ȼ�����,�˴�����static��ʾ�ú���ֻ�ܱ�bsp_exti.c������ļ������ã������ļ����ܵ���
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn ;
	
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;// �����ȼ�
	
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// �����ȼ�
	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;// �����ж�
	
	NVIC_Init(& NVIC_InitStructure);
}

void EXIT_KEY_Config(void)
{
			/*���ÿ⺯������ʼ��GPIO*/
		GPIO_InitTypeDef GPIO_InitStructure;
	  EXTI_InitTypeDef EXTI_InitStructure;
	
	  EXIT_NVIC_Config();// �����ж����ȼ�
	
		RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);

		GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;	

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure);	
	
	   /*��ʼ��EXTI*/
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	   /*��ʼ��EXTI�ṹ��*/
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	  
	  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		
		EXTI_Init(&EXTI_InitStructure);

}