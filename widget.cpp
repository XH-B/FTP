#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{



    ui->setupUi(this);










    ui->qwtPlot->setTitle("通道一");
    ui->qwtPlot_2->setTitle("通道二");
    ui->qwtPlot_3->setTitle("通道三");
    ui->qwtPlot_4->setTitle("通道四");
    ui->qwtPlot_5->setTitle("通道五");
    ui->qwtPlot_6->setTitle("通道六");

    QwtPlotCanvas *canvas=new QwtPlotCanvas();//设置画布
    canvas->setPalette(Qt::white);
    canvas->setBorderRadius(10);
    ui->qwtPlot->setCanvas(canvas);
    QwtPlotCanvas *canvas2=new QwtPlotCanvas();//设置画布
    canvas2->setPalette(Qt::white);
    canvas2->setBorderRadius(10);
    ui->qwtPlot_2->setCanvas(canvas2);
    QwtPlotCanvas *canvas3=new QwtPlotCanvas();//设置画布
    canvas3->setPalette(Qt::white);
    canvas3->setBorderRadius(10);
    ui->qwtPlot_3->setCanvas(canvas3);
    QwtPlotCanvas *canvas4=new QwtPlotCanvas();//设置画布
    canvas4->setPalette(Qt::white);
    canvas4->setBorderRadius(10);
    ui->qwtPlot_4->setCanvas(canvas4);
    QwtPlotCanvas *canvas5=new QwtPlotCanvas();//设置画布
    canvas5->setPalette(Qt::white);
    canvas5->setBorderRadius(10);
    ui->qwtPlot_5->setCanvas(canvas5);
    QwtPlotCanvas *canvas6=new QwtPlotCanvas();//设置画布
    canvas6->setPalette(Qt::white);
    canvas6->setBorderRadius(10);
    ui->qwtPlot_6->setCanvas(canvas6);


   // QwtPlotMagnifier *ma=new QwtPlotMagnifier(ui->qwtPlot->canvas());//滚轮缩放
   // qDebug()<<ma->wheelFactor();
   // qDebug()<<canvas->size();

   //qDebug()<<wheelFactor();



    new QwtPlotPanner(ui->qwtPlot->canvas());//左键平移
    new QwtPlotPanner(ui->qwtPlot_2->canvas());//左键平移
    new QwtPlotPanner(ui->qwtPlot_3->canvas());//左键平移
    new QwtPlotPanner(ui->qwtPlot_4->canvas());//左键平移
    new QwtPlotPanner(ui->qwtPlot_5->canvas());//左键平移
    new QwtPlotPanner(ui->qwtPlot_6->canvas());//左键平移
    //plotLayout()->setAlignCanvasToScale(true);


    //ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,"电压/V/A");
    //ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,"时间/S");
    //ui->qwtPlot->setAxisScale(QwtPlot::yLeft,15,40);


    QwtPlotGrid *grid=new QwtPlotGrid;//划分网格
    grid->enableX(true);
    grid->enableY(true);
    grid->setMajorPen(Qt::black,0,Qt::DotLine);
    grid->attach(ui->qwtPlot);
    QwtPlotGrid *grid2=new QwtPlotGrid;//划分网格
    grid2->enableX(true);
    grid2->enableY(true);
    grid2->setMajorPen(Qt::black,0,Qt::DotLine);
    grid2->attach(ui->qwtPlot_2);
    QwtPlotGrid *grid3=new QwtPlotGrid;//划分网格
    grid3->enableX(true);
    grid3->enableY(true);
    grid3->setMajorPen(Qt::black,0,Qt::DotLine);
    grid3->attach(ui->qwtPlot_3);
    QwtPlotGrid *grid4=new QwtPlotGrid;//划分网格
    grid4->enableX(true);
    grid4->enableY(true);
    grid4->setMajorPen(Qt::black,0,Qt::DotLine);
    grid4->attach(ui->qwtPlot_4);
    QwtPlotGrid *grid5=new QwtPlotGrid;//划分网格
    grid5->enableX(true);
    grid5->enableY(true);
    grid5->setMajorPen(Qt::black,0,Qt::DotLine);
    grid5->attach(ui->qwtPlot_5);
    QwtPlotGrid *grid6=new QwtPlotGrid;//划分网格
    grid6->enableX(true);
    grid6->enableY(true);
    grid6->setMajorPen(Qt::black,0,Qt::DotLine);
    grid6->attach(ui->qwtPlot_6);



    QwtLegend *legend=new QwtLegend;//插入图标
    legend->setDefaultItemMode(QwtLegendData::Checkable);
    ui->qwtPlot->insertLegend(legend,QwtPlot::RightLegend);
    QwtLegend *legend2=new QwtLegend;//插入图标
    legend2->setDefaultItemMode(QwtLegendData::Checkable);
    ui->qwtPlot_2->insertLegend(legend2,QwtPlot::RightLegend);
    QwtLegend *legend3=new QwtLegend;//插入图标
    legend3->setDefaultItemMode(QwtLegendData::Checkable);
    ui->qwtPlot_3->insertLegend(legend3,QwtPlot::RightLegend);
    QwtLegend *legend4=new QwtLegend;//插入图标
    legend4->setDefaultItemMode(QwtLegendData::Checkable);
    ui->qwtPlot_4->insertLegend(legend4,QwtPlot::RightLegend);
    QwtLegend *legend5=new QwtLegend;//插入图标
    legend5->setDefaultItemMode(QwtLegendData::Checkable);
    ui->qwtPlot_5->insertLegend(legend5,QwtPlot::RightLegend);
    QwtLegend *legend6=new QwtLegend;//插入图标
    legend6->setDefaultItemMode(QwtLegendData::Checkable);
    ui->qwtPlot_6->insertLegend(legend6,QwtPlot::RightLegend);

    connect(legend,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));




   // QwtPlotCurve curve[6][6]=new QwtPlotCurve;
//    curve[0][0].setTitle("通道一");


    QwtPlotCurve *curve= new QwtPlotCurve("通道一");
    curve->setPen(Qt::blue ,2);
    curve->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    //QwtSymbol *symbool=new QwtSymbol(QwtSymbol::Ellipse,QBrush(Qt::yellow),QPen(Qt::red,2),QSize(1,1));
    //curve->setSymbol(symbool);
    curve->setLegendAttribute(curve->LegendShowLine);
    curve->attach(ui->qwtPlot);
    QwtPlotCurve *curve2= new QwtPlotCurve("通道二");
    curve2->setPen(Qt::red ,2);
    curve2->attach(ui->qwtPlot);
    curve2->setLegendAttribute(curve->LegendShowLine);
    curve2->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    QwtPlotCurve *curve3= new QwtPlotCurve("通道三");
    curve3->setPen(Qt::black ,2);
    curve3->attach(ui->qwtPlot);
    curve3->setLegendAttribute(curve->LegendShowLine);
    curve3->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    QwtPlotCurve *curve4= new QwtPlotCurve("通道四");
    curve4->setPen(Qt::green ,2);
    curve4->attach(ui->qwtPlot);
    curve4->setLegendAttribute(curve->LegendShowLine);
    curve4->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    QwtPlotCurve *curve5= new QwtPlotCurve("通道五");
    curve5->setPen(Qt::cyan ,2,Qt::DotLine);
    curve5->attach(ui->qwtPlot);
    curve5->setLegendAttribute(curve->LegendShowLine);
    curve5->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    QwtPlotCurve *curve6= new QwtPlotCurve("通道六");
    curve6->setPen(Qt::magenta ,2,Qt::DotLine);
    curve6->attach(ui->qwtPlot);
    curve6->setLegendAttribute(curve->LegendShowLine);
    curve6->setRenderHint(QwtPlotItem::RenderAntialiased,true);


    QwtPlotItemList items=ui->qwtPlot->itemList(QwtPlotItem::Rtti_PlotCurve);
    //qDebug()<<items.size();
    for(int i=0;i<items.size();i++){
        if(i==0){
            const QVariant itemInfo=ui->qwtPlot->itemToInfo(items[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items[i]->setVisible(true);
        }
        else {
            items[i]->setVisible(false);

        }
    }

    //ui->qwtPlot->resize(300,300);
    //ui->qwtPlot->setAutoReplot(true);



    connect(ui->pushButton_openfile,&QPushButton::clicked,this,[=](){//打开文件并显示
        fileName=QFileDialog::getOpenFileName(this,"打开文件",":/");
        if(fileName!=NULL){
            hz=fileName.split(",").at(1);//频率
        }
        //        qDebug()<<fileName;
        //fileName ="D:/1/2019051118,1000Hz.txt";
        readFile(fileName);
        curve->setSamples(x,channel_1);
        curve2->setSamples(x,channel_2);
        curve3->setSamples(x,channel_3);
        curve4->setSamples(x,channel_4);
        curve5->setSamples(x,channel_5);
        curve6->setSamples(x,channel_6);

        showTimeRange();
        ui->doubleSpinBox->setMaximum(x[x.size()-1]);
        ui->doubleSpinBox_2->setMaximum(x[x.size()-1]);
    });


    //qDebug()<<start<<end;


    connect(ui->pushButton_queding,&QPushButton::clicked,this,[=](){//分段显示
        j=0;
        channel_11.clear();
        channel_22.clear();
        channel_33.clear();
        channel_44.clear();
        channel_55.clear();
        channel_66.clear();
        x1.clear();
        start=ui->doubleSpinBox->text().toDouble();//开始时间
        end=ui->doubleSpinBox_2->text().toDouble();//结束时间

        for(int i=0;i<x.size();i++){
            if(x[i]>=start&&x[i]<=end){
                x1.append(x[i]);
                channel_11.append(channel_1[i]);
                channel_22.append(channel_2[i]);
                channel_33.append(channel_3[i]);
                channel_44.append(channel_4[i]);
                channel_55.append(channel_5[i]);
                channel_66.append(channel_6[i]);

            }
        }
        curve->setSamples(x1,channel_11);
        curve2->setSamples(x1,channel_22);
        curve3->setSamples(x1,channel_33);
        curve4->setSamples(x1,channel_44);
        curve5->setSamples(x1,channel_55);
        curve6->setSamples(x1,channel_66);
        ui->qwtPlot->replot();

    });
    connect(ui->pushButton_cancelsegshow,&QPushButton::clicked,this,[=](){
        curve->setSamples(x,channel_1);
        curve2->setSamples(x,channel_2);
        curve3->setSamples(x,channel_3);
        curve4->setSamples(x,channel_4);
        curve5->setSamples(x,channel_5);
        curve6->setSamples(x,channel_6);
        ui->qwtPlot->replot();
    });
    ui->progressBar_readfile->setValue(0);


    ui->qwtPlot->hide();
    ui->qwtPlot_2->hide();
    ui->qwtPlot_3->hide();
    ui->qwtPlot_4->hide();
    ui->qwtPlot_5->hide();
    ui->qwtPlot_6->hide();

    connect(ui->checkBox,&QCheckBox::stateChanged,this,[=](){//选择框是否选中，如果选中显示通道图，未选中隐藏
        if(!ui->checkBox->isChecked()){
            ui->qwtPlot->hide();//通道图隐藏
        }
        else{
            ui->qwtPlot->show();
        }
    });
    connect(ui->checkBox_2,&QCheckBox::stateChanged,this,[=](){//选择框是否选中，如果选中显示通道图，未选中隐藏
        if(!ui->checkBox_2->isChecked()){
            ui->qwtPlot_2->hide();//通道图隐藏
        }
        else{
            ui->qwtPlot_2->show();
        }
    });
    connect(ui->checkBox_3,&QCheckBox::stateChanged,this,[=](){//选择框是否选中，如果选中显示通道图，未选中隐藏
        if(!ui->checkBox_3->isChecked()){
            ui->qwtPlot_3->hide();//通道图隐藏
        }
        else{
            ui->qwtPlot_3->show();
        }
    });
    connect(ui->checkBox_4,&QCheckBox::stateChanged,this,[=](){//选择框是否选中，如果选中显示通道图，未选中隐藏
        if(!ui->checkBox_4->isChecked()){
            ui->qwtPlot_4->hide();//通道图隐藏
        }
        else{
            ui->qwtPlot_4->show();
        }
    });
    connect(ui->checkBox_5,&QCheckBox::stateChanged,this,[=](){//选择框是否选中，如果选中显示通道图，未选中隐藏
        if(!ui->checkBox_5->isChecked()){
            ui->qwtPlot_5->hide();//通道图隐藏
        }
        else{
            ui->qwtPlot_5->show();
        }
    });
    connect(ui->checkBox_6,&QCheckBox::stateChanged,this,[=](){//选择框是否选中，如果选中显示通道图，未选中隐藏
        if(!ui->checkBox_6->isChecked()){
            ui->qwtPlot_6->hide();//通道图隐藏
        }
        else{
            ui->qwtPlot_6->show();
        }
    });



//****************************************************************************************
//***************************************************************************************



    QIcon icon(":/images/cdtoparent.png");//为返回键设置图标
    ui->treeWidget_ftp->setSortingEnabled(true);//设置排序可用 按时间 名称
    ui->treeWidget_localfile->setSortingEnabled(true);



    connect(ui->pushButton_connect, SIGNAL(clicked()), this, SLOT(connectToFtp()));//连接服务器

    downloadPath = QDir::currentPath();//当前程序路径


    currentPath=QDir::currentPath();//当前程序路径
    QDir dir(currentPath);
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
    ui->progressBar->setValue(0);//初始化进度条

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeCd()));
    connect(ui->pushButton_canceldownload,SIGNAL(clicked(bool)),this,SLOT(cancelDownload()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::readFile(const QString &fa)
{
    QFile file(fa);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!";
        return;
    }
    int sumLine=0;
    int k;
    while (!file.atEnd())
    {
        file.readLine();//读取一行
        sumLine++;
    }
    file.close();
    if(sumLine>10000)//判断文件大小 如果文件行数大于1000行则除以1000处理  否则正常处理
        ui->progressBar_readfile->setRange(0,sumLine/10000);
    else
        ui->progressBar_readfile->setRange(0,sumLine);

    int i=0;
    int flag = 0;
    channel_1.clear();
    channel_2.clear();
    channel_3.clear();
    channel_4.clear();
    channel_5.clear();
    channel_6.clear();
    x.clear();
    QFile file1(fa);
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!";
        return;
    }else{
        int sum=0;


        while (!file1.atEnd())
        {
            QByteArray line = file1.readLine();//读取一行
            QString str(line);
            QStringList strList =  str.split(" ");
            if(flag){
                QStringList t = strList.at(0).split(":");
                // timeSt.append( QTime(0,t.at(0).toInt(),t.at(1).toInt(),t.at(2).toInt()));
                channel_1.append(strList.at(1).toInt()/100.00);
                //qDebug()<<strList.at(1).toInt()/100.00;

                channel_2.append(strList.at(2).toInt()/100.00);
                channel_3.append(strList.at(3).toInt()/100.00);
                channel_4.append(strList.at(4).toInt()/100.00);
                channel_5.append(strList.at(5).toInt()/100.00);
                channel_6.append(strList.at(6).toInt()/100.00);
                if(hz == "100Hz.txt")
                    x.append(i++/10.00);
                else
                    x.append(i++/100.00);
            }

            flag = 1;
            sum++;
            if(sumLine>10000){//判断文件大小  太大就
                if(sum%10000==0){
                    ui->progressBar_readfile->setValue(sum/10000);
                }
            }
            else {
                ui->progressBar_readfile->setValue(sum);
            }
        }

        file1.close();
    }
    qDebug()<<"文件读取成功";

}

void Widget::showItem(const QVariant &itemInfo, bool on){
    QwtPlotItem *plotItem=ui->qwtPlot->infoToItem(itemInfo);
    qDebug()<<on;
    if(plotItem){
        plotItem->setVisible(on);
    }
}
void Widget::showTimeRange()//显示时间范围
{
    QString time="0";
    time+="：";
    double end=x[x.size()-1];
    qDebug()<<end;
    QString str=QString::number(end,10,2);;//QString::number(a,基底，精度)
    time+=str;
    ui->label_timerange->setText(time);

}
void Widget::cancelSegmentShow(){

    curve->setSamples(x,channel_1);
    curve2->setSamples(x,channel_2);
    curve3->setSamples(x,channel_3);
    curve4->setSamples(x,channel_4);
    curve5->setSamples(x,channel_5);
    curve6->setSamples(x,channel_6);


    ui->qwtPlot->replot();


}

//***************************************************************************************************
//***************************************************************************************************
void Widget::connectOrDisconnect()//建立或者断开连接
{
//    if (ftp!=NULL) {//断开连接
//        qDebug()<<"5";
//        ftp->abort();
//        ftp->deleteLater();
//        ui->treeWidget_ftp->clear();
//        ui->treeWidget_ftp->setEnabled(false);
//        //ui->pushButton_download->setEnabled(false);
//        ui->pushButton_connect->setEnabled(true);
//        ui->pushButton_connect->setText(tr("Connect"));
//        ui->label_status->setText(tr("Please enter the name of an FTP server."));
//        return;
//    }

    if (!networkSession || !networkSession->isOpen()) {//建立连接
        qDebug()<<"1";
        //if (manager.capabilities() && QNetworkConfigurationManager::NetworkSessionRequired) {
            if (!networkSession) {
                // Get saved network configuration
                QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
                settings.beginGroup(QLatin1String("QtNetwork"));
                const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
                settings.endGroup();
qDebug()<<"2";
                // If the saved network configuration is not currently discovered use the system default
                QNetworkConfiguration config = manager.configurationFromIdentifier(id);
                if ((config.state() & QNetworkConfiguration::Discovered) !=
                        QNetworkConfiguration::Discovered) {
                    config = manager.defaultConfiguration();
                }
qDebug()<<"3";
                networkSession = new QNetworkSession(config, this);
                connect(networkSession, SIGNAL(opened()), this, SLOT(connectToFtp()));
                connect(networkSession, SIGNAL(error(QNetworkSession::SessionError)), this, SLOT(enableConnectButton()));
            }
            ui->pushButton_connect->setEnabled(false);
            ui->label_status->setText(tr("Opening network session."));
            networkSession->open();
            return;
        //}
    }
    qDebug()<<"4";
    connectToFtp();
}
//*************************************************************************************************
void Widget::downloadFile()//download按钮->下载文件
{

    QString fileName = ui->treeWidget_ftp->currentItem()->text(0); //当前选中文件名


//    file = new QFile(currentPath + "/" + fileName);
    if(ui->treeWidget_ftp->currentItem()->text(2)==0){
        QMessageBox::information(this,tr("FTP"),tr("文件大小为0,不能下载"));
        return;
    }

    if (QFile::exists(currentPath + "/" + fileName)){//本地目录存在该文件
        QMessageBox::information(this,tr("FTP"),tr("文件已存在本地目录中，无需下载"));
        return;

//        QString name=fileName.split(".").at(0);
//        QString houzui=fileName.split(".").at(1);
//        fileName.clear();
//        fileName=name+"-副本1"+"."+houzui;
//        int i=2;
//        while(1){
//            if(QFile::exists(currentPath+"/"+fileName)){

//                QString name=fileName.split(".").at(0);
//                QString houzui=fileName.split(".").at(1);
//                QString k=QString::number(i,10);
//                i++;
//                qDebug()<<name;

//                name.remove(name.size()-1,1);
//                qDebug()<<name;
//                fileName=name+k+"."+houzui;
//            }
//            else{
//                break;
//            }

        //}

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

        //ui->label_status->setText(tr("Downloading %1...").arg(fileName));

    }
}

//************************************************************************************************
void Widget::upLoad()
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
            for(int m=0;m<ftpFileName.size();m++){
                qDebug()<<ftpFileName[m];
                if(fileName==ftpFileName[m])
                {
                   QMessageBox::information(this, tr("FTP"),tr("文件已经存在于FTP服务区,无需上传"));

//                    qDebug()<<"1";
//                    QString name=fileName.split(".").at(0);
//                    QString houzui=fileName.split(".").at(1);
//                    fileName.clear();
//                    fileName=name+"-副本1"+"."+houzui;
//                    int i=2;
//                    int j;
//                    while(1){
//                        for(j=0;j<ftpFileName.size();j++){
//                            if(fileName==ftpFileName[j])
//                            {
//                                qDebug()<<"xiangtong";
//                                QString name=fileName.split(".").at(0);
//                                QString houzui=fileName.split(".").at(1);
//                                QString k=QString::number(i,10);
//                                i++;

//                                name.remove(name.size()-1,1);
//                                fileName=name+k+"."+houzui;
//                                break;
//                            }
//                        }
//                        if(j==ftpFileName.size())//如果没有重复的退出循环
//                        {
//                            break;
//                        }
//                    }
//                    des.clear();
//                    des=fileName;
//                    break;
                   return;
                }
            }
            qDebug()<<fileName;
            QByteArray data=upLoadFile->readAll();
            ftp->put(data,(ToSpecialEncoding(des)));
            //ftpFileName.append(des);//名字数组中加入新文件名

            qDebug()<<"2";
        }
    }
}


//*************************************************************************************************
void Widget::cancelDownload()//取消下载
{
    ftp->abort();
    ui->label_status->setText("取消下载");

//    if (file->exists()) {
//        file->close();
//        file->remove();
//    }
//    delete file;
}
//*************************************************************************************************
void Widget::connectToFtp()//连接服务器
{
    ftp = new QFtp(this);

    ui->treeWidget_ftp->clear();
    isDirectory.clear();
    ftpFileName.clear();


    connect(ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpCommandStarted(int)));
    connect(ftp, SIGNAL(commandFinished(int,bool)),this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp, SIGNAL(listInfo(QUrlInfo)),//由ftp->list()发出 登录完成时调用
            this, SLOT(addToList(QUrlInfo)));
    connect(ftp, SIGNAL(dataTransferProgress(qint64,qint64)),
            this, SLOT(updateDataTransferProgress(qint64,qint64)));

//    QString ftpServer="10.108.12.31";
//    QString userName="Goldensun";
//    QString passWord="7622041.";
//    ftp->connectToHost(ftpServer,21);
//    ftp->login(userName,passWord);


//    QString readScheme;
//    QString readHost;
//    QString readPort;
//    QString readUserName;
//    QString passWord;


//    ftpReadInit("scheme", readScheme);//string
//    ftpReadInit("IP", readHost);//string
//    ftpReadInit("PORT", readPort);//int
//    ftpReadInit("username", readUserName);//string
//    ftpReadInit("password", passWord);//string
//    QUrl url;
//    bool ok;
//    url.scheme()=readScheme;
//    url.host()=readHost;
//    int p=readPort.toInt();
//    //url.port()=p;//string->int
//    url.userName()=readUserName;
//    url.password()=passWord;
//    //QString s = ui->lineEdit->text();
//    //qDebug()<<"url"<<s;
//    if (!url.isValid() || url.scheme().toLower() != QLatin1String("ftp")) {
//        ftp->connectToHost(ui->lineEdit->text(), 21);//只有ip时，连接服务器
//        ftp->login();
//        //qDebug()<<"1";
//    }
//    else {
//        ftp->connectToHost(url.host(), url.port());//格式 IP：port

//        if (!url.userName().isEmpty())//用户名：ip:port
//            ftp->login(QUrl::fromPercentEncoding(url.userName().toLatin1()), url.password());
//        else
//            ftp->login();
//        if (!url.path().isEmpty())
//             ftp->cd(url.path());
//    }
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
    ui->pushButton_connect->setEnabled(false);
    ui->label_status->setText("连接服务器成功");



//    WriteInit("scheme", url.scheme());//string
//    WriteInit("IP", url.host());//string
//    WriteInit("PORT", url.port());//int
//    WriteInit("username", url.userName());//string
//    WriteInit("password", url.password());//string




}
//*************************************************************************************************

void Widget::ftpWriteInit(QString key, QString value)
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

void Widget::ftpReadInit(QString key, QString &value)
{
    value = QString("");
    QString path = "ip.ini";

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //读取配置信息
    value = config->value(QString("config/") + key).toString();
    delete config;
}

void Widget::ftpCommandFinished(int commandId, bool error)
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
        ui->pushButton_connect->setEnabled(true);
        return;
    }

    if (ftp->currentCommand() == QFtp::Login){
        ui->label_status->setText(tr("登录成功"));
        ftp->list();//发出信号

    }

    if (ftp->currentCommand() == QFtp::Get) {
        if (error) {
//            ui->label_status->setText(tr("Canceled download of %1.")
//                                 .arg(file->fileName()));
            file->close();
            file->remove();
        } else {
            ui->label_status->setText(tr("下载完成"));
//            statusLabel->setText(tr("Downloaded %1 to %2.")
//                                 .arg(file->fileName().split("/").takeLast()).arg(downloadPath));
            file->close();
        }
        delete file;
        refreshLocalFile();//刷新local文件目录

    } else if (ftp->currentCommand() == QFtp::List) {
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
void Widget::ftpCommandStarted(int)
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

void Widget::addToList(const QUrlInfo &urlInfo)//显示服务器文件
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, FromSpecialEncoding(urlInfo.name()));
    item->setText(1, urlInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
    item->setText(2, QString::number(urlInfo.size())+" KB");




    if(urlInfo.isDir()){//设置图标
        QPixmap pixmap(":/images/dir.png" );
        item->setIcon(0, pixmap);

    }
    else {
        QPixmap pixmap( ":/images/file.png");
        item->setIcon(0, pixmap);
        setIcon(FromSpecialEncoding(urlInfo.name()),item);
        ftpFileName.append(FromSpecialEncoding(urlInfo.name()));

    }


    isDirectory[urlInfo.name()] = urlInfo.isDir();
    ui->treeWidget_ftp->addTopLevelItem(item);
    if (!ui->treeWidget_ftp->currentItem()) {
        ui->treeWidget_ftp->setCurrentItem(ui->treeWidget_ftp->topLevelItem(0));
        ui->treeWidget_ftp->setEnabled(true);
    }

}


//**********************************************************************************************
void Widget::processItem(QTreeWidgetItem *item, int column)//双击进去FTP文件夹

{
    QString name = item->text(0);

    if (isDirectory.value(name)) {
        ui->treeWidget_ftp->clear();
        isDirectory.clear();
        //currentPath += '/';
        //currentPath += name;
        ftp->cd(name);
        list = ftp->list();
        return;
    }
}
//*************************************************************************************************
void Widget::cdToParent()//返回上一目录
{

    ui->treeWidget_ftp->clear();
    isDirectory.clear();
    ftp->cd("..");
    ftp->list();//发送信号
    //connect(ftp, SIGNAL(listInfo(QUrlInfo)),//由ftp->list()发出 登录完成时调用
            //this, SLOT(addToList(QUrlInfo)));
}
//*************************************************************************************************
void Widget::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes)//进度条
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(readBytes);
}
//*************************************************************************************************
void Widget::enableDownloadButton()//下载按钮可用
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
void Widget::enableConnectButton()//连接按钮可用
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
QString Widget::FromSpecialEncoding(const QString &InputStr)//显示中文
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
QString Widget::ToSpecialEncoding(const QString &InputStr)//显示中文
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

void Widget::slotDirShowLocal(QTreeWidgetItem *item)//双击进入本地文件夹文件
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
void Widget::cdToParentLocal(){//返回上一层
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
}

//*************************************************************************************************
void Widget::refreshLocalFile(){//刷新本地列表
    QDir dir;
    dir.setPath(currentPath);
   // qDebug()<<currentPath;
    slotShow(dir);
}
//*************************************************************************************************
void Widget::refreshLocalFileSlot(){//刷新本地列表
    QDir dir;
    dir.setPath(currentPath);
    slotShow(dir);
    //qDebug()<<currentPath;
    ui->label_status->setText("刷新本地目录");
}
//*************************************************************************************************
void Widget::slotShow(QDir dir)
{
    QFileInfoList list = dir.entryInfoList();
    showFileInfoList(list);
}
//*************************************************************************************************
void Widget::refreshFtpFile(){//刷新FTP服务器列表
    ftpFileName.clear();//先清除原先数据
    ui->treeWidget_ftp->clear();
    ftp->list();//发送信号
}
//*************************************************************************************************
void Widget::refreshFtpFileSlot(){//刷新FTP服务器列表
    ftpFileName.clear();
    ui->treeWidget_ftp->clear();
    ftp->list();//发送信号
    ui->label_status->setText("刷新FTP目录");
}


//*************************************************************************************************
void Widget::showFileInfoList(QFileInfoList list)//显示本地目录
{
    ui->treeWidget_localfile->clear();
    ui->treeWidget_localfile->setEnabled(true);
    for(int i=2; i<list.count() ;i++)
    {
        QFileInfo tmpFileInfo = list.at(i);
        if(tmpFileInfo.isDir())//为目录则添加文件夹图标及对应文件名
        {


            QString fileName = tmpFileInfo.fileName();
           // qDebug()<<fileName;

            QTreeWidgetItem *newItem=new QTreeWidgetItem();
            newItem->setText(0,fileName);
            newItem->setText(1,tmpFileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
            newItem->setText(2,QString::number(tmpFileInfo.size())+" KB");
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
            newItem->setText(1,tmpFileInfo.created().toString("yyyy-MM-dd hh:mm:ss"));
            newItem->setText(2,QString::number(tmpFileInfo.size())+" KB");
            QPixmap pixmap(":/images/file.png");
            newItem->setIcon(0, pixmap);
            setIcon(fileName,newItem);

            ui->treeWidget_localfile->addTopLevelItem(newItem);
        }
    }

}
//************************************************************************************************
void Widget::setIcon(QString fileName,QTreeWidgetItem *newItem){

    QStringList strList =  fileName.split(".");
    if(strList.size()==2){

        if(strList.at(1)=="doc"||strList.at(1)=="docx"){
            QPixmap pixmap(":/images/word.jpg");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(1)=="ppt"||strList.at(1)=="pptx"){
            QPixmap pixmap(":/images/ppt.jpg");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(1)=="xlsx"||strList.at(1)=="xls"){
            QPixmap pixmap(":/images/excel.jpg");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(1)=="pdf"){
            QPixmap pixmap(":/images/pdf.jpg");
            newItem->setIcon(0,pixmap);
        }
        else if(strList.at(1)=="rar"||strList.at(1)=="zip"){
            QPixmap pixmap(":/images/zip.jpg");
            newItem->setIcon(0,pixmap);
        }
    }



}


//*************************************************************************************************
void Widget::ftpRightMenu(QPoint pos)
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
//    QVariant var = curItem->data(0,Qt::UserRole);
//    if(0 == var)      //data(...)返回的data已经在之前建立节点时用setdata()设置好
//    {
//       QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单

//       popMenu->addAction("ui->action_newDB");//往菜单内添加QAction   该action在前面用设计器定义了

//       popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
//    }
//    else
//    {
//        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单

//        popMenu->addAction("ui->action_newTable");//往菜单内添加QAction   该action在前面用设计器定义了

//        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
//    }
    else{QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
    //popMenu->addAction("上传");//往菜单内添加上传
    QAction *action=new QAction("下载",popMenu);
    QAction *action1=new QAction("返回上一目录",popMenu);
    QAction *action3=new QAction("刷新目录",popMenu);
    QAction *action4=new QAction("删除",popMenu);
    popMenu->addAction(action);
    popMenu->addAction(action3);
    popMenu->addAction(action1);
    popMenu->addAction(action4);
    connect(action,SIGNAL(triggered(bool)),this,SLOT(downloadFile()));
    connect(action1,SIGNAL(triggered(bool)),this,SLOT(cdToParent()));//返回上一目录
    connect(action3,SIGNAL(triggered(bool)),this,SLOT(refreshFtpFileSlot()));//刷新目录
    connect(action4,SIGNAL(triggered(bool)),this,SLOT(deleteFtpFile()));//刷新目录
    popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    }
}
void Widget::localRightMenu(QPoint pos)
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
//这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
//    QVariant var = curItem->data(0,Qt::UserRole);
//    if(0 == var)      //data(...)返回的data已经在之前建立节点时用setdata()设置好
//    {
//       QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单

//       popMenu->addAction("ui->action_newDB");//往菜单内添加QAction   该action在前面用设计器定义了

//       popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
//    }
//    else
//    {
//        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单

//        popMenu->addAction("ui->action_newTable");//往菜单内添加QAction   该action在前面用设计器定义了

//        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
//    }

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
        connect(action,SIGNAL(triggered(bool)),this,SLOT(upLoad()));
        connect(action1,SIGNAL(triggered(bool)),this,SLOT(refreshLocalFileSlot()));
        connect(action2,SIGNAL(triggered(bool)),this,SLOT(newDirLocal()));
        connect(action3,&QAction::triggered,this,[=](){
            QString strName=ui->treeWidget_localfile->currentItem()->text(0);
            currentPath+="/";
            currentPath+=strName;
            deleteDirLocal(currentPath);
            currentPath=currentPath.left(currentPath.lastIndexOf('/'));
            refreshLocalFileSlot();
        });
        connect(action4,SIGNAL(triggered(bool)),this,SLOT(cdToParentLocal()));


        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
    }
}
void Widget::changeCd(){
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
void Widget::newDirFtp(){

}

void Widget::newDirLocal(){
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
            return;

        }
    }
}

bool Widget::deleteDirLocal(const QString path)

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
            if (fi.isFile())
                fi.dir().remove(fi.fileName());
            else
                deleteDirLocal(fi.absoluteFilePath());
        }
        return dir.rmpath(dir.absolutePath()) ;
    }
    else {
        QFile::remove(path);
    }
    ui->label_status->setText("删除文件");
}
void Widget::deleteFtpFile(){
    QString name=ui->treeWidget_ftp->currentItem()->text(0);
    ftp->remove((ToSpecialEncoding(name)));
    refreshFtpFile();
}

void Widget::reNameLocal(){

}

