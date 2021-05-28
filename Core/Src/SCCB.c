//
// Created by 彭世辰 on 2021/5/28.
//

#include "SCCB.h"
#include "delay.h"


void SCCB_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin = SCCB_SCL_Pin|SCCB_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_WritePin(SCCB_SCL_GPIO_Port, SCCB_SCL_Pin, GPIO_PIN_SET);

    SCCB_SDA_OUT();
}

void SCCB_Start(void)
{
    SCCB_SDA_SET();
    SCCB_SCL_SET();
    delay_us(200);
    SCCB_SDA_RESET();
    delay_us(200);
    SCCB_SCL_RESET();
}


void SCCB_Stop(void)
{
    SCCB_SDA_RESET();
    delay_us(200);
    SCCB_SCL_SET();
    delay_us(200);
    SCCB_SDA_SET();
    delay_us(200);
}

void SCCB_No_Ack(void)
{
    delay_us(200);
    SCCB_SDA_SET();
    SCCB_SCL_SET();
    delay_us(200);
    SCCB_SCL_RESET();
    delay_us(200);
    SCCB_SDA_RESET();
    delay_us(200);
}

uint8_t SCCB_WR_Byte(uint8_t dat)
{
    uint8_t j,res;
    for(j=0;j<8;j++)
    {
        if(dat&0x80)SCCB_SDA_SET();
        else SCCB_SDA_RESET();
        dat<<=1;
        delay_us(200);
        SCCB_SCL_SET();
        delay_us(200);
        SCCB_SCL_RESET();
    }
    SCCB_SDA_IN();
    delay_us(200);
    SCCB_SCL_SET();
    delay_us(200);
    if(SCCB_SDA_READ())res=1;
    else res=0;
    SCCB_SCL_RESET();
    SCCB_SDA_OUT();
    return res;
}

uint8_t SCCB_RD_Byte(void)
{
    uint8_t temp=0,j;
    SCCB_SDA_IN();
    for(j=8;j>0;j--)
    {
        delay_us(200);
        SCCB_SCL_SET();
        temp=temp<<1;
        if(SCCB_SDA_READ())temp++;
        delay_us(200);
        SCCB_SCL_RESET();
    }
    SCCB_SDA_OUT();
    return temp;
}

uint8_t SCCB_WR_Reg(uint8_t reg,uint8_t data)
{
    uint8_t res=0;
    SCCB_Start();
    if(SCCB_WR_Byte(SCCB_ID))res=1;
    delay_us(400);
    if(SCCB_WR_Byte(reg))res=1;
    delay_us(400);
    if(SCCB_WR_Byte(data))res=1;
    SCCB_Stop();
    return	res;
}

uint8_t SCCB_RD_Reg(uint8_t reg)
{
    uint8_t val=0;
    SCCB_Start();
    SCCB_WR_Byte(SCCB_ID);
    delay_us(400);
    SCCB_WR_Byte(reg);
    delay_us(400);
    SCCB_Stop();
    delay_us(400);

    SCCB_Start();
    SCCB_WR_Byte(SCCB_ID|0X01);
    delay_us(400);
    val=SCCB_RD_Byte();
    SCCB_No_Ack();
    SCCB_Stop();
    return val;
}

uint8_t SCCB_RD_Reg_ecc(uint8_t reg)
{
    uint8_t val = 0xff;
    do {
        val = SCCB_RD_Reg(reg);
    } while (val == 0xff);
    return val;
}

uint8_t SCCB_WR_Reg_ecc(uint8_t reg,uint8_t data)
{
    while(!SCCB_WR_Reg(reg, data));
}
