

/******************** (C) COPYRIGHT  �ൺ���������з���************************
 *�ļ���   ��systick.c
 *����     ��ϵͳʱ������ 
 *Ӳ��ƽ̨ ����ǹ��CTSQ01-M-V100 CTSQ01-M-V2.1��STM8S105K4��
 *����汾 ��V2.1.0
 *����     ��WangJiandong
 *�޸�ʱ�� ��2014-9-30
 *ʵ�ֹ��� ��ϵͳʱ�ӳ�ʼ�����жϺ�������ȡ��ǰ������ֵ����Ӳ��׼ȷ��ʱ
******************************************************************************/

#include "bsp_config.h"

static u32 SysClk1Ms;  //ϵͳ����ֵ�����ڼ�ʱ��


/*
*******************************************************************************
* ��������:  CLK_Config()
* ��������:  оƬʱ��Դ����
* ��ڲ���:  ʱ��Դ����Ƶ
* ���ڲ�������
* �ر�ע�⣺ʱ��Դ��4�֣�CLK_SYSCLKSource_HSI��CLK_SYSCLKSource_LSI 
  CLK_SYSCLKSource_HSE�� CLK_SYSCLKSource_LSE
*******************************************************************************
*/
void CLK_Config(CLK_SYSCLKSource_TypeDef CLK_SYSCLKSource ,CLK_SYSCLKDiv_TypeDef CLK_SYSCLKDiv)
{
  /* Select HSE as system clock source */
  CLK_SYSCLKSourceSwitchCmd(ENABLE);
  CLK_SYSCLKSourceConfig(CLK_SYSCLKSource);
  /* system clock prescaler */
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv);
  while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource);

}


/*
*******************************************************************************
* ��������:  SysTickInit()
* ��������:  Timer����
* ��ڲ���: ��
* ���ڲ�������
* �ر�ע�⣺����1ms�жϣ�Ҫ�뾧��Ƶ�����
12M HSE  
*******************************************************************************
*/
void SysTickInit(void)
{
    CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);
    TIM4_DeInit();
    //��ʱ1ms    16M ---TIM4_TimeBaseInit(TIM4_Prescaler_64, 250)
    //��ʱ1ms    2M  ---TIM4_TimeBaseInit(TIM4_Prescaler_8, 250)
    TIM4_TimeBaseInit(TIM4_Prescaler_8, 250);
    TIM4_ARRPreloadConfig(ENABLE);
    TIM4_ITConfig(TIM4_IT_Update, ENABLE);
 //   TIM4_ClearFlag(TIM4_FLAG_Update);
    TIM4_Cmd(ENABLE);
}


/*
*******************************************************************************
* ��������:  SysTickIncrease()
* ��������:  SysClk1Ms��1
* ��ڲ���: ��
* ���ڲ�������
* �ر�ע�⣺��TIM4�ж������ã�ÿ�����1
*******************************************************************************
*/
void SysTickIncrease(void)
{
  SysClk1Ms++;
}


/*
*******************************************************************************
* ��������:  GetSysTick()
* ��������:  ����SysClk1Ms��ֵ
* ��ڲ���: ��
* ���ڲ�����SysClk1Ms
* �ر�ע�⣺��ȡ��ǰSysClk1Ms��ֵ
*******************************************************************************
*/
u32 GetSysTick(void)
{
  return SysClk1Ms;
}


/*
*******************************************************************************
* ��������:  TimerDelay_1ms()
* ��������:  ��ȷ��ʱ��1ms��
* ��ڲ���: ��ʱֵ
* ���ڲ�������
* �ر�ע�⣺�൱��delay�����жϷ�ʽ��ȷ��ʱ
*******************************************************************************
*/
void TimerDelay_1ms( uint32_t nTime)
{
  uint32_t counter;
  
  counter=SysClk1Ms;
  
  while (nTime>(SysClk1Ms-counter));
  
}


/*
*******************************************************************************
* ��������:  DelayMs()
* ��������:  �Ǿ�ȷ��ʱ1ms
* ��ڲ���: ��ʱֵ
* ���ڲ�������
* �ر�ע�⣺�Ǿ�ȷ��ʱ1ms
*******************************************************************************
*/
void DelayMs(u16 nCount)
{
	unsigned int i;
	while(nCount--)
	{
		for(i=0;i<33;i++) //143
		{
                    
		}
	}
}

/*
*******************************************************************************
* ��������:  Delay()
* ��������:  �Ǿ�ȷ��ʱ
* ��ڲ���: ��ʱֵ
* ���ڲ�������
* �ر�ע�⣺�Ǿ�ȷ��ʱ
*******************************************************************************
*/
  void Delay(u32 nCount)
{
  while (nCount != 0)
  {
    nCount--;
  }
}