#include "globals.hpp"

String commandBuffer;
String leftCommandBuffer;
String rightCommandBuffer;

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
        commandBuffer = Serial.readString();
        int commandLength = commandBuffer.length();

        if (commandLength == 7 && commandBuffer[0] == 'B') {
            leftCommandBuffer = commandBuffer.substring(1, 4);
            rightCommandBuffer = commandBuffer.substring(4, 7);
            leftPos = leftCommandBuffer.toInt();
            rightPos = rightCommandBuffer.toInt();
        }
        else if (commandLength == 4) {
            if (commandBuffer[0] == 'L') {
                leftCommandBuffer = commandBuffer.substring(1, 4);
                leftPos = leftCommandBuffer.toInt();
            } 
            else if (commandBuffer[0] == 'R') {
                rightCommandBuffer = commandBuffer.substring(1, 4);
                rightPos = rightCommandBuffer.toInt();
            }
        }

        leftServo.write(leftPos);
        rightServo.write(rightPos);
    }
}
