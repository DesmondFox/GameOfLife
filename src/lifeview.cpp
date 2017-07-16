#include "lifeview.h"

LifeView::LifeView(QWidget *parent) : QGraphicsView(parent)
{

}

void LifeView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    event->accept();
}
