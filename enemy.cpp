#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <typeinfo>
#include "player.h"
#include "game.h"
#include <time.h>
#include <QGraphicsTextItem>

#define windowwidth 500
#define windowheight 500
#define enemyradius 20
#define maxinc 10
#define fixedspeed 3

extern Game *game;

Enemy::Enemy(int dir, float element)
{
    m_dir=dir;
    m_element=element;
    srand(time(NULL)); //may be commented out to set a constant scenario
    if (m_dir==0) //enemy comes from top
        setPos(rand()%windowwidth-enemyradius,0);
    else if (m_dir==1) //enemy comes from right
        setPos(windowwidth,rand()%windowheight-enemyradius);
    else if (m_dir==2) //enemy comes from bottom
        setPos(rand()%windowwidth-enemyradius,windowheight);
    else if (m_dir==3) //enemy comes from left
        setPos(0,rand()%windowheight-enemyradius);
    m_inc=rand()%maxinc;
    m_incdir=rand()%2;
    if (m_incdir==0)
        m_incdir=-1;
    m_speed=m_incdir*m_inc;
    setRect(0,0,enemyradius+(element-1)*5,enemyradius+(element-1)*5);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    switch ((m_element-1)%5){
        case 0:
            this->setBrush(Qt::green);
            break;
        case 1:
            this->setBrush(Qt::yellow);
            break;
        case 2:
            this->setBrush(Qt::red);
            break;
        case 3:
            this->setBrush(Qt::gray);
            break;
        case 4:
            this->setBrush(Qt::white);
    }
    m_symbol=new QGraphicsTextItem();
    m_symbol->setPlainText(QString::number(m_element));
    m_symbol->setDefaultTextColor(Qt::black);
    m_symbol->setFont(QFont("magneto",12));
    m_symbolAdded=false;
}

void Enemy::move()
{
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for (int i=0,n=colliding_items.size();i<n;i++){
        if (typeid(*(colliding_items[i]))==typeid(Player)){
            game->health->decrease();
            scene()->removeItem(this);
            if (m_symbol)
                delete m_symbol;
            if (this)
                delete this;
            return;
        }
        if (typeid(*(colliding_items[i]))==typeid(Enemy)){
            Enemy *fusion=new Enemy(rand()%3,static_cast<Enemy*>(colliding_items[i])->m_element+m_element);
            fusion->setPos(x(),y());
            scene()->addItem(fusion);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            if (static_cast<Enemy*>(colliding_items[i])->m_symbol)
                delete static_cast<Enemy*>(colliding_items[i])->m_symbol;
            if (colliding_items[i])
                delete colliding_items[i];
            if (m_symbol)
                delete m_symbol;
            if (this)
                delete this;
            return;
        }
    }
    if (m_dir==0)
        setPos(x()+m_speed,y()+fixedspeed-(m_element-1)/4);
    else if (m_dir==1)
        setPos(x()-fixedspeed+(m_element-1)/4,y()+m_speed);
    else if (m_dir==2)
        setPos(x()+m_speed,y()-fixedspeed+(m_element-1)/4);
    else if (m_dir==3)
        setPos(x()+fixedspeed-(m_element-1)/4,y()+m_speed);
    if (pos().y()<0 || pos().y()>windowheight || pos().x()<0 || pos().x()>windowwidth){
        scene()->removeItem(this);
        if (m_symbol)
            delete m_symbol;
        if (this)
            delete this;
        return;
    }
    m_symbol->setPos(x()+3,y());
    if (!m_symbolAdded){
        scene()->addItem(m_symbol);
        m_symbolAdded=true;
    }
}
