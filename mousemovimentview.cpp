#include "mousemovimentview.h"
#include "player.h"

extern Player *player;

MouseMovimentView::MouseMovimentView():QGraphicsView()
{

}

void MouseMovimentView::mouseMoveEvent(QMouseEvent *event)
{
    player->mouseMoved(event->x(),event->y());
}
