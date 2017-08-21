

#include <reg52.h>

/***********************
宏定义查表得表格
***********************/
#define left40		11100
#define left30 		11000
#define left20 		10000
#define left10 		01000
#define left5			01100
#define straight 	00100
#define right5		00110
#define right10 	00010
#define right20 	00001
#define right30 	00011
#define right40		00111


#define HIGHELEC	PWM_D = 1
#define LOWELEC		PWM_D = 0

/*************
函数申明
*************/
void Time1Config();
void delay(unsigned int i);  
void Sensor_Module();
int SpeedControl();

/**************
全局变量
**************/
extern unsigned char timer1;
extern unsigned int timer2; 
extern unsigned char duty;
extern unsigned char direction;
extern unsigned int angle;
extern unsigned char lastdir;

/*************
使用的引脚
*************/
sbit PWM=P0^5;
sbit PWM_D=P0^6;

sbit led1=P0^0;
sbit led2=P0^1;
sbit led3=P0^2;
sbit led4=P0^3;
sbit led5=P0^4;
sbit deng7=P1^6;
sbit deng6=P1^5;
sbit deng1=P1^0;
sbit deng2=P1^1;
sbit deng3=P1^2;
sbit deng4=P1^3;
sbit deng5=P1^4;