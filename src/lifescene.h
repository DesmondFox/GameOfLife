//
// Сцена для отрисовки клеток
//

#ifndef LIFESCENE_H
#define LIFESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QDebug>

#include "lifecell.h"
#include "lifematrix.h"

class LifeScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LifeScene(ushort width, ushort height, short cellWidth, QObject *parent = nullptr);

    // Загрузка размеров поля и клеток
    void    setCellSize(ushort width);

    // тестовая функция для отладки
    void    drawCleanField();

    // Метод отрисовки заданной матрицы
    void    drawMatrix(const LifeMatrix &mtrx);

    // изменение размеров сцены (по колич клеток)
    void    resizeField(uint _row, uint _col, ushort _cellw);

    // Геттеры/сеттеры
    inline uint getRowCount() const { return rowCount; }
    inline uint getColCount() const { return colCount; }

private:
    // максимальный размер клетки
    static const ushort MaxSizeOfCell = 100;

    // Количество ячеек (ряды/столбцы)
    ushort rowCount;    // Количество рядов из клеток
    ushort colCount;    // Количество столбцов из клеток
    short  cellSize;    // Длинна стороны клетки

    // Размер сцены
    int sceneWidth;
    int sceneHeight;

    // Рисовка клеток
    QGraphicsItemGroup *m_itemGroup;    // группа клеток (для удобства изменений)

    // Задание количества клеток
    void    setField(uint row, uint col);
    // Просчет количества клеток
    void    resolveCells();
signals:

public slots:
};

#endif // LIFESCENE_H
