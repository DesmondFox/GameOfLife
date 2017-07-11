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
    void setTimerDelay(unsigned short msec = 100);

    // Получение сцены (для GraphicsView)
    //! используется только для задания сцены QGraphicsView и нигде больше!
    LifeScene* getScene() const { return m_scene; }

private:
    // Матрицы текущего и следующего поколения
    LifeMatrix m_currentGeneration;
    LifeMatrix m_nextGeneration;

    // Сцена
    LifeScene *m_scene;

    // Таймер
    QTimer m_timer;


signals:

public slots:
//    void slotStart();
//    void slotStop();

};

#endif // PROCESSING_H
