#include <SoftwareSerial.h>
#include <Servo.h>

#include "Trax.h"
#include "board.h"
#include "PIR.h"
#include "Sonic_XMTR.h"
#include "CMD_Interface.h"

Servo SonarServo;


const int pingPin = 10;
const int SafeDist = 20;              //cm

int ServoAngle1[] = {
  1250,1500,1800, 2000};          //define angles in microseconds for object avoidance sweep
int ServoAngle2[] = {
  0,45,90,135,180,135,90,45,0};       //define angles for distance sweep 
int MyArray1[9] = {
  0};                                 //distance values saved into array

Trax trax;
CMD_Interface cmd_Interface;
PIR pir(13);
Sonic_XMTR sonic_xmtr(12);

int mspeed;
int i;
int q;

int slow = 50;

long duration, inches, cm, m;

void setup()
{
  cmd_Interface.Init();
  trax.Init();
  pir.Init();
  mspeed = 75;                 //motor speed
  SonarServo.attach(Head_Sonic_XMTR);         
  delay(5000);
  cmd_Interface.Serial_Main_Menu_Init();
}

void loop(){                        //sends rover5 forward whilst performaing object avoidance sweep 

  cmd_Interface.Serial_Main_Menu();

  pir.Get();
  delay(50);                                      //allow servo to reach position
  SonarScan();                                     //scan for objects
  Serial.print(cm);
  Serial.print("cm   \r");
  delay(300);                                      //wait a bit more
  Serial.print("                \r");
/*   Serial.print("motor forward");
  trax.forward(slow);
  

  for(int x = 0; x < 4; x++){                          
    SonarServo.writeMicroseconds(ServoAngle1[x]);    // write servo in microseconds through angles in array
    Serial.print(ServoAngle1[x]);
    Serial.print(" Degrees-");
    delay(250);                                      //allow servo to reach position
    SonarScan();                                     //scan for objects
    Serial.print(cm);
    Serial.print("cm   ");
    delay(200);                                      //wait a bit more
    if (cm < SafeDist && cm > 0){                    //min sensor range is 3cm however a bad reading of 0cm is sometimes recorded 
      Serial.println("stop!");
      trax.Stop();
      trax.backward(slow);
      delay(500);
      trax.Stop();
      DistanceSweep();                              //scan and determine best direction to travel next
    }
  }
  */
}

void POST(){

  
}

void DistanceSweep(){

  for(int a = 0; a < 8; a++){             
    SonarServo.write(ServoAngle2[a]);     //Write servo through values saved in array
    delay(300);                           //give servo enough time to reach position
    SonarScan();                          //scan for distance measurements
    delay(300);                           //wait long enough for sound to return before moving to next position
    MyArray1[a] = cm;                     //save reading to array
  }

  q = getIndexOfMaximumValue(MyArray1, 9);        //prints maximum distance and index in array
  Serial.print("max distance is at index --");
  Serial.print(q);
  Serial.print(" with value of - ");
  Serial.println(MyArray1[q]);
  Serial.println(" ");

  if (q == 0){                          //Still pretty rough!
    trax.right(slow);                             
    Serial.println("full right");
    delay(2000);
  }
  else if (q== 1){
    trax.right(slow);
    Serial.println("Partial right");
    delay(1000);
  }
  else if (q == 2){
    Serial.println("straight ahead");
    loop();
  }
  else if (q== 3){
    trax.left(slow);
    Serial.println("Partial left");
    delay(1000);
  }
  else if (q==4){
    trax.left(slow);
    Serial.println("Full left");
    delay(2000);
  }
  else if (q == 5){
    trax.right(slow);
    Serial.println("Full right");
    delay(2000);
  }
  else if (q== 6){
    trax.right(slow);
    Serial.println("Partial right");
    delay(1000);
  }
  else if (q == 7){
    loop();
    Serial.println("straight");
  }
  else if (q== 8){
    trax.left(slow);
    Serial.println("Partial left");
    delay(1000);
  }
}

void SonarScan()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

int getIndexOfMaximumValue(int* array, int size){              //determines the maximum value of an array and its index value 
  int maxIndex = 0;
  int max = array[maxIndex];
  for (int i=1; i<size; i++){
    if (max<array[i]){
      max = array[i];
      maxIndex = i;
    }
  }
  return maxIndex;
} 
