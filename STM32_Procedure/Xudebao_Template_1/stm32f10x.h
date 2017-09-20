// 用来存放STM32寄存器映射的代码

// 外设perirhral
// 三条总线(APB1、APB2、AHB)的基地址
#define PERIPH_BASE ((unsigned int)0x40000000)
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE (PERIPH_BASE + 0x20000)

// 对应外设的基地址
#define RCC_BASE (AHBPERIPH_BASE + 0x1000)
#define GPIOB_BASE (APB2PERIPH_BASE + 0x0c00)

// 外设内部寄存器基地址
//#define RCC_APB2ENR *(unsigned int*)(RCC_BASE + 0x18)

// 外设内部寄存器基地址
//#define GPIOB_CRL   *(unsigned int*)(GPIO_BASE + 0x00)
//#define GPIOB_CRH   *(unsigned int*)(GPIO_BASE + 0x04)
//#define GPIOB_IDR   *(unsigned int*)(GPIO_BASE + 0x08)
//#define GPIOB_ODR   *(unsigned int*)(GPIO_BASE + 0x0c)
//#define GPIOB_BSRR   *(unsigned int*)(GPIO_BASE + 0x10)
//#define GPIOB_BRR   *(unsigned int*)(GPIO_BASE + 0x14)
//#define GPIOB_LCKR   *(unsigned int*)(GPIO_BASE + 0x18)
	
typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;

typedef struct 
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;	
}GPIO_TypeDef;   // 定义结构体类型为GPIO_TypeDef

//将基地址GPIOB_BASE强制类型转换为结构体类型的指针，再进行宏定义将其命名为GPIOB
#define GPIOB  ((GPIO_TypeDef*)GPIOB_BASE) 

typedef struct 
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;	
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t AHBRSTR;
	uint32_t CFGR2;
}RCC_TypeDef; // 同上

#define RCC  ((RCC_TypeDef*)RCC_BASE) // 作用同上

/*
   结构体方式的原理：
1、先定义一个结构体，并且里面的成员及其分布的顺序和外设中的寄存器排列的顺序相同
2、找到一个外设的基地址如GPIOB_BASE，然后把这个地址强制类型转换为GPIO_TypeDef结构体类型的指针，
   之后这个指针就指向一个内存单元，这个内存单元中的寄存器和结构体中的成员一一对应
3、最后，就可以通过C语言结构体的方式对外设中的寄存器进行操作
*/
					
