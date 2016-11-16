#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <observer.h>
#include <model.h>
class view: observer
{
public:
    view(model*_m);
    ~view(){}
    virtual void update(int c);
private:
    void menu();
    model *model_;
};

#endif // VIEW_H
