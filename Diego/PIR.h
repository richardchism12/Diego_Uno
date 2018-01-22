/***********************************************************************************************************
/*
/*	This is the PIR Interface for Auduino Uno controller for the Diego robot.  
/*
/*
/*		Written by Rich Chism
/*		Ardesea Group
/*
/*		Revion 1.00 		Original Release
/*
/***********************************************************************************************************/

#ifndef PIR_h
#define PIR_h
 
//#define LOW 0
//#define HIGH 1

//int ledPin = 13;                // choose the pin for the LED
//int pirState = LOW;             // we start, assuming no motion detected
//int val = 0;                    // variable for reading the pin status
 
 /***********************************************************************************************************
/*  Init_PIR
/*  Inputs - Pointer To Input Pin
/*  Output - None
/***********************************************************************************************************/

class PIR{
  public:
    PIR(int pin);
    void Init();  
    void Get();

  private:
    int _pin;
};

#endif
