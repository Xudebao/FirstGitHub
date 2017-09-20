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
#include "bsp_exti.h"
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
	// HSI_SetSysClock(RCC_PLLMul_4);

	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();// ��ʼ��LED��
  EXIT_KEY_Config();// ��ʼ���жϺ���
	while (1);
}

/*********************************************END OF FILE**********************/
