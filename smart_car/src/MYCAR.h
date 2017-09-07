

#include <reg52.h>

/***********************
宏定义查表得表格
***********************/
#define STRAIGHT        (0)
#define LEFT_30         (30)
#define LEFT_15       	(15)
#define LEFT_40      		(40)
#define LEFT_20					(20)
#define RIGHT_30        (-30)
#define RIGHT_15      	(-15)
#define RIGHT_40      	(-40)
#define RIGHT_20	  		(-20)

/**************
全局变量
**************/
unsigned char timer1;
unsigned int timer2; 
unsigned int left;
unsigned int right;
unsigned char direction;
unsigned int angle;
unsigned char lastdir;

/*************
使用的引脚
*************/
sbit servo_pwm = P1^6;

sbit motor_left_pwm = P1^0;
sbit motor_left_In1 = P1^1;
sbit motor_left_In2 = P1^2;
sbit motor_right_pwm = P1^3;
sbit motor_right_In3 = P1^4;
sbit motor_right_In4 = P1^5;

sbit sensor_pin1 = P0^0;
sbit sensor_pin2 = P0^1;
sbit sensor_pin3 = P0^2;
sbit sensor_pin4 = P0^3;
sbit sensor_pin5 = P0^4;
