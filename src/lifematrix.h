#ifndef LIFEMATRIX_H
#define LIFEMATRIX_H

#include "basematrix.h"

class LifeMatrix : public BaseMatrix<bool>
{
public:
    LifeMatrix();
    ~LifeMatrix();

    // Оператор сравнения
    bool operator ==(const LifeMatrix &mtrx);

    // Получить количество соседей у клетки
    short getNeighbours(size_t row, size_t col);

    // Получить количество элементов с true
    uint countFilled();

private:
    // Заполнение массива нулями / очистка
    void fillZero();
};

#endif // LIFEMATRIX_H
