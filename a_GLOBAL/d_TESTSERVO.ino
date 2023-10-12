void testLeftServo() {
    leftServo.write(0);
    for (int i = 0; i <= 180; i++) {
        if (i == 90) delay(500);
        else {
            leftServo.write(i);
            delay(WAITSERVO);
        }
    }
}

void testRightServo() {
    rightServo.write(0);
    for (int i = 0; i <= 180; i++) {
        if (i == 90) delay(500);
        else {
            rightServo.write(i);
            delay(WAITSERVO);
        }
    }
}

void testBothServos() {
    leftServo.write(0);
    rightServo.write(0);
    for (int i = 0; i <= 180; i++) {
        leftServo.write(i);
        rightServo.write(i);
        delay(WAITSERVO);
    }
}

void testSerialServo() {

    if (Serial.available()) {
        String commandBuffer = Serial.readString();
        
        int commandLength = commandBuffer.length();

        if (commandLength == 7 && commandBuffer[0] == 'B') {
            String leftCommandBuffer = commandBuffer.substring(1, 4);
            rightCommandBuffer = commandBuffer.substring(4, 7);
            String leftPos = leftCommandBuffer.toInt();
            rightPos = rightCommandBuffer.toInt();
        }

        else if (commandLength == 4) {
            if (commandBuffer[0] == 'L') {
                String leftCommandBuffer = commandBuffer.substring(1, 4);
                leftPos = leftCommandBuffer.toInt();
            } 
            
            else if (commandBuffer[0] == 'R') {
                String rightCommandBuffer = commandBuffer.substring(1, 4);
                rightPos = rightCommandBuffer.toInt();
            }
        }
        
        leftServo.write(leftPos);
        rightServo.write(rightPos);
    }
}

