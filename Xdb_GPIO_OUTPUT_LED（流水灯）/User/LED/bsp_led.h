#ifndef _BSP_LED_H   // 防止这个头文件被调用时，引起重复定义
#define _BSP_LED_H

#include "stm32f10x.h"

/*绿灯引脚宏定义*/
#define LED_G_GPIO_PIN    GPIO_Pin_0  // 引脚
#define LED_G_GPIO_PORT   GPIOB       // 端口
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB  // 时钟

/*蓝灯引脚宏定义*/
#define LED_B_GPIO_PIN    GPIO_Pin_1  // 引脚
#define LED_B_GPIO_PORT   GPIOB       // 端口
#define LED_B_GPIO_CLK    RCC_APB2Periph_GPIOB  // 时钟

/*红灯引脚宏定义*/
#define LED_R_GPIO_PIN    GPIO_Pin_5  // 引脚
#define LED_R_GPIO_PORT   GPIOB       // 端口
#define LED_R_GPIO_CLK    RCC_APB2Periph_GPIOB  // 时钟

#define ON 1
#define OFF 0

// 使用带参数的宏定义LED_G(a) ，如果参数为1，则执行GPIO_ResetBits；否则如果参数为0，执行GPIO_ResetBits
// \反斜杠在C语言中表示续行符，后面不能有任何东西,空格都不能有
#define LED_G(a)   if(a) \
                          GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN); \
                    else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

#define LED_R(a)   if(a) \
                          GPIO_ResetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN); \
                    else  GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);

#define LED_B(a)   if(a) \
                          GPIO_ResetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN); \
                    else  GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);

#define LED_RED       LED_G(OFF);LED_R(ON);LED_B(OFF)  // 红

// 带参数的宏定义,如果为ON，相当于执行GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN)，为OFF相当于执行GPIO_SetBits;

#define LED_GREEN     LED_G(ON);LED_R(OFF);LED_B(OFF)  // 绿

#define LED_BLUE      LED_G(OFF);LED_R(OFF);LED_B(ON)  // 蓝

#define LED_WHITE     LED_G(ON);LED_R(ON);LED_B(ON)    // 白

#define LED_YELLOW    LED_G(ON);LED_R(ON);LED_B(OFF)   // 黄

#define LED_BLACK     LED_G(OFF);LED_R(OFF);LED_B(OFF) // 黑（灭）

#define LED_PURPLE    LED_G(OFF);LED_R(ON);LED_B(ON)   // 紫

#define LED_CYAN      LED_G(ON);LED_R(OFF);LED_B(ON)   // 青

void LED_GPIO_Config(void);  // LED灯的初始化函数声明

#endif /*_BSP_LED_H*/

