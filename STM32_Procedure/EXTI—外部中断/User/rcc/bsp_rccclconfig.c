#include "bsp_rccclconfig.h"

/*��������������ͨ��������ã�����Լ���Ҫ��ϵͳʱ�ӵĴ�С�����ҿ����趨��ϵͳʱ������HSI����HSE�ṩ*/

void HSE_SetSysClock(uint32_t RCC_PLLMul_x) // ʹ�� HSE ������ϵͳʱ��
{
	ErrorStatus HSEStatus;  // �������HSE��״̬
	RCC_DeInit();// Ϊ����������RCC�Ĵ�������Ҫ��RCC��λΪ���ϵ�ʱ��״̬
	RCC_HSEConfig(RCC_HSE_ON);// HSEʹ�ܣ������ⲿ����
	
	HSEStatus = RCC_WaitForHSEStartUp();// RCC_WaitForHSEStartUp()���ڵȴ�����HSE�������ú����ķ���ֵΪSUCCESS��ERROR
	
	if (HSEStatus == SUCCESS) // ���HSE�����ɹ�
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);// ʹ��FLASH��Ԥ��ȡ������
		FLASH_SetLatency(FLASH_Latency_2);// ����FLASH�ȴ�����
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1); // AHBԤ��Ƶ���ӣ�72M
		RCC_PCLK1Config(RCC_HCLK_Div2);  // APB1Ԥ��Ƶ���ӣ�36M
		RCC_PCLK2Config(RCC_HCLK_Div1);  // APB2Ԥ��Ƶ���ӣ�72M
		
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);// ����PLL����Դ�Լ���Ƶ����
    RCC_PLLCmd(ENABLE); // PLL ʹ��
		
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); // �ȴ�PLL�ȶ�
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // ѡ��ϵͳʱ��
		while(RCC_GetSYSCLKSource() != 0x08); // ��ȡʱ���л�״̬λ��ȷ��PLLCLK��ѡΪϵͳʱ��
	}
	else
	{
		// ���HSI����ʧ�ܣ��û������������������ʧ�ܵĴ���
	}
}

void HSI_SetSysClock(uint32_t RCC_PLLMul_x) // ʹ�� HSI ������ϵͳʱ��
{
	__IO uint32_t HSIStatus = 0;

	RCC_DeInit();// Ϊ����������RCC�Ĵ�������Ҫ��RCC��λΪ���ϵ�ʱ��״̬
	
	RCC_HSICmd(ENABLE);// HSIʹ�ܣ������ⲿ����
	
	 HSIStatus = RCC->CR & RCC_CR_HSERDY;// �ȴ�HSI����
	
	if (HSIStatus == RCC_CR_HSERDY) // ���HSE�����ɹ�
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);// ʹ��FLASH��Ԥ��ȡ������
		FLASH_SetLatency(FLASH_Latency_2);// ����FLASH�ȴ�����
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1); // AHBԤ��Ƶ���ӣ�72M
		RCC_PCLK1Config(RCC_HCLK_Div2);  // APB1Ԥ��Ƶ���ӣ�36M
		RCC_PCLK2Config(RCC_HCLK_Div1);  // APB2Ԥ��Ƶ���ӣ�72M
		
		RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);// ����PLL����Դ�Լ���Ƶ����
    RCC_PLLCmd(ENABLE); // PLL ʹ��
		
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); // �ȴ�PLL�ȶ�
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); // ѡ��ϵͳʱ��
		while(RCC_GetSYSCLKSource() != 0x08); // ��ȡʱ���л�״̬λ��ȷ��PLLCLK��ѡΪϵͳʱ��
	}
	else
	{
		// ���HSI����ʧ�ܣ��û������������������ʧ�ܵĴ���
	}
}













