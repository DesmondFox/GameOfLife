#ifndef LIFESCENE_H
#define LIFESCENE_H

#include <QObject>

class LifeScene : public QObject
{
    Q_OBJECT
public:
    explicit LifeScene(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LIFESCENE_H