#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Controller.h"
#include <QMediaPlayer>
#include "Button.h"

class View : public QGraphicsView{
    Q_OBJECT

private:
    QTimer * viewTimer;
    int seconds;
    Controller * viewController;
    QMediaPlayer * viewPlayer1;
    QMediaPlayer * viewPlayer2;
    Button * startGameButton;
    Button * exitGameButton;
public:
    explicit View();
    ~View();

public slots:
    void schedule();
    void startGame();
    void exitGame();

signals:

};

#endif // VIEW_H
