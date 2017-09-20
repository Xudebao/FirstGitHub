#include "bsp_key.h"

void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct; // 初始化一个结构体
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE); // 调用初始化函数将上面的配置写入到RCC中（开时钟）
	
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN; // 向GPIO_InitStruct这个结构体中的成员添加需要控制的参数
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;  // 模式(浮空输入)
		
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);// 调用初始化函数将上面的配置写入到CRL中
}

uint8_t Key_Scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin)  // 定义两个形参，一个是要扫描的端口，一个是端口的引脚
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		// 松手检测
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
		return KEY_ON;
	}
	else return KEY_OFF;
}

