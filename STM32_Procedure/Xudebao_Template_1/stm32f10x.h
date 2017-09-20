// �������STM32�Ĵ���ӳ��Ĵ���

// ����perirhral
// ��������(APB1��APB2��AHB)�Ļ���ַ
#define PERIPH_BASE ((unsigned int)0x40000000)
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE (PERIPH_BASE + 0x20000)

// ��Ӧ����Ļ���ַ
#define RCC_BASE (AHBPERIPH_BASE + 0x1000)
#define GPIOB_BASE (APB2PERIPH_BASE + 0x0c00)

// �����ڲ��Ĵ�������ַ
//#define RCC_APB2ENR *(unsigned int*)(RCC_BASE + 0x18)

// �����ڲ��Ĵ�������ַ
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
}GPIO_TypeDef;   // ����ṹ������ΪGPIO_TypeDef

//������ַGPIOB_BASEǿ������ת��Ϊ�ṹ�����͵�ָ�룬�ٽ��к궨�彫������ΪGPIOB
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
}RCC_TypeDef; // ͬ��

#define RCC  ((RCC_TypeDef*)RCC_BASE) // ����ͬ��

/*
   �ṹ�巽ʽ��ԭ��
1���ȶ���һ���ṹ�壬��������ĳ�Ա����ֲ���˳��������еļĴ������е�˳����ͬ
2���ҵ�һ������Ļ���ַ��GPIOB_BASE��Ȼ��������ַǿ������ת��ΪGPIO_TypeDef�ṹ�����͵�ָ�룬
   ֮�����ָ���ָ��һ���ڴ浥Ԫ������ڴ浥Ԫ�еļĴ����ͽṹ���еĳ�Աһһ��Ӧ
3����󣬾Ϳ���ͨ��C���Խṹ��ķ�ʽ�������еļĴ������в���
*/
					
