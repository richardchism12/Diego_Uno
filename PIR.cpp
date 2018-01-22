
#include "Arduino.h"
#include "board.h"
#include "PIR.h"

/*
 * PIR sensor tester
 */
#define LOW 0
#define HIGH 1

int ledPin = 13;                // choose the pin for the LED
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

PIR::PIR(int pin){
    pinMode(pin, INPUT);
    _pin = pin;
  
}
 
void PIR::Init() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(_pin, INPUT);     // declare sensor as input
}
 
void PIR::Get(){
  val = digitalRead(_pin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}

