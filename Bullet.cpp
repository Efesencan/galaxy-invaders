//
// Created by acun on 4/22/23.
//

#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>
#include <QBrush>
#include "Alien.h"
#include <QGraphicsItem>

Bullet::Bullet(int b_x, int b_y, int x_size, int y_size, SpaceCraft* sp, QGraphicsItem * parent) {
    this->b_x = b_x - 5;
    this->b_y = b_y - 5;
    this->x_size = x_size;
    this->y_size = y_size;
    setPos(this->b_x,this->b_y);
//    setRect(b_x,b_y,x_size,y_size);
//    this->setBrush(QBrush(Qt::black));
    setPixmap(QPixmap(":/images/brick.png"));
     //  adjust the position to align with the rect item
    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    this->sp = sp;
    timer->start(50);
}

void Bullet::move(){

    QList<QGraphicsItem *> intersecteds = collidingItems();
    QList<QGraphicsItem *> itemsToRemove;
    bool crashDetect = 0;
    foreach(QGraphicsItem *item, intersecteds) {
        if(typeid(*(item)) == typeid(Alien)) {
            crashDetect = 1;
            qDebug() << "ENEMY + BULLET CRASH" ;
            itemsToRemove.append(item);
//            itemsToRemove.append(this);
            sp->score += 1;

            foreach(QGraphicsItem *item, scene()->items()) {
                if (QGraphicsTextItem *textItem = dynamic_cast<QGraphicsTextItem*>(item)) {
                    if (textItem->toPlainText().startsWith("Score:")) {
                        scene()->removeItem(textItem);
                        delete textItem;
                    }
                }
            }
            QGraphicsTextItem *scoreText = new QGraphicsTextItem("Score: " + QString::number(sp->score));
            scoreText->setDefaultTextColor(Qt::white);
            scoreText->setFont(QFont("times", 20));
            scoreText->setPos(0,0);
            scene()->addItem(scoreText);
            qDebug() << sp->score;
        }
    }
    foreach(QGraphicsItem *item, itemsToRemove) {
        scene()->removeItem(item);
        delete item;
    }
    if(crashDetect) {
        delete this;
        return;
    }
    this->b_x = x()+10;
    this->b_y = y();
    setPos(this->b_x,this->b_y);
//    pixmapItem->setPos(this->b_x,this->b_y);
    if(b_x > 480) {
        scene()->removeItem(this);
        delete this;
//        qDebug() << "BULLET DELETED";
    }
}