#include <REGX52.H>
#include <INTRINS.H>

void Delay10us(unsigned int xus)		//@12.000MHz
{
	while(xus--)
	{
		unsigned char i;

		_nop_(); //要引<INTRINS.H>
		i = 2;
		while (--i);
	}

}