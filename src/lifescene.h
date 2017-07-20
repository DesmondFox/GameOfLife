//
// Сцена для отрисовки клеток
//

#ifndef LIFESCENE_H
#define LIFESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QDebug>

#include "graphicsitemmatrix.h"
#include "lifematrix.h"

class LifeScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LifeScene(ushort width, ushort height, ushort cellWidth, QObject *parent = nullptr);
    ~LifeScene();

    // Задание количества строк/столбцов
    void    setRowColCount(uint row, uint col);
    void    setCellSize(ushort width);

    // Перерисовка сцены. Клетки все ЧИСТЫЕ
    void    drawNewField();

    // Отрисовка матрицы
    void    drawMatrix(const LifeMatrix &mtrx);
    void    fromSceneToMtrx(LifeMatrix &mtrx);

    inline ushort  getRows() const { return rowCount; }
    inline ushort  getCols() const { return colCount; }
    inline short   getCellSize() const { return cellSize; }

    // Очистка поля (НЕ удаление элементов)
    void    clearField();
    // Перерисовка сцены с сохранением состояний клеток

private:
    // Отступ между клетками
    static const short SPACE = 2;

    // Размеры сцены
    ushort  sceneWidth;
    ushort  sceneHeight;
    // Размеры клетки
    ushort  cellSize;

    // Количество строк/столбцов
    uint    rowCount;
    uint    colCount;

    // Матрица графических элементов
    GraphicsItemMatrix itmMatrix;

    // Вычисление количества клеток при заданном размере сцены
    void    solveCellCount();

signals:

public slots:
};

#endif // LIFESCENE_H
