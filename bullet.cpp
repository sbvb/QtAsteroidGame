#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"
#include <QtMath>
#include <time.h>

#define bulletwidth 5
#define bulletheight 5
#define windowwidth 500
#define windowheight 500
#define bulletspeed 20
#define halfplayersize 25

extern Game *game;

Bullet::Bullet(int x, int y, float angle)
{
    this->setBrush(QBrush(Qt::white));
    setPos(x+halfplayersize,y+halfplayersize);
    setRect(0,0,bulletwidth,bulletheight);
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    m_angle=angle;
    srand(time(NULL)); //may be commented out to set a constant scenario
}

void Bullet::move()
{
    QList<QGraphicsItem*>colliding_items=collidingItems();
    for (int i=0,n=colliding_items.size();i<n;i++){
        if (typeid(*(colliding_items[i]))==typeid(Enemy)){
            if (static_cast<Enemy*>(colliding_items[i])->m_element>1){
                Enemy *fission1=new Enemy(0,static_cast<Enemy*>(colliding_items[i])->m_element-1);
                fission1->setPos(x(),y()+20+5*fission1->m_element);
                scene()->addItem(fission1);
                Enemy *fission2=new Enemy(2,1);
                fission2->setPos(x(),y());
                scene()->addItem(fission2);
                Bullet *bullet1; //avoids cross initialization errors
                Bullet *bullet2; //avoids cross initialization errors
                switch (rand()%6){
                    case 0:
                        bullet1=new Bullet(x(),y(),qDegreesToRadians(90.0));
                        scene()->addItem(bullet1);
                        bullet2=new Bullet(x(),y(),qDegreesToRadians(270.0));
                        scene()->addItem(bullet2);
                        break;
                    case 1:
                        bullet1=new Bullet(x(),y(),qDegreesToRadians(0.0));
                        scene()->addItem(bullet1);
                        bullet2=new Bullet(x(),y(),qDegreesToRadians(180.0));
                        scene()->addItem(bullet2);
                        break;
                    case 2:
                        bullet1=new Bullet(x(),y(),qDegreesToRadians(0.0));
                        scene()->addItem(bullet1);
                        bullet2=new Bullet(x(),y(),qDegreesToRadians(90.0));
                        scene()->addItem(bullet2);
                        break;
                    case 3:
                        bullet1=new Bullet(x(),y(),qDegreesToRadians(0.0));
                        scene()->addItem(bullet1);
                        bullet2=new Bullet(x(),y(),qDegreesToRadians(270.0));
                        scene()->addItem(bullet2);
                        break;
                    case 4:
                        bullet1=new Bullet(x(),y(),qDegreesToRadians(180.0));
                        scene()->addItem(bullet1);
                        bullet2=new Bullet(x(),y(),qDegreesToRadians(90.0));
                        scene()->addItem(bullet2);
                        break;
                    case 5:
                        bullet1=new Bullet(x(),y(),qDegreesToRadians(180.0));
                        scene()->addItem(bullet1);
                        bullet2=new Bullet(x(),y(),qDegreesToRadians(270.0));
                        scene()->addItem(bullet2);
                        break;
                }
            }
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            if (static_cast<Enemy*>(colliding_items[i])->m_symbol)
                delete static_cast<Enemy*>(colliding_items[i])->m_symbol;
            if (colliding_items[i])
                delete colliding_items[i];
            if (this)
                delete this;
            return;
        }
    }
    setPos(x()+bulletspeed*qCos(m_angle),y()-bulletspeed*qSin(m_angle));
    if (pos().y()<0 || pos().y()>windowheight || pos().x()<0 || pos().x()>windowwidth){
        scene()->removeItem(this);
        if (this)
            delete this;
    }
}
