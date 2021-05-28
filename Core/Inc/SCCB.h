//
// Created by 彭世辰 on 2021/5/28.
//

#ifndef CAMERA_H7_SCCB_H
#define CAMERA_H7_SCCB_H

#include "stm32h7xx_hal.h"
#include "main.h"

#define SCCB_SCL_Pin SCL_Pin
#define SCCB_SCL_GPIO_Port SCL_GPIO_Port
#define SCCB_SDA_Pin SDA_Pin
#define SCCB_SDA_GPIO_Port SDA_GPIO_Port

#define SCCB_SDA_IN() do{ \
    GPIO_InitTypeDef  GPIO_InitStruct; \
    GPIO_InitStruct.Pin = SCCB_SDA_Pin; \
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT; \
    GPIO_InitStruct.Pull = GPIO_PULLUP; \
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH; \
    HAL_GPIO_Init(SCCB_SDA_GPIO_Port, &GPIO_InitStruct); \
} while(0)



#define SCCB_SDA_OUT() do{ \
    GPIO_InitTypeDef  GPIO_InitStruct; \
    GPIO_InitStruct.Pin = SCCB_SDA_Pin; \
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; \
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH; \
    HAL_GPIO_Init(SCCB_SDA_GPIO_Port, &GPIO_InitStruct); \
} while(0)

#define SCCB_SCL_SET()      HAL_GPIO_WritePin(SCCB_SCL_GPIO_Port, SCCB_SCL_Pin, GPIO_PIN_SET)
#define SCCB_SCL_RESET()    HAL_GPIO_WritePin(SCCB_SCL_GPIO_Port, SCCB_SCL_Pin, GPIO_PIN_RESET)

#define SCCB_SDA_SET()      HAL_GPIO_WritePin(SCCB_SDA_GPIO_Port, SCCB_SDA_Pin, GPIO_PIN_SET)
#define SCCB_SDA_RESET()    HAL_GPIO_WritePin(SCCB_SDA_GPIO_Port, SCCB_SDA_Pin, GPIO_PIN_RESET)

#define SCCB_SDA_READ()     HAL_GPIO_ReadPin(SCCB_SDA_GPIO_Port, SCCB_SDA_Pin)

#define SCCB_ID             0X42

void SCCB_Init(void);
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
uint8_t SCCB_WR_Byte(uint8_t dat);
uint8_t SCCB_RD_Byte(void);
uint8_t SCCB_WR_Reg(uint8_t reg,uint8_t data);
uint8_t SCCB_RD_Reg(uint8_t reg);

uint8_t SCCB_WR_Reg_ecc(uint8_t reg,uint8_t data);
uint8_t SCCB_RD_Reg_ecc(uint8_t reg);


#endif //CAMERA_H7_SCCB_H
