#include "SpaceCraft.h"
#include <QKeyEvent>
#include <QTouchEvent>
#include <QDebug>
#include <QEvent>
#include <QBrush>
#include <QString>
#include <string>
#include "HoverScene.h"
#include "Alien.h"
#include "Bullet.h"


SpaceCraft::SpaceCraft(int x, int y, int x_size, int y_size, QGraphicsItem * parent) {
    this->x = x;
    this->y = y;
    this->x_size = x_size;
    this->y_size = y_size;
    setPos(this->x,this->y);
    setPixmap(QPixmap(":/images/yankucuk.png"));
//    setRect(x,y,x_size,y_size);
//    this->setBrush(QBrush(Qt::blue));
    this->score = 0;
    this->game_over = 0;
//    setBrush(Qt::red);
}

void SpaceCraft::move(QPointF position){
        this->x = position.x()-x_size/2;
        this->y = position.y()-y_size/2;
       setPos(this->x, this->y);
}

void SpaceCraft::alienAppear() {
    qDebug() << "alienAppear";
    int x_bound = 50; // Upper bound of the random number (inclusive)
    int x_alien = 480 - (std::rand() % (x_bound + 1)); // Generate a random number between 0 and n (inclusive)

    int y_bound = 250; // Upper bound of the random number (inclusive)
    int y_alien = (std::rand() % (y_bound + 1)); // Generate a random number between 0 and n (inclusive)

    qDebug() << "Alien: " << x_alien << ", " << y_alien;

    Alien * alien = new Alien(x_alien, y_alien, 30, 30, 0);
    scene()->addItem(alien);
}


void SpaceCraft::checkScene() {

    if (!game_over){
        qDebug() << "check scene";
        QList<QGraphicsItem *> intersecteds = collidingItems();
        QList<QGraphicsItem *> itemsToRemove;
//    bool gameOver = 0;

        foreach(QGraphicsItem *item, intersecteds) {
            qDebug() << "INTERSECTS";
            if(typeid(*(item)) == typeid(Alien)) {
                qDebug() << "ALIEN + SPACE CRAFT CRASHH";
                itemsToRemove.append(item);
                game_over = 1;
            }
        }

        foreach(QGraphicsItem *item, itemsToRemove) {
//        scene()->removeItem(item);
            delete item;
        }

        QGraphicsTextItem *scoreText = new QGraphicsTextItem("Score: " + QString::number(this->score));
        scoreText->setDefaultTextColor(Qt::white);
        scoreText->setFont(QFont("times", 20));
        scoreText->setPos(0,0);
        scene()->addItem(scoreText);

        if(game_over) {
            qDebug() << "GAME OVER";
            gameOverText = new QGraphicsTextItem("Game over, your score is: " + QString::fromStdString(std::to_string(this->score)));
            gameOverText->setDefaultTextColor(Qt::white);
            gameOverText->setFont(QFont("times", 24));
            qDebug() << "GAME OVER AFTER TEXTT";

            foreach(QGraphicsItem *item, scene()->items()) {
                if (QGraphicsTextItem *textItem = dynamic_cast<QGraphicsTextItem*>(item)) {
                    if (textItem->toPlainText().startsWith("Score:")) {
                        scene()->removeItem(textItem);
                        delete textItem;
                    }
                }
            }

            QGraphicsTextItem *scoreText = new QGraphicsTextItem();
            scoreText->setDefaultTextColor(Qt::red);
            scoreText->setFont(QFont("times", 24));


// Set the position of the "Game Over" text item in the scene
            gameOverText->setPos(0,0);


// Add the "Game Over" text item to the scene
            scene()->addItem(gameOverText);
            qDebug() << "GAME OVER TEXTT SCENE ADDED";


//        scene()->removeItem(this);
            qDebug() << "SPACECRAFT REMOVED";

//        QGraphicsTextItem* playAgain = new QGraphicsTextItem("Play Again");
//        playAgain->setDefaultTextColor(Qt::white);
//        playAgain->setFont(QFont("times", 20));
//        playAgain->setPos(0, 250);
//        scene()->addItem(playAgain);
//        // Connect the play again button to the reset game slot
//        connect(playAgain, &QGraphicsTextItem::clicked, this, &SpaceCraft::resetGame);
            bool text_found = false;
            QList<QGraphicsItem*> itemsToRemove = scene()->items();
            for (auto item : itemsToRemove) {
                if(typeid(*(item)) != typeid(SpaceCraft)) {
                    if (item != gameOverText) {
                        delete item;
                    }
                }
            }


            playAgainButton = new QPushButton("Play Again");
            playAgainButton->setFont(QFont("times", 20));
            playAgainButton->setGeometry(QRect(QPoint(250, 200), QSize(200, 50)));
            playAgainButton->setStyleSheet("background-color: blue; color: white;");

            QGraphicsProxyWidget *buttonProxy = scene()->addWidget(playAgainButton);
            buttonProxy->setPos(140, 180);

            // connect the button to the resetGame() slot
            connect(playAgainButton, &QPushButton::pressed, this, &SpaceCraft::resetGame);


//        QCoreApplication::quit();
//        qDebug() << "APP QUIT";
            //delete this;
            // Create a QGraphicsTextItem to display "Game Over"
        }
    }



}

void SpaceCraft::resetGame()
{

    qDebug() << "BUTTON IS PRESSED";
    // Remove any items from the scene
    QList<QGraphicsItem*> itemsToRemove = scene()->items();
    for (auto item : itemsToRemove) {
        if(typeid(*(item)) == typeid(Alien))
            delete item;
    }
    //scene()->removeItem(playAgainButton);
    //scene()->removeItem(gameOverText);
    delete playAgainButton;
    delete gameOverText;
    qDebug() << "ITEMS ARE DELETED";
    score = 0;
    game_over = false;

    this->x = x;
    this->y = y;
    this->x_size = x_size;
    this->y_size = y_size;
    qDebug() << "BEFORE SET POS";
    setPos(this->x,this->y);
    qDebug() << "AFTER SET POS";
}
