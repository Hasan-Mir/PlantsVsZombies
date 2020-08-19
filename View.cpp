#include "View.h"


View::View()
{
    //create viewController
    viewController = new Controller();

    //connect view and controller
    connect(viewController, SIGNAL(endRound(int )), this, SLOT(endRoundSlot(int )));
    connect(this , SIGNAL(gameStart()) , viewController , SLOT(addBoard()));

    // create scene
    setScene(viewController->scene);

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/homePage.png")));

    // create home page buttons
    startGameButton = new Button();
    startGameButton->setPixmap(QPixmap(":/images/startButton.png"));
    startGameButton->setPos(381 , 496);
    exitGameButton = new Button();
    exitGameButton->setPixmap(QPixmap(":/images/exitButton.png"));
    exitGameButton->setPos(381 , 550);

    // add button to the scene
    viewController->scene->addItem(startGameButton);
    viewController->scene->addItem(exitGameButton);

    // connect buttons to view slots
    connect(startGameButton , SIGNAL(buttonClicked()) , this , SLOT(startGame()) );
    connect(exitGameButton , SIGNAL(buttonClicked()) , this , SLOT(exitGame()) );

    // set fixed size
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set home page's background music
    viewPlayer1 = new QMediaPlayer();
    viewPlayer1->setMedia(QUrl("qrc:/musics/MainMenuPvZ1.mp3"));
    viewPlayer1->play();

    // initialize seconds to zero
    seconds = 0;

    //set line
    line = (rand() % viewController->level) + 1;
}

View::~View() {
    delete viewTimer;
    delete viewController;
    delete viewPlayer1;
}

void View::schedule(){
   ++seconds;

    if (viewController->getRound() == 1) {
        setBackgroundBrush(QBrush(QImage(":/images/bgstepone.png")));
        if(seconds == 50 || seconds == 54 || seconds == 57 || seconds == 59 || seconds == 60){
            viewController->addZombie(5 , 4, 1);
        }
    }

     else if (viewController->getRound() == 2) {
        setBackgroundBrush(QBrush(QImage(":/images/bgsteptwo.png")));
        if( line == 1){
            if(seconds == 45 || seconds == 48 ||seconds == 50 ||seconds == 51 ||seconds == 52){
                viewController->addZombie(5 , 4, line);
            }

            if(seconds == 48 || seconds == 49 ||seconds == 50 ||seconds == 51 ||seconds == 52){
                viewController->addZombie(5 , 4, line + 1);
            }
        }
        if(line == 2){
            if(seconds == 45 || seconds == 48 ||seconds == 50 ||seconds == 51 ||seconds == 52){
                viewController->addZombie(5 , 4, line);
            }

            if(seconds == 48 || seconds == 49 ||seconds == 50 ||seconds == 51 ||seconds == 52){
                viewController->addZombie(5 , 4, line - 1);
            }
        }

    }

     else if (viewController->getRound() == 3){
        setBackgroundBrush(QBrush(QImage(":/images/bgstepthree.png")));
        if(seconds == 40 || seconds == 47 ||seconds == 48 ||seconds == 50 ||seconds == 53){
            viewController->addMasterZombie(5 , 10, 1);
        }
        if(seconds == 44 || seconds == 47 ||seconds == 50 ||seconds == 51 ||seconds == 53){
            viewController->addMasterZombie(5 , 10, 2);
        }
        if(seconds == 46 || seconds == 48 ||seconds == 50 ||seconds == 51 ||seconds == 53){
            viewController->addMasterZombie(5 , 10, 3);
        }
    }

    // add sun every 2 seconds
    if(seconds % 2 == 0){
        viewController->addSun();
    }
}

void View::startGame()
{
    // stop home page's music
    viewPlayer1->stop();

    // remove button
    viewController->scene->removeItem(startGameButton);

    exitGameButton->setPos(695,0);
    delete startGameButton;

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/bgstepone.png")));

    // set background music
    viewPlayer2 = new QMediaPlayer();
    viewPlayer2->setMedia(QUrl("qrc:/musics/GrasswalkPvZ1.mp3"));
    viewPlayer2->play();

    // start timer
    viewTimer = new QTimer();
    viewTimer->start(1000);
    connect(viewTimer , SIGNAL(timeout()) , this , SLOT(schedule()));
    //connect(viewTimer , SIGNAL(timeout()) , viewController , SLOT(addBoard()));

    emit gameStart();
}

void View::exitGame(){
    exit(0);
}

void View::endRoundSlot(int level)
{
    Controller* viewControl = viewController;
    viewController = new Controller( level );

    setScene(viewController->scene);
    connect(viewController, SIGNAL(endRound(int )), this, SLOT(endRoundSlot(int )));
    connect(this , SIGNAL(gameStart()) , viewController , SLOT(addBoard()));
    emit gameStart();
}



