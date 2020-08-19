#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent)
        : QGraphicsTextItem(parent) , playerScore(0)
{
    // set Text
    setPlainText(QString::number(playerScore));
    setDefaultTextColor("black");
    setFont(QFont("times" , 15));

    // set Player
    scorePlayer = new QMediaPlayer();
    scorePlayer->setMedia(QUrl("qrc:/musics/coin.mp3"));

}

Score::~Score()
{
    delete scorePlayer;
}

void Score::addToScore(int s)
{
    playerScore += s;
    setPlainText(QString::number(playerScore));

    //send player score to plantBoard
    emit signalChangeAmount(playerScore);
}

void Score::isPlaced(int price)
{
    playerScore -= price;
    setPlainText(QString::number(playerScore));
    emit signalChangeAmount(playerScore);
}

