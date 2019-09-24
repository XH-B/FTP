#include "kb.h"
#include "ui_kb.h"

kb::kb(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kb)
{
    ui->setupUi(this);
}

kb::~kb()
{
    delete ui;
}
