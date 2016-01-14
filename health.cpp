#include "health.h"
#include <QFont>
#include <QMessageBox>

extern bool isplaying;

Health::Health(QGraphicsItem *parent,int max): QGraphicsTextItem(parent)
{
    m_health=max;
    setPlainText(QString("Health: ")+QString::number(m_health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("magneto",16));
}

void Health::decrease()
{
    if (m_health>0){
        m_health--;
        setPlainText(QString("Health: ")+QString::number(m_health));
    }
    else{
        isplaying=false;
        setPlainText(QString("Game Over!"));
        setFont(QFont("magneto",32));
        static int endmessage=QMessageBox::critical(0,"Game Over!","Sorry! You lost all your lives.");
    }
}

int Health::getHealth()
{
    return m_health;
}
