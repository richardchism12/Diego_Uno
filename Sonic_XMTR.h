/***********************************************************************************************************
/*
/*	Ultra Sonic XMTR Program for Auduino Uno controller for the Diego robot.  
/*		Front and back ultrasonic detector Source
/*
/*		Written by Rich Chism
/*		Ardesea Group
/*
/*		Revion 1.00 		Original Release
/*
/***********************************************************************************************************/

#include "Arduino.h"
#include "board.h"

#ifndef Sonic_XMTR_h
#define Sonic_XMTR_h


/*
 HC-SR04 Ping distance sensor
 VCC to arduino 5v 
 GND to arduino GND
 Echo and Trig tied together for a single processor pin
 
You only need to supply a short 10uS
pulse to the trigger input to start the ranging, and then the module will send out
an 8 cycle burst of ultrasound at 40 kHz and raise its echo. The Echo is a
distance object that is pulse width and the range in proportion .You can
calculate the range through the time interval between sending trigger signal and
receiving echo signal. Formula: uS / 58 = centimeters or uS / 148 =inch; or: the
range = high level time * velocity (340M/S) / 2; we suggest to use over 60ms
measurement cycle, in order to prevent trigger signal to the echo signal. 
 */
class Sonic_XMTR {
   public:
     Sonic_XMTR(int pin);
     void Get_Distance();   

   private:
     int trigPin;
     int echoPin;
};



#endif

