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
    void    draw();

    // Отрисовка матрицы
    void    drawMatrix(const LifeMatrix &mtrx);
    void    fromSceneToMtrx(LifeMatrix &mtrx);

    inline ushort  getRows() const { return rowCount; }
    inline ushort  getCols() const { return colCount; }

    // Очистка поля (НЕ удаление элементов)
    void    clearField();

private:
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
