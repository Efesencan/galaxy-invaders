//
// Created by acun on 4/21/23.
//

#include "HoverScene.h"
#include "SpaceCraft.h"
#include "Bullet.h"
#include <QTimer>
#include <QDebug>

HoverScene::HoverScene() {
    spaceCraft = new SpaceCraft(0,0,50,50, 0);
    addItem(spaceCraft);


    QTimer * alienTimer = new QTimer();
    QObject::connect(alienTimer,SIGNAL(timeout()),spaceCraft,SLOT(alienAppear()));
    alienTimer->start(3000);



    QTimer * checkSceneTimer = new QTimer();
    QObject::connect(checkSceneTimer,SIGNAL(timeout()),spaceCraft,SLOT(checkScene()));
    checkSceneTimer->start(50);


    setBackgroundBrush(QBrush(QImage(":/images/space.jpg")));
//    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(QPixmap(":/images/qt_logosdfsdf.png"));
//    background->setPos(50, 50);  // set the position of the pixmap to (0,0)
//    background->setZValue(1);  // set the z-value to -1 to ensure it's behind other items in the scene
//    addItem(background);  // add the pixmap item to the scene
//    qDebug() << background;

}

void HoverScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << spaceCraft->game_over;
    if(!spaceCraft->game_over) {
        QPointF pos = event->scenePos();
        qDebug() << "Mouse is hovering over the item at" << pos;
        spaceCraft->move(pos);
    }
}

void HoverScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "PRESSED";
    if(!spaceCraft->game_over) {
        Bullet *bullet = new Bullet(spaceCraft->x+spaceCraft->x_size + 2,
                                    spaceCraft->y+spaceCraft->y_size/2 -5,
                                    10, 10, spaceCraft, 0);
        addItem(bullet);
    }
}

