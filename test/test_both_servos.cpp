void testBothServos() {
    leftServo.write(0);
    rightServo.write(0);
    for (int i = 0; i <= 180; i++) {
        leftServo.write(i);
        rightServo.write(i);
        delay(WAITSERVO);
    }
}