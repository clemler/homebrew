/**
 * Reads whether a button is pressed using digitalRead to monitor pin 2
 *
 * Based largely on the Arduino DigitalReadSerial example
 */

int button = 2;


/*
 * Initialize serial communication, and set pin 2 to
 * INPUT mode
 */
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
}

/*
 * Read the button (pin 2) state and log a message to the
 * serial console
 */
void loop() {
  int buttonState = digitalRead(button);
  Serial.println(buttonState);
  
  // Delay between reads for stability
  delay(1);
}
