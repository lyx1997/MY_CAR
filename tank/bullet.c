/*
#include "define.h"

void movebullet()
void printbulle(int dir)
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;

	switch(dir)//炮头不一样需要条件判断
	{
		case UP:
				tmp.X = pos.X;
				tmp.Y = pos.Y-6;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf("*");
			break;
		case LEFT:
				tmp.X = pos.X-10;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf("*");
			break;
		case DOWN:
				tmp.X = pos.X;
				tmp.Y = pos.Y+6;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf("*");
		case RIGHT:
				tmp.X = pos.X+10;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf("*");
	}
}
int showbullet(int color,int direct)
*/