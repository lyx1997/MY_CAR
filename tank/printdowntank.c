
#include "define.h"


int printdowntank()
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;
	
	for(i = 0;i < 5;i++)
	{
		tmp.X = pos.X-14;
		tmp.Y = pos.Y-5+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-13;
		tmp.Y = pos.Y-5+i*4;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.X = pos.X-12;
		tmp.Y = pos.Y-5+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-11;
		tmp.Y = pos.Y-5+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 4;i++)
	{
		tmp.X = pos.X-10;
		tmp.Y = pos.Y-1+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-10;
		tmp.Y = pos.Y-5+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-9;
		tmp.Y = pos.Y-5+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.X = pos.X-8;
		tmp.Y = pos.Y-5+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-7;
		tmp.Y = pos.Y-5+i*4;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.X = pos.X-6;
		tmp.Y = pos.Y-5+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	return 0;
}