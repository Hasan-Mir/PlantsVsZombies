#ifndef SUNFLOWERBOARD_H
#define SUNFLOWERBOARD_H

#include <QObject>
#include "PlantBoard.h"
#include <QGraphicsSceneMouseEvent>
#include <SunFlower.h>

class SunflowerBoard : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit SunflowerBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    SunFlower* sunflowerSellected();
    void UnselectSunflower();

public slots:
    void slotPlayerScore(int playerScore);
    void isPlaced();
};

#endif // SUNFLOWERBOARD_H
