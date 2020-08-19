#include "Block.h"
#include "Controller.h"

Block::Block(QGraphicsItem* parent, Score* blockScore):
    blockScore{blockScore}, QGraphicsRectItem (parent)
{
    plant = nullptr;//at first this is null

    //start timer
    bTimer = new QTimer();
    bTimer->start(50);

    //initialize all plants flags
    sunflower = false;
    shooter = false;
    oak = false;
    cherry = false;
}


void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   
    if (plant == nullptr)
    {
        if (shooter){
            plant = new Shooter(bTimer, parentItem());
            scene()->addItem(plant);
            plant->setPos(x() , y());
            emit signalIsPlacedToScore(100);
            emit signalIsPlacedToBoard();
        }
        else if (sunflower){
            plant = new SunFlower(bTimer, blockScore, parentItem());
            scene()->addItem(plant);
            plant->setPos( x() , y());
            emit signalIsPlacedToScore(50);
            emit signalIsPlacedToBoard();
        }

        else if (cherry){
            plant = new Cherry(bTimer, parentItem());
            scene()->addItem(plant);
            plant->setPos(x() + 10 - 80 , y() + 10 - 100);
            emit signalIsPlacedToScore(150);
            emit signalIsPlacedToBoard();

        }

        else if (oak){
            plant = new Oak(bTimer, 5,parentItem());
            scene()->addItem(plant);
            plant->setPos(x()+10 , y()+10);
            emit signalIsPlacedToScore(150);
            emit signalIsPlacedToBoard();

        }
    }
    else if (plant != nullptr && shovel){
        delete plant;
        plant = nullptr;
        emit isDeleted();
    }
}

void Block::ShooterSellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        shooter = true;
    }
}

void Block::SunFlowerSellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        sunflower = true;
    }
}

void Block::OakSellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        oak = true;
    }
}

void Block::CherrySellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        cherry = true;
    }
}

void Block::UnSelect()
{
    sunflower = false;
    shooter = false;
    oak = false;
    cherry = false;
    shovel = false;
}

void Block::ShovelSellected()
{
    shovel = true;
}

