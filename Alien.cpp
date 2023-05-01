//
// Created by acun on 4/22/23.
//

#include "Alien.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QBrush>
#include <QList>
#include "Bullet.h"

Alien::Alien(int b_x, int b_y, int x_size, int y_size, QGraphicsItem * parent){
    // drew the rect
    this->b_x = b_x;
    this->b_y = b_y;
    this->x_size = x_size;
    this->y_size = y_size;
    setPos(this->b_x,this->b_y);
    setPixmap(QPixmap(":/images/alien_s.png"));
//    setRect(b_x,b_y,x_size,y_size);
//    this->setBrush(QBrush(Qt::red));
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Alien::move() {

    this->b_x = x()-5;
    this->b_y = y();
    setPos(this->b_x,this->b_y);

    if(b_x < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "ALIEN DELETED";
    }
}