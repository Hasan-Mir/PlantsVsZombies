#include "Shooterboard.h"

ShooterBoard::ShooterBoard(QGraphicsItem *parent) :
    QObject(), PlantBoard (100, false, false, parent)
{
    setPixmap(QPixmap(":/images/shooterUnSelected.jpg"));
    setPos(95,8);
}

void ShooterBoard::slotPlayerScore(int playerScore)
{
    if (price <= playerScore){
        isSelectable = true;
        setPixmap(QPixmap(":/images/shooterSelectable.jpg"));
    }
    else{
        isSelectable = false;
        setPixmap(QPixmap(":/images/shooterUnSelected.jpg"));
    }
}

void ShooterBoard::isPlaced()
{
    isSelected = false;
    emit UnselectShooter();
}

void ShooterBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //first we check that plant is selectable
    if(isSelectable && !(isSelected)){
       isSelected = true;

       //set selected picture
       setPixmap(QPixmap(":/images/shooterSelected.jpg"));

       emit ShooterSellected();
    }
    else if ( isSelected ){
        isSelected = false;
        setPixmap(QPixmap(":/images/shooterSelectable.jpg"));
        emit UnselectShooter();
    }
}
