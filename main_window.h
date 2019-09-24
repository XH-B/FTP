#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include"widget.h"
#include"kb.h"
#include"ftp.h"
#include"show.h"
#include"example.h"
#include"ip.h"
#include"translate.h"
namespace Ui {
class main_window;
}

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = 0);
    ~main_window();


private:
    Ui::main_window *ui;
    Kb *kb;
    Ftp *ftp;
    Show *chartShow;
    example *ex;
    Ip *ip;
    Translate *translate;
};

#endif // MAIN_WINDOW_H
