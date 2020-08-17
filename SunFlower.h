#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include <QObject>

class SunFlower : public QObject
{
    Q_OBJECT
public:
    explicit SunFlower(QObject *parent = nullptr);

signals:

};

#endif // SUNFLOWER_H
