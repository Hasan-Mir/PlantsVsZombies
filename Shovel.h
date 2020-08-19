#ifndef SHOVEL_H
#define SHOVEL_H

#include <QObject>
#include "PlantBoard.h"
#include <QGraphicsSceneMouseEvent>

class Shovel : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit Shovel(QGraphicsItem *parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void UnselectShovel();
    void ShovelSellected();

public slots:
    void isDelete();

};

#endif // SHOVEL_H
