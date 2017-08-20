
#include "MYCAR.h"

unsigned char timer1 = 0;
unsigned int 	timer2 = 0;
unsigned char x = 0;
unsigned char y = 0; 
unsigned char duty = 10;
unsigned char direction = 0;
unsigned int 	angle;
unsigned char lastdir;

void main()
{
	Time1Config();
	while(1) 
	{ 
		Sensor_Module();
		if(plus==0)
		{
			delay(5);	  
			if(plus==0){
				while(!plus);
				x=1;
				if(x==1){
					duty++;
					deng6=0;
					delay(5);
					deng6=1;
				}
				if(duty>20){
					duty=0;
				}
			}
		}

		if(sub==0)
		{
			delay(5);	 
			if(sub==0)	
			{
				while(!sub);
				y=1;
				if(y==1){
					duty--;
					deng7=0;
					delay(5);
					deng7=1;;
				}
				if(duty<=0){
					duty=20;
				}
			}  
		}
	}
 }
 
 void Time1Config()
 {
	 TMOD|= 0x20;  
	 
	 TH1 = 0xA3; 
	 TL1 = 0xA3;
	 ET1 = 1; 	 
	 EA = 1;
	 TR1 = 1;	 
 }
 
 void Time1(void) interrupt 3   
 {
	 timer1++; 
	 timer2++; 
	 if(timer1>20)
	 {
		 timer1=0;
	 }
	 if(timer1 < duty)
		 PWM=1;
	 if(timer1 >= duty)
		 PWM=0; 
	 if(timer2 == 200)
	 {
		 timer2=0;
	 }	
	 	if(timer2 <= angle){
			 HIGHELEC;
		 }else{
			 LOWELEC;
		 }
		
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


