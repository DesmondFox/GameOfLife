#include "lifematrix.h"

LifeMatrix::LifeMatrix()
{

}

LifeMatrix::~LifeMatrix()
{

}

bool LifeMatrix::operator ==(const LifeMatrix &mtrx)
{
    // Перегрузка оператора сравнения

    // Проверка на размеры
    Q_CHECK_PTR(m_matrix);
    Q_ASSERT(this->countCol == mtrx.countCol);
    Q_ASSERT(this->countRow == mtrx.countRow);

    for (size_t i = 0; i < this->countRow; i++)
        for (size_t j = 0; j < this->countCol; j++)
            if (this->m_matrix[i][j] != mtrx.m_matrix[i][j])
                return false;
    return true;
}

short LifeMatrix::getNeighbours(size_t row, size_t col)
{
    // Получение количества соседей
    Q_ASSERT(row < countRow);
    Q_ASSERT(col < countCol);

    short ng = 0;

    // Подсчитаем верхние и нижние грани массива
    // т.к. поле будет повторяться
    short   rowL    = (row == 0) ? countRow - 1 : row - 1,
            rowH    = (row == countRow - 1) ? 0 : row + 1,
            colL    = (col == 0) ? countCol - 1 : col - 1,
            colH    = (col == countCol - 1) ? 0 : col + 1;

    // Верх
    ng  += m_matrix[rowL][colL];
    ng  += m_matrix[rowL][col];
    ng  += m_matrix[rowL][colH];

    // Середина
    ng  += m_matrix[row][colL];
    ng  += m_matrix[row][colH];

    // Низ
    ng  += m_matrix[rowH][colL];
    ng  += m_matrix[rowH][col];
    ng  += m_matrix[rowH][colH];

    return ng;
}

uint LifeMatrix::countFilled()
{
    // Получение количества ненулевых значений в массиве
    unsigned int count = 0;

    for (size_t i = 0; i < countRow; i++)
        for (size_t j = 0; j < countCol; j++)
            if (m_matrix[i][j] == true)
                count++;

    return count;
}


void LifeMatrix::fillZero()
{
    // Заполнение матрицы нулями
    if (m_matrix == nullptr)
        return;
    for (size_t i = 0; i < countRow; i++)
        for (size_t j = 0; j < countCol; j++)
            m_matrix[i][j]  = false;
}
