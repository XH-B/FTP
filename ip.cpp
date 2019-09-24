#include "ip.h"
#include "ui_ip.h"

Ip::Ip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ip)
{
    ui->setupUi(this);


    ui->treeWidget->setColumnWidth(0,50);//设置第0列的宽度
    int i=0;
    QList<QNetworkInterface> network=QNetworkInterface::allInterfaces();    // 获取所有的接口
    foreach(QNetworkInterface net,network)
    {
        i++;
        QString str=net.humanReadableName();

        QTreeWidgetItem *item= new QTreeWidgetItem;
        item->setText(0,QString::number(i,10));
        item->setText(1,str);
        ui->treeWidget->addTopLevelItem(item);
    }




}

Ip::~Ip()
{
    delete ui;
}



void Ip::on_pushButton_queding_clicked()//选择网络
{

    QString ipName=ui->treeWidget->currentItem()->text(1);
    ui->lineEdit_name->setText(ipName);

    QList<QNetworkInterface> network=QNetworkInterface::allInterfaces();    // 获取所有的接口
    foreach(QNetworkInterface net,network)
    {
       QString netName=net.humanReadableName();// 获取网络名称

        if(netName==ipName)
        {
            QList<QNetworkAddressEntry> list=net.addressEntries();// 获取IP地址与子掩码等
            foreach(QNetworkAddressEntry address,list)
            {

                if(address.ip().protocol()==QAbstractSocket::IPv4Protocol)// 获取IPv4的地址
                {
                    qDebug()<< address.ip().toString();
                    ui->lineEdit_ip->setText(address.ip().toString());
                    ui->lineEdit_subnet->setText(address.netmask().toString());//获取子网掩码
                }

            }
        }
    }
    QString st="当前网络：";
    st+=ui->lineEdit_name->text();
    ui->label_status->setText(st);


}
void Ip::on_pushButton_changeip_clicked()//改变ip
{
//用法: set address [name=]
//       [[source=]dhcp |
//        [source=] static [addr=]IP address [mask=]IP subnet mask]
//       [[gateway=]|none [gwmetric=]integer]

    QProcess *process = new QProcess();
    QString cmd = "netsh interface ip set address \"";
    cmd+=ui->lineEdit_name->text();

    //cmd +="\"WLAN\" ";     //网卡名称要加双引号
    cmd +="\" static ";

    cmd += ui->lineEdit_ip_ipnew->text(); //从界面上获取IP地址
    //cmd +="192.168.10.99";
    cmd +=" 255.255.255.0 ";
    cmd += "192.168.10.1";
    qDebug()<<"cmd = "<<cmd;
    process->start(cmd);   //执行dos命令
    process->waitForFinished(); //等待执行完成
    delete process;
    ui->label_status->setText("网络设置为”手动获取IP地址“,IP地址已更改");

}

void Ip::on_pushButton_auotoip_clicked()//设置自动获取ip
{
    QString cmd = "netsh interface ip set address \"";
    cmd+=ui->lineEdit_name->text();
    cmd +="\" dhcp";

    QProcess *process = new QProcess();
    process->start(cmd);   //执行dos命令
    process->waitForFinished(); //等待执行完成
    delete process;
    ui->label_status->setText("恢复为自动获取IP地址");

}

