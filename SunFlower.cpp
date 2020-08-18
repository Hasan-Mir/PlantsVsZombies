#include "SunFlower.h"
#include "Sun.h"
#include <QGraphicsScene>
#include <QGraphicsItem>


SunFlower::SunFlower(QTimer *sunflowerTimer, Score * sunflowerScore, QGraphicsItem *parent)
    :QObject() , Plant(parent) ,sunflowerTimer(sunflowerTimer) , sunflowerScore(sunflowerScore)
    , timeIntervals(0)
{

    //set picture
    setPixmap(QPixmap(":/images/sunflower.png"));

    // connect createSun slot
    connect(sunflowerTimer , SIGNAL(timeout()) , this , SLOT(createSun()));

}

void SunFlower::createSun() {
    // increment timeIntervals
    ++timeIntervals;

    // create sun every 15000 miliSec
    if(timeIntervals % 300 == 0){
        // create Sun
        auto sun = new Sun(scene() , sunflowerScore , parentItem() , sunflowerTimer);
        sun->setPos( x(), y());
    }
}
