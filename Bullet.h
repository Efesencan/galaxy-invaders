//
// Created by acun on 4/22/23.
//

#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

#include <QObject>
#include <QGraphicsPixmapItem>
#include "SpaceCraft.h"

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(int b_x, int b_y, int x_size, int y_size, SpaceCraft* sp, QGraphicsItem * parent);
    int b_x, b_y, x_size, y_size;
    SpaceCraft *sp;
//    QGraphicsPixmapItem* pixmapItem;

public slots:
    void move();
};

#endif // BULLET_H
