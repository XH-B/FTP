#ifndef UP_H
#define UP_H

#include <QWidget>
#include <QtCore>
#include <QtNetwork>
#include <QDebug>

namespace Ui {
class up;
}

class up : public QWidget
{
    Q_OBJECT
public:
    explicit up(QWidget *parent = 0);
    ~up();
   void start(const QString &file);



public slots:
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
   void uploadDone();


private:

    QNetworkAccessManager nam;
    QFile *data;
    QNetworkReply *reply;
    Ui::up *ui;
};

#endif // UP_H
