#include "MYCAR.h"

void Parameter(unsigned char dir,int speed)
{
	if(direction == dir)
	{
		delay(5);
		if(direction == dir){
			duty = speed;
		}
	}
}

int SpeedControl()
{
	switch(direction)
	{
		case straight:Parameter(straight,20);break;
		case right40:Parameter(right40,3);break;
		case right30:Parameter(right30,5);break;
		case right20:Parameter(right20,10);break;
		case right10:Parameter(right10,15);break;
		case right5:Parameter(right5,18);break;
		case left40:Parameter(left40,3);break;
		case left30:Parameter(left30,5);break;
		case left20:Parameter(left20,10);break;
		case left10:Parameter(left10,15);break;
//		case left5:Parameter(left5,18);break;
	}
	return 0;
}