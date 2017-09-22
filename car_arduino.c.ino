#include <Servo.h>


#define DEBUG 1

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

#define STRAIGHT        (1)
#define LEFT_30         (-13)
#define LEFT_15         (-4)
#define LEFT_20         (-8)

#define RIGHT_30        (15)
#define RIGHT_15        (6)
#define RIGHT_20        (10)



struct car_status car;


const unsigned int motor_left_pwm = 5;
const unsigned int motor_left_pin1 = 7;
const unsigned int motor_left_pin2 = 8;
const unsigned int motor_right_pwm = 6;
const unsigned int motor_right_pin1 = 2;
const unsigned int motor_right_pin2 = 4;

const unsigned int servo_line = 9;

#define NUM_OF_SENSOR_PINS 5
const unsigned int sensor_pins[NUM_OF_SENSOR_PINS] = {14,15,16,17,18};

int flag = 1;


#define SEETRING_OFFSET    92

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
  } 
  
   angle += SEETRING_OFFSET;
    myservo.write(angle);
    return angle;
}


int sensor2steering_array[33] = {
  0,              // 0x00 
  0,       // 0x01 
  0,       // 0x02
  0,       // 0x03
  0,       // 0x04
  0,          // 0x05
  0,       // 0x06
  0,       // 0x07
  0,        // 0x08
  0,           // 0x09  
  0,       // 0xA
  0,          // 0xB
  0,        // 0xC
  0,          // 0xD
  0,       // 0xE
  LEFT_30,          // 0xF
  0,        // 0x10
  0,       // 0x11
  0,          // 0x12
  LEFT_15,          // 0x13
  0,          // 0x14
  0,       // 0x15
  0,          // 0x16
  0,//LEFT_20,          // 0x17
  0,        // 0x18
  RIGHT_15,          // 0x19
  0,          // 0x1A
  STRAIGHT,       // 0x1B
  0,        // 0x1C
  0,//RIGHT_20,          // 0x1D
  RIGHT_30,          // 0x1E
  0           // 0x1F
}; 


int sensor2steering(unsigned int sensor)
{
  if (sensor > (1 << NUM_OF_SENSOR_PINS)) {
    return STRAIGHT;
  }

  if(sensor2steering_array[sensor] != 0){
  return sensor2steering_array[sensor];
  }else{
    return car.laststeering;
  }
}

int limitsteering(int angle,int lastangle)
{
    if(angle - lastangle >= 20 || angle - lastangle <= -20){
    return STRAIGHT;
  }
  /*else if(car.sensor == 2)
  {
    if(lastangle == 8){
    angle = 18;
    }else if(car.laststeering == -8){
    angle = -18;
    }
    return angle;
  }*//*else if(lastangle == 15 && angle == 1 || angle == 6){
    delay(350);
    return angle;
  }else if(lastangle == -13 && angle == 1 || angle == -4){
    delay(350);
    return angle;
  }*/
  else{
    return angle;
  }
}

int steering2motor(int steering)
{
  
  /*if(steering >= 10){
    car.left = 87;
    car.right = 87;
  } else if(steering <= -10){
    car.right = 87;
    car.left = 7;
  }else{*/
    car.left = 127;
      car.right = 127;
  
  
    motor_dual(car.left, car.right);
}
/*
void isr_second_handler()
{
  flag = 1;
}*/

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
  car.steering = limitsteering(car.steering,car.laststeering);
  steering(car.steering,car.laststeering);
  car.laststeering = car.steering;
  steering2motor(car.steering);
#if DEBUG
  Serial.print("car status:");
  Serial.print(car.left);
  Serial.print("   ");
  Serial.print(car.right);
  Serial.print("   ");
  Serial.print(car.sensor);
  Serial.print("   ");
  Serial.print(car.steering);
  Serial.print("   ");
  Serial.print(car.laststeering);
  Serial.println("   ");
  
  /* to do add more output info. */
#endif
}
