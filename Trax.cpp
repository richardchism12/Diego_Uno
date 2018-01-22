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

// Include files
#include "Arduino.h"
#include "board.h"
#include "Trax.h"


Trax::Trax(){
  
}

/***********************************************************************************************************
/*  Initialize Trax IO
/*  Inputs - None
/*  Output - None
/***********************************************************************************************************/

void Trax::Init()
{
  pinMode( DIR1, OUTPUT);
  pinMode( PwM1, OUTPUT);
  //pinMode( PwMa1, ANALOGIN);
  pinMode( DIR2, OUTPUT);
  pinMode( PwM2, OUTPUT);
  //pinMode( PwMa1, ANALOGIN);
  pinMode( DIR3, OUTPUT);
  pinMode( PwM3, OUTPUT);
  //pinMode( PwMa1, ANALOGIN);
  pinMode( DIR4, OUTPUT);
  pinMode( PwM4, OUTPUT);   
  //pinMode( PwMa1, ANALOGIN);  
//  mspeed = 75;                 
 }
 
/***********************************************************************************************************
/*  Forward Trax Function
/*  Inputs - Motor_Speed
/*  Output - None
/***********************************************************************************************************/

void Trax::forward(int Motor_Speed){
  digitalWrite(DIR1, LOW);        		//back left 
  analogWrite(PwM1, Motor_Speed);      	//back left
  digitalWrite(DIR3, LOW);        		//front left
  analogWrite(PwM3, Motor_Speed);      	//front left
  digitalWrite(DIR2, LOW);        		//back right
  analogWrite(PwM2, Motor_Speed);      	//back right
  digitalWrite(DIR4, HIGH);		  		//front left
  analogWrite(PwM4, Motor_Speed);	  	//front left
}

 
/***********************************************************************************************************
/*  Backward Trax Function
/*  Inputs - Motor_Speed
/*  Output - None
/***********************************************************************************************************/

void Trax::backward(int Motor_Speed){
  digitalWrite(DIR1, HIGH);       		//back left 
  analogWrite(PwM1, Motor_Speed);      	//back left 
  digitalWrite(DIR3, HIGH);       		//front left 
  analogWrite(PwM3, Motor_Speed);      	//front left
  digitalWrite(DIR2, HIGH);       		//back right
  analogWrite(PwM2,Motor_Speed);       	//back right
  digitalWrite(DIR4, LOW);		  		//front left
  analogWrite(PwM4, Motor_Speed);	  	//front left
}


/***********************************************************************************************************
/*  Left Trax Function
/*  Inputs - Motor_Speed
/*  Output - None
/***********************************************************************************************************/

void Trax::left(int Motor_Speed){
  digitalWrite(DIR1, LOW);     			//back left direction
  analogWrite(PwM1, Motor_Speed);       //back left motor speed
  digitalWrite(DIR3, LOW);      		//front left direction
  analogWrite(PwM3, Motor_Speed);       //front left motor speed
  digitalWrite(DIR2, HIGH);     		//back right direction
  analogWrite(PwM2,Motor_Speed);        //back right motor speed
  digitalWrite(DIR4, LOW);      		//front left direction 
  analogWrite(PwM4, Motor_Speed);       //front left speed
}

/***********************************************************************************************************
/*  Right Trax Function
/*  Inputs - Motor_Speed
/*  Output - None
/***********************************************************************************************************/

void Trax::right(int Motor_Speed){
  digitalWrite(DIR1, HIGH);       		//back left direction
  analogWrite(PwM1, Motor_Speed);       //back left motor speed
  digitalWrite(DIR3, HIGH);       		//front left direction
  analogWrite(PwM3, Motor_Speed);       //front left motor speed
  digitalWrite(DIR2, LOW);       		//back right direction
  analogWrite(PwM2,Motor_Speed);        //back right motor speed
  digitalWrite(DIR4, HIGH);      		//front left direction 
  analogWrite(PwM4, Motor_Speed);       //front left speed
}


/***********************************************************************************************************
/*  Stop Trax Function
/*  Inputs - Motor_Speed
/*  Output - None
/***********************************************************************************************************/


void Trax::Stop(){
  analogWrite(PwM1, 0);					//back left motor speed	        
  analogWrite(PwM3, 0);        			//front left motor speed
  analogWrite(PwM2,0);        			//back right motor speed
  analogWrite(PwM4, 0);					//front left motor speed
}

