#include "Shovel.h"

Shovel::Shovel(QGraphicsItem *parent) : QObject(),
    PlantBoard (0, false , true , parent)
{
    isSelectable = true;
    setPixmap(QPixmap(":/images/shovel.png"));
    setPos(375,8);
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!(isSelected)){
       isSelected = true;

       //set selected picture
       setPixmap(QPixmap(":/images/selectedShovle.png"));

       emit ShovelSellected();
    }
    else if ( isSelected ){
        isSelected = false;
        setPixmap(QPixmap(":/images/shovel.png"));
        emit UnselectShovel();
    }
}

void Shovel::isDelete()
{
    isSelected = false;
    setPixmap(QPixmap(":/images/shovel.png"));

}
