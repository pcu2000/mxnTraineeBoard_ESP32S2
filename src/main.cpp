#include <Arduino.h>
#include <mxnFeatherBoard.h>


uint8_t   state         = 0;
uint16_t  numberDisplay = 0;
uint8_t   ledPoint        = 1;
bool      ledPointDirection = 0;

void showLEDBar();
void showKnightRider();
void switchToLed();
void printNumber(uint16_t numberToPrint);

void setup() {
  // sets the digital pins for LED's as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  // sets the digital pins for switch's as input
  pinMode(SWITCH1, INPUT);
  pinMode(SWITCH2, INPUT);
  pinMode(SWITCH3, INPUT);

  // sets the digital pins for 7-Segment Display's as output
  pinMode(SegmentBitA, OUTPUT);
  pinMode(SegmentBitB, OUTPUT);
  pinMode(SegmentBitC, OUTPUT);
  pinMode(SegmentBitD, OUTPUT);
  pinMode(SegmentLD1, OUTPUT);    // read enable for 10er
  pinMode(SegmentLD2, OUTPUT);    // read enable for 1er
  pinMode(SegmentCC, OUTPUT);     // enapble the power for 7-Segment Display
  
  // sets the digital pin for the Power of 7-Segment Display ON
  digitalWrite(SegmentCC, HIGH);

}

void loop() {

  //switchToLed();

  //check the state of switches
  state = !digitalRead(SWITCH1) + (!digitalRead(SWITCH2) * 2) +  (!digitalRead(SWITCH3) * 4);


  switch(state){
    case 0:
      showLEDBar();
      break;
    case 1:  
      printNumber(numberDisplay);
      delay(100);
      if(numberDisplay <99){
        numberDisplay++;
      }else{
        numberDisplay = 0;
      }
      break;
    case 2:   
      showKnightRider();
      break;
  }

}

void showLEDBar(){
  digitalWrite(LED1, HIGH); // sets the LED1 on
  delay(100);            // waits for 0.1s
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED3, HIGH);
  delay(100);
  digitalWrite(LED4, HIGH);
  delay(100);
  digitalWrite(LED5, HIGH);
  delay(100);
  digitalWrite(LED6, HIGH);
  delay(100);
  digitalWrite(LED7, HIGH);
  delay(100);
  digitalWrite(LED8, HIGH);

  delay(500);            // waits for a half second

  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED4, LOW);
  delay(100);
  digitalWrite(LED5, LOW);
  delay(100);
  digitalWrite(LED6, LOW);
  delay(100);
  digitalWrite(LED7, LOW);
  delay(100);
  digitalWrite(LED8, LOW);

  delay(500);            // waits for a half second
}

void showKnightRider(){
  digitalWrite(LED1, (ledPoint & BIT0));
  digitalWrite(LED2, (ledPoint & BIT1));
  digitalWrite(LED3, (ledPoint & BIT2));
  digitalWrite(LED4, (ledPoint & BIT3));
  digitalWrite(LED5, (ledPoint & BIT4));
  digitalWrite(LED6, (ledPoint & BIT5));
  digitalWrite(LED7, (ledPoint & BIT6));
  digitalWrite(LED8, (ledPoint & BIT7));

  if(ledPoint == 0b10000000){
    ledPointDirection = 0;
  }else if(ledPoint == 0b00000001){
    ledPointDirection = 1;
  }

  if(ledPointDirection){
    ledPoint = ledPoint << 1;
  }else{
    ledPoint = ledPoint >> 1;
  }
  delay(100);  
}

void switchToLed(){
  if(digitalRead(SWITCH1)==1){
    digitalWrite(LED1, HIGH);
  }else{
    digitalWrite(LED1, LOW);
  }
  if(digitalRead(SWITCH2)==1){
    digitalWrite(LED2, HIGH);
  }else{
    digitalWrite(LED2, LOW);
  }
  if(digitalRead(SWITCH3)==1){
    digitalWrite(LED3, HIGH);
  }else{
    digitalWrite(LED3, LOW);
  }
}


void printNumber(uint16_t numberToPrint){
  uint16_t numberToPrint10er = numberToPrint / 10;
  uint16_t numberToPrint1er = numberToPrint % 10;
  digitalWrite(SegmentLD1, HIGH);
  digitalWrite(SegmentBitA, (numberToPrint10er & BIT0));
  digitalWrite(SegmentBitB, (numberToPrint10er & BIT1));
  digitalWrite(SegmentBitC, (numberToPrint10er & BIT2));
  digitalWrite(SegmentBitD, (numberToPrint10er & BIT3));
  digitalWrite(SegmentLD1, LOW);
  
  digitalWrite(SegmentLD2, HIGH);
  digitalWrite(SegmentBitA, (numberToPrint1er & BIT0));
  digitalWrite(SegmentBitB, (numberToPrint1er & BIT1));
  digitalWrite(SegmentBitC, (numberToPrint1er & BIT2));
  digitalWrite(SegmentBitD, (numberToPrint1er & BIT3));
  digitalWrite(SegmentLD2, LOW);
}