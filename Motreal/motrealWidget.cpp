#include "motrealWidget.h"
#include <QPainter>
#include <QTimerEvent>

MotrealWidget::MotrealWidget(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(0, 0, 1024, 600);
    timerId = startTimer(17);
}

MotrealWidget::~MotrealWidget()
{

}

void MotrealWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter p(this);
    p.fillRect(QRect(0,0,1024,600),  QColor(Qt::black));
}

void MotrealWidget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() != timerId)
        return;

}
