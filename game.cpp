#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QCloseEvent>

#define windowwidth 500
#define windowheight 500
#define timetospawn 3000 //in miliseconds
#define soundvolume 50
#define enemiesperspawn 4
#define halfplayersize 25

bool isplaying;

Game::Game(QWidget *parent, int difficulty, int timelimit){
    m_difficulty=difficulty;
    m_timelimit=timelimit;
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,windowwidth,windowheight);
    QPixmap bg(":/images/backgroundimage.png");
    scene->setBackgroundBrush(bg);
    player=new Player();
    player->setPos(windowwidth/2-halfplayersize,windowheight/2-halfplayersize);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    score=new Score();
    scene->addItem(score);
    health=new Health(0,4-m_difficulty);
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    if (m_timelimit!=0){
        Counter *counter=new Counter(0,m_timelimit);
        counter->setPos(health->x()+380,health->y()-25);
        scene->addItem(counter);
        QTimer *timer=new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),counter,SLOT(decrease()));
        timer->start(1000);
    }
    view=new QGraphicsView(scene);
    QTimer *enemytimer=new QTimer();
    for (int i=0;i<enemiesperspawn;i++)
        QObject::connect(enemytimer,SIGNAL(timeout()),player,SLOT(spawn()));
    enemytimer->start(timetospawn);
    backgroundmusic=new QMediaPlayer();
    backgroundmusic->setMedia(QUrl("qrc:/sounds/backgroundmusic.mp3")); //"[AMIGA MUSIC] Blasteroids -01- Ecran Titre", extracted from youtube.com
    backgroundmusic->setVolume(soundvolume);
    backgroundmusic->play();
    isplaying=true;
    layout=new QVBoxLayout();
    layout->addWidget(view);
    setLayout(layout);
    show();
}

void Game::closeEvent(QCloseEvent *event)
{
    event->accept();
    backgroundmusic->stop();
    delete backgroundmusic;
    delete player;
    delete score;
    delete health;
    delete scene;
    delete view;
    delete layout;
    delete this;
}
