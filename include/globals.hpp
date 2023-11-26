// includes, defines, global variables 
#include <Arduino.h>
#include <Servo.h>
#include <string.h>

#define L_SERVO_PIN 3
#define R_SERVO_PIN 5
#define WAIT_SERVO 10
#define WAIT_FOR_INIT_SERVO 500
#define TIMEOUT 0
#define BAUDRATE 9600
#define BOTH 'B'
#define LEFT 'L'
#define RIGHT 'R'

Servo leftServo;
Servo rightServo;

int leftPos = 0;
int rightPos = 0;