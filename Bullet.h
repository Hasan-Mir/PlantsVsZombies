#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

class Bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int velocity;   // (50 miliSec) 20x = pixel per seconds
    QMediaPlayer* bulletPlayer;
public:
    explicit Bullet(QTimer *bulletTimer , const int& velocity ,
                    QGraphicsItem* parent = nullptr);

signals:

public slots:
    void moveToRight();

};

#endif // BULLET_H
