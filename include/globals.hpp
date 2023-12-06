#include <Arduino.h>
#include <Servo.h>
#include <string.h>



const uint8_t L_SERVO_PIN = 3;
const uint8_t R_SERVO_PIN = 5;
const uint8_t WAIT_SERVO = 10;
const uint16_t WAIT_FOR_INIT_SERVO = 500;
const uint8_t TIMEOUT = 0;
const uint16_t BAUDRATE = 9600;
const size_t CMD_LEN = 4; // 4 bytes for one cmd
const char BOTH = 'B';
const char LEFT = 'L';
const char RIGHT = 'R';



Servo lServo;
Servo rServo;

int lPos = 0;
int rPos = 0;