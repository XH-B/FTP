#include "up.h"
#include "ui_up.h"

up::up(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::up)
{
    ui->setupUi(this);

}

up::~up()
{
    delete ui;
}
void up::start(const QString &file){
    // no passwd
    // QUrl url("ftp://172.20.5.167/ftp.txt");
    QUrl url;
    url.setScheme("ftp");
    //url.setHost("10.106.20.250");
   url.setHost("10.108.13.158");
    QFileInfo info(file);
    QString name=info.fileName();


    // 这里是设置远端主机上传时的文件名，不设置则名称为本地端上传名称
    url.setPath(name);
   // url.setUserName("root");
    url.setPort(21);

    // need passwd
    /*
    QUrl url("ftp://172.20.5.167/ftp.txt");
    url.setScheme("ftp");
    url.setUserName("root");
    url.setPort(21);
    */

    data = new QFile(file, this);
    if (data->open(QIODevice::ReadOnly)) {
        qDebug()<<"open";
        reply = nam.put(QNetworkRequest(url), data);
        connect(reply, SIGNAL(uploadProgress(qint64, qint64)), SLOT(uploadProgress(qint64, qint64)));
        connect(reply, SIGNAL(finished()), SLOT(uploadDone()));
    }
    else
        qDebug() << "Oops";

}


void up::uploadProgress(qint64 bytesSent, qint64 bytesTotal)    {
    ui->progressBar->setMaximum(bytesTotal);
    ui->progressBar->setValue(bytesSent);




    qDebug() << "Uploaded" << bytesSent << "of" << bytesTotal;
}

void up::uploadDone(){
    qDebug() << "Finished" << reply->error();
    data->deleteLater();
    reply->deleteLater();
}
