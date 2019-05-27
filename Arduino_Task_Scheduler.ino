#include "Scheduler.h"    //Takes care of everything
#include "Servo.h"  // Takes care of servo 
#include "Screen.h"  //Takes care of lcd
#include "Pot.h"    //Takes care of potentiometer

Scheduler *taskManager;  //Pointer to nowhere yet
Pot *newpot;            //Pointer to nowhere yet
Screen *ScreenLCD;      //Same
Servo1 *Servomotor;     //Same



void setup() {          //Everything inside here only runs one time
  Serial.begin(115200);         //Same number as in serial monitor
  
  taskManager = new Scheduler();    //Makes a new object of the type "scheduler" and makes the taskmanger point to scheduler 
  ScreenLCD = new Screen();   //Same
  newpot = new Pot(A0, ScreenLCD);    //Gives some parameters to the initializer/constructor 
  Servomotor = new Servo1(9);   //Same as new pot

  taskManager->registerTask(newpot,1000);   // Feeds registerTask two parameters
 
  taskManager->registerTask(Servomotor,10); // Does exactly the same
}


void loop() {  //This is the main
  
  taskManager->update();  //Runs the scheduler object, update funcion, which runs the task.
}
