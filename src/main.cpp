#include "globals.hpp"

uint8_t cmdBuff[CMD_LEN+1], reCmdBuff[CMD_LEN+1];
uint8_t ctrlByte1, ctrlByte2; // control bytes
uint8_t lPosBuff, rPosBuff;

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
        // TODO przetestowac czy dziala z wartosciami >127 i <=127
        reCmdBuff = reinterpret_cast<char*>(cmdBuff);
        Serial.readBytes(reCmdBuff, CMD_LEN);
        ctrlByte1 = (uint8_t)reCmdBuff[0] - '0';
        ctrlByte2 = (uint8_t)reCmdBuff[strlen(reCmdBuff)-1] - '0';

        if (ctrlByte1 == 1 && ctrlByte2 == 0) {
            memmove(reCmdBuff, reCmdBuff + 1, strlen(reCmdBuff));
            reCmdBuff[strlen(reCmdBuff)-1] = '\0';
        }

        if (strlen(reCmdBuff) == 2) {
            lPosBuff = (uint8_t)reCmdBuff[0] - '0';
            rPosBuff = (uint8_t)reCmdBuff[1] - '0';
            if (lPosBuff <= 180 && rPosBuff <= 180) {
                lPos = lPosBuff;
                rPos = rPosBuff;
            }   
        }
        
        leftServo.write(leftPos);
        rightServo.write(rightPos);    

        Serial.flush();
    }
}
