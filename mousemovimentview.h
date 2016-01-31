#ifndef MOUSEMOVIMENTVIEW_H
#define MOUSEMOVIMENTVIEW_H

#include <QGraphicsView>

class MouseMovimentView: public QGraphicsView
{
public:
    MouseMovimentView();
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MOUSEMOVIMENTVIEW_H
