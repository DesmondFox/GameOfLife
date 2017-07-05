#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PROCESSING_H