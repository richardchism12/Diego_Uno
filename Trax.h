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



class Trax{
  public:
    Trax();
    void Init();
    void forward(int Motor_Speed);
    void backward(int Motor_Speed);
    void left(int Motor_Speed);
    void right(int Motor_Speed);
    void Stop();

    
  
  private:
   // int Motor_Speed;
  
};
