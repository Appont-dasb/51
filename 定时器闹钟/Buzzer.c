#include <REGX52.H>
//#inlude "Delay10us.h"
#include <INTRINS.H>

//sbit DEEP = P2^5 ; //注意是 2^5

//void Buzzer()
//{
//	unsigned int i = 2000 ;
//	
//	while(i--)
//		{
//			DEEP = !(DEEP) ; //周期2ms
//			Delay10us(50);
//			DEEP = !(DEEP) ; 
//			Delay10us(150);
//			
//		}
//		i = 0 ;       //让蜂鸣器不发出声音
//		DEEP = 0;
//}