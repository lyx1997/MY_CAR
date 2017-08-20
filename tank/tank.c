
#include "define.h"
#include "stdlib.h"

COORD pos = {20,20};


int movetank(int direct)
{
	showtank(PINK,direct);
	Sleep(HIGHSPEED);
	clean(direct);
	return 0;
}



int main()
{
	HANDLE hOut = NULL;


	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	keyboardcontrol();

	SetConsoleCursorPosition(hOut,pos);
	pos.X = 100;
	pos.Y = 100;
	
	return 0;
}
