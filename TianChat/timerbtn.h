#ifndef TIMERBTN_H
#define TIMERBTN_H
#include "QPushButton.h"
#include "QTimer.h"

class TimerBtn:public QPushButton
{
public:
    TimerBtn(QWidget *parent = nullptr);
    ~TimerBtn();
    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    QTimer* _timer;
    int _counter;
};

#endif // TIMERBTN_H
