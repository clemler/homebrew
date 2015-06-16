// Servo
// Sample sketch to control a basic servo. This is derived from the Arduino Sweep tutorial
//http://www.arduino.cc/en/Tutorial/Sweep
//

#include <Servo.h>

Servo myservo;     // The Servo object which will control the device
int pos = 0;       // Current servo position
int servoPin = 9;  // The servo will be controlled via pin 9

void setup() {
  myservo.attach(servoPin);
}


// The Micro Servo 9g A0090 only has about ~160 degrees of movement when the servo
// is positioned to '180'. Through trial and error I found that position '120' was
// more or less the 90 degree position.
//
void loop() {
  //for (pos = 0; pos < 180; pos +=10) {
  //  myservo.write(pos);  // Tell servo to move to the position 'pos'
  //  delay(100);          // Wait 100ms for the servo to reach the position
  //}
  
  //for (pos = 180; pos >= 1; pos -= 1) {
  //  myservo.write(pos);  // Tell servo to move to the position 'pos'
  //  delay(20);          // Wait 20ms for the servo to reach the position
  //}
  myservo.write(0);  // Tell servo to move to the position 'pos'
  delay(1000);          // Wait 20ms for the servo to reach the position
  myservo.write(120);
  delay(1000);
  myservo.write(179);
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo.write(120);
  delay(5000);
}
