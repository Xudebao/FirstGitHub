#ifndef _BSP_LED_H   // ��ֹ���ͷ�ļ�������ʱ�������ظ�����
#define _BSP_LED_H

#include "stm32f10x.h"

#define LED_G_GPIO_PIN    GPIO_Pin_1  // ����
#define LED_G_GPIO_PORT   GPIOB       // �˿�
#define LED_G_GPIO_CLK    RCC_APB2Periph_GPIOB  // ʱ��

#define ON 1
#define OFF 0

// ʹ�ô������ĺ궨��LED_G(a) ���������Ϊ1����ִ��GPIO_ResetBits�������������Ϊ0��ִ��GPIO_ResetBits
// \��б����C�����б�ʾ���з������治�����κζ���,�ո񶼲�����
#define LED_G(a)   if(a) \
                          GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN); \
                    else  GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);

//  ^ ������򡱣�C���Ե�һ�������Ƶ����������1���ı䣬��0��򲻱�
#define LED_G_TOGGLE      {LED_G_GPIO_PORT-> ODR ^= LED_G_GPIO_PIN;}

void LED_GPIO_Config(void);

#endif /*_BSP_LED_H*/

