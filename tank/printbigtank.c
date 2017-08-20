
#include "define.h"


void printstars(int count,int a,int b,int coe)
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
		printf("*");
	}
}

int printbigtank(int dir)
{
	int i;
	HANDLE hOut = NULL;
	COORD tmp;
	switch(dir)//炮头不一样需要条件判断
	{
		case UP:
			printstars(4,0,-2,-1);
			break;
		case LEFT:
			for(i = 0;i < 6;i++)
			{
				tmp.X = pos.X-4-i;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf("*");
			}break;
		case DOWN:
			printstars(4,0,2,1);
			break;
		case RIGHT:
			for(i = 0;i < 6;i++)
			{
				tmp.X = pos.X+4+i;
				tmp.Y = pos.Y;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleCursorPosition(hOut,tmp);
				printf("*");
			}break;
	}
	

	printstars(2,0,-1,2);
	printstars(2,1,-1,2);
	printstars(2,-1,-1,2);
	printstars(5,2,-2,1);
	printstars(5,-2,-2,1);
	printstars(2,3,-2,4);
	printstars(2,-3,-2,4);
	printstars(5,4,-2,1);
	printstars(5,-4,-2,1);

	return 0;
}