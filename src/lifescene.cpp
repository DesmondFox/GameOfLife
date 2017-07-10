#include "lifescene.h"


LifeScene::LifeScene(ushort width, ushort height, ushort cellWidth, QObject *parent) : QGraphicsScene(parent)
{
    this->sceneWidth    = width;
    this->sceneHeight   = height;
    this->cellSize      = cellWidth;

    // Обнуление строк/столбцов
    this->rowCount  = 0;
    this->colCount  = 0;

    // Покрасим сцену в серый цвет
    this->setBackgroundBrush(QBrush(Qt::gray));

}

LifeScene::~LifeScene()
{
}

void LifeScene::setRowColCount(uint row, uint col)
{
    // Задать конкретное количество строк/столбцов
    Q_ASSERT(row > 0 && col > 0);

    if (this->rowCount == row && this->colCount == col)
        return;

    this->rowCount  = row;
    this->colCount  = col;

}

void LifeScene::setCellSize(ushort width)
{
    Q_ASSERT(width > 0);

    this->cellSize  = width;
}

void LifeScene::draw()
{
    Q_ASSERT(rowCount > 0 && colCount > 0);
    Q_ASSERT(cellSize > 0);

    itmMatrix.allocate(rowCount, colCount);
    for (size_t i = 0; i < rowCount; i++)
    {
        for (size_t j = 0; j < colCount; j++)
        {
            QRectF  rect;

            // Вычисление координат клетки
            qreal x  = j * cellSize;
            qreal y  = i * cellSize;

            rect.setX(x);               rect.setY(y);
            rect.setWidth(cellSize);    rect.setHeight(cellSize);

            //itmMatrix.setElement(i, j, new LifeCell(rect));
        }
    }

}

