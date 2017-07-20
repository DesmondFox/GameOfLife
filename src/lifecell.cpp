#include "lifecell.h"

LifeCell::LifeCell(const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsRectItem(rect, parent)
{
    // При запуске клетка изначально мертвая
    changeStatus(C_DIED);
    this->setAcceptHoverEvents(true);

}

void LifeCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Если клетка живая была до нажатия, то перекрашиваем и делаем её мертвой


    if (event->button() == Qt::LeftButton)
    {
        changeStatus(C_ALIVE);

    }
    if (event->button() == Qt::RightButton)
    {
        changeStatus(C_DIED);
    }
    QGraphicsRectItem::mousePressEvent(event);


}

CellStatus LifeCell::getStatus() const
{
    return currentStatus;
}

void LifeCell::changeStatus(CellStatus stt)
{
    // Изменяем состояние и перекрашиваем
    currentStatus = stt;
    if (stt == C_ALIVE)
        this->setBrush(Qt::black);
    if (stt == C_DIED)
        this->setBrush(Qt::white);
    this->setPen(QPen(QColor(200, 200, 200, 100)));
}
