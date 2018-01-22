
/*
 * Hello World!
 *
 * This is the Hello World! for Arduino. 
 * It shows how to send data to the computer
 */
//#include <SoftwareSerial.h>
#include "Arduino.h"
#include "CMD_Interface.h"

void CMD_Interface::Init()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
}

void CMD_Interface::Serial_Main_Menu_Init()
{
  Serial.println("Welcome to Diego low level command interface!");  // prints hello with ending line break 
  Serial.println("Control Interface Version 1.001");  // prints hello with ending line break 
  Serial.println("Copyright Ardesea group 2018");  // prints hello with ending line break 
  Serial.println("\r");  // prints hello with ending line break 
  Serial.println("Press 'S' for servo control and diagnostics");  // prints hello with ending line break 
  Serial.println("Press 'F' for front ultrasonic sensor");  // prints hello with ending line break 
  Serial.println("Press 'H' for head servo control");  // prints hello with ending line break 
  Serial.println("Press 'D' for HID Sensor");  // prints hello with ending line break 
  Serial.println("\r");  // prints hello with ending line break 
  Serial.println("\r");  // prints hello with ending line break 
  Serial.println("Press 'X' To exit the control interface and return to normal operation");  // prints hello with ending line break 
}


void CMD_Interface::Serial_Main_Menu()                       // run over and over again
{
  if (Serial.available()) {
    rx_byte = Serial.read();        // do nothing!
 }
 switch(rx_byte){
    case 'S':
      Serial.println("Servo Control and Diagnostics");
      rx_byte = 0;
    break;
    case 'F':
      Serial.println("Front Ultrasonic Sensor");
      rx_byte = 0;
    break;
    case 'H':
      Serial.println("Front Ultrasonic Sensor");
      rx_byte = 0;
    break;
     case 'D':
      Serial.println("Front Ultrasonic Sensor");
      rx_byte = 0;
    break;
    default:
    rx_byte = 0;
      break;
 } 
}
