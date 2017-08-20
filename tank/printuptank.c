
#include "define.h"


int printuptank()
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;
	
	for(i = 0;i < 4;i++)
	{
		tmp.X = pos.X;
		tmp.Y = pos.Y-2-i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X;
		tmp.Y = pos.Y+1+2*i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X+1;
		tmp.Y = pos.Y+1+2*i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-1;
		tmp.Y = pos.Y+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 4;i++)
	{
		tmp.X = pos.X+2;
		tmp.Y = pos.Y-8+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-6;
		tmp.Y = pos.Y-5+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X-4;
		tmp.Y = pos.Y-5+1+i*2;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.X = pos.X-2;
		tmp.Y = pos.Y-5+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 2;i++)
	{
		tmp.X = pos.X;
		tmp.Y = pos.Y-5+i*4;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	for(i = 0;i < 5;i++)
	{
		tmp.X = pos.X+2;
		tmp.Y = pos.Y-5+i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf("*");
	}
	return 0;
}