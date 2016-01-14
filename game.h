#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include <QMediaPlayer>
#include "counter.h"
#include <QVBoxLayout>

class Game: public QWidget{
public:
    Game(QWidget *parent=0, int difficulty=0, int timelimit=0);
    void closeEvent(QCloseEvent *event);
    QGraphicsScene *scene;
    QGraphicsView *view;
    QVBoxLayout *layout;
    Score *score;
    Health *health;
    QMediaPlayer *backgroundmusic;
    Player *player;
    int m_difficulty;
    int m_timelimit;
};

#endif // GAME
