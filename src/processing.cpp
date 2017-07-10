#include "processing.h"

Processing::Processing(ushort width, ushort height, short cellWidth, QObject *parent) : QObject(parent)
{
    // Запуск работы с такими параметрами сцены
    m_scene = new LifeScene(width, height, cellWidth);
    m_scene->drawCleanField();

    // Зададим размеры матрицам
    m_currentGeneration.allocate(m_scene->getRowCount(),
                                 m_scene->getColCount());
    m_nextGeneration.allocate(m_scene->getRowCount(),
                              m_scene->getColCount());

Processing::~Processing()
{
    delete m_scene;
}

void Processing::setTimerDelay(unsigned short msec)
{
    // Установка задержки таймера

    qDebug() << "Notice:\t Setting a timer delay as " << msec << "ms";
    m_timer.setInterval(msec);
}
