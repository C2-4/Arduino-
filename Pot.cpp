#include "Pot.h"
#include "Arduino.h"

Pot::Pot(uint8_t _pin, Screen* ScreenPointer) : pin(_pin)
{
  skearm = ScreenPointer;
  pinMode(pin, INPUT);
 
}
  
bool Pot::run(){        //Inherance
  if (cycles < 15)        //Numbers of times the statement should be run
  {
    cycles++;     //You know this
    int tempVerdi = analogRead(pin);    //Feeds the analogread in tempverdi

    float voltage = tempVerdi * (5.0 / 1023.0) * 50;      //Converts analogread to voltages
    totalWatt += voltage;               //Saves voltage inside totalwatts every second

  
    skearm->ScreenWriting(String(voltage), "Watts");  //gives a string to screenwriting
  }
  else
  {
    skearm->ScreenWriting(String(totalWatt), "Total");      //Gives a string to screenwriting
    String dataToPC = "#" + String(totalWatt) + "!";        //This is to sent data to QT program (STL)
    delay(5000);          //Makes sure that the data on the totalwatts stays on the lcd for 5 sec
    cycles = 0;   //You know this
    totalWatt = 0;      //Same
  }
 
}
