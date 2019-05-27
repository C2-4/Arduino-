
#ifndef TASK_H
#define TASK_H

class Task
{
public:
  Task()
  {
    return;
  }
  virtual bool run() //Works as a header file for every liberary in this code. This is inherance
  {
    return true;
  };
};

#endif
