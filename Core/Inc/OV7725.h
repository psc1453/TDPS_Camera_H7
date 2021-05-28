//
// Created by 彭世辰 on 2021/5/28.
//

#ifndef CAMERA_H7_OV7725_H
#define CAMERA_H7_OV7725_H

#include "sys.h"
#include "SCCB.h"

#define OV7725_MID				0X7FA2
#define OV7725_PID				0X7721


u8   OV7725_Init(void);
void OV7725_Light_Mode(u8 mode);
void OV7725_Color_Saturation(s8 sat);
void OV7725_Brightness(s8 bright);
void OV7725_Contrast(s8 contrast);
void OV7725_Special_Effects(u8 eft);
void OV7725_Window_Set(u16 width,u16 height,u8 mode);

#endif //CAMERA_H7_OV7725_H
