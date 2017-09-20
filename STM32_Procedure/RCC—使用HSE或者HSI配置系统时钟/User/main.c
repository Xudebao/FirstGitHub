/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_rccclconfig.h"
#define SOFT_DELAY Delay(0x0FFFFF);

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	 // ����ѡ��ϵͳʱ��(ʹ��HSE�ṩϵͳʱ��)��ͨ���޸Ĳ������16M��128M�Ȳ�ͬ��ϵͳʱ��,(������x��ȡֵ(����Ƶ����)������2��16)
	 //HSE_SetSysClock(RCC_PLLMul_9); 
	
	 // ����ѡ��ϵͳʱ��(ʹ��HSI�ṩϵͳʱ��)��ͨ���޸Ĳ������8M��64M�Ȳ�ͬ��ϵͳʱ��,(������x��ȡֵ(����Ƶ����)������2��16)
	 HSI_SetSysClock(RCC_PLLMul_4);

	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 
 
	while (1)
	{
		LED1_ON;			  // ��
		SOFT_DELAY;
		LED1_OFF;		   // ��

		LED2_ON;			 // ��
		SOFT_DELAY;
		LED2_OFF;		   // ��

		LED3_ON;			 // ��
		SOFT_DELAY;
		LED3_OFF;		   // ��	 

		/*������ʾ ������������� ��ɫ*/
		LED_RED;
		SOFT_DELAY;
		
		LED_GREEN;
		SOFT_DELAY;
		
		LED_BLUE;
		SOFT_DELAY;
		
		LED_YELLOW;
		SOFT_DELAY;
		
		LED_PURPLE;
		SOFT_DELAY;
				
		LED_CYAN;
		SOFT_DELAY;
		
		LED_WHITE;
		SOFT_DELAY;
		
		LED_RGBOFF;
		SOFT_DELAY;		
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
