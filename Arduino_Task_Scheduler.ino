#include "Scheduler.h"    //Takes care of everything
#include "Servo.h"  // Takes care of servo 
#include "Screen.h"  //Takes care of lcd
#include "Pot.h"    //Takes care of potentiometer

Scheduler *taskManager;  // Creating a taskManager to run things at specific times
Pot *newpot;            //Pointer to nowhere yet
Screen *ScreenLCD;      //Same
Servo1 *Servomotor;     //Same



void setup() {
  Serial.begin(115200);         //Same number as in serial monitor
  
  taskManager = new Scheduler();    //Puts taskmanger equal to scheduler
  ScreenLCD = new Screen();   //Same
  newpot = new Pot(A0, ScreenLCD);    //Same
  Servomotor = new Servo1(9);   //

  taskManager->registerTask(newpot,1000);   //Feeds the registerTask two paremetors
 // newpot->run();
  taskManager->registerTask(Servomotor,10);
}


void loop() {
  
  taskManager->update();  //Runs the scheduler, which runs the task.
}
