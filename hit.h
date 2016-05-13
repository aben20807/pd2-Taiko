#ifndef HIT_H
#define HIT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class Hit : public QGraphicsPixmapItem
{
public:
    Hit();

    double x_speed;//hit移動速度
    void advance(int phase);
};

#endif // HIT_H
