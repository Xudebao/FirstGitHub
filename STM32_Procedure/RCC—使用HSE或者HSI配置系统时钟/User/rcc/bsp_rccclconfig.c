#include "bsp_rccclconfig.h"

/*下面两个函数是通过软件设置，获得自己想要的系统时钟的大小，并且可以设定该系统时钟是由HSI或者HSE提供*/

void HSE_SetSysClock(uint32_t RCC_PLLMul_x) // 使用 HSE 来设置系统时钟
{
	ErrorStatus HSEStatus;  // 定义变量HSE的状态
	RCC_DeInit();// 为了重新配置RCC寄存器，需要把RCC复位为刚上电时的状态
	RCC_HSEConfig(RCC_HSE_ON);// HSE使能，开启外部晶振
	
	HSEStatus = RCC_WaitForHSEStartUp();// RCC_WaitForHSEStartUp()用于等待晶振HSE就绪，该函数的返回值为SUCCESS或ERROR
	
	if (HSEStatus == SUCCESS) // 如果HSE启动成功
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);// 使能FLASH，预存取缓冲区
		FLASH_SetLatency(FLASH_Latency_2);// 设置FLASH等待周期
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1); // AHB预分频因子，72M
		RCC_PCLK1Config(RCC_HCLK_Div2);  // APB1预分频因子，36M
		RCC_PCLK2Config(RCC_HCLK_Div1);  // APB2预分频因子，72M
		
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);// 设置PLL的来源以及倍频因子
    RCC_PLLCmd(ENABLE); // PLL 使能
		
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); // 等待PLL稳定
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // 选择系统时钟
		while(RCC_GetSYSCLKSource() != 0x08); // 读取时钟切换状态位，确保PLLCLK被选为系统时钟
	}
	else
	{
		// 如果HSI启动失败，用户可以在这里添加启动失败的代码
	}
}

void HSI_SetSysClock(uint32_t RCC_PLLMul_x) // 使用 HSI 来设置系统时钟
{
	__IO uint32_t HSIStatus = 0;

	RCC_DeInit();// 为了重新配置RCC寄存器，需要把RCC复位为刚上电时的状态
	
	RCC_HSICmd(ENABLE);// HSI使能，开启外部晶振
	
	 HSIStatus = RCC->CR & RCC_CR_HSERDY;// 等待HSI就绪
	
	if (HSIStatus == RCC_CR_HSERDY) // 如果HSE启动成功
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);// 使能FLASH，预存取缓冲区
		FLASH_SetLatency(FLASH_Latency_2);// 设置FLASH等待周期
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1); // AHB预分频因子，72M
		RCC_PCLK1Config(RCC_HCLK_Div2);  // APB1预分频因子，36M
		RCC_PCLK2Config(RCC_HCLK_Div1);  // APB2预分频因子，72M
		
		RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);// 设置PLL的来源以及倍频因子
    RCC_PLLCmd(ENABLE); // PLL 使能
		
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); // 等待PLL稳定
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // 选择系统时钟
		while(RCC_GetSYSCLKSource() != 0x08); // 读取时钟切换状态位，确保PLLCLK被选为系统时钟
	}
	else
	{
		// 如果HSI启动失败，用户可以在这里添加启动失败的代码
	}
}













