#include "Controller.h"
#include "Shooter.h"
#include "SunFlower.h"
#include "Oak.h"
#include "Cherry.h"
#include <cstdlib>



Controller::Controller(QObject *parent) : QObject(parent){
    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    // create holder
    holder = new QGraphicsRectItem();
    holder->setRect(0,0,800,600);

    // create and start ctimer
    cTimer = new QTimer();
    cTimer->start(50);

    // add score board
    controllerScore = new Score(holder);
    scene->addItem(controllerScore);
    controllerScore->setPos(30,57);

    // add a test shooter
    auto myShooter = new Shooter(cTimer , holder);
    scene->addItem(myShooter);
    myShooter->setPos(40+300,375);

    // add a test SunFlower
    auto mySunFlower = new SunFlower(cTimer, controllerScore , holder);
    scene->addItem(mySunFlower);
    mySunFlower->setPos(40,375);


    // add a test Oak
//    auto myOak = new Oak(cTimer , 10 , holder);
//    scene->addItem(myOak);
//    myOak->setPos(40,375);

}

Controller::~Controller() {
    delete holder;
    delete cTimer;
    delete scene;
}

void Controller::addZombie(const int& velocity , const int& lives) {
    zombieList.push_back(new Zombie(velocity , cTimer , lives ,holder));
    // add to the scene
    scene->addItem(zombieList.last());
    zombieList.last()->setPos(800,390);
}

void Controller::addMasterZombie(const int &velocity, const int &lives)
{
    masterZombieList.push_back(new MasterZombie(velocity , cTimer , lives ,holder));
    // add to the scene
    scene->addItem(masterZombieList.last());
    masterZombieList.last()->setPos(800,370);
}

void Controller::addSun() {
    sunList.push_back(new Sun(scene , controllerScore , holder , cTimer));
    sunList.last()->setPos( rand() % 800 , 0);
}

// test
void Controller::addOak() {
    auto myOak = new Oak(cTimer , 10 , holder);
    scene->addItem(myOak);
    myOak->setPos(40,375);
}

void Controller::addCherry(){
    auto myCherry = new Cherry(cTimer , holder);
    scene->addItem(myCherry);
    myCherry->setPos(380,150);
}
