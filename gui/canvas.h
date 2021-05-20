#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QTimer>


class Canvas: public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene *scene;
    QTimer* timer;
    void initBackground();
public:
    Canvas();
    ~Canvas();
protected slots:
    void slotAlarmTimer();
};

#endif // CANVAS_H
