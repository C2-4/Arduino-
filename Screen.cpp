#include "Screen.h"


//Implementation of Blinker class

Screen::Screen()
{
  lcd = new LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);    //Activates lcd 
  lcd->begin(16,2);         //Screen dimensions
  lcd->backlight();       //Power on the back light
}

bool Screen::run()        //INherance
{
 
  return true;        //This does not have to be here but needs to be in the header file
}

  void Screen::ScreenWriting(String input, String input2){ //This is two strings sent from pot
  lcd->clear();     //Clears lcd screen
  lcd->setCursor(0,0);      //Set cursor for first string
  lcd->print(input);      //Plots first string

  lcd->setCursor(11,0);     //Sets cursor for second string
  lcd->print(input2);       //Plots second string
    };
