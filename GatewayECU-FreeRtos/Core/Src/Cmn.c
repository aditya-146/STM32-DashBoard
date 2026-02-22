#include "main.h"
#include "Cmn.h"

void delay(uint16_t time, TIM_HandleTypeDef *htim){
	__HAL_TIM_SET_COUNTER(htim, 0);
	while((__HAL_TIM_GET_COUNTER(htim)) < time);
}

int _write(int file, char *ptr, int len)
{
    for(int DataIdx = 0; DataIdx < len; DataIdx++)
    {
        ITM_SendChar(*ptr++);
    }
    return len;
}

