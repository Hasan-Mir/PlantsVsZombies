#include "Cherry.h"
#include <QList>
#include <QTimer>
#include <QGraphicsScene>
#include "Zombie.h"

Cherry::Cherry(QTimer * cherryTimer , QGraphicsItem *parent)
    : QObject() , Plant(parent)
{
    // set picture
    setPixmap(QPixmap(":/images/cherry.png"));

    // set player
    cherryPlayer = new QMediaPlayer();
    cherryPlayer->setMedia(QUrl("qrc:/musics/cherrybomb.mp3"));

    // connect
    connect(cherryTimer , SIGNAL(timeout()) , this , SLOT(explode()));

    timeIntervals = 0;
}


void Cherry::explode() {
    timeIntervals += 50;

    // it explodes after 2 seconds
    if(timeIntervals == 2000){

        // play cherryPlayer
        if(cherryPlayer->state() == QMediaPlayer::PlayingState){
            cherryPlayer->setPosition(0);
        }
        else if (cherryPlayer->state() == QMediaPlayer::StoppedState){
            cherryPlayer->play();
        }

        // collect all colliding items in a list
        QList<QGraphicsItem *> collidingList = collidingItems();

        for (size_t i = 0 ; i < collidingList.size() ; ++i){
            Zombie * zom = dynamic_cast<Zombie*>(collidingList[i]);
            if(zom){
                // delete and remove zombie
                scene()->removeItem(collidingList[i]);
                delete collidingList[i];
                //return;
            }
        }
        scene()->removeItem(this);
        delete this;
    }
}
