#include "Servo.h"
#include "Arduino.h"

//Implementation of Servo class

Servo1::Servo1(int pin)
{
  motorControlPin = pin;
  pinMode(motorControlPin, OUTPUT);   //It states the pin is an output, meaning it gives values to the motor    
}

bool Servo1::run()
{
  if(canRun == true){
     int sensorValue = analogRead(A1);
  float speed2 = (sensorValue*255.0)/1023.0;
 // Serial.println(speed2);                                                     
  analogWrite(motorControlPin, speed2);
    };
    
  
  return true;
}
