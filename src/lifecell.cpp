#include "lifecell.h"

LifeCell::LifeCell(const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsRectItem(rect, parent)
{
    // При запуске клетка изначально мертвая
    changeStatus(C_DIED);


}

void LifeCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Если клетка живая была до нажатия, то перекрашиваем и делаем её мертвой
    changeStatus((currentStatus == C_ALIVE) ? C_DIED : C_ALIVE);
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
}
