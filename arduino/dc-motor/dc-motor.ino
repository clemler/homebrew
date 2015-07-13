// Sample DC motor sketch based on the adafruit tutorials:
// https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors?view=all
//

int motorPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}

void loop() {
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
}
