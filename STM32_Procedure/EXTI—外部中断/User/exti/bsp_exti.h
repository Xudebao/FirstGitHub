#ifndef _BSP_EXTI_H
#define _BSP_EXTI_H

#include "stm32f10x.h"

#define KEY1_INT_GPIO_PORT    	GPIOA			              /* GPIO�˿� */
#define KEY1_INT_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define KEY1_INT_GPIO_PIN		    GPIO_Pin_0			        /* ���ӵ�SCLʱ���ߵ�GPIO */

void EXIT_KEY_Config(void);


#endif /*_BSP_EXTI_H*/


