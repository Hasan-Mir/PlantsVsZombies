#ifndef SHOOTERBOARD_H
#define SHOOTERBOARD_H

#include <QObject>
#include "PlantBoard.h"
#include <QGraphicsSceneMouseEvent>
#include <Shooter.h>

class ShooterBoard : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit ShooterBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void ShooterSellected();
    void UnselectShooter();
public slots:
    void slotPlayerScore(int playerScore);
    void isPlaced();
};

#endif // SHOOTERBOARD_H
