//dc-motor-hbridge.ino
//
// This sketch uses an SN754410 H-Bridge to control the direction of a DC
// motor. There is a digital switch attached to Pin 2 (toggelDirectionPin),
// which is used to toggle the direction of the motor. In future versions
// there will be a second motor, hence the naming conventions (motor1...).

const int toggleDirectionPin = 2;       // Toggle based on switch input
const int motor1hbridge2Pin = 3;        // H-Bridge pin 2 (1A)
const int motor1hbridge7Pin = 4;        // H-Bridge pin 7 (2A)
const int motor1EnablePin = 9;          // H-Bridge pin 1 (1,2EN)


void setup() {
    // Set the toggle switch as an input
    pinMode(toggleDirectionPin, INPUT);

    // Set all other pins as outputs
    pinMode(motor1hbridge2Pin, OUTPUT);
    pinMode(motor1hbridge7Pin, OUTPUT);
    pinMode(motor1EnablePin, OUTPUT);

    // Set the motor1EnablePin to HIGH so the motor will turn on
    digitalWrite(motor1EnablePin, HIGH);
}


void loop() {
    // If the switch (toggleDirectionPin) is HIGH. the motor will turn
    // in one direction
    if ( digitalRead(toggleDirectionPin) == HIGH) {
        digitalWrite(motor1hbridge2Pin, LOW);   // Set leg 1 of the H-Bridge to LOW
        digitalWrite(motor1hbridge7Pin, HIGH);   // Set leg 2 of the H-Bridge to HIGH
    }
    else {  // Switch LOW, turn the other direction
        digitalWrite(motor1hbridge2Pin, HIGH);   // Set leg 1 of the H-Bridge to HIGH
        digitalWrite(motor1hbridge7Pin, LOW);   // Set leg 2 of the H-Bridge to LOW
    }
}
