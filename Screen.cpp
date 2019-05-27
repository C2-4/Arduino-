#include "Screen.h"


//Implementation of Blinker class

Screen::Screen()
{
  lcd = new LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  lcd->begin(16,2);
  lcd->backlight();//Power on the back light
}

bool Screen::run()
{
 
  return true;
}

  void Screen::ScreenWriting(String input, String input2){
  lcd->clear();     
  lcd->setCursor(0,0);
  lcd->print(input);

  lcd->setCursor(11,0);
  lcd->print(input2);
    };
