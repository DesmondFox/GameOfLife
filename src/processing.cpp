#include "processing.h"

Processing::Processing(QObject *parent) : QObject(parent)
Processing::Processing(ushort width, ushort height, QObject *parent) : QObject(parent)
{

}

void Processing::setTimerDelay(unsigned short msec)
{
    // Установка задержки таймера

    qDebug() << "Notice:\t Setting a timer delay as " << msec << "ms";
    m_timer.setInterval(msec);
}
