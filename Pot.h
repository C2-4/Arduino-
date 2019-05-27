#include "Arduino.h"
#include "Task.h"
#include "Screen.h"

#ifndef POT_H
#define POT_H

class Pot : public Task
{
  public:
  uint8_t pin;
  virtual bool run();
  Pot(uint8_t, Screen*);

  private:
  Screen *skearm;
  float totalWatt = 0;
  int cycles = 0;
  
  };

#endif
