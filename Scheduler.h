#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Arduino.h"
#include "Task.h"
#define STACK_SIZE 5

//Scheduler to run tasks

class Scheduler
{
public:
  Scheduler();
  void update();
  bool registerTask(Task* inputTask, uint16_t intervalRunTime);
private:
  Task* tasks [STACK_SIZE]; //Array for pointers to tasks.
  bool numOfTasks[STACK_SIZE]; //For figuring out if a place in the tasks is occupied.
  uint32_t lastRunTime[STACK_SIZE]; //Array for the last time a task was run.
  uint16_t ratesForTasks[STACK_SIZE]; //The interval at which tasks have to run.
};

#endif
