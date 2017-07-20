//
// Класс механики игры
//

// TODO: Перевести строки/столбцы на ushort или int


#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include "lifescene.h"
#include "lifematrix.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(ushort width, ushort height, short cellWidth, QObject *parent = nullptr);
    ~Processing();

    // Получение сцены (для GraphicsView)
    //! используется только для задания сцены QGraphicsView и нигде больше!
    LifeScene* getScene() const { return m_scene; }

    // Слот для вычисления одного шага
    void solveOneStep();

    // Очистка поля (но не удаление элементов)
    void clearField();

    // Установление новых параметров
    void setParameters(ushort row, ushort col, ushort cellsize);

    // Сеттеры/геттеры для размеров поля
    int getRows() const { return m_scene->getRows(); }
    int getCols() const { return m_scene->getCols(); }
    ushort getCellSize() const { return m_scene->getCellSize(); }

private:
    // Матрицы текущего и следующего поколения
    LifeMatrix m_currentGeneration;
    LifeMatrix m_nextGeneration;

    // Сцена
    LifeScene *m_scene;

    // Вычисление след.поколения
    void solveNextGen();

    void allocMatrix();

    // Специальный флаг, означающий, нужно ли перед просчетом поколения
    // считывать сцену (если одиночный просчет)
    bool needFromSceneMode;

signals:
    // Сигнал при окончании игры. Если вычисленное поколение равно текущему
    void sigGameOver();
    // Сигнал при каждой итерации. [количество живых клеток]
    void sigGenIteration(uint aliveCellsCount);

public slots:
};

#endif // PROCESSING_H
