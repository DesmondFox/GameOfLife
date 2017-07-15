#include "processing.h"

Processing::Processing(ushort width, ushort height, short cellWidth, QObject *parent) : QObject(parent)
{
    // Запуск работы с такими параметрами сцены
    m_scene = new LifeScene(width, height, cellWidth);
    m_scene->draw();

    // Сразу выделяем память под массивы
    allocMatrix();

    // В начале, требуется для просчета считывать сцену
    needFromSceneMode = true;
}

void Processing::allocMatrix()
{
    m_currentGeneration.allocate(m_scene->getRows(), m_scene->getCols());
    m_currentGeneration.fillZero();

    m_nextGeneration.allocate(m_scene->getRows(), m_scene->getCols());
    m_nextGeneration.fillZero();
}

Processing::~Processing()
{
    delete m_scene;
}

void Processing::solveOneStep()
{
    // Вычисление одного шага

    // Если стоит флаг, то надо сначала считать клетки со сцены
    if (needFromSceneMode)
        m_scene->fromSceneToMtrx(m_currentGeneration);

    solveNextGen();
}

void Processing::clearField()
{
    // Очистка поля, матриц

    this->m_currentGeneration.fillZero();
    this->m_nextGeneration.fillZero();
    this->m_scene->clearField();

    qDebug() << "Notice:\t Processing: Cleaning Field...";
}

void Processing::solveNextGen()
{
    // Вычисление следующего поколения

    Q_ASSERT(m_currentGeneration.getCountColumns() == m_nextGeneration.getCountColumns());
    Q_ASSERT(m_currentGeneration.getCountRows() == m_nextGeneration.getCountRows());

    m_nextGeneration.fillZero();

    size_t  rows = m_currentGeneration.getCountRows(),
            cols = m_currentGeneration.getCountColumns();

    for (size_t i = 0; i < rows; i++)
    {
        for (ushort j = 0; j < cols; j++)
        {
            ushort nb = m_currentGeneration.getNeighbours(i, j);

            // Далее по правилам игры

            bool currCell = m_currentGeneration.getElement(i, j);
            // Если клетка мертвая
            if (currCell == false)
            {
                // Если вокруг == 3 жизни, то зарождается жизнь
                if (nb == 3)
                    m_nextGeneration.setElement(i, j, true);
            }
            // Если клетка живая
            if (currCell == true)
            {
                // если у живой клетки есть две или три живые соседки,
                // то эта клетка продолжает жить
                // в противном случае, если соседей меньше двух или больше трёх,
                // клетка умирает
                if (nb == 2 || nb == 3)
                    m_nextGeneration.setElement(i, j, true);
                else
                    m_nextGeneration.setElement(i, j, false);
            }
        }
    }

    // Условия прекращения игры

    // Если поколения одинаковы
    // Или количество клеток равно нулю
    if ((m_currentGeneration == m_nextGeneration) ||
            (m_currentGeneration.countFilled() == 0))
    {
        emit sigGameOver();
        return;
    }

    // Сигнал о итерации
    emit sigGenIteration(m_nextGeneration.countFilled());

    // Теперь прировняем новое поколение старому
    m_currentGeneration = m_nextGeneration;

    // Отрисуем матрицу
    m_scene->drawMatrix(m_currentGeneration);
}

