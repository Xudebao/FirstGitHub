#ifndef  _BSP_RCCCLCONFIG_H
#define  _BSP_RCCCLCONFIG_H

#include "stm32f10x.h"

void HSE_SetSysClock(uint32_t RCC_PLLMul_x); // 函数（HSE提供系统时钟）的声明
void HSI_SetSysClock(uint32_t RCC_PLLMul_x); // 函数（HSI提供系统时钟）的声明

#endif  /*_BSP_RCCCLCONFIG_H*/


