#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "Alien.h"
#include <vector>
#include <iostream>
#include <QPushButton>
#include <QGraphicsTextItem>
using namespace std;

class SpaceCraft: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    SpaceCraft(int x, int y, int x_size, int y_size, QGraphicsItem * parent);
    int x, y, x_size, y_size;
    int score;
    int game_over;
    QGraphicsTextItem *gameOverText;
    QPushButton *playAgainButton;
    void move(QPointF position);
    Q_INVOKABLE void resetGame();
public slots:
    void alienAppear();
    void checkScene();

};

#endif // SPACECRAFT_H