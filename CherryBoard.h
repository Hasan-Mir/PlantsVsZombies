#ifndef CHERRYBOARD_H
#define CHERRYBOARD_H

#include <QObject>
#include "PlantBoard.h"
#include <QGraphicsSceneMouseEvent>
#include <Cherry.h>

class CherryBoard : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit CherryBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
        Cherry* CherrySelected();
        void UnSelectCherry();

public slots:
    void slotPlayerScore(int playerScore);
    void isPlaced();

};

#endif // CHERRYBOARD_H
