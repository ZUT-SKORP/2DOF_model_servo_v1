// includes, defines, global variables 
#include <Servo.h>
#include <string.h>

#define LSERVOPIN 3
#define RSERVOPIN 5
#define WAITSERVO 10
#define WAITFORINITSERVO 500
#define MYTIMEOUT 0
#define BAUDRATE 9600

Servo leftServo;
Servo rightServo;

int leftPos = 0;
int rightPos = 0;
