#ifndef LIFECELL_H
#define LIFECELL_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QBrush>
#include <QRectF>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPen>

// Состояние клетки
enum CellStatus
{
    C_ALIVE,    // Клетка живая
    C_DIED      // Клетка мертвая
};

class LifeCell : public QGraphicsRectItem
{
public:
    explicit LifeCell(const QRectF &rect, QGraphicsItem *parent = nullptr);

    // Изменение состояния клетки
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // Получение текущего состояния клетки
    CellStatus getStatus() const;

    // Изменение состояния клетки через метод
    void changeStatus(CellStatus stt);

private:
    // текущее состояние клетки (живая/мертвая)
    CellStatus currentStatus;
signals:

public slots:
};

#endif // LIFECELL_H
