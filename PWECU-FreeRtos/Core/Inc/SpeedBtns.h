/*
 * SpeedBtns.h
 *
 *  Created on: Feb 22, 2026
 *      Author: adity
 */

#ifndef INC_SPEEDBTNS_H_
#define INC_SPEEDBTNS_H_

#include "main.h"

/* =========================
   Speed Configuration
========================= */

#define MAX_SPEED        200
#define ACCEL_STEP       5
#define BRAKE_STEP       10
#define NATURAL_DECAY    1
#define BRAKE_THRESHOLD  10

void SpeedCalculate(uint8_t *Speed);


#endif /* INC_SPEEDBTNS_H_ */
