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