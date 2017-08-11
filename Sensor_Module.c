#include "MYCAR.h"

void Sensor_Module()
{
	if(led1 == 0 && led2 != 0)
	{
		delay(5);
		if(led1 == 0 && led2 != 0){
		direction = left40;
		}
	}
	if(led2 == 0 && led1 != 0)
	{
		delay(5);
		if(led2 == 0 && led1 != 0){
		direction = left10;
		}
	}
	if(led3 == 0)
	{
		delay(5);
		if(led3 == 0){
		direction = straight;
		}
	}
	if(led4 == 0 && led5 != 0)
	{
		delay(5);
		if(led4 == 0 && led5 != 0){
		direction = right10;
		}
	}
	if(led5 == 0 && led4 != 0)
	{
		delay(5);
		if(led5 == 0 && led4 != 0){
		direction = right40;
		}
	}
	if((led2==0)&&(led1==0))
	{
		delay(5);
		if((led2==0)&&(led1==0)){
		direction = left20;
		}
	}
	if((led4==0)&&(led5==0))
	{
		delay(5);
		if((led4==0)&&(led5==0)){
			direction = right20;
		}
	}
}

	
