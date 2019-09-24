#include "widget.h"
#include <QApplication>
#include"plotlines.h"
#include"kb.h"
#include"mainwindow.h"
#include"up.h"
#include"main_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    mainWindow win;
//    QIcon icon(":/images/Ftp.ico");

//    win.setWindowIcon(icon);
//    win.setWindowTitle("FTP客户端");
//    win.show();

    main_window w;
    w.show();


    //up u;
    //u.start(QString("D:/dtwpc.dat"));

    return a.exec();
}
