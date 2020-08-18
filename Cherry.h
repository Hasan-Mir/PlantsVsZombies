#ifndef CHERRY_H
#define CHERRY_H

#include <QObject>
#include <QMediaPlayer>
#include "Plant.h"

class Cherry : public QObject , public Plant
{
    Q_OBJECT
private:
    int timeIntervals;
    QMediaPlayer *cherryPlayer;
public:
    explicit Cherry(QTimer * cherryTimer ,QGraphicsItem *parent = nullptr);
signals:

public slots:
    void explode();

};

#endif // CHERRY_H
