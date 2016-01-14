#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include "enemy.h"
#include <QtMath>
#include "Game.h"
#include "time.h"
#include <QDebug>

#define windowwidth 500
#define windowheight 500
#define playerspeed 20
#define halfplayersize 20

extern Game *game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    m_enemydir=0;
    srand(time(NULL)); //may be commented out to set a constant scenario
    setPixmap(QPixmap(":/images/player.png")); // extracted from http://pics-about-space.com/space-station-sprite?p=2
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_A && pos().x()>0){
        setPos(x()-playerspeed,y());
    }
    else if (event->key()==Qt::Key_D && pos().x()<windowwidth-2*halfplayersize){
        setPos(x()+playerspeed,y());
    }
    else if (event->key()==Qt::Key_W && pos().y()>0){
        setPos(x(),y()-playerspeed);
    }
    else if (event->key()==Qt::Key_S && pos().y()<windowheight-2*halfplayersize){
        setPos(x(),y()+playerspeed);
    }
    else if (event->key()==Qt::Key_Up){
        Bullet *bullet=new Bullet(pos().x(),pos().y(),qDegreesToRadians(90.0));
        scene()->addItem(bullet);
    }
    else if (event->key()==Qt::Key_Down){
        Bullet *bullet=new Bullet(pos().x(),pos().y(),qDegreesToRadians(270.0));
        scene()->addItem(bullet);
    }
    else if (event->key()==Qt::Key_Left){
        Bullet *bullet=new Bullet(pos().x(),pos().y(),qDegreesToRadians(180.0));
        scene()->addItem(bullet);
    }
    else if (event->key()==Qt::Key_Right){
        Bullet *bullet=new Bullet(pos().x(),pos().y(),qDegreesToRadians(0.0));
        scene()->addItem(bullet);
    }
}

void Player::mouseMoved(int x, int y) //not being called yet
{
    m_angle=qAtan2(y,x);
    qDebug()<<m_angle;
}

void Player::spawn()
{
    Enemy *enemy=new Enemy(m_enemydir,1+rand()%(1+static_cast<int>(round(game->score->getScore()/4))));
    scene()->addItem(enemy);
    m_enemydir=(m_enemydir+1)%4;
}
