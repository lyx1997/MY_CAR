
#include "MYCAR.h"

struct car_status {
/* ������λ */
  int left; /* �������� */
  int right;  /* �ҵ������ */
  int steering; /* ����Ƕ� */
	int laststeering; /*	��һ�εĶ���Ƕ�	*/
  unsigned int sensor;  /* �����������ֵ */
};

struct car_status car;
 
void motor_dual(int left, int right)
{
	/*  ��֤���ٵ�ռ�ձȴ�������״̬	*/
	if (left > 20) {
    left = 20;
  } else if (left < 0) {
    left = 0;
  }

  if (right > 20) {
    right = 20;
  } else if (right < 0) {
    right = 0;
  }
	/*	����С������ת�ͷ�ת	*/
	if (left > 0) {
		motor_left_In1 = 1;
		motor_left_In2 = 0;
		} else {
			motor_left_In1 = 0;
			motor_left_In2 = 1;
			left = -left;
	}

	if (right > 0) {
		motor_right_In3 = 1;
		motor_right_In4 = 0;
		} else {
			motor_right_In3 = 0;
			motor_right_In4 = 1;
			right = -right;
	}

	car.left = left;
	car.right = right;
}

/*******************************
����bug����CPU���ıȽϴ�
��õķ���Ϊ��8��IO�������ֵ��Ϊһ������
�磺
if(P1 == 0xfd)
0xfd = 11 11110 1
*******************************/
unsigned int sensor(void)
{
  unsigned int input;
	unsigned int pin1 = sensor_pin1;
	unsigned int pin2 = sensor_pin2;
	unsigned int pin3 = sensor_pin3;
	unsigned int pin4 = sensor_pin4;
	unsigned int pin5 = sensor_pin5;
	
  input = (pin1 << 0) | (pin2 << 1) | (pin3 << 2)	| (pin4 << 3) | (pin5 << 4);
	
  /* todo: ����һ����������������ֵ */
  return input;
}

int steering(int angle,int lastangle)
{
	if (angle > 40) {
    angle = 40;
  } else if (angle < -40) {
    angle = -40;
  } else if (angle == 0){
  	angle = lastangle;
  }
	angle += 90;
	return angle;
}

int sensor2steering_array[33] = {			/*	�Բ��ķ�ʽ���нǶȵ�ɸѡ	*/
  0,       				// 0x00 
  RIGHT_30, 			// 0x01 
  RIGHT_15,				// 0x02
  RIGHT_30,				// 0x03
  STRAIGHT,				// 0x04
  -5,							// 0x05
  RIGHT_20,				// 0x06
  RIGHT_40,				// 0x07
  LEFT_15,				// 0x08
  10,							// 0x09	
  STRAIGHT,				// 0x10
  -7,							// 0x11
  LEFT_20,				// 0xC
  -6,							// 0xD
  STRAIGHT,				// 0xE
  -14,						// 0xF
  LEFT_30,				// 0x10
  STRAIGHT,				// 0x11
  7,							// 0x12
  -5,							// 0x13
  5,							// 0x14
  STRAIGHT,				// 0x15
  6,							// 0x16
  -5,							// 0x17
  LEFT_30,				// 0x18
  7,							// 0x19
  7,							// 0x1A
  STRAIGHT,				// 0x1B
  LEFT_40,				// 0x1C
	8,							// 0x1D
	9,							// 0x1E
  0								// 0x1F
}; 

/**********************************
���봫������������ֵ�����в��
**********************************/
int sensor2steering(unsigned int sensor)
{
  if (sensor > (1 << 4)) {
    return STRAIGHT;
  }
  return sensor2steering_array[sensor];
}

int steering2motor(int steering)
{
  if(steering >= 30){
		car.left -= 10;
	} else if(steering <= -30){
		car.right -= 10;
	} else if(steering >= 20 && steering < 30){
		car.left -= 5;
	} else if(steering <=-20 && steering > -30){
		car.right -= 5;
	} else{
		car.left = 20;
  	car.right = 20;
	}
  motor_dual(car.left, car.right);
	return 0;
}


 void TimeConfig()
 {
	 TMOD|= 0x20;  	//˫��λ�Ķ�ʱ��
	 TH1 = 0xA3; 
	 TL1 = 0xA3;
	 TH0 = 0xA3;
	 TL0 = 0xA3;
	 ET0 = 1;
	 TR0 = 1;
	 ET1 = 1; 	 
	 EA = 1;
	 TR1 = 1;
 }
 
 
 void Time2(void) interrupt 1
{
	timer1++;
	timer2++;
}
 
/*bit PWM=0;
unsigned int dataa[2]={123,321};
void Timer2(void) interrupt ?
{
	TH0=dataa[PWM]/256;
	TL0=dataa[PWM]%256;
	PWM=~PWM;
	



} */
 
 
 void Time1(void) interrupt 3   
 {
	/*	ͨ�����������������С�����ҵ�����ٶ�	*/
	 if(timer1>20)
	 {
		 timer1=0;
	 }
	 if(timer1 < left){	//leftΪ������������������ĳ���
		 motor_left_pwm = 1;
	 }else{
		 motor_left_pwm = 0;
	 }		
	 if(timer1 < right){	//rightΪ��������������ҵ���ĳ���
		 motor_right_pwm = 1;
	 }else{
		 motor_right_pwm = 0;
	 }		
	 
	 /*		ͨ��ռ�ձ������ƶ��ת���ĽǶ�	*/
	 if(timer2 == 200)
	 {
		 timer2=0;
	 }	
	 	if(timer2 <= angle){
			 servo_pwm = 1;
		 }else{
			 servo_pwm = 0;
		 }
}


void main()
{
	TimeConfig();
	while(1) 
	{ 
		car.sensor = sensor();
		car.steering = sensor2steering(car.sensor);
		car.steering = steering(car.steering,car.laststeering);
		car.laststeering = car.steering;
		steering2motor(car.steering);
	}
 }

