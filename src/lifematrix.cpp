#include "lifematrix.h"

LifeMatrix::LifeMatrix()
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

    // Инициализируем массив
    if (m_matrix != nullptr)
        return;
    m_matrix        = new bool*[rowCount];
    for (size_t i = 0; i < rowCount; i++)
        m_matrix[i] = new bool[columnCount];

    countCol = columnCount;
    countRow = rowCount;

    // Заполнение нулями
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

bool LifeMatrix::getElement(size_t row, size_t col)
{
    // Получение элемента массива

    Q_CHECK_PTR(m_matrix);      // Проверка матрицы на существование
    Q_ASSERT(row < countRow);
    Q_ASSERT(col < countCol);

    return m_matrix[row][col];
}

void LifeMatrix::setElement(size_t row, size_t col, bool value)
{
    // Задать элемент массива

    Q_CHECK_PTR(m_matrix);      // Проверка мастрицы на существование
    Q_ASSERT(row < countRow);
    Q_ASSERT(col < countCol);

    m_matrix[row][col] = value;
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

unsigned int LifeMatrix::countFilled()
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

