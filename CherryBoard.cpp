#include "CherryBoard.h"

CherryBoard::CherryBoard(QGraphicsItem* parent) : QObject(), PlantBoard (150, false, false, parent)
{
    setPixmap(QPixmap(":/images/cherryUnSelected.jpg"));
    setPos(215,8);
}

void CherryBoard::slotPlayerScore(int playerScore)
{
    if (price <= playerScore){
        isSelectable = true;
        setPixmap(QPixmap(":/images/cherrySelectable.jpg"));
    }
    else{
        isSelectable = false;
        setPixmap(QPixmap(":/images/cherryUnSelected.jpg"));
    }
}

void CherryBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //first we check that plant is selectable
    if(isSelectable && !(isSelected)){
       isSelected = true;

       //set selected picture
       setPixmap(QPixmap(":/images/cherrySelected.jpg"));
        
       emit CherrySelected();
    }
    else if ( isSelected ){
        isSelected = false;
        setPixmap(QPixmap(":/images/cherrySelectable.jpg"));
        emit UnSelectCherry();
    }
}

void CherryBoard::isPlaced()
{
    isSelected = false;
    emit UnSelectCherry();
}
