#ifndef ENEMY
#define ENEMY

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsTextItem>

class Enemy: public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    bool m_symbolAdded;
    int m_dir;
    int m_inc;
    int m_incdir;
    int m_speed;
    int m_element;
    QGraphicsTextItem *m_symbol;
    Enemy(int dir, float element);
public slots:
    void move();
};

#endif // ENEMY
