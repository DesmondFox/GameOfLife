//
// Класс для описания матрицы, вычисления соседей и т.д.
//

#ifndef LIFEMATRIX_H
#define LIFEMATRIX_H

#include <QDebug>

class LifeMatrix
{
public:
    explicit LifeMatrix();
    ~LifeMatrix();

    // Выделение памяти под массив
    void allocate(size_t rowCount, size_t columnCount);
    // Заново создаем массив (изменяем размер, только всё с нуля)
    void reallocate(size_t horizontalCount, size_t verticalCount);

    inline size_t getCountRows() const { return countRow; }
    inline size_t getCountColumns() const { return countCol; }

    bool operator ==(const LifeMatrix &mtrx);
    bool getElement(size_t row, size_t col);
    void setElement(size_t row, size_t col, bool value);

    // Получить количество соседей у клетки
    short getNeighbours(size_t row, size_t col);

private:
    // Матрица, собственно
    bool    **m_matrix;

    // Текущее количество клеток
    size_t  countCol;
    size_t  countRow;

    // Заполнение массива нулями / очистка
    void fillZero();
    // Удаление массива
    void deleteMatrix();


signals:

public slots:
};

#endif // LIFEMATRIX_H
