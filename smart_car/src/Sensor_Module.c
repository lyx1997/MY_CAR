#include "MYCAR.h"

/******************************************************************************************
程序名称：传感器模块
功能：以查表得形式，将小车行驶时所有可能的状态进行判
因为一共五个传感器，最高11111，一共只能有32种状态
*******************************************************************************************/
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

	