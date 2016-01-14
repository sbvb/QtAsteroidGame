#ifndef HEALTH
#define HEALTH

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem *parent=0, int max=3);
    void decrease();
    int getHealth();
private:
    int m_health;
};

#endif // HEALTH
