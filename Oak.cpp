#include "Oak.h"
#include <QList>
#include "Zombie.h"
#include <QGraphicsScene>



Oak::Oak(QTimer * oakTimer , int velocity , QGraphicsItem *parent)
    : QObject() ,Plant(parent) , velocity(velocity) , oakTimer(oakTimer)
{
    //set picture
    setPixmap(QPixmap(":/images/oak1.png"));

    // set oak player
    oakPlayer = new QMediaPlayer();
    oakPlayer->setMedia(QUrl("qrc:/musics/killZombie.mp3"));

    // connect createSun slot
    connect(oakTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

    miliSec = 0;
}

void Oak::moveToRight()
{
    miliSec += 50;

    if(miliSec % 700 == 0){
        setPixmap(QPixmap(":images/oak7.png"));
    }
    else if(miliSec % 600 == 0){
        setPixmap(QPixmap(":images/oak6.png"));
    }
    else if(miliSec % 500 == 0){
        setPixmap(QPixmap(":images/oak5.png"));
    }
    else if(miliSec % 400 == 0){
        setPixmap(QPixmap(":images/oak4.png"));
    }
    else if(miliSec % 300 == 0){
        setPixmap(QPixmap(":images/oak3.png"));
    }
    else if(miliSec % 200 == 0){
        setPixmap(QPixmap(":images/oak2.png"));
    }
    else if(miliSec % 100 == 0){
        setPixmap(QPixmap(":images/oak1.png"));
    }

    // collect all colliding items in a list
    QList<QGraphicsItem *> collidingList = collidingItems();

    // remove and delete zombies
    for (size_t i = 0 ; i < collidingList.size() ; ++i){
       Zombie * zom = dynamic_cast<Zombie*>(collidingList[i]);
       if(zom){

            // play oak player
            if(oakPlayer->state() == QMediaPlayer::PlayingState){
                oakPlayer->setPosition(0);
            }
            else if (oakPlayer->state() == QMediaPlayer::StoppedState){
                oakPlayer->play();
            }
            scene()->removeItem(zom);
            delete zom;
       }
    }

    // move to right
    setPos(x() + velocity , y());


    // delete if the Oak is off the screen
    if( x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
