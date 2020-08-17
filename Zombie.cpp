#include "Zombie.h"
#include "Plant.h"
#include <QGraphicsScene>
#include <QList>


Zombie::Zombie(const int & pixPer50MiliSec , QTimer *timer ,
               const int& lives , QGraphicsItem * parent)
    : QObject() , QGraphicsPixmapItem(parent),
      pixPer50MiliSec(pixPer50MiliSec)  , lives(lives) {

    // set picture
    setPixmap(QPixmap(":images/zombie1.png"));

    // connect timer to moveToLeft()
    connect( timer , SIGNAL(timeout()) , this , SLOT(  moveToLeft() ) );

    // set zombie sound
    zombiePlayer = new QMediaPlayer();
    zombiePlayer->setMedia(QUrl("qrc:/musics/groan.mp3"));
    zombiePlayer->play();

    miliSec = 0;

}

Zombie::~Zombie(){
    delete zombiePlayer;
}

void Zombie::decrementLives() {
    // decrement zombie's lives
    --lives;

    // remove and delete if lives == 0
    if ( lives == 0 ){
        scene()->removeItem(this);
        delete this;
    }
}

void Zombie::moveToLeft(){
    miliSec += 50;

    if(miliSec % 500 == 0){
        setPixmap(QPixmap(":images/zombie4.png"));
    }
    else if(miliSec % 400 == 0){
        setPixmap(QPixmap(":images/zombie3.png"));
    }
    else if(miliSec % 200 == 0){
        setPixmap(QPixmap(":images/zombie2.png"));
    }
    else if(miliSec % 100 == 0){
        setPixmap(QPixmap(":images/zombie1.png"));
    }

    // collect colliding items in a list
    QList <QGraphicsItem *> collidingObjects = collidingItems();

    // remove and delete colliding plants
    for (size_t i = 0 ; i < collidingObjects.size() ; ++i){
        Plant * plant = dynamic_cast<Plant*>(collidingObjects[i]);
        if( plant ){
            scene()->removeItem(collidingObjects[i]);
            delete collidingObjects[i];
        }
    }

    setPos(x() - pixPer50MiliSec , y());

    if ( x() == 0 ){
        exit(1);     // TO DO
    }
}
