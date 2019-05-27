
#ifndef TASK_H
#define TASK_H

class Task
{
public:
  Task()
  {
    return;
  }
  virtual bool run()
  {
    return true;
  };
};

#endif
