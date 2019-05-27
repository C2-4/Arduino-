#include "Task.h"
#include "Scheduler.h"
#include "Arduino.h"

//Implementation of Scheduler class

void Scheduler::update() //Runs though the tasks array and runs the onces that are on time.
{
  uint32_t now = millis();    //Puts the current time into "now"
  for(int i = 0; i < STACK_SIZE; i++) //Enters the forloop
  {
    if (numOfTasks[i] == true){     //numOfTasks 0,1 are true
      if (now - lastRunTime[i] >= ratesForTasks[i]) //Now is current time, lastRunTime is last time task was run, RatesForTask is what we have set it to in the main
      {
        Task* tempTask = tasks[i]; // First time this function runs tempTask becomes newPot
  
        tempTask->run(); //tempTask points to run
        lastRunTime[i] = now;       //puts last run time equal to "current time"
      }
    }
  }
}

bool Scheduler::registerTask(Task* inputTasks, uint16_t intervalRunTime) //For adding a task which has to be run.
{

  for (int i = 0; i < STACK_SIZE; i++) //Enters a forloop
  {
    if (numOfTasks[i] == false) //Check if the "numOfTasks[i] is false", which it is
    {
      numOfTasks[i] = true; //Puts it true
      tasks[i] = inputTasks;   //inputTasks is equal to "Newpot" first time the function is called
      lastRunTime[i] = millis(); //Saves the current time
      ratesForTasks[i] = intervalRunTime;   // This is 1000 the first time the function is called
      return true;  //It is a bool function, needs to return something
    }
  }
  return false;
}
