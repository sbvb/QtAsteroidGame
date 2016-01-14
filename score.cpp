#include "score.h"
#include <QFont>

extern bool isplaying;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    m_score=0;
    setPlainText(QString("Score: ")+QString::number(m_score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("magneto",16));
}

void Score::increase()
{
    if(isplaying){
        m_score++;
        setPlainText(QString("Score: ")+QString::number(m_score));
    }
}

int Score::getScore()
{
    return m_score;
}
