#include "Pot.h"
#include "Arduino.h"

Pot::Pot(uint8_t _pin, Screen* ScreenPointer) : pin(_pin)
{
  skearm = ScreenPointer;
  pinMode(pin, INPUT);
 
}
  
bool Pot::run(){
  if (cycles < 15)
  {
    cycles++;
    int tempVerdi = analogRead(pin);

    float voltage = tempVerdi * (5.0 / 1023.0) * 50;
    totalWatt += voltage;

  
    skearm->ScreenWriting(String(voltage), "Watts");
  }
  else
  {
    skearm->ScreenWriting(String(totalWatt), "Total");
  }
}
