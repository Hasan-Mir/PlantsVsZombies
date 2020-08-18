#include "View.h"

View::View()
{
    //create viewController
    viewController = new Controller();

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
}

View::~View() {
    delete viewTimer;
    delete viewController;
    delete viewPlayer1;
}

void View::schedule(){
   ++seconds;

    if(seconds == 10 || seconds == 15){
        viewController->addZombie(5 , 10);
        //viewController->addOak();
        //viewController->addCherry();
    }

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
}

void View::exitGame(){
    exit(0);
}
