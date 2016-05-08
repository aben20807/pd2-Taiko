#ifndef HIT_H
#define HIT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Hit : public QGraphicsPixmapItem
{
public:
    Hit();

    double x_speed;
    void advance(int phase);
};

#endif // HIT_H
