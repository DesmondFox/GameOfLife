//
// Класс механики игры
//

#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include <QTimer>

#include "lifescene.h"
#include "lifematrix.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(ushort width, ushort height, short cellWidth, QObject *parent = nullptr);
    ~Processing();

    // Установка задержки таймера
    void setTimerDelay(ushort msec = 100);

    // Получение сцены (для GraphicsView)
    //! используется только для задания сцены QGraphicsView и нигде больше!
    LifeScene* getScene() const { return m_scene; }


    // Слот для вычисления одного шага
    void solveOneStep();

private:
    // Матрицы текущего и следующего поколения
    LifeMatrix m_currentGeneration;
    LifeMatrix m_nextGeneration;

    // Сцена
    LifeScene *m_scene;

    // Таймер
    QTimer m_timer;

    // Вычисление след.поколения
    void solveNextGen();

    void allocMatrix();



signals:
    // Сигнал при окончании игры. Если вычисленное поколение равно текущему
    void sigGameOver();
    // Сигнал при каждой итерации. [номер поколения, количество живых клеток]
    void sigGenIteration(uint genNum, uint aliveCellsCount);

public slots:
    // Слот начатия игры с заданными параметрами
    void slotStart(ushort tmrDelay);
    // Слот принудительного окончания игры
    void slotStop();

};

#endif // PROCESSING_H
