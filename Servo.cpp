#include "Servo.h"
#include "Arduino.h"

//Implementation of Servo class

Servo1::Servo1(int pin)
{
  motorControlPin = pin;
  pinMode(motorControlPin, OUTPUT);   //It states the pin is an output, meaning it gives values to the motor    
}

bool Servo1::run()       //Inherance
{
  if(canRun == true){      //This is true look in header
     int sensorValue = analogRead(A1);      //States that it should get value from A1
  float speed2 = (sensorValue*255.0)/1023.0; // This is not nessesary                                          
  analogWrite(motorControlPin, speed2);       //Same with this
    };
    
  
  return true;        //It is a bool function
}
