#ifndef OAKBOARD_H
#define OAKBOARD_H

#include <QObject>
#include "PlantBoard.h"
#include <QGraphicsSceneMouseEvent>
#include <Oak.h>

class OakBoard : public QObject ,public PlantBoard
{
    Q_OBJECT
public:
    explicit OakBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void OakSellected();
    void UnselectOak();

public slots:
    void slotPlayerScore(int playerScore);
    void isPlaced();

};

#endif // OAKBOARD_H
