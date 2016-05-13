#include "hit.h"
#include <iostream>
using namespace std;
Hit::Hit()
{
    x_speed = 0.1;
}
void Hit::advance(int phase)
{
    // Do moving
    this->setPos(this->pos().x()- x_speed , this->pos().y());
    //cout<<x_speed<<" ";
    // check the boundary
    //checkBoundary();
}
