#ifndef _BSP_KEY_H   // ��ֹ���ͷ�ļ�������ʱ�������ظ�����
#define _BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_PIN    GPIO_Pin_0  // ����
#define KEY1_GPIO_PORT   GPIOA       // �˿�
#define KEY1_GPIO_CLK    RCC_APB2Periph_GPIOA  // ʱ��

#define KEY_ON   1  // �ߵ�ƽ��ʾ��������
#define KEY_OFF  0

void KEY_GPIO_Config(void);  // ������ͷ�ļ��н���������Ϊ���������ĺ������е���
uint8_t Key_Scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin);   // ������ͷ�ļ��н���������Ϊ���������ĺ������е���




#endif  