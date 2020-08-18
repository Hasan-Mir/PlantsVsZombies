#include "Button.h"
#include <QFont>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>

Button::Button(QGraphicsItem *parent)
    : QObject() , QGraphicsPixmapItem(parent)
{

}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit buttonClicked();
}

