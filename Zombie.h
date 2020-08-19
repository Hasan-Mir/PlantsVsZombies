#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Zombie : public QObject , public QGraphicsPixmapItem {
    Q_OBJECT

    protected:
    bool deleteZomb;
    int miliSec;
    int lives;
    int pixPer50MiliSec;    // 20X = pixels per a second
    QMediaPlayer * zombiePlayer;
public:
    Zombie(const int & pixPer50MiliSec , QTimer *timer ,
           const int& lives , QGraphicsItem * parent);
    ~Zombie();
    void decrementLives();

signals:
void decrementZombie();

public slots:
    void moveToLeft();
};

#endif // ZOMBIE_H
