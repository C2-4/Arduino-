#ifndef SERVO_H
#define SERVO_H

#include "Task.h"
#include "Arduino.h"



class Servo1 : public Task
{
public:
  Servo1(int);
  virtual bool run();

  int motorControlPin;    //Assigns pin 9 to control the dc motor
  bool canRun = true;
  
};

#endif
