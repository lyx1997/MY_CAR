#include <Servo.h>
#include <MsTimer2.h>

Servo myservo;

#define STRAIGHT       	90
#define LEFT_30         60
#define LEFT_15     	75
#define LEFT_40     	50
#define RIGHT_30        120
#define RIGHT_15    	105
#define RIGHT_40   	 	130

const unsigned int motor_left_pwm = 6;
const unsigned int motor_left_pin1 = 7;
const unsigned int motor_left_pin2 = 8;
const unsigned int motor_right_pwm = 5;
const unsigned int motor_right_pin1 = 12;
const unsigned int motor_right_pin2 = 13;

const unsigned int servo_line = 9;
const unsigned int sensor_pin[6] = {10,14,15,16,17,18};

unsigned int angle;

void motor(char pin1,char pin2,char pwmpin,char state,char val)
{
    if(state == 1)    //当state为1时正转
    {
      analogWrite(pwmpin,val);
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
    }
    if(state == 2)    //当state为2时反转
    {
      analogWrite(pwmpin,val);
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
    }
    if(state == 0)    //当state为1时停止
    {
      analogWrite(pwmpin,0);
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
    }
}


unsigned char sensor_read()
{
  unsigned int dir;
  unsigned int Direc;
  Direc = 10000*sensor_pin[5]+1000*sensor_pin[4]+100*sensor_pin[3]+10*sensor_pin[2]+sensor_pin[1];
  switch(Direc)
  {
    case 1:dir = RIGHT_30;break;
    case 10:dir = RIGHT_15;break;
    case 11:dir = RIGHT_30;break;
    case 111:dir = RIGHT_40;break;
    case 100:dir = STRAIGHT;break;
    case 10000:dir  = LEFT_30; break;
    case 11000:dir = LEFT_30;break;
    case 1000:dir = LEFT_15;break;
    case 11100:dir = LEFT_40;break;
  }
  angle = dir;
  return dir;
}

void steering(int pos)
{
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15ms for the servo to reach the position
}

void car_move()
{
     unsigned Angle;
     Angle = angle - 90;
     switch(Angle)
     {
      case -40:motor(motor_left_pin1,motor_left_pin2,motor_left_pwm,1,180-40);break;
      case -30:motor(motor_left_pin1,motor_left_pin2,motor_left_pwm,1,180-30);break;
      case 0:break;
      case 30:motor(motor_right_pin1,motor_right_pin2,motor_right_pwm,1,180-30);break;
      case 40:motor(motor_right_pin1,motor_right_pin2,motor_right_pwm,1,180-40);break;
      default:
      {
        angle = 90;
        motor(motor_left_pin1,motor_left_pin2,motor_left_pwm,1,180);
        motor(motor_right_pin1,motor_right_pin2,motor_right_pwm,1,180);
        break;
      }
     }
}

void setup() 
{
    myservo.attach(9);
    pinMode(sensor_pin[0], OUTPUT); // declare the ledPin as as OUTPUT
    Serial.begin(9600);
    pinMode(motor_right_pin1, OUTPUT);
    pinMode(motor_right_pin2, OUTPUT);
    pinMode(motor_left_pin1, OUTPUT);
    pinMode(motor_left_pin2, OUTPUT);    
}


void loop()
{
    motor(motor_left_pin1,motor_left_pin2,motor_left_pwm,1,180);
    motor(motor_right_pin1,motor_right_pin2,motor_right_pwm,1,180);
    steering(sensor_read());  
    car_move();
}