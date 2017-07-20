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
    this->setBackgroundBrush(QBrush(QColor(200, 200, 200, 100)));

    // Сразу вычислим строки/столбцы
    this->solveCellCount();
}

LifeScene::~LifeScene()
{
}

void LifeScene::setRowColCount(uint row, uint col)
{
    // Задать конкретное количество строк/столбцов
    Q_ASSERT(row > 0 && col > 0);

    this->rowCount  = row;
    this->colCount  = col;
    this->itmMatrix.reallocate(row, col);
}

void LifeScene::setCellSize(ushort width)
{
    Q_ASSERT(width > 0);

    qDebug() << "Notice:\t Proc: Resizing of cell: " << width;
    this->cellSize = width;
}

void LifeScene::drawNewField()
{
    Q_ASSERT(rowCount > 0 && colCount > 0);
    Q_ASSERT(cellSize > 0);

    for (size_t i = 0; i < rowCount; i++)
    {
        for (size_t j = 0; j < colCount; j++)
        {
            QRectF  rect;

            // Вычисление координат клетки
            qreal x  = j * (cellSize+SPACE);
            qreal y  = i * (cellSize+SPACE);

            rect.setX(x);               rect.setY(y);
            rect.setWidth(cellSize);    rect.setHeight(cellSize);

            // Добавление элемента на сцену
            itmMatrix.setElement(i, j, new LifeCell(rect));
            this->addItem(itmMatrix.getElement(i, j));
        }
    }

}

void LifeScene::drawMatrix(const LifeMatrix &mtrx)
{

    Q_ASSERT(mtrx.getCountRows()    == this->itmMatrix.getCountRows());
    Q_ASSERT(mtrx.getCountColumns() == this->itmMatrix.getCountColumns());

    size_t  rows = mtrx.getCountRows(),
            cols = mtrx.getCountColumns();

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            bool currStt    = mtrx.getElement(i, j);
            CellStatus stt  = (currStt) ? C_ALIVE : C_DIED;
            this->itmMatrix.getElement(i, j)->changeStatus(stt);
        }
}

void LifeScene::fromSceneToMtrx(LifeMatrix &mtrx)
{
    // Метод для извлечения состояния клеток з сцены в матрицу
    Q_ASSERT(mtrx.getCountRows()    == this->itmMatrix.getCountRows());
    Q_ASSERT(mtrx.getCountColumns() == this->itmMatrix.getCountColumns());

    size_t  rows = mtrx.getCountRows(),
            cols = mtrx.getCountColumns();

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            CellStatus currStt = this->itmMatrix.getElement(i, j)->getStatus();
            bool stt = (currStt == C_ALIVE) ? true : false;

            mtrx.setElement(i, j, stt);
        }
}

void LifeScene::clearField()
{
    // Очистка поля
    itmMatrix.allDead();
}

void LifeScene::solveCellCount()
{
    // Вычисление количества клеток при заданном размере сцены

    rowCount    = sceneHeight / (cellSize+SPACE);
    colCount    = sceneWidth  / (cellSize+SPACE);
}

