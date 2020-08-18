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

    // set media player
    bulletPlayer = new QMediaPlayer();
    bulletPlayer->setMedia(QUrl("qrc:/musics/bulletZombie.mp3"));

    // connect to moveToRight
    connect(bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));

}

void Bullet::moveToRight(){

    // collect all colliding items in a list
    QList<QGraphicsItem *> collidingList = collidingItems();

    // decrement zombies lives
    for (size_t i = 0 ; i < collidingList.size() ; ++i){
        Zombie * zom = dynamic_cast<Zombie*>(collidingList[i]);
        if(zom){
            dynamic_cast<Zombie*>(collidingList[i])->decrementLives();

            // play bullet player
            if(bulletPlayer->state() == QMediaPlayer::PlayingState){
                bulletPlayer->setPosition(0);
            }
            else if (bulletPlayer->state() == QMediaPlayer::StoppedState){
                bulletPlayer->play();
            }

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
