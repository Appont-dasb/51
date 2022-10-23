#include <REGX52.H>
#include "Delay10us.h"
#include "LCD1602.h"
//#include "Delay.h"
#include "Timer0.h"

unsigned int Sec ,Min = 5 ,Hour ;

sbit DEEP = P2^5 ; //注意是 2^5

void Buzzer()
{
	unsigned int i = 2000 ;
	
	while(i--)
		{
			DEEP = !(DEEP) ; //周期2ms
			Delay10us(50);
			DEEP = !(DEEP) ; 
			Delay10us(150);
			
		}
		i = 0 ;       //让蜂鸣器不发出声音
		DEEP = 0;
}


void Timer0_Routine() interrupt 1  //中断功能
{
	static unsigned int i ;
	TL0 = 0x18 ;
	TH0 = 0xFC ;
	i ++ ;
	if(i == 1000)
	{
		i = 0 ;
		Sec ++ ;
		if(Sec >= 60)
		{
			Sec = 0;
			Min++ ;
			if(Min >= 60)
			{
				Min = 0 ;
				Hour ++;
				if(Hour == 24)
				{
					Hour = 0 ;
				}
			}
		}
	}
}

void main()
{	
	LCD_Init();
	Timer0Init() ;
	
	LCD_ShowString(1,1, "Clock:");
	LCD_ShowString(2,1 ,"  :  :  ");
	
	while(1)
	{
		LCD_ShowNum(2,1, Hour, 2);
		LCD_ShowNum(2,4, Min, 2);
		LCD_ShowNum(2,7, Sec, 2);
		
		if(Min == 5 && Sec == 21)
		{
			Buzzer();
		}
		//Buzzer();
	}
	
}



