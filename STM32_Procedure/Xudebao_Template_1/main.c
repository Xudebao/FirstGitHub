#include "stm32f10x.h"

int main(void)
{
	#if 0    // 6行到14行不编译
	*(unsigned int *)0x40021018 |= (1<<3) ;// 打开GPIO端口的时钟(配置RCC_APB2ENR寄存器)
	
	*(unsigned int *)0x40010c00 &=~((0X0f)<<0) ;// 先将最低4位清零
	
	*(unsigned int *)0x40010c00 |= (1<<0) ;// 再设置IO为推挽输出模式，最大速度10M(配置CRL寄存器)
	
	*(unsigned int *)0x40010c0c &= ~(1<<0) ;// 设置数据(配置ODR寄存器)
/*0x40010c0c前面的unsigned int*是将其转换为指针类型，再加上一个*是将其所对应的地址取出*/	
	while(1);
	
	#elif 0  // #elif 0后的语句不编译(即18行到25行不编译) 
	
	RCC_APB2ENR |= (1<<3) ;// 打开GPIO端口的时钟(配置RCC_APB2ENR寄存器)
	
	GPIOB_CRL &=~((0x0f)<<0) ;// 先将最低4位清零
	
	GPIOB_CRL |= (1<<0) ;// 再设置IO为推挽输出模式，最大速度10M(配置CRL寄存器)
	
	GPIOB_ODR &=~(1<<0) ;// 设置数据(配置ODR寄存器)
	while(1);
	
	#elif 1  // 只有#elif 1后的语句才被编译
	RCC->APB2ENR |= (1<<3) ;// 打开GPIO端口的时钟(配置RCC_APB2ENR寄存器)
	
	GPIOB->CRL &=~((0x0f)<<0) ;// 先将最低4位清零
	
	GPIOB->CRL |= (1<<0) ;// 再设置IO为推挽输出模式，最大速度10M(配置CRL寄存器)
	
	GPIOB->ODR &=~(1<<0) ;// 设置数据(配置ODR寄存器)
	while(1);
	
	#endif
}

void SystemInit(void)
{
	// 函数体为空，目的是骗过编译器不报错
}

