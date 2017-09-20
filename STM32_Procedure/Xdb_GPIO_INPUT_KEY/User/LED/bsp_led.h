#ifndef _BSP_LED_H   // 防止这个头文件被调用时，引起重复定义
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN    GPIO_Pin_1  // 引脚
#define LED_G_GPIO_PORT   GPIOB       // 端口
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB  // 时钟

#define ON 1
#define OFF 0

// 使用带参数的宏定义LED_G(a) ，如果参数为1，则执行GPIO_ResetBits；否则如果参数为0，执行GPIO_ResetBits
// \反斜杠在C语言中表示续行符，后面不能有任何东西,空格都不能有
#define LED_G(a)   if(a) \
                          GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN); \
                    else  GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

//  ^ 即“异或”，C语言的一个二进制的运算符，和1异或改变，和0异或不变
#define LED_G_TOGGLE      {LED_G_GPIO_PORT-> ODR ^= LED_G_GPIO_PIN;}

void LED_GPIO_Config(void);

#endif /*_BSP_LED_H*/

