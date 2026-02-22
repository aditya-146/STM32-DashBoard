#ifndef INC_CMN_H_
#define INC_CMN_H_
#include "main.h"


extern TIM_HandleTypeDef htim6;

void Cmn_DelayUs(uint16_t time_us);

int _write(int file, char *ptr, int len);

/* =========================
   GPIO Direction Control
========================= */

void Cmn_SetPinOutput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Cmn_SetPinInput(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
#endif /* INC_CMN_H_ */
