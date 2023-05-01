//
// Created by acun on 4/21/23.
//

#ifndef QT_EXAMPLES_HOVERSCENE_H
#define QT_EXAMPLES_HOVERSCENE_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QEvent>
#include <QTouchEvent>
#include <QtGui>
#include <QGraphicsItem>
#include "SpaceCraft.h"
#include "Bullet.h"



class HoverScene : public QGraphicsScene
{
    public:
        HoverScene();
        SpaceCraft *spaceCraft;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
//    public slots:
//        void alienAppear();
};

#endif //QT_EXAMPLES_HOVERSCENE_H
