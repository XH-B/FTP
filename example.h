#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QWidget>

namespace Ui {
class example;
}

class example : public QWidget
{
    Q_OBJECT

public:
    explicit example(QWidget *parent = 0);
    ~example();

private:
    Ui::example *ui;
};

#endif // EXAMPLE_H
