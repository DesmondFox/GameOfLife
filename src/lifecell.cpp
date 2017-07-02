#include "lifecell.h"

LifeCell::LifeCell(const QRectF &rect, QGraphicsItem *parent)
    : QGraphicsRectItem(rect, parent)
{
    // При инициализации клетки - она мертвая
    currentStatus = C_DIED;
}

void LifeCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Если клетка живая была до нажатия, то перекрашиваем и делаем её мертвой
    if (currentStatus == C_ALIVE)
    {
        this->setBrush(QBrush(Qt::white));
        currentStatus   = C_DIED;
    }
    // Аналогично с мертвой клеткой
    if (currentStatus == C_DIED)
    {
        this->setBrush(QBrush(Qt::black));
        currentStatus   = C_ALIVE;
    }
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
        this->setBrush(Qt::white);
    if (stt == C_DIED)
        this->setBrush(Qt::black);
}
