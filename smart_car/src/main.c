
#include "MYCAR.h"

unsigned char timer1 = 0;
unsigned int 	timer2 = 0;
unsigned char duty = 10;
unsigned char direction = 0;
unsigned int 	angle;
unsigned char lastdir;

void main()
{
	Time1Config();
	while(1) 
	{ 
		Sensor_Module();//调用传感器模块
		SpeedControl();
		lastdir = direction;
	}
 }
 
 void Time1Config()
 {
	 TMOD|= 0x20;  	//双八位的定时器
	 
	 TH1 = 0xA3; 
	 TL1 = 0xA3;
	 ET1 = 1; 	 
	 EA = 1;
	 TR1 = 1;	 
 }
 
 
 bit PWM=0;
unsigned int dataa[2]={123,321};
void Timer2(void) interrupt ?
{
	
	TH0=dataa[PWM]/256;
	TL0=dataa[PWM]%256;
	PWM=~PWM;
	



} 
 
 
 void Time1(void) interrupt 3   
 {
	 timer1++; 
	 timer2++; 
	 if(timer1>20)
	 {
		 timer1=0;
	 }
	 if(timer1 < duty)	//duty为电机的脉宽，调节车速
		 PWM=1;
	 if(timer1 >= duty)
		 PWM=0; 
	 if(timer2 == 200)
	 {
		 timer2=0;
	 }	
	 	if(timer2 <= angle){
			 HIGHELEC;				//PWM_D = 1 	高电平
		 }else{	
			 LOWELEC;					//PWM_D = 0		低电平
		 }
		/*******************************************
		 以传感器模块改变的方向角度，
		 在这里进行switch的选择，调节占空比
		 ******************************************/
	 switch(direction)
		 {
		 case left40: angle = 3; break;
		 case left20: angle = 5; break;
		 case left10: angle = 7; break;
		 case straight: angle = 9; break;
		 case right10: angle = 19; break;
		 case right20: angle = 22; break;
		 case right40: angle = 24; break;
		}
}

void delay(unsigned int i)
{
    unsigned char j;
    for(i; i > 0; i--)   
        for(j = 255; j > 0; j--);
}


