#include "translate.h"
#include "ui_translate.h"

Translate::Translate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Translate)
{
    ui->setupUi(this);
    flag=0;

    ui->progressBar->setValue(0);
    ui->pushButton_2->setEnabled(false);


}

Translate::~Translate()
{
    delete ui;
}
void Translate::on_pushButton_clicked()//读取文件信息
{
    currentTime=QDateTime::currentDateTime();
    flag=0;//初始值为0
    ui->progressBar->setValue(0);//进度条初始化

    filePath=QFileDialog::getOpenFileName(this,tr("打开文件"),"./");

    QFileInfo info(filePath);//文件信息
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        ui->textEdit->append(currentTime.toString("yyyy-MM-dd hh:mm:ss")+":");
        ui->textEdit->append("打开文件失败");
        return;
    }

    int i=0;
//    while(!file.atEnd()){
//        QByteArray line=file.readLine();
//        i++;
//    }
    ui->textEdit->append(currentTime.toString("yyyy-MM-dd hh:mm:ss")+":");
    ui->textEdit->append("  文件读取成功");
    ui->textEdit->append("  当前文件大小："+QString::number((info.size()+1023)/1024)+"KB");

    ui->pushButton_2->setEnabled(true);


    qint64 n=2;




//    if(i>10000){
//        ui->progressBar->setRange(0,i/10000);
//        flag=1;//文件过大
//        qDebug()<<i/10000;
//    }
//    else{
//        ui->progressBar->setRange(0,i);
//        //qDebug()<<i;
//    }

}

void Translate::on_pushButton_2_clicked()//转换格式

{
    ui->textEdit->append(currentTime.toString("yyyy-MM-dd hh:mm:ss")+":");
    ui->textEdit->append("  二进制转换十进制中...");
    currentTime=QDateTime::currentDateTime();


    QFile file(filePath);
    QStringList list=filePath.split("/");
    QString n=list[list.count()-1];
    QString time=n.mid(8,2);



    QString name=filePath.left(filePath.size()-4);//分离出名字
    QString end=filePath.right(4);
    QString newFilePath=name+"--转化"+end;//新路径
    QFile file1(newFilePath);

    if(!file.open(QIODevice::ReadOnly)){
        ui->textEdit->append(currentTime.toString("yyyy-MM-dd hh:mm:ss")+":");
        ui->textEdit->append("不能打开文件");
    }
    if(!file1.open(QIODevice::WriteOnly|QIODevice::Text)){
        ui->textEdit->append(currentTime.toString("yyyy-MM-dd hh:mm:ss")+":");
        ui->textEdit->append("不能写入文件");
    }

    qint64 filesize=file.size();//字节数

    ui->progressBar->setMaximum(int(filesize/1000));
    quint8 minute;//分钟
    quint8 second;//秒
    quint16 millsecond;//毫秒
    quint16 ch[6];//通道
    quint8  qtime;

    //qtime=quint8(time.toUInt());

    QDataStream read(&file);//读文件
    QTextStream out(&file1);//写文件

    int i=0;

    out<<"TimeStamp FK_V FK_I LJYK_V KJ_I LJWK_V VIN"<<endl;
    while(!read.atEnd()){
        i++;
            read>>minute>>second>>millsecond>>ch[0]>>ch[1]>>ch[2]>>ch[3]>>ch[4]>>ch[5];


            out<<time<<":"<<minute<<":"<<second<<":"<<QString("%1").arg(int(millsecond),3,10,QLatin1Char('0'))<<" "<<QString("%1").arg(int(ch[0]),4,10,QLatin1Char('0'))<<" "
              <<QString("%1").arg(int(ch[1]),4,10,QLatin1Char('0'))<<" "<<QString("%1").arg(int(ch[2]),4,10,QLatin1Char('0'))<<" "<<QString("%1").arg(int(ch[3]),4,10,QLatin1Char('0'))
                    <<" "<<QString("%1").arg(int(ch[4]),4,10,QLatin1Char('0'))<<" "<<QString("%1").arg(int(ch[5]),4,10,QLatin1Char('0'))<<endl;

            if(i%1000==0){
                ui->progressBar->setValue(i/1000*16);
            }

    }
    file1.close();
    file.close();

    ui->textEdit->append(currentTime.toString("yyyy-MM-dd hh:mm:ss")+":");
    ui->textEdit->append("  转换完成");
    ui->progressBar->setValue(int(filesize/1000));


    QProcess *proc = new QProcess();
    QStringList path;
    path<<newFilePath;
    qDebug()<<path;
    proc->startDetached("notepad",path);
    ui->textEdit->append("  Txt文件已生成");
    proc->close();
    return;
}
