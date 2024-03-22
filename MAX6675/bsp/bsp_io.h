

/******************** C) COPYRIGHT  �ൺ���������з��� *************************
 * �ļ���  ��led.c
 * ����    ��IO�����ú�����   
 * ʵ��ƽ̨����ǹ��stms103k3
 * ��汾  ��V2.0.0
 * ����    ��Wangjiandong
 *�޸�ʱ�� ��2013-11-21

  STM8S103Ӳ������
    |--------------------|
    |  LED_L-PB7         |
    |  LED_R-PD2         |
    |  LED_G-PD3         |
    |  FMQ-PD4           |
    |--------------------|

******************************************************************************/

#ifndef __BSP_IO_H
#define __BSP_IO_H
#include "bsp_config.h"


#define ON  0
#define OFF 1

#define GREEN_LED(ON_OFF)  if(ON_OFF==OFF)GPIO_SetBits(GPIOE, GPIO_Pin_6);\
                      else GPIO_ResetBits(GPIOE, GPIO_Pin_6)
                          
#define GREEN_LED_REVERSE()  GPIO_ToggleBits(GPIOE, GPIO_Pin_6)                           
                          
#define RED_LED(ON_OFF)  if(ON_OFF==OFF)GPIO_SetBits(GPIOE, GPIO_Pin_7);\
                      else GPIO_ResetBits(GPIOE, GPIO_Pin_7)
                          
#define RED_LED_REVERSE()  GPIO_ToggleBits(GPIOE, GPIO_Pin_7)                        
                        

#define BUZZER(ON_OFF)  if(ON_OFF==ON)GPIO_SetBits(GPIOB, GPIO_Pin_2);\
                      else GPIO_ResetBits(GPIOB, GPIO_Pin_2)
                          
#define VDD_SI7005(ON_OFF)  if(ON_OFF==ON)GPIO_SetBits(GPIOD, GPIO_Pin_7);\
                      else GPIO_ResetBits(GPIOD, GPIO_Pin_7)                          
                          

#define S1_SWITCH    ((BitStatus)(GPIOC->IDR & (uint8_t)GPIO_Pin_4))              
                        
#define S2_SWITCH    ((BitStatus)(GPIOC->IDR & (uint8_t)GPIO_Pin_7))
                          
#define S3_SWITCH    ((BitStatus)(GPIOD->IDR & (uint8_t)GPIO_Pin_4))

                          
void EXTI_InputPin_Init(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);                          
void BSP_IO_Init(void);   


#endif


/************************END OF FILE********************************/