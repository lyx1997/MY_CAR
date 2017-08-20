#include "define.h"

int showtank(int color,int direct)
{
	HANDLE hOut = NULL;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,color);
	switch(direct)
	{
	case UP:
		printbigtank(UP);
		break;
	case LEFT:
		printbigtank(LEFT);
		break;
	case RIGHT:
		printbigtank(RIGHT);
		break;
	case DOWN:
		printbigtank(DOWN);
		break;
	}
	
	return 0;
}
