#include <REGX52.H>

//中断初始化函数
void Timer0Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	
	ET0 = 1 ;
	EA = 1 ;
	PT0 = 0 ;
}


//void Timer0_Routine() interrupt 1
//{
//	static unsigned int i ;
//	TL0 = 0x18 ;
//	TH0 = 0xFC ;
//	i ++ ;
//	if(i == 1000)
//	{
//		i = 0 ;
//		Sec ++ ;
//	}
//}

