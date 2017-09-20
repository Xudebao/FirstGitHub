// bsp:板级支持包（即此驱动程序要和指南者开发板对应）
#include "bsp_led.h"  // 在此之后，要指定bsp_led.h的路径,这样编译器才能找到这个头文件。另：每次新建一个头文件都需要指定它的路径


/*初始化函数的内容有：开时钟、选择引脚、设置模式、设置速度、调用函数GPIO_Init将这些配置写入寄存器*/
void LED_GPIO_Config(void)  /*LED灯的初始化函数*/
{
	GPIO_InitTypeDef  GPIO_InitStruct; // 初始化一个结构体
	
	RCC_APB2PeriphClockCmd( LED_G_GPIO_CLK | LED_R_GPIO_CLK | LED_R_GPIO_CLK, ENABLE); // 调用初始化函数将上面的配置写入到RCC中（开时钟）
	
	GPIO_InitStruct.GPIO_Pin = LED_G_GPIO_PIN; // 向GPIO_InitStruct这个结构体中的成员添加需要控制的参数
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // 模式
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;// 速度
	GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);// 调用初始化函数将上面的配置写入到CRL中
	
	GPIO_InitStruct.GPIO_Pin = LED_B_GPIO_PIN; // 向GPIO_InitStruct这个结构体中的成员添加需要控制的参数
	GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStruct);// 调用初始化函数将上面的配置写入到CRL中

	GPIO_InitStruct.GPIO_Pin = LED_R_GPIO_PIN; // 向GPIO_InitStruct这个结构体中的成员添加需要控制的参数
	GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStruct);// 调用初始化函数将上面的配置写入到CRL中
	
	GPIO_SetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);
	GPIO_SetBits(LED_B_GPIO_PORT,LED_B_GPIO_PIN);
	GPIO_SetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);
}
