#include "Plantboard.h"

PlantBoard::PlantBoard(int price, bool isSelected,
                       bool isSelectable, QGraphicsItem *parent)
    :price{price}, isSelected{isSelected}, isSelectable{isSelectable}
    ,QGraphicsPixmapItem (parent)
{

}
