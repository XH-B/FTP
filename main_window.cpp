#include "main_window.h"
#include "ui_main_window.h"
#include<QDebug>

main_window::main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_window)
{





    ui->setupUi(this);

    ftp=new Ftp(ui->page);
    chartShow=new Show(ui->page_2);




    connect(ui->menuFTP,&QMenu::triggered,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
        qDebug()<<"0";

    });
    connect(ui->menushow,&QMenu::triggered,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
        qDebug()<<"1";
    });
    connect(ui->actionKb,&QAction::triggered,this,[=](){
        kb=new Kb(this);
        kb->show();
        qDebug()<<"2";
    });
    connect(ui->actionIP,&QAction::triggered,this,[=](){
         ip=new Ip(this);
         ip->show();

        qDebug()<<"3";
    });
    connect(ui->actiontrans,&QAction::triggered,this,[=](){
            translate=new Translate(this);
            translate->show();
        qDebug()<<"4";
    });





}

main_window::~main_window()
{
    delete ui;
}
