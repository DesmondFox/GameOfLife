#include "lifescene.h"


LifeScene::LifeScene(ushort width, ushort height, short cellWidth, QObject *parent) : QGraphicsScene(parent)
{
    // Установка начальных значений

    Q_ASSERT(width > 0 && height > 0);

    // Обнулим переменные
    cellSize    = 0;
    colCount    = 0;
    rowCount    = 0;

    // Интересно то, что надо немного уменьшить размер поля, т.к. вылезает полоса прокрутки.
    // Костыль или нет - хз
    sceneHeight = height-3;
    sceneWidth  = width-3;
    // Зададим размеры клетки
    setCellSize(cellWidth);
    // FIXME: решить проблему с полосой прокрутки

    qDebug() << "Notice:\t Scene: Scene created with size [" << sceneWidth << " x " << sceneHeight << "]";

    // Указателям присвоить nullptr
    m_itemGroup = nullptr;

    // Фон сцены - серый
    this->addRect(0.0, 0.0, (qreal) sceneWidth, (qreal) sceneHeight,
                  QPen(QColor(Qt::gray)), QBrush(Qt::gray));


    // Посчитаем поле
    resolveCells();
}

void LifeScene::setField(uint row, uint col)
{
    qDebug() << "Notice:\t Scene: Changing a field size as [" << row << " x " << col << "] " << cellWidth << "px";

    Q_ASSERT(row > 0 && col > 0);
    Q_ASSERT(cellWidth < MaxSizeOfCell);  // ограничение на размер клетки

    this->rowCount  = row;
    this->colCount  = col;
}

void LifeScene::resolveCells()
{
    // Просчет количества клеток

    rowCount = sceneHeight / cellSize;
    colCount = sceneWidth  / cellSize;

    qDebug() << "Notice:\t Scene: Row count / col count: " << rowCount << " / " << colCount;
}

void LifeScene::setCellSize(ushort width)
{
    // Проверим, подходит ли максимальному размеру
    Q_ASSERT(width <= MaxSizeOfCell);
    Q_ASSERT(width > 0);

    cellSize    = width;
}

void LifeScene::drawCleanField()
{
    //
    // Рисовать чистое поле
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

void LifeScene::drawMatrix(const LifeMatrix &mtrx)
{
    // TODO: написать метод отрисовки матрицы
}

void LifeScene::resizeField(uint _row, uint _col, ushort _cellw)
{
    // Изменение поля(количество полей/столбцов)

    if (_row == rowCount && _col == colCount)
        return;

    this->setCellSize(_cellw);
    this->setField(_row, _col);
}
