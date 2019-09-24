#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"widget.h"
#include"kb.h"
#include"ftp.h"
#include"show.h"
#include"example.h"
#include"ip.h"
#include"translate.h"


#include <QWidget>
#include<QTableWidget>

namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private:

    Ui::mainWindow *ui;
    Kb *kb;
    Ftp *ftp;
    Show *chartShow;
    example *ex;
    Ip *ip;
    Translate *translate;


};

#endif // MAINWINDOW_H
