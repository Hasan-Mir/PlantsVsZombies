#include "Bullet.h"
#include <QGraphicsScene>
#include <QList>
#include "Zombie.h"

Bullet::Bullet(QTimer *bulletTimer, const int &velocity,
               QGraphicsItem *parent)
        : QObject() , QGraphicsPixmapItem(parent) , velocity(velocity)
{
    // set picture
    setPixmap(QPixmap(":/images/ball-shadow.png"));

    // connect to moveToRight
    connect(bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}

void Bullet::moveToRight(){

    // collect all colliding items in a list
    QList<QGraphicsItem *> collidingList = collidingItems();

    // decrement zombies lives
    for (size_t i = 0 ; i < collidingList.size() ; ++i){
        if( typeid(*(collidingList[i])) == typeid (Zombie)){
            dynamic_cast<Zombie*>(collidingList[i])->decrementLives();

            // delete and remove bullet
            scene()->removeItem(this);
            delete this;
            return;
        }
    }


    // move to right
    setPos(x() + velocity , y());

    // delete if the bullet is off the screen
    if( x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
