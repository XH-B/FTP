#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{


    ui->setupUi(this);

    ftp=new Ftp(ui->tab);
    chartShow=new Show(ui->tab_2);
    kb=new Kb(ui->tab_3);
    ip=new Ip(ui->tab_4);
    translate=new Translate(ui->tab_5);



    QGridLayout *layout1=new QGridLayout(ui->tab);//对tab1设置布局
    layout1->addWidget(ftp);
    layout1->setAlignment(Qt::AlignCenter);


    QGridLayout *layout2=new QGridLayout(ui->tab_2);//对tab2设置布局
    layout2->addWidget(chartShow);
    layout2->setAlignment(Qt::AlignCenter);

    QGridLayout *layout3=new QGridLayout(ui->tab_3);//对tab3设置布局
    layout3->addWidget(kb);
    layout3->setAlignment(Qt::AlignCenter);

    QGridLayout *layout4=new QGridLayout(ui->tab_4);//对tab4设置布局
    layout4->addWidget(ip);
    layout4->setAlignment(Qt::AlignCenter);

    QGridLayout *layout5=new QGridLayout(ui->tab_5);//对tab5设置布局
    layout5->addWidget(translate);
    layout5->setAlignment(Qt::AlignCenter);

}

mainWindow::~mainWindow()
{
    delete ui;
}
