/*
 * HC_SR04.h
 *
 *  Created on: Feb 15, 2026
 *      Author: adity
 */

#ifndef INC_HC_SR04_H_
#define INC_HC_SR04_H_

#define TRIG_PIN GPIO_PIN_9
#define TRIG_PORT GPIOA

void HCSR04_Read (TIM_HandleTypeDef *htim);

#endif /* INC_HC_SR04_H_ */
