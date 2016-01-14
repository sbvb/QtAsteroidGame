#ifndef COUNTER_H
#define COUNTER_H

#include <QGraphicsTextItem>

class Counter: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Counter(QGraphicsItem *parent=0, int timelimit=0);
    int getCounter();
private:
    int m_time;
public slots:
    void decrease();
};

#endif // COUNTER_H
