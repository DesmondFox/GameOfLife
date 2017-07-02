#include "lifematrix.h"

LifeMatrix::LifeMatrix(QObject *parent) : QObject(parent)
{

}

LifeMatrix::~LifeMatrix()
{
    qDebug() << "Deleted";
}

void LifeMatrix::allocate(size_t horizontalCount, size_t verticalCount)
{
    // Выделение памяти под массив

    // Выкидываем предупреждение, если меньше количество 0
    Q_ASSERT(horizontalCount > 0 || verticalCount > 0);

    if (m_matrix == nullptr)
        return;
    m_matrix        = new bool*[verticalCount];
    for (size_t i = 0; i < horizontalCount; i++)
        m_matrix[i] = new bool[horizontalCount];

    sizeHor = horizontalCount;
    sizeVer = verticalCount;

    fillZero();

    qDebug() << "Notice:\n Created Matrix [" << sizeVer << "][" << sizeHor << "]";
}

void LifeMatrix::reallocate(size_t horizontalCount, size_t verticalCount)
{
    qDebug() << "Notice:\n Reallocating memory for a Matrix to ["
             << verticalCount << "]["
             << horizontalCount << "]";

    // Переопределение матрицы
    deleteMatrix();
    allocate(horizontalCount, verticalCount);

}

bool LifeMatrix::operator ==(const LifeMatrix &mtrx)
{
    // Перегрузка оператора сравнения


    return false;
}

void LifeMatrix::fillZero()
{
    // Заполнение матрицы нулями
    if (m_matrix == nullptr)
        return;
    for (size_t i = 0; i < sizeVer; i++)
        for (size_t j = 0; j < sizeVer; j++)
            m_matrix[i][j]  = false;
}

void LifeMatrix::deleteMatrix()
{
    // Удаление массива и освобождение памяти
    if (m_matrix == nullptr)
        return;
    for (size_t i = 0; i < sizeVer; i++)
        delete []m_matrix[i];
    delete []m_matrix;

    // На всякий случай приравниваем к nullptr
    m_matrix = nullptr;

    qDebug() << "Notice:\t Deleting a matrix";
}
