#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
class observer
{
public:
    virtual void update(int c) = 0;
};

class observable
{
public:
   void addObserver(observer *_ob)
   {
      observers_.push_back(_ob);
   }
   void notifyUpdate(int c)
   {
      int size = observers_.size();
      for (int i = 0; i < size; i++)
      {
         observers_[i]->update(c);
      }
   }
private:
   std::vector<observer*> observers_;
};

#endif // OBSERVER_H
