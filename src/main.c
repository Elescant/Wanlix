#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "device.h"
#include "stdio.h"


//int main(void)
//{

//	GPIO_InitTypeDef gpio;
//	
//	DEV_UartInit();
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

//	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
//	gpio.GPIO_Pin = GPIO_Pin_13;
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;

//	GPIO_Init(GPIOC,&gpio);
//	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
//	//GPIO_SetBits(GPIOC,GPIO_Pin_13);

//	while(1)
//	{
//		printf("hello\n");
//		DEV_DelayMs(1000);
//	}
//}


void DEV_DelayMs(U32 uiMs)
{
    U32 i;
    U32 j;

    j = 5540 * uiMs;

    for(i = 0; ; i++)
    {
        if(i == j)
        {
            break;
        }
    }
}
