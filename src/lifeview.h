#ifndef LIFEVIEW_H
#define LIFEVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QDebug>
#include <QtEvents>

class LifeView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit LifeView(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:

public slots:
};

#endif // LIFEVIEW_H
