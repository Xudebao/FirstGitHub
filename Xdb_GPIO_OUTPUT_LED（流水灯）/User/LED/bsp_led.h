#ifndef _BSP_LED_H   // ��ֹ���ͷ�ļ�������ʱ�������ظ�����
#define _BSP_LED_H

#include "stm32f10x.h"

/*�̵����ź궨��*/
#define LED_G_GPIO_PIN    GPIO_Pin_0  // ����
#define LED_G_GPIO_PORT   GPIOB       // �˿�
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB  // ʱ��

/*�������ź궨��*/
#define LED_B_GPIO_PIN    GPIO_Pin_1  // ����
#define LED_B_GPIO_PORT   GPIOB       // �˿�
#define LED_B_GPIO_CLK    RCC_APB2Periph_GPIOB  // ʱ��

/*������ź궨��*/
#define LED_R_GPIO_PIN    GPIO_Pin_5  // ����
#define LED_R_GPIO_PORT   GPIOB       // �˿�
#define LED_R_GPIO_CLK    RCC_APB2Periph_GPIOB  // ʱ��

#define ON 1
#define OFF 0

// ʹ�ô������ĺ궨��LED_G(a) ���������Ϊ1����ִ��GPIO_ResetBits�������������Ϊ0��ִ��GPIO_ResetBits
// \��б����C�����б�ʾ���з������治�����κζ���,�ո񶼲�����
#define LED_G(a)   if(a) \
                          GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN); \
                    else  GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

#define LED_R(a)   if(a) \
                          GPIO_ResetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN); \
                    else  GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);

#define LED_B(a)   if(a) \
                          GPIO_ResetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN); \
                    else  GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);

#define LED_RED       LED_G(OFF);LED_R(ON);LED_B(OFF)  // ��

// �������ĺ궨��,���ΪON���൱��ִ��GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN)��ΪOFF�൱��ִ��GPIO_SetBits;

#define LED_GREEN     LED_G(ON);LED_R(OFF);LED_B(OFF)  // ��

#define LED_BLUE      LED_G(OFF);LED_R(OFF);LED_B(ON)  // ��

#define LED_WHITE     LED_G(ON);LED_R(ON);LED_B(ON)    // ��

#define LED_YELLOW    LED_G(ON);LED_R(ON);LED_B(OFF)   // ��

#define LED_BLACK     LED_G(OFF);LED_R(OFF);LED_B(OFF) // �ڣ���

#define LED_PURPLE    LED_G(OFF);LED_R(ON);LED_B(ON)   // ��

#define LED_CYAN      LED_G(ON);LED_R(OFF);LED_B(ON)   // ��

void LED_GPIO_Config(void);  // LED�Ƶĳ�ʼ����������

#endif /*_BSP_LED_H*/

