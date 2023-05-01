//
// Created by acun on 4/22/23.
//

#ifndef QT_EXAMPLES_ALIEN_H
#define QT_EXAMPLES_ALIEN_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Alien: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Alien(int b_x, int b_y, int x_size, int y_size, QGraphicsItem * parent);
    int b_x, b_y, x_size, y_size;
public slots:
    void move();
};

#endif //QT_EXAMPLES_ALIEN_H
