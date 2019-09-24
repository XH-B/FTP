#include "ftp.h"
#include "ui_ftp.h"

Ftp::Ftp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ftp)
{
    ui->setupUi(this);

    borwserModel=new QDirModel;
    //ftp = new QFtp(this);

//    borwserModel->setSorting(QDir::DirsFirst|QDir::IgnoreCase|QDir::Time);
//    ui->treeWidget_localfile->setModel(borwserModel);
//    ui->treeWidget_localfile->setModel(1);
//    ui->treeWidget_ftp->setModel();


    ui->treeWidget_ftp->setColumnWidth(0,370);//设置第0列的宽度
    ui->treeWidget_localfile->setColumnWidth(0,370);//设置第0列的宽度
    ui->treeWidget_ftp->setSortingEnabled(true);//设置排序可用 按时间 名称
    ui->treeWidget_localfile->setSortingEnabled(true);
    //ui->treeWidget_localfile->sortByColumn(1,Qt::DescendingOrder);

    connect(ui->pushButton_connect, SIGNAL(clicked()), this, SLOT(connectToFtp()));//连接服务器
    connect(ui->pushButton_diconnect,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_diconnect_clicked()));


    downloadPath = QDir::currentPath();//当前程序路径


    currentPath=QDir::currentPath();//当前程序路径
    currentPath+="/文件";

    //currentPath="D:/FTPClientFile";


    //if(dir(currentPath).is)
    QDir dir(currentPath);


//    if(!dir.exists()){


//        qDebug()<<"2";
//        bool ok=dir.mkdir(currentPath);
//        qDebug()<<ok;




//    }
//    else{
//        qDebug()<<"1";
//    }
//    qDebug()<<currentPath;



    dir.setFilter(QDir::Dirs|QDir::Files);//除了目录和文件 其他过滤掉（过滤了快捷方式)
    dir.setSorting(QDir::DirsFirst);//优先显示目录
    QFileInfoList list;
    list=dir.entryInfoList();


    showFileInfoList(list);

    ui->treeWidget_ftp->setContextMenuPolicy(Qt::CustomContextMenu);//重新设定右键
    ui->treeWidget_localfile->setContextMenuPolicy(Qt::CustomContextMenu);//重新设定右键
    connect(ui->treeWidget_localfile,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),//双击进入本地文件夹
            this,SLOT(slotDirShowLocal(QTreeWidgetItem*)));
    connect(ui->treeWidget_ftp,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),//双击进入FTP文件夹
            this,SLOT(slotDirShowFtp(QTreeWidgetItem*)));
    connect(ui->treeWidget_ftp,SIGNAL(customContextMenuRequested(QPoint)),//FTP右键菜单
            this,SLOT(ftpRightMenu(QPoint)));
    connect(ui->treeWidget_localfile,SIGNAL(customContextMenuRequested(QPoint)),//local右键菜单
            this,SLOT(localRightMenu(QPoint)));



    connect(ui->treeWidget_ftp,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(processItem(QTreeWidgetItem*,int)));


    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeCd()));
    connect(ui->pushButton_canceldownload,SIGNAL(clicked(bool)),this,SLOT(cancelDownload()));



    quanbu=0;//初始化是否下载全部文件，初始化为0
    ui->progressBar->setValue(0);//初始化进度条
    ui->pushButton_canceldownload->setEnabled(false);//初始化按钮
    ui->pushButton_diconnect->setEnabled(false);

//    connect(process,&QProcess::finished,this,[=](){
//        refreshFtpFile();
//    });


}

Ftp::~Ftp()
{
    delete ui;
}
//*************************************************************************************************
void Ftp::connectToFtp()//连接服务器
{
    ftp = new QFtp(this);
    ui->treeWidget_ftp->clear();
    isDirectory.clear();
    ftpFileName.clear();

    connect(ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpCommandStarted(int)));
    connect(ftp, SIGNAL(commandFinished(int,bool)),this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp, SIGNAL(listInfo(QUrlInfo)),//由ftp->list()发出   登录完成时调用
            this, SLOT(addToList(QUrlInfo)));
    connect(ftp, SIGNAL(dataTransferProgress(qint64,qint64)),
            this, SLOT(updateDataTransferProgress(qint64,qint64)));

    QUrl url(ui->lineEdit->text());
    //协议：//用户名:密码@子域名.域名.顶级域名:端口号/目录/文件名.文件后缀?参数=值#标志
    //ftp://Goldensun:7622041.@10.108.12.31：21
    QString s = ui->lineEdit->text();

    //qDebug()<<"url"<<s;
    if (!url.isValid() || url.scheme().toLower() != QLatin1String("ftp")) {
        ftp->connectToHost(ui->lineEdit->text(), 21);//只有ip时，连接服务器
        ftp->login();
        //qDebug()<<"1";
    }
    else {
        ftp->connectToHost(url.host(), url.port());//格式 IP：port

        if (!url.userName().isEmpty())//用户名：ip:port
            ftp->login(QUrl::fromPercentEncoding(url.userName().toLatin1()), url.password());
        else
            ftp->login();
        if (!url.path().isEmpty())
             ftp->cd(url.path());
    }
    ui->treeWidget_ftp->setEnabled(true);
    ui->label_status->setText("服务器已连接");
    ui->pushButton_connect->setEnabled(false);
    ui->pushButton_diconnect->setEnabled(true);

}
//*************************************************************************************************
void Ftp::on_pushButton_diconnect_clicked()//断开服务器连接
{
    ftp->abort();
    ftp->deleteLater();
    ui->treeWidget_ftp->clear();

    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_diconnect->setEnabled(false);
    ui->label_status->setText(tr("连接已断开"));
    return;
}
//*************************************************************************************************
void Ftp::downLoadDirFileSlot(){//下载文件夹内全部文件
    for(int i=0;i<ftpFileName.size();i++){
        QString str1=ftpFileName[i];
        file=new QFile(currentPath+"/"+str1);
        if (!file->open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("FTP"),tr("下载失败"));
            delete file;
            return;
        }else{

            ftp->get(ToSpecialEncoding(ftpFileName[i]), file);//下载文件
            ui->label_status->setText("下载中");
        }

    }

}

void Ftp::downloadFile()//download按钮->下载文件
{

    ui->pushButton_canceldownload->setEnabled(true);
    QString fileName = ui->treeWidget_ftp->currentItem()->text(0); //当前选中文件名
//    file = new QFile(currentPath + "/" + fileName);
    if(ui->treeWidget_ftp->currentItem()->text(2)=="0 KB"){//如果下载的为文件夹
        QMessageBox::information(this,tr("FTP"),tr("文件大小为0,不能下载"));
        return;
//        int i=2;
//        ftpFileName.clear();//在进入文件夹之前，先清空之前记录的文件名
//        QString name=ui->treeWidget_ftp->currentItem()->text(0);//记住该文件夹名字

//        QDir dir;
//        dir.cd(currentPath);

//        QString str=ui->treeWidget_ftp->currentItem()->text(0);
//        while(1){
//            if(!dir.exists(str)){
//                dir.mkdir(str);
//                refreshLocalFile();
//                flag=0;
//                break;

//            }
//            else {
//                if(dir.exists(str)&&flag==0){
//                    str+="1";
//                    flag++;
//                    dir.mkdir(str);
//                    refreshLocalFile();
//                    break;
//                }
//                else {
//                    if(dir.exists(str)){
//                        str.remove(str.size(),1);//删除最后一个数字 新加一个
//                        QString s = QString::number(i, 10);
//                        str+=s;
//                        i++;
//                    }
//                    else {
//                        dir.mkdir(str);
//                        refreshLocalFile();
//                        break;

//                    }
//                }
//            }
//        }

//        ui->treeWidget_ftp->clear();
//        //isDirectory.clear();

//        qDebug()<<"右键"<<ftpFileName.size();

//        ftp->cd(name);
//        ftp->list();//进入文件夹内 显示文件夹内容

//        while(1){//加循环等着ftp->list 执行完

//            if(ftpFileName.size()!=0){
//                qDebug()<<ftpFileName.size();
//                break;
//            }
//        }

//        dir.setPath(currentPath);
//        if(!dir.cd(str))
//        {
//            qDebug()<<"错误";
//            return;
//        }
//        currentPath = dir.absolutePath();    //更新路径
//        refreshLocalFile();
//       // refreshFtpFile();
//        quanbu=1;


//        if(ui->treeWidget_ftp->currentItem()!=NULL){
//            qDebug()<<"1111";
//        }


////        qDebug()<<"右键"<<ftpFileName.size();


////        QTime t;
////        t.start();
////        while(t.elapsed()<1000);

////        qDebug()<<"右键"<<ftpFileName.size();
////        QTreeWidgetItemIterator it(QWidget);

////        i=0;
////        while (*it) {
////            //do something like

////            ++it;
////            i++;
////            qDebug()<<(*it)->text(0)<<i;
////        }
////        qDebug()<<i;

////        qDebug()<<ui->treeWidget_ftp->topLevelItemCount();
////        qDebug()<<ui->treeWidget_ftp->indentation();
////        QTreeWidgetItemIterator it(ui->treeWidget_ftp);
////        qDebug()<<(*it)->values



//        qDebug()<<"数量"<<ui->treeWidget_ftp->topLevelItemCount();
//        for(int i=0;i<(ui->treeWidget_ftp->topLevelItemCount());i++){
//            QString name=ui->treeWidget_ftp->topLevelItem(i)->child(0)->text(0);//获取文件名
//            qDebug()<<name;

//        }

////        for(int i=0;i<ftpFileName.size();i++){
////            QString str1=ftpFileName[i];
////            file=new QFile(currentPath+"/"+str1);
////            if (!file->open(QIODevice::WriteOnly)) {
////                QMessageBox::information(this, tr("FTP"),
////                                         tr("下载失败")
////                                         .arg(fileName).arg(file->errorString()));
////                delete file;
////                return;
////            }else{

////                ftp->get(ToSpecialEncoding(ftpFileName[i]), file);//下载文件
////                ui->label_status->setText("下载中");

////            }

////        }

    }
    else{
        if (QFile::exists(currentPath + "/" + fileName)){//本地目录存在该文件
            // QMessageBox::information(this,tr("FTP"),tr("文件已存在本地目录中，无需下载"));
            //return;

            QString name=fileName.split(".").at(0);
            QString houzui=fileName.split(".").at(1);
            fileName.clear();
            fileName=name+"-副本1"+"."+houzui;
            int i=2;
            while(1){
                if(QFile::exists(currentPath+"/"+fileName)){

                    QString name=fileName.split(".").at(0);
                    QString houzui=fileName.split(".").at(1);
                    QString k=QString::number(i,10);
                    i++;
                    qDebug()<<name;

                    name.remove(name.size()-1,1);
                    qDebug()<<name;
                    fileName=name+k+"."+houzui;
                }
                else{
                    break;
                }

            }

        }
        file = new QFile(currentPath + "/" + fileName);
        //qDebug()<<currentPath;
        if (!file->open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("下载失败")
                                     .arg(fileName).arg(file->errorString()));
            delete file;
            return;
        }else{

            //connect(ui->progressBar, SIGNAL(canceled()), this, SLOT(cancelDownload()));



            ftp->get(ToSpecialEncoding(ui->treeWidget_ftp->currentItem()->text(0)), file);//下载文件


            //ui->label_status->setText(tr("下载文件中").arg(fileName));

        }
    }

}

//************************************************************************************************
void Ftp::upLoad()
{
    if(ui->treeWidget_localfile->currentItem()!=NULL){
        QString fileName = ui->treeWidget_localfile->currentItem()->text(0);
        QString path=currentPath+"/"+fileName;
        upLoadFile= new QFile(path);
        QString des=fileName;

        //qDebug()<<fileName;
        if(!upLoadFile->open(QIODevice::ReadOnly)){
            QMessageBox msgBox;
            msgBox.setText("File Not Found");
            msgBox.exec();
            delete upLoadFile;
            return;
        }
        else{
            qDebug()<<"daxiao"<<ftpFileName.size();
            for(int m=0;m<ftpFileName.size();m++){//ftpFileName为服务器文件名
                //qDebug()<<ftpFileName[m];
                if(fileName==ftpFileName[m])
                {
                   //QMessageBox::information(this, tr("FTP"),tr("文件已经存在于FTP服务区,无需上传"));

                    qDebug()<<"1";
                    QString name=fileName.split(".").at(0);
                    QString houzui=fileName.split(".").at(1);
                    fileName.clear();
                    fileName=name+"-副本1"+"."+houzui;
                    int i=2;
                    int j;
                    while(1){
                        for(j=0;j<ftpFileName.size();j++){
                            if(fileName==ftpFileName[j])
                            {
                                qDebug()<<"xiangtong";
                                QString name=fileName.split(".").at(0);
                                QString houzui=fileName.split(".").at(1);
                                QString k=QString::number(i,10);
                                i++;

                                name.remove(name.size()-1,1);
                                fileName=name+k+"."+houzui;
                                break;
                            }
                        }
                        if(j==ftpFileName.size())//如果没有重复的退出循环
                        {
                            break;
                        }
                    }
                    des.clear();
                    des=fileName;
                    break;
                   return;
                }
            }
            //qDebug()<<fileName;
            ftp->put(upLoadFile,(ToSpecialEncoding(des)));
        }
    }
    if(ftp->currentCommand()==QFtp::Put){
        qDebug()<<"正在上传";
    }

}

void Ftp::upLoad1(){
   // if(ftp){
//        QString filePath;
//        QStringList list=currentPath.split('/');//改变文件格式
//        for(int i=0;i<list.count();i++){
//            filePath+=list[i];
//            filePath+="/";
//        }
//        QString path=ui->treeWidget_localfile->currentItem()->text(0);
//        filePath+=path;
//        QString txtPath="./不要删除.txt";
//        QFile file(txtPath);

//        if(file.exists()){//如果文件存在，删除nei内容，重新写入文件地址
//            file.remove();
//            file.close();
//            QFile file1(txtPath);
//            if(file1.open(QIODevice::ReadWrite|QIODevice::Text)){
//                QTextStream stream(&file1);
//                stream<<"put "<<filePath<<"\n";
//            }
//            file1.close();
//        }
//        else{
//            if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
//                QTextStream stream(&file);
//                stream<<"put "<<filePath<<"\n";
//            }
//            file.close();
//        }


//        process=new QProcess;
//        QStringList list1;
//        list1<<"/c"<<"ftp"<<"-s:./不要删除.txt"<<"-A"<<ui->lineEdit->text();
//        //process->startDetached("cmd.exe",list1);
//        process->startDetached("FTP.exe", QStringList()<<"-s:./不要删除.txt"<<"-A"<<"10.108.13.65");

        QProcess p(0);
        //p.startDetached("cmd", QStringList()<<"/c"<<"FTP"<<"-s:./2.txt"<<"-A"<<"10.108.13.65");
        p.start("ftp", QStringList()<<"-s:./不要删除.txt"<<"-A"<<"10.108.13.65");
        //list1<<"/c"<<"ftp"<<"-s:./不要删除.txt"<<"-A"<<ui->lineEdit->text();
        //p.startDetached("cmd", QStringList()<<"/c"<<"ping www.baidu.com");
        p.waitForStarted();
        p.waitForFinished();
        QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());

        QMessageBox testMassage;
        testMassage.setText(strTemp);
        testMassage.exec();


        //connect(process , SIGNAL(readyReadStandardOutput()) , this , SLOT(upLoadRefreshSlot()));
   // }

}
void Ftp::upLoadRefreshSlot(){
    qDebug()<<QString::fromLocal8Bit(process->readAllStandardOutput());   //将输出信息读取到编辑框
    refreshFtpFile();
    if(process) {
        process->close();
        qDebug()<<"关闭进程";
        delete process;
    }
}


//*************************************************************************************************
void Ftp::cancelDownload()//取消下载
{
    if(ui->label_status->text()!="下载完成"){
        ftp->abort();
        upLoadFile->close();

        ui->label_status->setText("取消下载");
    }
}
void Ftp::cancelUpload()//取消上传
{
    if(ui->label_status->text()!="上传完成"){
        ftp->abort();


        ui->label_status->setText("取消上传");
    }
}
//*************************************************************************************************

void Ftp::ftpWriteInit(QString key, QString value)
{
    QString path = "ip.ini";

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //将信息写入配置文件
    config->beginGroup("config");
    config->setValue(key, value);
    config->endGroup();
    delete config;
}

void Ftp::ftpReadInit(QString key, QString &value)
{
    value = QString("");
    QString path = "ip.ini";

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //读取配置信息
    value = config->value(QString("config/") + key).toString();
    delete config;
}

void Ftp::ftpCommandFinished(int commandId, bool error)
{

    if (ftp->currentCommand() == QFtp::ConnectToHost) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),"不能连接服务器,IP地址或者端口有误");
            ui->pushButton_connect->setEnabled(true);
            return;
           // connectToFtp();

        }
//        ui->label_status->setText(tr("Logged onto %1.")
//                             .arg(ftpServerLineEdit->text()));
        ui->treeWidget_ftp->setFocus();
    }

    if (ftp->currentCommand() == QFtp::Login){
        ui->label_status->setText(tr("登录成功"));
        ftp->list();//发出信号
        ui->pushButton_diconnect->setEnabled(true);


    }

    if (ftp->currentCommand() == QFtp::Get) {
        if (error) {

            file->close();
            file->remove();
        } else {
            ui->label_status->setText(tr("下载完成"));
            file->close();
        }
        delete file;
        refreshLocalFile();//刷新local文件目录
        ui->pushButton_canceldownload->setEnabled(false);

    }
    if (ftp->currentCommand() == QFtp::List) {
        if (isDirectory.isEmpty()) {
            ui->treeWidget_ftp->addTopLevelItem(new QTreeWidgetItem(QStringList() << tr("<empty>")));
            ui->treeWidget_ftp->setEnabled(false);
        }
    }
    if(ftp->currentCommand()==QFtp::Put){

        ui->label_status->setText(tr("上传完成"));\
        upLoadFile->close();
        delete upLoadFile;
        refreshFtpFile();
    }
}
//*************************************************************************************************
void Ftp::ftpCommandStarted(int)
{
    int id=ftp->currentCommand();
    switch (id) {
    case QFtp::ConnectToHost:

        ui->label_status->setText(tr("连接服务器中..."));
        break;
    case QFtp::Login:
        ui->label_status->setText(tr("登录中..."));
        break;
    case QFtp::Get:
        ui->label_status->setText(tr("下载中..."));
        break;
    case QFtp::Put:
        ui->label_status->setText(tr("上传中..."));
        break;
    case QFtp::Close:
        ui->label_status->setText(tr("关闭中..."));
    default:
        break;
    }
}



//*************************************************************************************************

void Ftp::addToList(const QUrlInfo &urlInfo)//显示服务器文件  登录完成时调用
{

    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, FromSpecialEncoding(urlInfo.name()));
    item->setText(1, urlInfo.lastModified().toString("yyyy-MM-dd hh:mm"));
    if(!urlInfo.isDir()){
        //item->setText(2, QString::number(urlInfo.size()/1024+1)+" KB");
        item->setData(2,0,QVariant((urlInfo.size()+1023)/1024));
    }
    if(urlInfo.name()=="."||urlInfo.name()==".."){
        return;
    }



    if(urlInfo.isDir()){
        QPixmap pixmap(":/images/dir.png" );
        item->setIcon(0, pixmap);
    }
    else {
        QPixmap pixmap( ":/images/file.png");
        item->setIcon(0, pixmap);
        setIcon(FromSpecialEncoding(urlInfo.name()),item);//设置图标
        ftpFileName.append(FromSpecialEncoding(urlInfo.name()));//更新文件名数组  记着要先清空
       // qDebug()<<ftpFileName.size();
       // qDebug()<<FromSpecialEncoding(urlInfo.name());
       //qDebug()<<"1";
    }


    isDirectory[urlInfo.name()] = urlInfo.isDir();
    ui->treeWidget_ftp->addTopLevelItem(item);
    if (!ui->treeWidget_ftp->currentItem()) {
        ui->treeWidget_ftp->setCurrentItem(ui->treeWidget_ftp->topLevelItem(0));
        ui->treeWidget_ftp->setEnabled(true);
    }

}


//**********************************************************************************************
void Ftp::processItem(QTreeWidgetItem *item, int column)//双击进去FTP文件夹

{
    QString name = item->text(0);

    if (isDirectory.value(name)) {
        ui->treeWidget_ftp->clear();
        isDirectory.clear();
        //currentPath += '/';
        //currentPath += name;
        ftp->cd(name);
        ftp->list();
        qDebug()<<list;

        return;
    }
}
//*************************************************************************************************
void Ftp::cdToParent()//返回上一目录
{

    ui->treeWidget_ftp->clear();
    isDirectory.clear();
    ftp->cd("..");
    ftp->list();//发送信号
    ui->label_status->setText("返回上一目录");
    //connect(ftp, SIGNAL(listInfo(QUrlInfo)),//由ftp->list()发出 登录完成时调用
            //this, SLOT(addToList(QUrlInfo)));
}
//*************************************************************************************************
void Ftp::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes)//进度条
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(readBytes);
    if(totalBytes==0){
        ui->progressBar->setMaximum(1);
        ui->progressBar->setValue(1);
    }
}
//*************************************************************************************************
void Ftp::enableDownloadButton()//下载按钮可用
{
    QTreeWidgetItem *current = ui->treeWidget_ftp->currentItem();
    if (current) {
        QString currentFile = current->text(0);
        //ui->pushButton_download->setEnabled(!isDirectory.value(currentFile));
    } else {
        //ui->pushButton_download->setEnabled(false);
    }
}
//*************************************************************************************************
void Ftp::enableConnectButton()//连接按钮可用
{
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

    ui->pushButton_connect->setEnabled(true);
    ui->label_status->setText(tr("Please enter the name of an FTP server."));
}

//*************************************************************************************************
QString Ftp::FromSpecialEncoding(const QString &InputStr)//显示中文
{
#ifdef Q_OS_WIN
    return  QString::fromLocal8Bit(InputStr.toLatin1());
#else
    QTextCodec *codec = QTextCodec::codecForName("gbk");
    if (codec)
    {
        return codec->toUnicode(InputStr.toLatin1());
    }
    else
    {
        return QString("");
    }
#endif
}
//*************************************************************************************************
QString Ftp::ToSpecialEncoding(const QString &InputStr)//显示中文
{
#ifdef Q_OS_WIN
    return QString::fromLatin1(InputStr.toLocal8Bit());
#else
    QTextCodec *codec= QTextCodec::codecForName("gbk");
    if (codec)
    {
        return QString::fromLatin1(codec->fromUnicode(InputStr));
    }
    else
    {
        return QString("");
    }
#endif
}
//*************************************************************************************************

void Ftp::slotDirShowLocal(QTreeWidgetItem *item)//双击进入本地文件夹文件
{
    QString str = item->text(0);
    QDir dir;

    dir.setPath(currentPath);
    if(!dir.cd(str))         //如果进入失败，则为普通文件，创建新的进程打开对应文件
    {
        QStringList arguments;
        QString start_path = currentPath+"\\" + str;
        arguments << "/c" << start_path;

        QProcess* process = new QProcess;

        process->start("cmd.exe",arguments);  //开启新进程打开文件
        return;
    }
    currentPath = dir.absolutePath();    //更新路径
    slotShow(dir);
}
void Ftp::cdToParentLocal(){//返回上一层
    //qDebug()<<currentPath;
    int i;
    for(i=currentPath.size()-1;i>=0;i--){
        if(currentPath[i]=='/'){
            break;
        }
        }
    QString str=currentPath.mid(0,i);
    //qDebug()<<str;
    if((str=="C:")||(str=="D:")||(str=="E:")||(str=="F:")){
        str+="/";
    }
    currentPath=str;
    QDir dir;
    dir.setPath(currentPath);
    slotShow(dir);
    ui->label_status->setText("返回上一目录");
}

//*************************************************************************************************
void Ftp::refreshLocalFile(){//刷新本地列表
    QDir dir;
    dir.setPath(currentPath);
   // qDebug()<<currentPath;
    slotShow(dir);
}
//*************************************************************************************************
void Ftp::refreshLocalFileSlot(){//刷新本地列表
    QDir dir;
    dir.setPath(currentPath);
    slotShow(dir);
    //qDebug()<<currentPath;

    ui->label_status->setText("刷新本地目录");
}
//*************************************************************************************************
void Ftp::slotShow(QDir dir)
{
    QFileInfoList list = dir.entryInfoList();
    showFileInfoList(list);
}
//*************************************************************************************************
void Ftp::refreshFtpFile(){//刷新FTP服务器列表
    ftpFileName.clear();//先清除原先数据
    ui->treeWidget_ftp->clear();
    ftp->list();//发送信号
    qDebug()<<ftpFileName.size();
}
//*************************************************************************************************
void Ftp::refreshFtpFileSlot(){//刷新FTP服务器列表
    ftpFileName.clear();
    ui->treeWidget_ftp->clear();
    ftp->list();//发送信号
    ui->label_status->setText("刷新FTP目录");
    qDebug()<<ftpFileName.size();
}


//*************************************************************************************************
void Ftp::showFileInfoList(QFileInfoList list)//显示本地目录
{
    ui->treeWidget_localfile->clear();
    ui->treeWidget_localfile->setEnabled(true);
    for(int i=0; i<list.count() ;i++)
    {

        QFileInfo tmpFileInfo = list.at(i);
        //qDebug()<<tmpFileInfo.fileName();
        if(tmpFileInfo.fileName()=="."||tmpFileInfo.fileName()==".."){//判断文件夹名，如果为“." ”.."，则不显示
            continue;
        }
        if(tmpFileInfo.isDir())//为目录则添加文件夹图标及对应文件名
        {


            QString fileName = tmpFileInfo.fileName();
           // qDebug()<<fileName;

            QTreeWidgetItem *newItem=new QTreeWidgetItem();
            newItem->setText(0,fileName);
            newItem->setText(1,tmpFileInfo.lastModified().toString("yyyy-MM-dd hh:mm"));
            QPixmap pixmap( ":/images/dir.png" );
            newItem->setIcon(0, pixmap);

            ui->treeWidget_localfile->addTopLevelItem(newItem);

        }
        else     //为普通文件则添加普通文件图标及对应文件名
       {

            QString fileName = tmpFileInfo.fileName();
            //qDebug()<<fileName;

            QTreeWidgetItem *newItem=new QTreeWidgetItem();
            newItem->setText(0,fileName);
            newItem->setText(1,tmpFileInfo.created().toString("yyyy-MM-dd hh:mm"));
            newItem->setData(2,0,QVariant((tmpFileInfo.size()+1023)/1024));//第三列设置成int 格式，对其进行排序

            QPixmap pixmap(":/images/file.png");
            newItem->setIcon(0, pixmap);
            setIcon(fileName,newItem);

            ui->treeWidget_localfile->addTopLevelItem(newItem);
        }
    }

}
//************************************************************************************************
void Ftp::setIcon(QString fileName,QTreeWidgetItem *newItem){

    QStringList strList =  fileName.split(".");
    int len=strList.count();
    if(strList.count()!=1)
    {

        if(strList.at(len-1)=="doc"||strList.at(len-1)=="docx"){
            QPixmap pixmap(":/images/word.png");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(len-1)=="ppt"||strList.at(len-1)=="pptx"){
            QPixmap pixmap(":/images/ppt.png");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(len-1)=="xlsx"||strList.at(len-1)=="xls"){
            QPixmap pixmap(":/images/excel.png");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(len-1)=="pdf"){
            QPixmap pixmap(":/images/pdf.png");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(len-1)=="rar"||strList.at(len-1)=="zip"){
            QPixmap pixmap(":/images/zip.png");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(len-1)=="txt"){
            QPixmap pixmap(":/images/txt.png");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(len-1)=="exe"){
            QPixmap pixmap(":/images/exe.png");
            newItem->setIcon(0,pixmap);
        }
    }



}


//*************************************************************************************************
void Ftp::ftpRightMenu(QPoint pos)
{
    QTreeWidgetItem* curItem=ui->treeWidget_ftp->itemAt(pos);  //获取当前被点击的节点
    if(curItem==NULL){//为空时
        QMenu *popMenu =new QMenu(this);
        QAction *action=new QAction("刷新目录",popMenu);
        QAction *action1=new QAction("返回上一目录",popMenu);
        popMenu->addAction(action);
        popMenu->addAction(action1);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(refreshFtpFileSlot()));//刷新目录
        connect(action1,SIGNAL(triggered(bool)),this,SLOT(cdToParent()));//返回上一目录
        popMenu->exec(QCursor::pos());
        }//这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
    else {
        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
    //popMenu->addAction("上传");//往菜单内添加上传
    QAction *action=new QAction("下载",popMenu);
    QAction *action1=new QAction("返回上一目录",popMenu);
    QAction *action3=new QAction("刷新目录",popMenu);

    //QAction *action5=new QAction("下载全部文件",popMenu);
    popMenu->addAction(action);
    popMenu->addAction(action3);
    popMenu->addAction(action1);
    if(ui->treeWidget_ftp->currentItem()->text(0)!="Configuration.txt"){
    QAction *action4=new QAction("删除",popMenu);
    popMenu->addAction(action4);
    connect(action4,SIGNAL(triggered(bool)),this,SLOT(deleteFtpFile()));//删除文件

    }
   // popMenu->addAction(action5);
    connect(action,SIGNAL(triggered(bool)),this,SLOT(downloadFile()));
    connect(action1,SIGNAL(triggered(bool)),this,SLOT(cdToParent()));//返回上一目录
    connect(action3,SIGNAL(triggered(bool)),this,SLOT(refreshFtpFileSlot()));//刷新目录

    popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    }
}
void Ftp::localRightMenu(QPoint pos)
{
    QTreeWidgetItem* curItem=ui->treeWidget_localfile->itemAt(pos);  //获取当前被点击的节点
    if(curItem==NULL){
        QMenu *popMenu =new QMenu(this);
        QAction *action=new QAction("刷新目录",popMenu);
        QAction *action2=new QAction("新建文件夹",popMenu);
        QAction *action1=new QAction("返回上一目录",popMenu);

        popMenu->addAction(action);
        popMenu->addAction(action2);
        popMenu->addAction(action1);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(refreshLocalFileSlot()));
        connect(action1,SIGNAL(triggered(bool)),this,SLOT(cdToParentLocal()));
        connect(action2,SIGNAL(triggered(bool)),this,SLOT(newDirLocal()));
        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    }

    else{
        QMenu *popMenu =new QMenu(this);
        QAction *action=new QAction("上传",popMenu);
        QAction *action1=new QAction("刷新目录",popMenu);
        QAction *action2=new QAction("新建文件夹",popMenu);
        QAction *action3=new QAction("删除",popMenu);
        QAction *action4=new QAction("返回上一目录",popMenu);



        popMenu->addAction(action);
        popMenu->addAction(action1);
        popMenu->addAction(action2);
        popMenu->addAction(action3);
        popMenu->addAction(action4);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(upLoad1()));
        connect(action1,SIGNAL(triggered(bool)),this,SLOT(refreshLocalFileSlot()));
        connect(action2,SIGNAL(triggered(bool)),this,SLOT(newDirLocal()));
        connect(action3,&QAction::triggered,this,[=](){
            QString strName=ui->treeWidget_localfile->currentItem()->text(0);
            currentPath+="/";
            currentPath+=strName;
            deleteDirLocal(currentPath);
            currentPath=currentPath.left(currentPath.lastIndexOf('/'));
            refreshLocalFileSlot();
            ui->label_status->setText("文件已删除");
        });
        connect(action4,SIGNAL(triggered(bool)),this,SLOT(cdToParentLocal()));


        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    }
}
void Ftp::changeCd(){
    if(ui->comboBox->currentIndex()==0){
        currentPath="C:/";
    }
    else if(ui->comboBox->currentIndex()==1){
        currentPath="D:/";
        QDir dir;
        dir.setPath(currentPath);
        if(dir.Size==0){
            QMessageBox::information(this, tr("D盘"),"不存在D盘");
            return;
        }
    }

    else if(ui->comboBox->currentIndex()==2){
        currentPath="E:/";
        QDir dir;
        dir.setPath(currentPath);
        if(dir.Size==0){
            QMessageBox::information(this, tr("E盘"),"不存在E盘");
            return;
        }
    }
    else if(ui->comboBox->currentIndex()==3){
        currentPath="F:/";
        QDir dir;
        dir.setPath(currentPath);
        if(dir.Size==2){
            QMessageBox::information(this, tr("F盘"),"不存在F盘");
            return;
        }
    }
    refreshLocalFile();
}
void Ftp::newDirFtp(){

}

void Ftp::newDirLocal(){
    int i=2;
    QDir dir;
    dir.cd(currentPath);
    QString str="新建文件夹1";
    while(1){
        if(dir.exists(str)){
            str.remove(5,1);
            QString s = QString::number(i, 10);
            str+=s;
            i++;
        }
        else {
            dir.mkdir(str);
            refreshLocalFile();
            break;

        }
    }
    ui->label_status->setText("在本地新建文件夹");
}

bool Ftp::deleteDirLocal(const QString path)

{

    QFileInfo info(path);
    if(info.isDir()){
        QDir dir(path);
        if (path.isEmpty())
            return false ;

        if(!dir.exists())
            return true;

        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
        QFileInfoList fileList = dir.entryInfoList();
        foreach (QFileInfo fi, fileList)
        {
            if (fi.isFile()){
                fi.dir().remove(fi.fileName());
            ui->label_status->setText("删除文件");
            }
            else{
                ui->label_status->setText("删除文件夹");
                deleteDirLocal(fi.absoluteFilePath());
            }

        }
        return dir.rmpath(dir.absolutePath()) ;
    }
    else {
        QFile::remove(path);
        qDebug()<<"删除";
    }
    ui->label_status->setText("文件夹已删除");
}
void Ftp::deleteFtpFile(){
    QString name=ui->treeWidget_ftp->currentItem()->text(0);
    ftp->remove((ToSpecialEncoding(name)));
    refreshFtpFile();
    ui->label_status->setText("文件已删除");
}

void Ftp::reNameLocal(){

}



