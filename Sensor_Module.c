#include "MYCAR.h"

void Sensor_Module()
{
	if(led1 == 1 && led2 == 1 && led3 == 1 && led4 == 0 && led5 == 0)
	{
		delay(5);
		if(led1 == 1 && led2 == 1 && led3 == 1 && led4 == 0 && led5 == 0){
		direction = left40;
		}
	}
	if(led1 == 1 && led2 == 1 && led3 == 0 && led4 == 0 && led5 == 0)
	{
		delay(5);
		if(led1 == 1 && led2 == 1 && led3 == 0 && led4 == 0 && led5 == 0){
		direction = left30;
		}
	}
	if(led1 == 1 && led2 == 0 && led3 == 0 && led4 == 0 && led5 == 0)
	{
		delay(5);
		if(led1 == 1 && led2 == 0 && led3 == 0 && led4 == 0 && led5 == 0){
		direction = left20;
		}
	}
	if(led1 == 0 && led2 == 1 && led3 == 0 && led4 == 0 && led5 == 0)
	{
		delay(5);
		if(led1 == 0 && led2 == 1 && led3 == 0 && led4 == 0 && led5 == 0){
		direction = left10;
		}
	}
	if(led1 == 0 && led2 == 1 && led3 == 1 && led4 == 0 && led5 == 0)
	{
		delay(5);
		if(led1 == 0 && led2 == 1 && led3 == 1 && led4 == 0 && led5 == 0){
		direction = left5;
		}
	}
	if(led1 == 0 && led2 == 0 && led3 == 1 && led4 == 0 && led5 == 0)
	{
		delay(5);
		if(led1 == 0 && led2 == 0 && led3 == 1 && led4 == 0 && led5 == 0){
		direction = straight;
		}
	}
	if(led1 == 0 && led2 == 0 && led3 == 1 && led4 == 1 && led5 == 0)
	{
		delay(5);
		if(led1 == 0 && led2 == 0 && led3 == 1 && led4 == 1 && led5 == 0){
			direction = right5;
		}
	}
	if(led1 == 0 && led2 == 0 && led3 == 0 && led4 == 1 && led5 == 0)
	{
		delay(5);
		if(led1 == 0 && led2 == 0 && led3 == 0 && led4 == 1 && led5 == 0){
			direction = right10;
		}
	}
	if(led1 == 0 && led2 == 0 && led3 == 0 && led4 == 0 && led5 == 1)
	{
		delay(5);
		if(led1 == 0 && led2 == 0 && led3 == 0 && led4 == 0 && led5 == 1){
			direction = right20;
		}
	}
	if(led1 == 0 && led2 == 0 && led3 == 0 && led4 == 1 && led5 == 1)
	{
		delay(5);
		if(led1 == 0 && led2 == 0 && led3 == 0 && led4 == 1 && led5 == 1){
			direction = right30;
		}
	}
	if(led1 == 0 && led2 == 0 && led3 == 1 && led4 == 1 && led5 == 1)
	{
		delay(5);
		if(led1 == 0 && led2 == 0 && led3 == 1 && led4 == 1 && led5 == 1){
			direction = right40;
		}
	}
}

	
