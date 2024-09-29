#include <Arduino.h>
#include <mxnFeatherBoard.h>


void setup() {
  pinMode(LED1, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED2, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED3, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED4, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED5, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED6, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED7, OUTPUT);    // sets the digital pin 13 as output
  pinMode(LED8, OUTPUT);    // sets the digital pin 13 as output
}

void loop() {
      digitalWrite(LED1, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED2, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED3, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED4, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED5, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED6, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED7, HIGH); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED8, HIGH); // sets the digital pin 13 on

      delay(500);            // waits for a second

      digitalWrite(LED1, LOW);  // sets the digital pin 13 off
      delay(100);            // waits for a second
      digitalWrite(LED2, LOW); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED3, LOW); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED4, LOW); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED5, LOW);  // sets the digital pin 13 off
      delay(100);            // waits for a second
      digitalWrite(LED6, LOW); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED7, LOW); // sets the digital pin 13 on
      delay(100);            // waits for a second
      digitalWrite(LED8, LOW); // sets the digital pin 13 on

      delay(500);            // waits for a second
}
