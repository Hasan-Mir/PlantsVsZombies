
#ifndef SHOOTER_H
#define SHOOTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include "Bullet.h"
#include "Plant.h"

class Shooter : public QObject , public Plant

{
    Q_OBJECT
private:
    QMediaPlayer* shooterPlayer;
    int timeIntervals;
    QTimer * shooterTimer;

public:
    explicit Shooter(QTimer *shooterTimer, QGraphicsItem *parent = nullptr);

signals:

public slots:
    void shoot();
};

#endif // SHOOTER_H
