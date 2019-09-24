#ifndef SETCOLOR_H
#define SETCOLOR_H

#include <QWidget>

namespace Ui {
class setColor;
}

class setColor : public QWidget
{
    Q_OBJECT

public:
    explicit setColor(QWidget *parent = 0);
    ~setColor();

private:
    Ui::setColor *ui;
};

#endif // SETCOLOR_H
