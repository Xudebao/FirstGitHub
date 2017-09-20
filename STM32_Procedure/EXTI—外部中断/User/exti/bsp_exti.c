#include "bsp_exti.h"

static void EXIT_NVIC_Config(void)  // 中断优先级控制,此处加上static表示该函数只能被bsp_exti.c里面的文件所调用，其他文件不能调用
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn ;
	
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;// 主优先级
	
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;// 子优先级
	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;// 开总中断
	
	NVIC_Init(& NVIC_InitStructure);
}

void EXIT_KEY_Config(void)
{
			/*调用库函数，初始化GPIO*/
		GPIO_InitTypeDef GPIO_InitStructure;
	  EXTI_InitTypeDef EXTI_InitStructure;
	
	  EXIT_NVIC_Config();// 配置中断优先级
	
		RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);

		GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;	

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure);	
	
	   /*初始化EXTI*/
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	   /*初始化EXTI结构体*/
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	  
	  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		
		EXTI_Init(&EXTI_InitStructure);

}