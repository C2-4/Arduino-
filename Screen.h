#ifndef SCREEN_H
#define SCREEN_H

#include "Arduino.h"
#include "Task.h"
#include <LiquidCrystal_I2C.h> //Communication with lcd



class Screen : public Task
{
public:
  Screen();
  virtual bool run(); //Overriding run method from TimedTask
  void ScreenWriting(String, String);

private:
  //i2c pins
  LiquidCrystal_I2C* lcd;
};

#endif
