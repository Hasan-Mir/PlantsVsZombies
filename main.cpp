#include <QApplication>
#include "View.h"
#include <cstdlib>
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // seed random number generator
    srand( time(0) );

    // create the game
    auto *myView = new View();
    myView->show();

    return a.exec();
}
