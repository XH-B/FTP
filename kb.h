#ifndef KB_H
#define KB_H

#include <QMainWindow>

namespace Ui {
class kb;
}

class kb : public QMainWindow
{
    Q_OBJECT

public:
    explicit kb(QWidget *parent = 0);
    ~kb();

private:
    Ui::kb *ui;
};

#endif // KB_H
