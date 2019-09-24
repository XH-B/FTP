#ifndef IP_H
#define IP_H

#include <QWidget>
#include<QProcess>
#include<QDebug>
#include<QList>
#include"qnetwork.h"
#include<QtNetwork/QNetworkInterface>
#include<QtNetwork/QHostAddress>
#include<QListWidget>
#include<QListWidgetItem>
namespace Ui {
class Ip;
}

class Ip : public QWidget
{
    Q_OBJECT

public:
    explicit Ip(QWidget *parent = 0);
    ~Ip();

private slots:
    void on_pushButton_changeip_clicked();

    void on_pushButton_queding_clicked();

    void on_pushButton_auotoip_clicked();

private:
    Ui::Ip *ui;
};

#endif // IP_H
