#include <stdio.h>
#include "device.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"


void DEV_SoftwareInit(void)
{
    /* 初始化任务切换信息结构 */
    //DEV_TaskSwitchMsgStrInit();
}

void DEV_HardwareInit(void)
{
	  DEV_UartInit();
}

void DEV_PutChar(U8 ucChar)
{
    /* Loop until USART1 DR register is empty */
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
    {
        ;
    }

    USART_SendData(USART1, ucChar);
}

void DEV_UartInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    /* Enable USART1 Clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1
                           | RCC_APB2Periph_AFIO, ENABLE);

    /* Configure USART1 Rx as input floating */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Configure USART1 Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_StructInit(&USART_InitStructure);

    /* Configure USART1 */
    USART_Init(USART1, &USART_InitStructure);

    /* Enable the USART1 */
    USART_Cmd(USART1, ENABLE);
}

struct __FILE { int handle; /* Add whatever you need here */ };
int fputc(int ch, FILE *f) {
  DEV_PutChar(ch);
  return 0;
}