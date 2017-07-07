#include "lifescene.h"


LifeScene::LifeScene(ushort width, ushort height, QObject *parent) : QGraphicsScene(parent)
{
    // Установка начальных значений

    // Интересно то, что надо немного уменьшить размер поля, т.к. вылезает полоса прокрутки.
    // Костыль или нет - хз
    sceneHeight = height-3;
    sceneWidth  = width-3;
    // TODO: решить проблему с полосой прокрутки

    qDebug() << "Notice:\t Scene: Scene created with size [" << sceneWidth << " x " << sceneHeight << "]";

    // Указателям присвоить nullptr
    m_itemGroup = nullptr;

    // Фон сцены - серый
    this->addRect(0.0, 0.0, (qreal) sceneWidth, (qreal) sceneHeight,
                  QPen(QColor(Qt::gray)), QBrush(Qt::gray));

}

void LifeScene::setField(size_t row, size_t col, unsigned short cellWidth)
{
    qDebug() << "Notice:\t Scene: Changing a field size as [" << row << " x " << col << "] " << cellWidth << "px";

    Q_ASSERT(row > 0 && col > 0);
    Q_ASSERT(cellWidth < MaxSizeOfCell);  // ограничение на размер клетки

    this->rowCount  = row;
    this->colCount  = col;
    this->cellSize  = cellWidth;
}

void LifeScene::setCellSize(ushort width)
{
    // Проверим, подходит ли максимальному размеру
    Q_ASSERT(width <= MaxSizeOfCell);

    cellSize    = width;

}

void LifeScene::draw()
{
    //
    // Рисовать клетки и добавлять в группу элементов
    //

    const ushort space = 1;

    Q_ASSERT(rowCount > 0 && colCount > 0);

    // Проверим на НЕсуществование группы элементов
    if (m_itemGroup != nullptr)
        return;

    m_itemGroup = new QGraphicsItemGroup();
    m_itemGroup->setHandlesChildEvents(false);
    this->addItem(m_itemGroup);

    LifeCell    *pCell  = nullptr;
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

            pCell   = new LifeCell(rect);

            m_itemGroup->addToGroup(pCell);
        }
    }


}
