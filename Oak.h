#ifndef OAK_H
#define OAK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include "Plant.h"

class Oak : public QObject , public Plant {
    Q_OBJECT
private:
    int miliSec;
    int velocity;   // 200px (2 blocks) per seconds --> 10px per 50 miliSec
    QTimer * oakTimer;
    QMediaPlayer* oakPlayer;
public:
    explicit Oak(QTimer * oakTimer , int velocity , QGraphicsItem *parent = nullptr);

signals:

public slots:
    void moveToRight();

};

#endif // OAK_H
