#include "define.h"
#include "conio.h"

int keyboardcontrol()
{
	char keyvalue = ' ';
	int dir;
	
	showtank(PINK,UP);
	while(1)
	{
		if(kbhit())
		{
			keyvalue = getch();
			switch(keyvalue)
			{
				case 'w':dir = UP;break;
				case 'a':dir = LEFT;break;
				case 's':dir = DOWN;break;
				case 'd':dir = RIGHT;break;
			}
		}
		
		switch(dir)
		{
			case UP:
				movetank(dir);
				pos.Y--;
				showtank(PINK,dir);
				break;
			case LEFT:
				movetank(dir);
				pos.X--;
				showtank(PINK,dir);
				break;
			case DOWN:
				movetank(dir);
				pos.Y++;
				showtank(PINK,dir);
				break;
			case RIGHT:
				movetank(dir);
				pos.X++;
				showtank(PINK,dir);
				break;
		}
		dir = 0;
	}
}