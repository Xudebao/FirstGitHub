#ifndef  _BSP_RCCCLCONFIG_H
#define  _BSP_RCCCLCONFIG_H

#include "stm32f10x.h"

void HSE_SetSysClock(uint32_t RCC_PLLMul_x); // ������HSE�ṩϵͳʱ�ӣ�������
void HSI_SetSysClock(uint32_t RCC_PLLMul_x); // ������HSI�ṩϵͳʱ�ӣ�������

#endif  /*_BSP_RCCCLCONFIG_H*/


