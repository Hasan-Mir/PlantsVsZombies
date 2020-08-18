#ifndef MASTERZOMBIE_H
#define MASTERZOMBIE_H

#include <QObject>
#include "Zombie.h"


class MasterZombie : public Zombie
{
    Q_OBJECT
public:
    explicit MasterZombie(const int & pixPer50MiliSec , QTimer *timer ,
                          const int& lives , QGraphicsItem * parent);

signals:

public slots:
    void moveToLeft();

};

#endif // MASTERZOMBIE_H
