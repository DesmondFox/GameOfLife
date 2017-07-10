//
// Класс для описания матрицы, вычисления соседей и т.д.
//

#ifndef BASEMATRIX_H
#define BASEMATRIX_H

#include <QDebug>

typedef unsigned int uint;

template<typename T>
class BaseMatrix
{
public:
    explicit BaseMatrix()
    {
        m_matrix = nullptr;
        countCol = 0;
        countRow = 0;
    }

    virtual ~BaseMatrix()
    {
        deleteMatrix();
    }

    // Выделение памяти под массив
    void allocate(size_t rowCount, size_t columnCount)
    {
        // Выделение памяти под массив

        // Инициализируем массив
        if (m_matrix != nullptr)
            return;
        m_matrix        = new T*[rowCount];
        for (size_t i = 0; i < rowCount; i++)
            m_matrix[i] = new T[columnCount];

        countCol = columnCount;
        countRow = rowCount;

        qDebug() << "Notice:\t Created Matrix [" << countRow << "][" << countCol << "]";
    }

    // Заново создаем массив (изменяем размер, только всё с нуля)
    void reallocate(size_t rowCount, size_t columnCount)
    {
        qDebug() << "Notice:\t Reallocating memory for a Matrix to ["
                 << rowCount << "]["
                 << columnCount << "]";

        // Переопределение матрицы
        deleteMatrix();
        allocate(rowCount, columnCount);
    }

    inline size_t getCountRows() const { return countRow; }
    inline size_t getCountColumns() const { return countCol; }

    T getElement(size_t row, size_t col)
    {
        // Получение элемента массива

        Q_CHECK_PTR(m_matrix);      // Проверка матрицы на существование
        Q_ASSERT(row < countRow);
        Q_ASSERT(col < countCol);

        return m_matrix[row][col];
    }
    void setElement(size_t row, size_t col, T value)
    {
        // Задать элемент массива

        Q_CHECK_PTR(m_matrix);      // Проверка мастрицы на существование
        Q_ASSERT(row < countRow);
        Q_ASSERT(col < countCol);

        m_matrix[row][col] = value;
    }

protected:
    // Матрица, собственно
    T    **m_matrix;

    // Текущее количество клеток
    size_t  countCol;
    size_t  countRow;

    // Удаление массива
    virtual void deleteMatrix()
    {
        // Удаление массива и освобождение памяти
        for (size_t i = 0; i < countRow; i++)
            delete []m_matrix[i];
        delete []m_matrix;

        // На всякий случай приравниваем к nullptr
        m_matrix = nullptr;

        qDebug() << "Notice:\t Deleting a matrix";
    }
};

#endif // BASEMATRIX_H
