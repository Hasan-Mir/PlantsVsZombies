#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"
#include "MasterZombie.h"
#include "Block.h"
#include "ShooterBoard.h"
#include "SunflowerBoard.h"
#include "OakBoard.h"
#include "CherryBoard.h"
#include "PlantBoard.h"
#include "Shovel.h"

class Controller : public QObject
{
    Q_OBJECT
    friend class View;
private:
    int level;
    int zombies;
    Shovel* shovel;
    CherryBoard* cherryBoard;
    SunflowerBoard* sunflowerBoard;
    OakBoard* oakboard;
    ShooterBoard* shooterBoard;
    QGraphicsScene * scene;
    QTimer * cTimer;
    QGraphicsRectItem * holder;
    QList<Zombie *> zombieList;
    QList<MasterZombie*> masterZombieList;
    QList<Sun *> sunList;
    QList<Block* > controllerBlocks;
    Score * controllerScore;
    //int timeintervalse;

public:
    explicit Controller(int level = 1 ,QObject *parent = nullptr);
    ~Controller();
    void addZombie(const int& velocity , const int& lives, int line);
    void addMasterZombie(const int& velocity , const int& lives, int line);
    void addSun();
    void addOak();
    void addCherry();
    int getRound();

signals:
    void endRound(int );

public slots:
    void addBoard();
    void calculateZombie();
};

#endif // CONTROLLER_H
