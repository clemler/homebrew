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

const int togglePin = 2;                // Toggle based on switch input
const int motor1EnablePin = 9;          // H-Bridge pin 1 (1,2EN)
const int motor2EnablePin = 10;          // H-Bridge pin 9 (3,4EN)

// Motor 1 (Right Motor)
const int motor1hbridge2Pin = 3;        // H-Bridge pin 2 (1A)
const int motor1hbridge7Pin = 4;        // H-Bridge pin 7 (2A)

// Motor 2 (Right Motor)
const int motor2hbridge10Pin = 6;        // H-Bridge pin 10 (3A)
const int motor2hbridge15Pin = 7;        // H-Bridge pin 15 (4A)

int motorState = 0;                      // 0 = off, 1 = fwd, 2 = rev
int buttonState;                         // the current reading from the input pin
int lastButtonState = LOW;               // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
    // Setup so we can log messages
    Serial.begin(9600);

    // Set the toggle switch as an input
    pinMode(togglePin, INPUT);

    // Set all other pins as outputs
    pinMode(motor1hbridge2Pin, OUTPUT);
    pinMode(motor1hbridge7Pin, OUTPUT);
    pinMode(motor1EnablePin, OUTPUT);
    pinMode(motor2hbridge10Pin, OUTPUT);
    pinMode(motor2hbridge15Pin, OUTPUT);
    pinMode(motor2EnablePin, OUTPUT);

    // Set the motor*EnablePins to LOW so they are initially off
    digitalWrite(motor1EnablePin, LOW);
    digitalWrite(motor2EnablePin, LOW);
}

// Set the motor*EnablePins to HIGH so the motors will turn on
void turnMotorsOn() {
    digitalWrite(motor1EnablePin, HIGH);
    digitalWrite(motor2EnablePin, HIGH);
}

// Set the motor*EnablePins to LOW so the motors will turn off
void turnMotorsOff() {
    digitalWrite(motor1EnablePin, LOW);
    digitalWrite(motor2EnablePin, LOW);
}


void loop() {
    // read the state of the switch into a local variable:
    int reading = digitalRead(togglePin);

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH),  and you've waited
    // long enough since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:

        // if the button state has changed:
        if (reading != buttonState) {
            buttonState = reading;

            // only toggle the LED if the new button state is HIGH
            if (buttonState == HIGH) {
                motorState = (motorState + 1) % 3;
                Serial.print("Motor State: ");
                Serial.println(motorState);
            }
        }
    }

    switch (motorState) {
        case 0:
            turnMotorsOff();
            break;
        case 1:
            turnMotorsOn();
            digitalWrite(motor1hbridge2Pin, HIGH);   // Set leg 1 of the H-Bridge to HIGH
            digitalWrite(motor1hbridge7Pin, LOW);   // Set leg 2 of the H-Bridge to LOW
            digitalWrite(motor2hbridge10Pin, HIGH);   // Set leg 1 of the H-Bridge to HIGH
            digitalWrite(motor2hbridge15Pin, LOW);   // Set leg 2 of the H-Bridge to LOW
            break;
        case 2:
            turnMotorsOn();
            digitalWrite(motor1hbridge2Pin, LOW);   // Set leg 1 of the H-Bridge to LOW
            digitalWrite(motor1hbridge7Pin, HIGH);   // Set leg 2 of the H-Bridge to HIGH
            digitalWrite(motor2hbridge10Pin, LOW);   // Set leg 1 of the H-Bridge to LOW
            digitalWrite(motor2hbridge15Pin, HIGH);   // Set leg 2 of the H-Bridge to HIGH
            break;
        default:
            break;
    }

    // save the reading.  Next time through the loop,
    // it'll be the lastButtonState:
    lastButtonState = reading;
}
