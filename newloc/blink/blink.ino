int redPin = 13;    // Red LED connected to pin 13
int yellowPin = 12; // Yellow LED on pin 12

void setup() {
  pinMode(redPin, OUTPUT);  // Sets the digital pin as OUTPUT
  pinMode(yellowPin, OUTPUT);  // Sets the digital pin as OUTPUT
}


void loop() {
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  delay(900);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(900);
}
