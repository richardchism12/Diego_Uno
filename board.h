/***********************************************************************************************************
/*
/*	This is the main program for Auduino Uno controller for the Diego robot.  
/*		Basic functionality of the robot include 4 motor control 
/*		Articulating head unit with 2 servos
/*		Front and back ultrasonic detector
/*
/*		Written by Rich Chism
/*		Ardesea Group
/*
/*		Revion 1.00 		Original Release
/*
/***********************************************************************************************************/

/*  Board Specifications
/*	14 Digital IO Points (6 PWM Ouptuts)
/*  6 Analog Input Pins
/*  Flash Memory 32K  .5K bootloader
/*  SRAM 2KB
/*  EEPROM 1KB
/*  Clock Speed 16 Hz

/*  Below is a list of pinouts for the Uno Board
/*  Pin 1  - PC6  /RESET, PCINT14 
/*  Pin 2  - PD0  RXD, PCINT16  Connected to USB Port
/*  Pin 3  - PD1	 TXD, PCINT17  Connected to USB Port
/*  Pin 4  - PD2  Digital IO 2, INT0, PCINT18
/*  Pin 5  - PD3  Digital IO 3 (PWM), INT1, PCINT19, OC2B
/*  Pin 6  - PD4  Digital IO 4, T0 PCINT20, XCK
/*  Pin 7  - PD5  Digital IO 5, T1 PCINT21 OC0B
/*  Pin 8  - PD6  Digital IO 6
/*  Pin 9  - PD7  Digital IO 7
/*  Pin 10 - PD7  Digital IO 8
/*  Pin 11 - PD7  Digital IO 9
/*  Pin 12 - PD7  Digital IO 10
/*  Pin 13 - PD7  Digital IO 11
/*  Pin 14 - PD7  Digital IO 12
/*  Pin 15 - PD7  Digital IO 13
/*  Pin 16
/*  Pin 17
/*  Pin 18
/*  Pin 19
/*  Pin 20
/*  Pin 21
/*  Pin 22
/*  Pin 23
/*  Pin 24
/*  Pin 25
/*  Pin 26- 
/*  Pin 27 - PC4 Analog Input "A4", ADC4
/*  Pin 28 - PC5 Analog Input "A5", ADC5, PCINT13, SCL */

#define TRUE 1
#define FALSE 0


// Tracks Drive System

// Motor 1 (CH1)
#define DIR1 29 // motor 1  Direction
#define PwM1 12 // Motor 1  Speed
#define MCR1  14 // Motor 1 Current

// Motor 2 (CH2)
#define DIR2 28 // Motor 2 Direction  
#define PwM2 11 // Motor 2 Speed
#define MCR2 11 // Motor 2 Current 

// Motor 3
#define DIR3 27 // motor 3   
#define PwM3 10
#define MCR3 10 // Motor 3 Current

// Motor 4
#define DIR4 26 // motor 4
#define PwM4 9
#define MCR3 10 // Motor 3 Current

// Head Unit System

// Head Rotation
#define PWM5 11 // Rotational Servo Control

// Head Up / Down
#define PWM6 12 // Head Up and Down Motion

// Sonic XMTR System

#define Head_Sonic_XMTR 2 //Pivot Head Ultra Sonic Detector
#define Fron_Sonic_XMTR 23 //Front Ultra Sonic Detector

// PIR Detector2
#define PIR_1 13 //  Front 135 degrees
#define PIR_2 14 //  Left rear 135 degrees
#define PIR_3 15 //  Right rear 135 degrees

// Motor Power Management Relay
#define MP_Rly 12

// PI Power Management Relay
#define PI_Rly 12

// Temp Sensor
#define Temp_AnalogIn 14

//Light IR Detector
#define IR Detector 15
