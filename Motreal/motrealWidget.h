#ifndef MOTREALWIDGETS_H
#define MOTREALWIDGETS_H

#include <QMainWindow>

class MotrealWidget : public QMainWindow
{
    Q_OBJECT

public:
    MotrealWidget(QWidget *parent = nullptr);
    ~MotrealWidget();
protected:
    void timerEvent(QTimerEvent *e) override;
    void paintEvent(QPaintEvent *e) override;
private:
    int timerId;
};

#endif // MOTREAL_H
