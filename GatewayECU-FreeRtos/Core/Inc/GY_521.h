#ifndef INC_GY_521_H_
#define INC_GY_521_H_

#include "main.h"
#include <math.h>

#define PI 3.14159265358979323846f

#define Dev_Address 0x68
#define Gyro_Range_Mem_Address 27
#define Acc_Range_Mem_Address  28
#define Sleep_Temp_Mem_Address 107
#define Gyro_ZData_Mem_Address  63


#define Gyro_Range 0b00001000
#define Acc_Range  0b00000000
#define Sleep_Config 0

HAL_StatusTypeDef GY521_Connection(I2C_HandleTypeDef *hi2c1);
void GY521_Config(I2C_HandleTypeDef *hi2c1);
float GY521_Calculate_Offset(I2C_HandleTypeDef *hi2c1);
float GY521_Calculate_Tilt(float Tilt_Offset, I2C_HandleTypeDef *hi2c1);

#endif /* INC_GY_521_H_ */
