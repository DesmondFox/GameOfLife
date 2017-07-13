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
    LifeMatrix& operator =(const LifeMatrix &mtrx);

    // Получить количество соседей у клетки
    short getNeighbours(size_t row, size_t col);

    // Получить количество элементов с true
    uint countFilled();

    // Заполнение массива нулями / очистка
    void fillZero();

private:

};

#endif // LIFEMATRIX_H
