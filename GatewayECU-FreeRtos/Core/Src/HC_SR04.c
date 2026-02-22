#include "Cmn.h"
#include "HC_SR04.h"
#include "main.h"


void HCSR04_Read (TIM_HandleTypeDef *htim)
{
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10, htim);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(htim, TIM_IT_CC1);
}
