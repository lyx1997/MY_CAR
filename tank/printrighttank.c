
#include "define.h"


int printrighttank()
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;
	
	for(i = 0;i < 5;i++)
	{
		tmp.Y = pos.Y-14;
		tmp.X = pos.X+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.Y = pos.Y-13;
		tmp.X = pos.X+i*4;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.Y = pos.Y-12;
		tmp.X = pos.X+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.Y = pos.Y-11;
		tmp.X = pos.X+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 4;i++)
	{
		tmp.Y = pos.Y-10;
		tmp.X = pos.X+4+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.Y = pos.Y-10;
		tmp.X = pos.X+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.Y = pos.Y-9;
		tmp.X = pos.X+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.Y = pos.Y-8;
		tmp.X = pos.X+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.Y = pos.Y-7;
		tmp.X = pos.X+i*4;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.Y = pos.Y-6;
		tmp.X = pos.X+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	return 0;
}
