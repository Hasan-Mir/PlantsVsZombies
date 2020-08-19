#include "Sun.h"
#include <cstdlib>

Sun::Sun(QGraphicsScene * sunScene , Score * sunScore ,
         QGraphicsItem * parent , QTimer * timer)
      : QObject() , QGraphicsPixmapItem(parent) ,
        sunScene(sunScene) , sunScore(sunScore) ,
        timeIntervals(0)
{
    //set Picture
    setPixmap(QPixmap(":/images/sun1.png"));

    // add to scene
    sunScene->addItem(this);
//    setPos( rand() % 750 , 0);

    // connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));

}


void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // add score
    sunScore->addToScore(25);

    // play sound
    sunScore->scorePlayer->play();

    // remove and delete
    sunScene->removeItem(this);
    delete this;
}

void Sun::move() {
    // increment timeIntervals each 50 milisec / if (timeIntervals == 40), it is 2 seconds
    timeIntervals++;

    // move downward
    setPos(x() , y() + 5);

    // remove and delete
    if(timeIntervals == 40 || y() > 500){
        sunScene->removeItem(this);
        delete this;
    }
}
