#include "Shooter.h"
#include <QGraphicsScene>

Shooter::Shooter(QTimer *shooterTimer,
                 QGraphicsItem *parent)
    : QObject()  , Plant(parent) ,
      shooterTimer(shooterTimer) , timeIntervals(0)
{
    //set picture
    setPixmap(QPixmap(":/images/shooter1.png"));

    // create shooter player
    shooterPlayer = new QMediaPlayer();
    shooterPlayer->setMedia(QUrl("qrc:/musics/throwBullet.mp3"));

    // connect shoot slot
    connect(shooterTimer , SIGNAL(timeout()) , this , SLOT(shoot()));

}

void Shooter::shoot()
{
    // shoot every 500 miliSec
    if(timeIntervals % 10 == 0 ){
        // create bullet
        auto bullet = new Bullet(shooterTimer , 20);
        scene()->addItem(bullet);
        bullet->setPos(x() + 60 , y() + 15);

        // play shooter player
        if(shooterPlayer->state() == QMediaPlayer::PlayingState){
            shooterPlayer->setPosition(0);
        }
        else if (shooterPlayer->state() == QMediaPlayer::StoppedState){
            shooterPlayer->play();
        }

    }

    // increment timeIntervals
    ++timeIntervals;
}
