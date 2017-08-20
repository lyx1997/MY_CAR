#include "define.h"


void printspace(int count,int a,int b,int coe)
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;
	for(i = 0;i < count;i++)
	{
		tmp.X = pos.X+a;
		tmp.Y = pos.Y+b+coe*i;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut,tmp);
		printf(" ");
	}
}

int clean(int dir)
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;
	switch(dir)//炮头不一样需要条件判断
	{
		case UP:
			for(i = 0;i < 6;i++)
			{
				tmp.X = pos.X+4+i;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf(" ");
			}
			for(i = 0;i < 6;i++)
			{
				tmp.X = pos.X-4-i;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf(" ");
			}break;
		case LEFT:
			printspace(4,0,-2,-1);
			printspace(4,0,2,1);
		case DOWN:
			for(i = 0;i < 6;i++)
			{
				tmp.X = pos.X+4+i;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf(" ");
			}
			for(i = 0;i < 6;i++)
			{
				tmp.X = pos.X-4-i;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf(" ");
			}break;
		case RIGHT:
			printspace(4,0,-2,-1);
			printspace(4,0,2,1);
	
	}
	

	printspace(2,0,-1,2);
	printspace(2,1,-1,2);
	printspace(2,-1,-1,2);
	printspace(5,2,-2,1);
	printspace(5,-2,-2,1);
	printspace(2,3,-2,4);
	printspace(2,-3,-2,4);
	printspace(5,4,-2,1);
	printspace(5,-4,-2,1);

	return 0;
}