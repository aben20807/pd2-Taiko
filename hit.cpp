#include "hit.h"
#include <iostream>
using namespace std;
Hit::Hit()
{
    x_speed = 0.1;
}
void Hit::advance(int phase)
{
    //移動
    this->setPos(this->pos().x()- x_speed , this->pos().y());
}
