#include <Servo.h>

#define DEBUG 0

Servo myservo;

/* the smart car status structure */
struct car_status {
/* basic status */
	int left; /* left motor pwm */
	int right;  /* right motor pwm */
	int steering; /* steering angle */
	int laststeering; /* last steering angle */
	unsigned int sensor;  /* optic sensor value */

};

#define STRAIGHT        (0)
#define LEFT_30         (30)
#define LEFT_15       	(15)
#define LEFT_40      	(40)
#define LEFT_20			(20)
#define RIGHT_30        (-30)
#define RIGHT_15      	(-15)
#define RIGHT_40      	(-40)
#define RIGHT_20	  	(-20)

struct car_status car;


const unsigned int motor_left_pwm = 6;
const unsigned int motor_left_pin1 = 7;
const unsigned int motor_left_pin2 = 8;
const unsigned int motor_right_pwm = 5;
const unsigned int motor_right_pin1 = 12;
const unsigned int motor_right_pin2 = 13;

const unsigned int servo_line = 9;

#define NUM_OF_SENSOR_PINS 5
const unsigned int sensor_pins[NUM_OF_SENSOR_PINS] = {14,15,16,17,18};


#define SEETRING_OFFSET    90

/**
 *  left: left motor pwm, [-255, 255], < 0 backward, > 0 forward
 *    ,  255: 100% volatage for motor
 *  right: see left above
 */
void motor_dual(int left, int right)
{
  if (left > 255) {
    left = 255;
  } else if (left < -255) {
    left = -255;
  }

  if (right > 255) {
    right = 255;
  } else if (right < -255) {
    right = -255;
  }

  if (left > 0) {
    digitalWrite(motor_left_pin1, LOW);
    digitalWrite(motor_left_pin2, HIGH);
  } else {
    digitalWrite(motor_left_pin1, HIGH);
    digitalWrite(motor_left_pin2, LOW);
    left = -left;
  }

  if (right > 0) {
    digitalWrite(motor_right_pin1, LOW);
    digitalWrite(motor_right_pin2, HIGH);
  } else {
    digitalWrite(motor_right_pin1, HIGH);
    digitalWrite(motor_right_pin2, LOW);
    right = -right;
  }

  car.left = left;
  car.right = right;
  analogWrite(motor_left_pwm, left);
  analogWrite(motor_right_pwm, right);
}


/*  0b pin5 pin4 pin3 pin2 pin1 pin0 
 *     18    17   16   15   14   10
*/ 
unsigned int sensor(void)
{
  int i;
  unsigned int input;
  
  for (i = 0; i < NUM_OF_SENSOR_PINS; i++) {
    input |= (digitalRead(sensor_pins[i]) << i);
  }

  /* todo: add filter for sensor ? */
  return input;
}


/** 
 *  [-40, 40]
 *  tell the servo to go to the position
 */
int steering(int angle,int lastangle)
{
  if (angle > 40) {
    angle = 40;
  } else if (angle < -40) {
    angle = -40;
  } else if (angle == 0){
  	angle = lastangle;
  }

    angle += SEETRING_OFFSET;
    myservo.write(angle);

    return angle;
}


int sensor2steering_array[33] = {
  0,       				// 0x00 
  RIGHT_30, 			// 0x01 
  RIGHT_15,				// 0x02
  RIGHT_30,				// 0x03
  STRAIGHT,				// 0x04
  0,					// 0x05
  RIGHT_20,				// 0x06
  RIGHT_40,				// 0x07
  LEFT_15,				// 0x08
  0,					// 0x09	
  STRAIGHT,				// 0x10
  0,					// 0x11
  LEFT_20,				// 0xC
  0,					// 0xD
  STRAIGHT,				// 0xE
  0,					// 0xF
  LEFT_30,				// 0x10
  STRAIGHT,				// 0x11
  0,					// 0x12
  0,					// 0x13
  0,					// 0x14
  STRAIGHT,				// 0x15
  0,					// 0x16
  0,					// 0x17
  LEFT_30,				// 0x18
  0,					// 0x19
  0,					// 0x1A
  STRAIGHT,				// 0x1B
  LEFT_40,				// 0x1C
  0,					// 0x1D
  0,					// 0x1E
  1						// 0x1F
}; 


int sensor2steering(unsigned int sensor)
{
  if (sensor > (1 << NUM_OF_SENSOR_PINS)) {
    return STRAIGHT;
  }

  return sensor2steering_array[sensor];
}

int steering2motor(int steering)
{
	
	if(steering >= 30){
		car.left -= 30;
	} else if(steering <= -30){
		car.right -= 30;
	} else if(steering >= 20 && steering < 30){
		car.left -= 10;
	} else if(steering <=-20 && steering > -30){
		car.right -= 10;
	} else{
		car.left = 127;
  		car.right = 127;
	}
	
  	motor_dual(car.left, car.right);
}

void setup() 
{
  int i;

    /* sensor initialization */
    for (i = 0; i < NUM_OF_SENSOR_PINS; i++) {
       pinMode(sensor_pins[i], INPUT); // declare the sensor pin as inpt
    }
  
    /* motor initialization */
    pinMode(motor_right_pwm, OUTPUT);
    pinMode(motor_left_pwm, OUTPUT);
    pinMode(motor_right_pin1, OUTPUT);
    pinMode(motor_right_pin2, OUTPUT);
    pinMode(motor_left_pin1, OUTPUT);
    pinMode(motor_left_pin2, OUTPUT); 

    /* servo initializaiton */
    myservo.attach(servo_line); 

  Serial.begin(9600);
}

void loop()
{
   //steering2motor(steering(sensor2steering(sensor_read())));
  car.sensor = sensor();
  car.steering = sensor2steering(car.sensor);
  steering(car.steering,car.laststeering);
  car.laststeering = car.steering;
  steering2motor(car.steering);
#if DEBUG
  Serial.print(car.left);
  Serial.print(car.right);
  /* to do add more output info. */
#endif
}