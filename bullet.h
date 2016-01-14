#ifndef BULLET
#define BULLET

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet(int x, int y, float angle);
    float m_angle;
public slots:
    void move();
};

#endif // BULLET
