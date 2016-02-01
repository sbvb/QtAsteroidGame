#include "counter.h"
#include <QFont>
#include <QMessageBox>

#define windowwidth 485

extern bool isplaying;

Counter::Counter(QGraphicsItem *parent, int timelimit)
{
    m_time=timelimit;
    setPlainText(QString("Time: ")+QString::number(m_time));
    setDefaultTextColor(Qt::red);
    setFont(QFont("magneto",16));
}

void Counter::decrease()
{
    if(m_time>0){
        m_time--;
        setPlainText(QString("Time: ")+QString::number(m_time));
    }
    else{
        isplaying=false;
        setPlainText(QString("Time's up!"));
        setFont(QFont("magneto",32));
        setPos(windowwidth/2,y());
        static int endmessage=QMessageBox::critical(0,"Time's up!","Your time limit has been reached!");
    }
}

int Counter::getCounter()
{
    return m_time;
}
