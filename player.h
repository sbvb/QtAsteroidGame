#ifndef PLAYER
#define PLAYER

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void mouseMoved(int x, int y);
    int m_enemydir;
    float m_angle;
public slots:
    void spawn();
};

#endif // PLAYER
