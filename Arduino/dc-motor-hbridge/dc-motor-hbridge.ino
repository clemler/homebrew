//dc-motor-hbridge.ino
//
// This sketch uses an SN754410 H-Bridge to control the direction of two DC
// motors. There is a digital switch attached to Pin 2 (toggelDirectionPin),
// which is used to toggle the direction of the motor. There are two motors
// in my prototype, but you can easily comment out Motor2 if you are only
// using a single motor.
//
// @Todo: I still need to enable PWM on the motor1EnablePin to control the motor
// speed. In future versions

const int toggleDirectionPin = 2;       // Toggle based on switch input
const int motor1EnablePin = 9;          // H-Bridge pin 1 (1,2EN)
const int motor2EnablePin = 10;          // H-Bridge pin 9 (3,4EN)

// Motor 1 (Right Motor)
const int motor1hbridge2Pin = 3;        // H-Bridge pin 2 (1A)
const int motor1hbridge7Pin = 4;        // H-Bridge pin 7 (2A)

// Motor 2 (Right Motor)
const int motor2hbridge10Pin = 6;        // H-Bridge pin 10 (3A)
const int motor2hbridge15Pin = 7;        // H-Bridge pin 15 (4A)



void setup() {
    // Set the toggle switch as an input
    pinMode(toggleDirectionPin, INPUT);

    // Set all other pins as outputs
    pinMode(motor1hbridge2Pin, OUTPUT);
    pinMode(motor1hbridge7Pin, OUTPUT);
    pinMode(motor1EnablePin, OUTPUT);
    pinMode(motor2hbridge10Pin, OUTPUT);
    pinMode(motor2hbridge15Pin, OUTPUT);
    pinMode(motor2EnablePin, OUTPUT);

    // Set the motor*EnablePins to HIGH so the motors will turn on
    digitalWrite(motor1EnablePin, HIGH);
    digitalWrite(motor2EnablePin, HIGH);
}


void loop() {
    // If the switch (toggleDirectionPin) is HIGH. the motor will turn
    // in one direction
    if ( digitalRead(toggleDirectionPin) == HIGH) {
        digitalWrite(motor1hbridge2Pin, LOW);   // Set leg 1 of the H-Bridge to LOW
        digitalWrite(motor1hbridge7Pin, HIGH);   // Set leg 2 of the H-Bridge to HIGH
        digitalWrite(motor2hbridge10Pin, LOW);   // Set leg 1 of the H-Bridge to LOW
        digitalWrite(motor2hbridge15Pin, HIGH);   // Set leg 2 of the H-Bridge to HIGH
    }
    else {  // Switch LOW, turn the other direction
        digitalWrite(motor1hbridge2Pin, HIGH);   // Set leg 1 of the H-Bridge to HIGH
        digitalWrite(motor1hbridge7Pin, LOW);   // Set leg 2 of the H-Bridge to LOW
        digitalWrite(motor2hbridge10Pin, HIGH);   // Set leg 1 of the H-Bridge to HIGH
        digitalWrite(motor2hbridge15Pin, LOW);   // Set leg 2 of the H-Bridge to LOW
    }
}
