#include "Controller.h"
#include "Shooter.h"
#include "SunFlower.h"
#include "Oak.h"
#include <cstdlib>
#include "View.h"


Controller::Controller(int level ,QObject *parent)
    : QObject(parent), level{level}, zombies{2} {
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

    //set shovel
    shovel = new Shovel(holder);

    //set palnt boards
    shooterBoard = new ShooterBoard(holder);
    sunflowerBoard = new SunflowerBoard(holder);
    oakboard = new OakBoard(holder);
    cherryBoard = new CherryBoard(holder);

    for (int i{0}; i < level ; ++i){
        for(int j{0}; j < 8 ; ++j){
            // create the block
            controllerBlocks.push_back( new Block(holder, controllerScore));

            //setting size of block
            controllerBlocks.last()->setRect( 0, 0 , 80 , 107 );
            controllerBlocks.last()->setPos(34 + ( j*80 ), 382 - ( i*108 ));

            // set pen for the block
            QPen pen{"green"};
            pen.setStyle(Qt::NoPen);
            controllerBlocks.last()->setPen(pen);

            //add to scene
            scene->addItem(controllerBlocks.last());

            //connect block to score
            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToScore(int )),
                                                  controllerScore, SLOT(isPlaced(int )));

            //send signal that plants is placed
            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  shooterBoard , SLOT(isPlaced()));

            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  sunflowerBoard , SLOT(isPlaced()));

            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  oakboard , SLOT(isPlaced()));

            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  cherryBoard , SLOT(isPlaced()));

            //select from board and send signal to block to change its related flag to true
            connect(shooterBoard , SIGNAL(ShooterSellected()),
                                      controllerBlocks.last() , SLOT(ShooterSellected()));

            connect(sunflowerBoard , SIGNAL(sunflowerSellected()),
                                      controllerBlocks.last() , SLOT(SunFlowerSellected()));

            connect(oakboard , SIGNAL(OakSellected()),
                                      controllerBlocks.last() , SLOT(OakSellected()));

            connect(cherryBoard , SIGNAL(CherrySelected()),
                                      controllerBlocks.last() , SLOT(CherrySellected()));

            //Unselect signal
            connect(shooterBoard , SIGNAL(UnselectShooter()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(sunflowerBoard , SIGNAL(UnselectSunflower()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(oakboard , SIGNAL(UnselectOak()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(cherryBoard , SIGNAL(UnSelectCherry()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            //connect score to board(send amount of score)
            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      shooterBoard , SLOT(slotPlayerScore(int )));

            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      sunflowerBoard , SLOT(slotPlayerScore(int )));

            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      oakboard , SLOT(slotPlayerScore(int )));

            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      cherryBoard , SLOT(slotPlayerScore(int )));


            // connect shovel to the block
            connect(shovel , SIGNAL(UnselectShovel()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(shovel , SIGNAL(ShovelSellected()),
                                      controllerBlocks.last() , SLOT(ShovelSellected()));

            connect(controllerBlocks.last() , SIGNAL(isDeleted()),
                                       shovel, SLOT(isDelete()));
        }
    }


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

void Controller::addZombie(const int& velocity , const int& lives, int line) {
    zombieList.push_back(new Zombie(velocity , cTimer , lives ,holder));
    // add to the scene
    scene->addItem(zombieList.last());

    //signal for zombie die
    connect(zombieList.last() , SIGNAL(decrementZombie()) , this , SLOT(calculateZombie()));

    zombieList.last()->setPos(800 ,490 - 100*line );
}

void Controller::addMasterZombie(const int &velocity, const int &lives, int line)
{
    masterZombieList.push_back(new MasterZombie(velocity , cTimer , lives ,holder));
    // add to the scene
    scene->addItem(masterZombieList.last());
    masterZombieList.last()->setPos(800,490 - 100*line);
}

void Controller::addSun() {
    sunList.push_back(new Sun(scene , controllerScore , holder , cTimer));
    sunList.last()->setPos( rand() % 800 , 0);
}

int Controller::getRound()
{
    return level;
}

void Controller::addBoard()
{
    //zombies = 2;
    scene->addItem(shooterBoard);
    scene->addItem(sunflowerBoard);
    scene->addItem(shovel);

    if ( level >= 2){
        zombies = 10;
        scene->addItem(oakboard);
    }

    if (level >= 3){
        zombies = 15;
        scene->addItem(cherryBoard);
    }
}

void Controller::calculateZombie()
{
    --zombies;
    if(zombies == 0){
        level++;
        //exit(0);
        if(level > 3){
            exit(0);
        }
        emit endRound( level );
    }
}

// test
//void Controller::addOak() {
//    auto myOak = new Oak(cTimer , 10 , holder);
//    scene->addItem(myOak);
//    myOak->setPos(40,375);
//}
