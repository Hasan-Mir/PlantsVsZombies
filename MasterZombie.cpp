#include "MasterZombie.h"
#include "Plant.h"
#include "Oak.h"
#include <QGraphicsScene>

MasterZombie::MasterZombie(const int &pixPer50MiliSec, QTimer *timer, const int &lives, QGraphicsItem *parent)
        : Zombie(pixPer50MiliSec , timer , lives , parent)
{
    // set picture
    setPixmap(QPixmap(":images/mZombie1.png"));

    // connect timer to moveToLeft()
    connect( timer , SIGNAL(timeout()) , this , SLOT(  moveToLeft() ) );
}

void MasterZombie::moveToLeft() {

    // change picture
    if(miliSec % 500 == 0){
        setPixmap(QPixmap(":images/mZombie4.png"));
    }
    else if(miliSec % 400 == 0){
        setPixmap(QPixmap(":images/mZombie3.png"));
    }
    else if(miliSec % 200 == 0){
        setPixmap(QPixmap(":images/mZombie2.png"));
    }
    else if(miliSec % 100 == 0){
        setPixmap(QPixmap(":images/mZombie1.png"));
    }

    // ** following codes are running in the Zombie class' moveToLeft() because
    // we connected Zombie class' moveToLeft() to timer in Zombie class' constructor
    // so we don't need to run these codes again.


    // collect colliding items in a list
//    QList <QGraphicsItem *> collidingObjects = collidingItems();

    // remove and delete colliding plants
//    for (size_t i = 0 ; i < collidingObjects.size() ; ++i){
//        Plant * plant = dynamic_cast<Plant*>(collidingObjects[i]);
//        if( plant ){
//            if(typeid(*(collidingObjects[i])) != typeid(Oak)){      // zombie destroy every plant except Oak
//                scene()->removeItem(collidingObjects[i]);
//                delete collidingObjects[i];
//            }
//        }
//    }

    //setPos(x() - pixPer50MiliSec , y());

//    if ( x() == 0 ){
//        exit(1);     // TO DO
//    }
}
