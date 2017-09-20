#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

//#define LED_G_GPIO_PORT          GPIOB
//#define LED_G_GPIO_CLK_ENABLE    RCC->APB2ENR |= (1<<3)
//#define LED_G_GPIO_PIN                                     GPIO_Pin_0  ,Pin_0Ϊ�̵���

#define LED_G_GPIO_PORT          GPIOB
#define LED_G_GPIO_CLK_ENABLE    RCC->APB2ENR |= (1<<3)
#define LED_G_GPIO_PIN           GPIO_Pin_5                  // Pin_5Ϊ�����

void Delay(uint32_t count)
{
	for( ;count != 0;count--);
}
int main(void)
{
	#if 0    // 6�е�14�в�����
	*(unsigned int *)0x40021018 |= (1<<3) ;// ��GPIO�˿ڵ�ʱ��(����RCC_APB2ENR�Ĵ���)
	
	*(unsigned int *)0x40010c00 &=~((0X0f)<<0) ;// �Ƚ����4λ����
	
	*(unsigned int *)0x40010c00 |= (1<<0) ;// ������IOΪ�������ģʽ������ٶ�10M(����CRL�Ĵ���)
	
	*(unsigned int *)0x40010c0c &= ~(1<<0) ;// ��������(����ODR�Ĵ���)
/*0x40010c0cǰ���unsigned int*�ǽ���ת��Ϊָ�����ͣ��ټ���һ��*�ǽ�������Ӧ�ĵ�ַȡ��*/	
	while(1);
	
	#elif 0  // #elif 0�����䲻����(��18�е�25�в�����) 
	
	RCC_APB2ENR |= (1<<3) ;// ��GPIO�˿ڵ�ʱ��(����RCC_APB2ENR�Ĵ���)
	
	GPIOB_CRL &=~((0x0f)<<0) ;// �Ƚ����4λ����
	
	GPIOB_CRL |= (1<<0) ;// ������IOΪ�������ģʽ������ٶ�10M(����CRL�Ĵ���)
	
	GPIOB_ODR &=~(1<<0) ;// ��������(����ODR�Ĵ���)
	while(1);
	
	#elif 0  // ֻ��#elif 0������ű�����
	RCC->APB2ENR |= (1<<3) ;// ��GPIO�˿ڵ�ʱ��(����RCC_APB2ENR�Ĵ���)
	
	GPIOB->CRL &=~((0x0f)<<0) ;// �Ƚ����4λ����
	
	GPIOB->CRL |= (1<<0) ;// ������IOΪ�������ģʽ������ٶ�10M(����CRL�Ĵ���)
	
	GPIOB->ODR &=~(1<<0) ;// ��������(����ODR�Ĵ���)
	while(1);
	
	#elif 1  // ֻ��#elif 1������ű�����
	
	GPIO_InitTypeDef  GPIO_InitStructure;  // ����һ��GPIO_InitTypeDef���͵ı���
	
	LED_G_GPIO_CLK_ENABLE ;// ��GPIO�˿ڵ�ʱ��(����RCC_APB2ENR�Ĵ���)
	
//	GPIOB->CRL &=~((0x0f)<<0) ;// �Ƚ����4λ����
//	
//	GPIOB->CRL |= (1<<0) ;// ������IOΪ�������ģʽ������ٶ�10M(����CRL�Ĵ���)

	GPIO_InitStructure.GPIO_Pin = LED_G_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_G_GPIO_PORT,&GPIO_InitStructure);
	
	while(1)
	{
		GPIO_SetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);// ����GPIO��λ��������PB0��1����Ϩ��
		Delay(0xFFFF);
		GPIO_ResetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);// ����GPIO��λ��������PB0��λ���Ƶ���
		Delay(0xFFFF);
	}
	#endif
}

void SystemInit(void)
{
	// ������Ϊ�գ�Ŀ����ƭ��������������
}

