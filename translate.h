#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QWidget>
#include<QFile>
#include<QDebug>
#include<QFileDialog>
#include<QProcess>
#include<QTime>
#include<QDataStream>

namespace Ui {
class Translate;
}

class Translate : public QWidget
{
    Q_OBJECT

public:
    explicit Translate(QWidget *parent = 0);
    ~Translate();
    QString filePath;//转换的文件路径
    QDateTime currentTime;
    int flag;//判断文件大小是否过大，如果过大就除以1000

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Translate *ui;
};

#endif // TRANSLATE_H
