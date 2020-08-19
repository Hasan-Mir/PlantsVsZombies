#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <Plant.h>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "PlantBoard.h"
#include <Cherry.h>
#include <Shooter.h>
#include <SunFlower.h>
#include <QGraphicsScene>
#include <Oak.h>

class Block : public QObject , public QGraphicsRectItem
{
    Q_OBJECT

private:
    Plant* plant;
    bool sunflower;
    bool shooter;
    bool oak;
    bool cherry;
    bool shovel;
    QTimer *bTimer;
    Score* blockScore;

public:
    explicit Block(QGraphicsItem* parent, Score* blockScore);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void signalIsPlacedToBoard();//for board
    void signalIsPlacedToScore(int price);//for score
    void isDeleted();

public slots:
    void ShooterSellected();
    void SunFlowerSellected();
    void OakSellected();
    void CherrySellected();
    void UnSelect();
    void ShovelSellected();
};

#endif // BLOCK_H
