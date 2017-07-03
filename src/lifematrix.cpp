#include "lifematrix.h"

LifeMatrix::LifeMatrix(QObject *parent) : QObject(parent)
{
    m_matrix = nullptr;
}

LifeMatrix::~LifeMatrix()
{
    deleteMatrix();
}

void LifeMatrix::allocate(size_t rowCount, size_t columnCount)
{
    // Выделение памяти под массив

    // Выкидываем предупреждение, если меньше количество 0
    Q_ASSERT(columnCount > 0 || rowCount > 0);

    if (m_matrix != nullptr)
        return;
    m_matrix        = new bool*[rowCount];
    for (size_t i = 0; i < rowCount; i++)
        m_matrix[i] = new bool[columnCount];

    countCol = columnCount;
    countRow = rowCount;

    fillZero();

    qDebug() << "Notice:\t Created Matrix [" << countRow << "][" << countCol << "]";
}

void LifeMatrix::reallocate(size_t horizontalCount, size_t verticalCount)
{
    qDebug() << "Notice:\t Reallocating memory for a Matrix to ["
             << verticalCount << "]["
             << horizontalCount << "]";

    // Переопределение матрицы
    deleteMatrix();
    allocate(horizontalCount, verticalCount);

}

bool LifeMatrix::operator ==(const LifeMatrix &mtrx)
{
    // Перегрузка оператора сравнения
    // Когда сравниваются явно

    // Проверка на размеры
    Q_ASSERT(this->countCol == mtrx.countCol);
    Q_ASSERT(this->countRow == mtrx.countRow);

    for (size_t i = 0; i < this->countRow; i++)
        for (size_t j = 0; j < this->countCol; j++)
            if (this->m_matrix[i][j] != mtrx.m_matrix[i][j])
                return false;
    return true;
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

void LifeMatrix::deleteMatrix()
{
    // Удаление массива и освобождение памяти
    if (m_matrix == nullptr)
        return;
    for (size_t i = 0; i < countRow; i++)
        delete []m_matrix[i];
    delete []m_matrix;

    // На всякий случай приравниваем к nullptr
    m_matrix = nullptr;

    qDebug() << "Notice:\t Deleting a matrix";
}

