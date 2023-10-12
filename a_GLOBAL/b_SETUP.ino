// setup function

void setup() {
    Serial.begin(BAUDRATE);
    Serial.setTimeout(MYTIMEOUT); //! interval between reading strings

    leftServo.attach(LSERVOPIN);
    rightServo.attach(RSERVOPIN);

    // initial position of the servos
    leftServo.write(90);
    rightServo.write(90);
    delay(WAITFORINITSERVO);

    //! make more efficient tests!
    // test phase
    // testLeftServo();
    // delay(500);
    // testRightServo();
    // delay(500);
    // testBothServos();
    // delay(500);
    // leftServo.write(0);
    // rightServo.write(0);
    // delay(WAITFORINITSERVO);   
}