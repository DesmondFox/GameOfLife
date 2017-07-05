//
// Класс механики игры
//

#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include <QTimer>

#include "lifematrix.h"
#include "lifescene.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = nullptr);

    // Установка задержки таймера
    void setTimerDelay(unsigned short msec = 80);

    // Получение сцены (для GraphicsView)
    LifeScene* getScene() { return &m_scene; }


private:
    // Матрицы текущего и следующего поколения
    LifeMatrix m_currentGeneration;
    LifeMatrix m_nextGeneration;

    // Сцена
    LifeScene m_scene;

    QTimer m_timer;
signals:

public slots:
};

#endif // PROCESSING_H