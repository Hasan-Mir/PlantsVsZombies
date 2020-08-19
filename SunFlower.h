#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include <QObject>
#include <QMediaPlayer>
#include <QTimer>
#include "Score.h"
#include "Plant.h"

class SunFlower : public QObject , public Plant
{
    Q_OBJECT
private:
    QMediaPlayer* sunflowerPlayer;
    int timeIntervals;
    QTimer * sunflowerTimer;
    Score * sunflowerScore;
public:
    explicit SunFlower(QTimer *sunflowerTimer, Score * sunflowerScore, QGraphicsItem *parent = nullptr);

signals:

public slots:
    void createSun();
};

#endif // SUNFLOWER_H
