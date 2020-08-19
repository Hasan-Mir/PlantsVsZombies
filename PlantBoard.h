#ifndef PLANTBOARD_H
#define PLANTBOARD_H

#include <QGraphicsPixmapItem>

class PlantBoard : public QGraphicsPixmapItem
{
    friend class Block;
protected:
    int price;
    bool isSelected;
    bool isSelectable;

public:
    PlantBoard(int price, bool isSelected, bool isSelectable, QGraphicsItem *parent);
};

#endif // PLANTBOARD_H
