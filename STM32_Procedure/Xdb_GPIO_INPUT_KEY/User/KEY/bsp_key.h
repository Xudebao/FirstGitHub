#ifndef _BSP_KEY_H   // 防止这个头文件被调用时，引起重复定义
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_PIN    GPIO_Pin_0  // 引脚
#define KEY1_GPIO_PORT   GPIOA       // 端口
#define KEY1_GPIO_CLK    RCC_APB2Periph_GPIOA  // 时钟

#define KEY_ON   1  // 高电平表示按键按下
#define KEY_OFF  0

void KEY_GPIO_Config(void);  // 函数在头文件中进行声明，为了让其他的函数进行调用
uint8_t Key_Scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin);   // 函数在头文件中进行声明，为了让其他的函数进行调用




#endif  