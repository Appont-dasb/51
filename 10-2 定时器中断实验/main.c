#include <REGX52.H>

#include <INTRINS.H>

//功能：

sbit LED1 = P2^0 ; //定义



void time0_init(void) //初始化
{
	TMOD |= 0X01 ; //工作方式1
	TH0 = 0XFC ; //定时器初值，定时1ms ,FC18
	TL0 = 0X18 ;
	ET0 = 1 ; //打开中断允许
	EA = 1 ; //打开总中断
	TR0 = 1 ; //打开定时器
}


void time0() interrupt 1 //定时器0中断   功能
{
	static unsigned int i = 0 ;
	
	TH0 = 0XFC ; 
	TL0 = 0X18 ;
	
	i++ ;
	if(i == 1000) //1s
	{
		i = 0 ;
		LED1 =!LED1 ;
	}
}



void main()
{
	time0_init();

	while(1)
	{
		P2_1 = 0 ;
	}
}




