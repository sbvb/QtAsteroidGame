#ifndef SCORE
#define SCORE

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    int getScore();
private:
    int m_score;
};

#endif // SCORE
