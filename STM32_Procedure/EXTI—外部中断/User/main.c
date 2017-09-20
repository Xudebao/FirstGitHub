/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	 // 自行选择系统时钟(使用HSE提供系统时钟)，通过修改参数获得16M到128M等不同的系统时钟,(参数中x的取值(即倍频因子)，可由2到16)
	 //HSE_SetSysClock(RCC_PLLMul_9); 
	
	 // 自行选择系统时钟(使用HSI提供系统时钟)，通过修改参数获得8M到64M等不同的系统时钟,(参数中x的取值(即倍频因子)，可由2到16)
	// HSI_SetSysClock(RCC_PLLMul_4);

	/* LED 端口初始化 */
	LED_GPIO_Config();// 初始化LED灯
  EXIT_KEY_Config();// 初始化中断函数
	while (1);
}

/*********************************************END OF FILE**********************/
