#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QEvent>
#include <QTouchEvent>
#include <QtGui>
#include <QGraphicsItem>
#include "HoverScene.h"
#include "SpaceCraft.h"

//class HoverScene : public QGraphicsScene
//{
//public:
//    HoverScene() : QGraphicsScene() {
//        // Create a graphics item and add it to the scene
//        item = new MyRect(0, 0, 50, 50);
//        item->setPos(100, 100);
//        item->setBrush(Qt::red);
//        addItem(item);
//    }
//
//protected:
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
//        QPointF pos = event->scenePos();
//        qDebug() << "Mouse is hovering over the item at" << pos;
//        move(pos);
//    }
//
//private:
//    QGraphicsRectItem *item;
//};

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    HoverScene scene;
//    QPixmap backgroundImage(":images/qt_logo.png");
//    QGraphicsPixmapItem* background = new QGraphicsPixmapItem(backgroundImage);
//
//    background->setPos(0, 0);  // set the position of the pixmap to (0,0)
//    background->setZValue(-1);  // set the z-value to -1 to ensure it's behind other items in the scene
//    scene.addItem(background);  // add the pixmap item to the scene



    QGraphicsView view(&scene);
    view.setDragMode(QGraphicsView::NoDrag);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    scene.addItem(background);
//    background->setZValue(-1); // Set the z-value to ma

    view.show();
    view.setFixedSize(480,270);
    scene.setSceneRect(0,0,480,270);

    return app.exec();
}

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//
//    TouchWindow window;
//    QGraphicsScene * scene = new QGraphicsScene(window);
//
//    MyRect * rect = new MyRect();
//    scene->addItem(rect);
//    rect->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
//
//    window.show();
//
//    return a.exec();
//}

//int main(int argc, char *argv[]){
//    QApplication a(argc, argv);
//
//    // create a scene
//    QGraphicsScene * scene = new QGraphicsScene();
//    // create an item to add to the scene
////    setAttribute(Qt::WA_AcceptTouchEvents);
//
//    MyRect * rect = new MyRect();
//    rect->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
//
//    // add the item to the scene
//    scene->addItem(rect);
//
//    // make rect focusable
////    rect->setFlag(QGraphicsItem::ItemIsFocusable);
////    rect->setFocus();
//
//    // create a view to visualize the scene
//    QGraphicsView * view = new QGraphicsView(scene);
//
//    // show the view
//    view->show();
//
//    return a.exec();
//}



//class TouchWindow : public QWindow
//{
//public:
//    TouchWindow() : QWindow() {
//        setFlags(Qt::FramelessWindowHint);
//        create();
//    }
//
//protected:
//    bool event(QEvent *event) override {
//        if (event->type() == QEvent::TouchBegin ||
//            event->type() == QEvent::TouchUpdate ||
//            event->type() == QEvent::TouchEnd)
//        {
//            QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
//            QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();
//            for (const QTouchEvent::TouchPoint &touchPoint : touchPoints) {
//                if (touchPoint.state() == Qt::TouchPointPressed) {
//                    qDebug() << "Touch Begin: " << touchPoint.pos();
//                }
//                else if (touchPoint.state() == Qt::TouchPointMoved) {
//                    qDebug() << "Touch Update: " << touchPoint.pos();
//
//                }
//                else if (touchPoint.state() == Qt::TouchPointReleased) {
//                    qDebug() << "Touch End: " << touchPoint.pos();
//                }
//            }
//        }
//        return QWindow::event(event);
//    }
//};