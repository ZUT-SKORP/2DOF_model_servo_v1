#include "globals.hpp"

uint8_t cmdBuff[CMD_LEN+1];
uint8_t ctrlByte1, ctrlByte2; // control bytes
String lCmdBuff;
String rCmdBuff;

void setup() {
    Serial.begin(BAUDRATE);
    Serial.setTimeout(TIMEOUT);

    leftServo.attach(L_SERVO_PIN);
    rightServo.attach(R_SERVO_PIN);

    // initial position of the servos
    leftServo.write(90);
    rightServo.write(90);
    delay(WAIT_FOR_INIT_SERVO);  
}

void loop() {
    if (Serial.available()) {
        // ! przetestowac czy dziala z wartosciami >127 i czy da sie to jakos upiekszyc
        Serial.readBytes(reinterpret_cast<char*>(cmdBuff), CMD_LEN);
        Serial.println(reinterpret_cast<char*>(cmdBuff));
        ctrlByte1 = (uint8_t)cmdBuff[0] - '0';
        ctrlByte2 = (uint8_t)cmdBuff[strlen(reinterpret_cast<char*>(cmdBuff))-1] - '0';
        if (ctrlByte1 == 1 && ctrlByte2 == 0) {
            memmove(cmdBuff, cmdBuff + 1, strlen(reinterpret_cast<char*>(cmdBuff)));
            cmdBuff[strlen(reinterpret_cast<char*>(cmdBuff))-1] = '\0';
            Serial.println(reinterpret_cast<char*>(cmdBuff));
        }

        // if (commandLength == 7 && cmdBuff[0] == BOTH) {
        //     lCmdBuff = cmdBuff.substring(1, 4);
        //     rCmdBuff = cmdBuff.substring(4, 7);
        //     leftPos = lCmdBuff.toInt();
        //     rightPos = rCmdBuff.toInt();
        // }
        // else if (commandLength == 4) {
        //     if (cmdBuff[0] == LEFT) {
        //         lCmdBuff = cmdBuff.substring(1, 4);
        //         leftPos = lCmdBuff.toInt();
        //     } 
        //     else if (cmdBuff[0] == RIGHT) {
        //         rCmdBuff = cmdBuff.substring(1, 4);
        //         rightPos = rCmdBuff.toInt();
        //     }
        // }

        // leftServo.write(leftPos);
        // rightServo.write(rightPos);
        Serial.flush();
    }
}
