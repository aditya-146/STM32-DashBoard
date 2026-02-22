#include "DHT11.h"
#include "Cmn.h"

/* =========================
   Public Functions
========================= */

void DHT11_Start(void)
{
    /* Set pin as output */
    Cmn_SetPinOutput(DHT11_PORT, DHT11_PIN);

    /* Send start signal */
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
    Cmn_DelayUs(DHT11_DELAY_18MS);

    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
    Cmn_DelayUs(DHT11_DELAY_20US);

    /* Switch to input for response */
    Cmn_SetPinInput(DHT11_PORT, DHT11_PIN);
}

uint8_t DHT11_CheckResponse(void)
{
    uint8_t Response = 0;

    Cmn_DelayUs(DHT11_RESPONSE_WAIT1);

    if(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
    {
        Cmn_DelayUs(DHT11_RESPONSE_WAIT2);

        if(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
            Response = 1;
        else
            Response = 0;
    }

    /* Wait until sensor releases line */
    while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));

    return Response;
}

uint8_t DHT11_Read(void)
{
    uint8_t j;
    uint8_t data = 0;

    for(j = 0; j < 8; j++)
    {
        /* Wait for pin to go high */
        while(!HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));

        /* Measure bit width */
        Cmn_DelayUs(40);

        if(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))
            data |= (1 << (7 - j));

        /* Wait for low again */
        while(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN));
    }

    return data;
}

/* =========================
   High Level Read Function
========================= */

void DHT11_ReadData(DHT11_Data_t *data)
{
    uint8_t Rh_byte1, Rh_byte2;
    uint8_t Temp_byte1, Temp_byte2;
    uint8_t SUM;

    uint16_t RH, TEMP;

    /* Start communication */
    DHT11_Start();

    if(!DHT11_CheckResponse())
        return; // Optional: error handling

    Rh_byte1 = DHT11_Read();
    Rh_byte2 = DHT11_Read();
    Temp_byte1 = DHT11_Read();
    Temp_byte2 = DHT11_Read();
    SUM = DHT11_Read();

    /* Simple conversion */
    RH = Rh_byte1;
    TEMP = Temp_byte1;

    data->humidity = (float)RH;
    data->temperature = (float)TEMP;
}
