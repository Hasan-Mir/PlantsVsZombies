#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>

class Button : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Button(QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void buttonClicked();

};

#endif // BUTTON_H
