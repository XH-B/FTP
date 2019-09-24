#include "show.h"
#include "ui_show.h"

Show::Show(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Show)
{
    ui->setupUi(this);



    //ui->spinBox_2->setSingleStep(10);//初始化时间间隔
    ui->spinBox_2->setMinimum(1);//设置时间间隔最小值为1
    ui->spinBox_2->setValue(20);





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


    QwtPlotPanner *pan1=new QwtPlotPanner(ui->qwtPlot->canvas());//中键平移
    QwtPlotPanner *pan2=new QwtPlotPanner(ui->qwtPlot_2->canvas());
    QwtPlotPanner *pan3=new QwtPlotPanner(ui->qwtPlot_3->canvas());
    QwtPlotPanner *pan4=new QwtPlotPanner(ui->qwtPlot_4->canvas());
    QwtPlotPanner *pan5=new QwtPlotPanner(ui->qwtPlot_5->canvas());
    QwtPlotPanner *pan6=new QwtPlotPanner(ui->qwtPlot_6->canvas());
    //plotLayout()->setAlignCanvasToScale(true);
    pan1->setMouseButton(Qt::MiddleButton);//中键平移
    pan2->setMouseButton(Qt::MiddleButton);
    pan3->setMouseButton(Qt::MiddleButton);
    pan4->setMouseButton(Qt::MiddleButton);
    pan5->setMouseButton(Qt::MiddleButton);
    pan6->setMouseButton(Qt::MiddleButton);


   //QwtPlotMagnifier *ma=new QwtPlotMagnifier(ui->qwtPlot->canvas());//滚轮缩放
//   QwtPlotZoomer *zoomer=  new QwtPlotZoomer(ui->qwtPlot->canvas());
//   zoomer->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
//   zoomer->setZoomBase(true);
//   pan1->setMouseButton(Qt::RightButton);

   z1= new Zoomer("0",ui->qwtPlot->canvas());//圈出矩形进行缩放，重写zoomer函数对大小进行限制
   z1->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
   z1->setZoomBase(true);
   z2= new Zoomer("0",ui->qwtPlot_2->canvas());//圈出矩形进行缩放，重写zoomer函数对大小进行限制
   z2->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
   z2->setZoomBase(true);
   z3= new Zoomer("0",ui->qwtPlot_3->canvas());//圈出矩形进行缩放，重写zoomer函数对大小进行限制
   z3->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
   z3->setZoomBase(true);
   z4= new Zoomer("0",ui->qwtPlot_4->canvas());//圈出矩形进行缩放，重写zoomer函数对大小进行限制
   z4->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
   z4->setZoomBase(true);
   z5= new Zoomer("0",ui->qwtPlot_5->canvas());//圈出矩形进行缩放，重写zoomer函数对大小进行限制
   z5->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
   z5->setZoomBase(true);
   z6= new Zoomer("0",ui->qwtPlot_6->canvas());//圈出矩形进行缩放，重写zoomer函数对大小进行限制
   z6->setMousePattern(QwtEventPattern::MouseSelect3,Qt::RightButton);
   z6->setZoomBase(true);


   connect(z1,SIGNAL(zoomed(const QRectF&)),this,SLOT(onZoomer1(const QRectF&)));
   connect(z2,SIGNAL(zoomed(const QRectF&)),this,SLOT(onZoomer2(const QRectF&)));
   connect(z3,SIGNAL(zoomed(const QRectF&)),this,SLOT(onZoomer3(const QRectF&)));
   connect(z4,SIGNAL(zoomed(const QRectF&)),this,SLOT(onZoomer4(const QRectF&)));
   connect(z5,SIGNAL(zoomed(const QRectF&)),this,SLOT(onZoomer5(const QRectF&)));
   connect(z6,SIGNAL(zoomed(const QRectF&)),this,SLOT(onZoomer6(const QRectF&)));





   //ui->qwtPlot->setAutoReplot(true);

   // qDebug()<<ma->wheelFactor();
   // qDebug()<<canvas->size();

   //qDebug()<<wheelFactor();






    //ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,"电压/V/A");
    //ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,"时间/S");
    //ui->qwtPlot->setAxisScale(QwtPlot::yLeft,26,40);


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

    connect(legend,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));//点击图例显示曲线
    connect(legend2,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));//点击图例显示曲线
    connect(legend3,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));//点击图例显示曲线
    connect(legend4,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));//点击图例显示曲线
    connect(legend5,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));//点击图例显示曲线
    connect(legend6,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));//点击图例显示曲线



    for(int i=0;i<6;i++)//创建各个通道图的曲线
        for(int j=0;j<6;j++){
            if(j==0){
                curve[i][j] = new QwtPlotCurve();
                curve[i][j]->setTitle("通道一");
                curve[i][j]->setPen(Qt::blue,2);
                curve[i][j]->setRenderHint(QwtPlotItem::RenderAntialiased,true);
                curve[i][j]->setLegendAttribute(curve[i][j]->LegendShowLine);
            }
            else if(j==1){
                curve[i][j] = new QwtPlotCurve();
                curve[i][j]->setTitle("通道二");
                curve[i][j]->setPen(Qt::red,2);
                curve[i][j]->setRenderHint(QwtPlotItem::RenderAntialiased,true);
                curve[i][j]->setLegendAttribute(curve[i][j]->LegendShowLine);
            }
            else if(j==2){
                curve[i][j] = new QwtPlotCurve();
                curve[i][j]->setTitle("通道三");
                curve[i][j]->setPen(Qt::black,2);
                curve[i][j]->setRenderHint(QwtPlotItem::RenderAntialiased,true);
                curve[i][j]->setLegendAttribute(curve[i][j]->LegendShowLine);
            }
            else if(j==3){
                curve[i][j] = new QwtPlotCurve();
                curve[i][j]->setTitle("通道四");
                curve[i][j]->setPen(Qt::green,2);
                curve[i][j]->setRenderHint(QwtPlotItem::RenderAntialiased,true);
                curve[i][j]->setLegendAttribute(curve[i][j]->LegendShowLine);
            }
            else if(j==4){
                curve[i][j] = new QwtPlotCurve();
                curve[i][j]->setTitle("通道五");
                curve[i][j]->setPen(Qt::darkYellow,2,Qt::DotLine);
                curve[i][j]->setRenderHint(QwtPlotItem::RenderAntialiased,true);
                curve[i][j]->setLegendAttribute(curve[i][j]->LegendShowLine);
            }
            else if(j==5){
                curve[i][j] = new QwtPlotCurve();
                curve[i][j]->setTitle("通道六");
                curve[i][j]->setPen(Qt::magenta,2,Qt::DotLine);
                curve[i][j]->setRenderHint(QwtPlotItem::RenderAntialiased,true);
                curve[i][j]->setLegendAttribute(curve[i][j]->LegendShowLine);
            }
        }

    for(int i=0;i<6;i++){//把曲线附在通道图上
            curve[0][i]->attach(ui->qwtPlot);
            curve[1][i]->attach(ui->qwtPlot_2);
            curve[2][i]->attach(ui->qwtPlot_3);
            curve[3][i]->attach(ui->qwtPlot_4);
            curve[4][i]->attach(ui->qwtPlot_5);
            curve[5][i]->attach(ui->qwtPlot_6);
    }

    QwtPlotItemList items=ui->qwtPlot->itemList(QwtPlotItem::Rtti_PlotCurve);//设置图例可点击
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
    QwtPlotItemList items2=ui->qwtPlot_2->itemList(QwtPlotItem::Rtti_PlotCurve);//设置图例可点击
    for(int i=0;i<items2.size();i++){
        if(i==1){
            const QVariant itemInfo=ui->qwtPlot_2->itemToInfo(items2[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend2->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items2[i]->setVisible(true);
        }
        else {
            items2[i]->setVisible(false);

        }
    }
    QwtPlotItemList items3=ui->qwtPlot_3->itemList(QwtPlotItem::Rtti_PlotCurve);//设置图例可点击
    for(int i=0;i<items3.size();i++){
        if(i==2){
            const QVariant itemInfo=ui->qwtPlot_3->itemToInfo(items3[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend3->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items3[i]->setVisible(true);
        }
        else {
            items3[i]->setVisible(false);

        }
    }
    QwtPlotItemList items4=ui->qwtPlot_4->itemList(QwtPlotItem::Rtti_PlotCurve);//设置图例可点击
    for(int i=0;i<items4.size();i++){
        if(i==3){
            const QVariant itemInfo=ui->qwtPlot_4->itemToInfo(items4[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend4->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items4[i]->setVisible(true);
        }
        else {
            items4[i]->setVisible(false);

        }
    }
    QwtPlotItemList items5=ui->qwtPlot_5->itemList(QwtPlotItem::Rtti_PlotCurve);//设置图例可点击
    for(int i=0;i<items5.size();i++){
        if(i==4){
            const QVariant itemInfo=ui->qwtPlot_5->itemToInfo(items5[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend5->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items5[i]->setVisible(true);
        }
        else {
            items5[i]->setVisible(false);

        }
    }
    QwtPlotItemList items6=ui->qwtPlot_6->itemList(QwtPlotItem::Rtti_PlotCurve);//设置图例可点击
    for(int i=0;i<items6.size();i++){
        if(i==5){
            const QVariant itemInfo=ui->qwtPlot_6->itemToInfo(items6[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend6->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items6[i]->setVisible(true);
        }
        else {
            items6[i]->setVisible(false);
        }
    }

    //ui->qwtPlot->resize(300,300);
    //ui->qwtPlot->setAutoReplot(true);


    connect(ui->pushButton_openfile,&QPushButton::clicked,this,[=](){//打开文件并显示
        fileName=QFileDialog::getOpenFileName(this,"打开文件","D:/1");
        if(fileName!=NULL){
            //hz=fileName.split(",").at(1);//频率
        }
        else{//未选中
            return;
        }
        qDebug()<<fileName;


        //fileName ="D:/1/2019050909,100Hz.txt";
        //fileName ="D:/1/2019051118,1000Hz.txt";

        readFile(fileName);

        start=ui->spinBox->value();
        interval=ui->spinBox_2->value();


        multiple=0.00;
        if(hz=="100Hz.txt"){
            multiple=100.00;
            qDebug()<<"100";

        }else if(hz=="200Hz.txt"){
            multiple=200.00;

        }
        else if(hz=="500Hz.txt"){
            multiple=500.00;

        }
        else if(hz=="1000Hz.txt"){
            multiple=1000.00;
            qDebug()<<"1000";

        }





        x.clear();//每次清空

        for(int k=0;k<interval*multiple;k++){
            x.append(k/multiple);
        }
        qDebug()<<"x.size"<<x.size();
        for(int i=0;i<6;i++){//初始化显示数据
            for(int j=0;j<6;j++){
                curve[i][j]->setSamples(x,channel[j].mid(0,interval*multiple));


                //ui->qwtPlot->setAxisScale(QwtPlot::yLeft,29,30.6,0.4);
                //ui->qwtPlot->setAxisMaxMajor(QwtPlot::yLeft,4);
                //ui->qwtPlot->setAxisAutoScale(QwtPlot::yLeft,false);

               // ui->qwtPlot->setAxisScaleDiv(QwtPlot::yLeft,scale);
                //ui->qwtPlot->setAxisScaleDiv(1,1);


            }

        }



        showTimeRange();
        ui->spinBox->setMaximum(sumLine/multiple-interval);
        ui->spinBox_2->setMaximum(sumLine/multiple);
        //ui->spinBox_2->setMaximum(x[x.size()-1]);
    });


    //qDebug()<<start<<end;


    ui->progressBar_readfile->setValue(0);

    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(changeChart1()));//开始位置改变
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(changeInterval()));






    //ui->qwtPlot->hide();
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

}

Show::~Show()
{
    delete ui;
}
void Show::changeInterval(){

    start=ui->spinBox->value();
    interval=ui->spinBox_2->value();

    ui->spinBox->setMaximum(sumLine/multiple-interval);


    x.clear();
    for(int k=0;k<interval*multiple;k++){
        x.append(k/multiple);
    }



    for(int k=0;k<interval*multiple;k++){
        x[k]+=start;
    }
    if((start+interval)<=sumLine/multiple){
        for(int i=0;i<6;i++){//初始化显示数据
            for(int j=0;j<6;j++){
                curve[i][j]->setSamples(x,channel[j].mid(start*multiple,interval*multiple));

                ui->qwtPlot->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_2->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_3->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_4->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_5->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_6->setAxisScale(QwtPlot::xBottom,start,start+interval);

            }
        }
    }
    else{
        return;
    }
    for(int k=0;k<interval*multiple;k++){
        x[k]-=start;
    }




}

void Show::changeChart(){

    start=ui->spinBox->value();
    interval=ui->spinBox_2->value();


    if((start+interval)<=x.size()/multiple){
        for(int i=0;i<6;i++){//初始化显示数据
            for(int j=0;j<6;j++){
                curve[i][j]->setSamples(x.mid(start*100,interval*100),channel[j].mid(start*100,interval*100));

                ui->qwtPlot->setAxisScale(QwtPlot::xBottom,start,start+interval);
            }
        }
    }
    else{
        //ui->spinBox->setEnabled(false);
        //ui->spinBox->
        for(int i=0;i<6;i++){//初始化显示数据
            for(int j=0;j<6;j++){
                curve[i][j]->setSamples(x.mid(start*100,x.size()-start*100),channel[j].mid(start*100,x.size()-start*100));

                ui->qwtPlot->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_2->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_3->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_4->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_5->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_6->setAxisScale(QwtPlot::xBottom,start,start+interval);

            }
        }

    }

}
void Show::changeChart1(){

    start=ui->spinBox->value();
    interval=ui->spinBox_2->value();

    ui->spinBox_2->setMaximum(sumLine/multiple-start);


    for(int k=0;k<interval*multiple;k++){
        x[k]+=start;
    }
//    qDebug()<<"start"<<start;
//    qDebug()<<"interval"<<interval;
//    qDebug()<<"x"<<x.size();
//    qDebug()<<"channel"<<channel[0].size();
    if((start+interval)<=sumLine/multiple){
        for(int i=0;i<6;i++){//初始化显示数据
            for(int j=0;j<6;j++){



                curve[i][j]->setSamples(x,channel[j].mid(start*multiple,interval*multiple));

                ui->qwtPlot->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_2->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_3->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_4->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_5->setAxisScale(QwtPlot::xBottom,start,start+interval);
                ui->qwtPlot_6->setAxisScale(QwtPlot::xBottom,start,start+interval);

            }
        }
    }
    else{
        return;
    }
    for(int k=0;k<interval*multiple;k++){
        x[k]-=start;
    }

}


void Show::readFile(const QString &fa)
{
    isFilesize=0;//初始化是否为大文件
    qDebug()<<"1";

    ui->spinBox->setValue(0);
    QString rename;
    sumLine=0;
    rename=fa;

    while(1){//判断读入的文件是否正确
        QFile fileRead(rename);
        if (!fileRead.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug()<<"Can't open the file!";
            return;
        }

        QByteArray line = fileRead.readLine();//读取一行
        QString str(line);
        qDebug()<<str;
        if(str!="TimeStamp Data1 Data2 Data3 Data4 Data5 Data6\n"){
            QMessageBox::information(this,tr("文件错误"),tr("不是该类型文件，重新选择文件"));
            rename=QFileDialog::getOpenFileName(this,"打开文件",".");
        }
        else{
            fileRead.close();
            break;
        }

    }


    QFile file2(rename);
    hz=rename.split(",").at(1);//频率

    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!";
        return;
    }

    while (!file2.atEnd())//计算该文件的行数
    {
        QByteArray line = file2.readLine();//读取一行
        sumLine++;
    }
    qDebug()<<sumLine;
    file2.close();



    if(sumLine>10000)//判断文件大小 如果文件行数大于1000行则除以1000处理  否则正常处理
        ui->progressBar_readfile->setRange(0,sumLine/10000);
    else
        ui->progressBar_readfile->setRange(0,sumLine);


    if(sumLine>=100000&&sumLine<1000000){
        isFilesize=1;//文件过大，简化数据 除以10
    }
    else if(sumLine>=1000000&&sumLine<10000000){
        isFilesize=2;//除以100
    }
    else if(sumLine>=10000000&&sumLine<100000000){
        isFilesize=3;//除以1000
    }


    int i=0;
    int flag = 0;
    for(int m=0;m<6;m++){
        channel[m].clear();
    }
    x.clear();

    QFile file1(rename);



    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!";
        return;
    }else{
        QByteArray line;
        QString str;
        QStringList strList;
        int sum=1;
        line = file1.readLine();//第一行不读入

        while(!file1.atEnd()){
            line=file1.readLine();
            str=line.data();
            strList=str.split(" ");
            for(int k=0;k<6;k++){
                channel[k].append(strList.at(k+1).toInt()/100.00);
            }
            sum++;
            if(sumLine>10000){//判断文件大小
                if(sum%10000==0){//文件过大
                    ui->progressBar_readfile->setValue(sum/10000);
                }
            }
            else {
                ui->progressBar_readfile->setValue(sum);
            }


        }
        qDebug()<<"sum"<<sum;
        qDebug()<<"数据读取完成 ";
        qDebug()<<sumLine;
        qDebug()<<channel[1][3000];


//        while (!file1.atEnd())
//        {
//            QByteArray line = file1.readLine();//读取一行
//            if(isFilesize==1){//大文件 简化处理
//                if(flag&&(sum%10==0)){//隔10行读一次
//                    QString str(line);
//                    QStringList strList =  str.split(" ");
//                    QStringList t = strList.at(0).split(":");
//                    // timeSt.append( QTime(0,t.at(0).toInt(),t.at(1).toInt(),t.at(2).toInt()));

//                    for(int k=0;k<6;k++){
//                        channel[k].append(strList.at(k+1).toInt()/100.00);
//                    }
//                    if(hz == "100Hz.txt")
//                        x.append(i++/100.00);
//                    else
//                        x.append(i++/1000.00);
//                }
//                flag = 1;
//                sum++;
//                if(sumLine>10000){//判断文件大小
//                    if(sum%10000==0){//文件过大
//                        ui->progressBar_readfile->setValue(sum/10000);
//                    }
//                }
//                else {
//                    ui->progressBar_readfile->setValue(sum);
//                }


//            }
//            else if(isFilesize==2){//大文件 简化处理
//                if(flag&&(sum%100==0)){//隔100行读一次
//                    QString str(line);
//                    QStringList strList =  str.split(" ");
//                    QStringList t = strList.at(0).split(":");
//                    // timeSt.append( QTime(0,t.at(0).toInt(),t.at(1).toInt(),t.at(2).toInt()));
//                    channel_1.append(strList.at(1).toInt()/100.00);
//                    //qDebug()<<strList.at(1).toInt()/100.00;

//                    channel_2.append(strList.at(2).toInt()/100.00);
//                    channel_3.append(strList.at(3).toInt()/100.00);
//                    channel_4.append(strList.at(4).toInt()/100.00);
//                    channel_5.append(strList.at(5).toInt()/100.00);
//                    channel_6.append(strList.at(6).toInt()/100.00);
//                    if(hz == "100Hz.txt")
//                        x.append(i++/100.00*100);
//                    else
//                        x.append(i++/1000.00*100);
//                }
//                flag = 1;
//                sum++;
//                if(sumLine>10000){//判断文件大小
//                    if(sum%10000==0){//文件过大
//                        ui->progressBar_readfile->setValue(sum/10000);
//                    }
//                }
//                else {
//                    ui->progressBar_readfile->setValue(sum);
//                }
//            }
//            else{
//                if(flag){//flag作用：第一行不读入
//                    QString str(line);
//                    QStringList strList =  str.split(" ");
//                    QStringList t = strList.at(0).split(":");
//                    // timeSt.append( QTime(0,t.at(0).toInt(),t.at(1).toInt(),t.at(2).toInt()));
//                    channel_1.append(strList.at(1).toInt()/100.00);
//                    //qDebug()<<strList.at(1).toInt()/100.00;

//                    channel_2.append(strList.at(2).toInt()/100.00);
//                    channel_3.append(strList.at(3).toInt()/100.00);
//                    channel_4.append(strList.at(4).toInt()/100.00);
//                    channel_5.append(strList.at(5).toInt()/100.00);
//                    channel_6.append(strList.at(6).toInt()/100.00);


//                    qDebug()<<"k";

//                    for(int k=0;k<6;k++){
//                        channel[k].append(strList.at(k+1).toInt()/100.00);
//                    }
//                    if(hz == "100Hz.txt")
//                        x.append(i++/100.00);
//                    else
//                        x.append(i++/1000.00);
//                }


//                flag = 1;
//                sum++;
//                if(sumLine>10000){//判断文件大小
//                    if(sum%10000==0){//文件过大
//                        ui->progressBar_readfile->setValue(sum/10000);
//                    }
//                }
//                else {
//                    ui->progressBar_readfile->setValue(sum);
//                }
//            }


//        }
//        file1.close();
//        qDebug()<<"文件读取成功";

    }
}

void Show::showItem(const QVariant &itemInfo, bool on){
    QwtPlotItem *plotItem=ui->qwtPlot->infoToItem(itemInfo);
    qDebug()<<on;
    if(plotItem){
        plotItem->setVisible(on);
    }
}
void Show::showTimeRange()//显示时间范围
{
    QString time="0";
    time+="：";
    double end=sumLine/multiple;
    qDebug()<<end;
    QString str=QString::number(end,10,2);;//QString::number(a,基底，精度)
    time+=str;
    ui->label_timerange->setText(time);

}
void Show::segmentShow(){
    j=0;
    channel_11.clear();
    channel_22.clear();
    channel_33.clear();
    channel_44.clear();
    channel_55.clear();
    channel_66.clear();
    x1.clear();
    start=ui->spinBox->text().toDouble();//开始时间
    //end=ui->spinBox_2->text().toDouble();//结束时间

//    for(int i=0;i<x.size();i++){
//        if(x[i]>=start&&x[i]<=end){
//            x1.append(x[i]);
//            channel_11.append(channel_1[i]);
//            channel_22.append(channel_2[i]);
//            channel_33.append(channel_3[i]);
//            channel_44.append(channel_4[i]);
//            channel_55.append(channel_5[i]);
//            channel_66.append(channel_6[i]);

//        }
//    }


   // ui->qwtPlot->setAxisScale(QwtPlot::xBottom,x1[0],x1[x1.size()-1]);

    for(int i=0;i<6;i++){//打开文件直接显示通道图
        curve[0][0]->setSamples(x1.mid(0,20),channel_11.mid(0,20));
        curve[0][1]->setSamples(x1.mid(0,20),channel_22.mid(0,20));
        curve[0][2]->setSamples(x1.mid(0,20),channel_33.mid(0,20));
        curve[0][3]->setSamples(x1.mid(0,20),channel_44.mid(0,20));
        curve[0][4]->setSamples(x1.mid(0,20),channel_55.mid(0,20));
        curve[0][5]->setSamples(x1.mid(0,20),channel_66.mid(0,20));
        curve[1][0]->setSamples(x1.mid(0,20),channel_11.mid(0,20));
        curve[1][1]->setSamples(x1.mid(0,20),channel_22.mid(0,20));
        curve[1][2]->setSamples(x1.mid(0,20),channel_33.mid(0,20));
        curve[1][3]->setSamples(x1.mid(0,20),channel_44.mid(0,20));
        curve[1][4]->setSamples(x1.mid(0,20),channel_55.mid(0,20));
        curve[1][5]->setSamples(x1.mid(0,20),channel_66.mid(0,20));
        curve[2][0]->setSamples(x1.mid(0,20),channel_11.mid(0,20));
        curve[2][1]->setSamples(x1.mid(0,20),channel_22.mid(0,20));
        curve[2][2]->setSamples(x1.mid(0,20),channel_33.mid(0,20));
        curve[2][3]->setSamples(x1.mid(0,20),channel_44.mid(0,20));
        curve[2][4]->setSamples(x1.mid(0,20),channel_55.mid(0,20));
        curve[2][5]->setSamples(x1.mid(0,20),channel_66.mid(0,20));
        curve[3][0]->setSamples(x1.mid(0,20),channel_11.mid(0,20));
        curve[3][1]->setSamples(x1.mid(0,20),channel_22.mid(0,20));
        curve[3][2]->setSamples(x1.mid(0,20),channel_33.mid(0,20));
        curve[3][3]->setSamples(x1.mid(0,20),channel_44.mid(0,20));
        curve[3][4]->setSamples(x1.mid(0,20),channel_55.mid(0,20));
        curve[3][5]->setSamples(x1.mid(0,20),channel_66.mid(0,20));
        curve[4][0]->setSamples(x1.mid(0,20),channel_11.mid(0,20));
        curve[4][1]->setSamples(x1.mid(0,20),channel_22.mid(0,20));
        curve[4][2]->setSamples(x1.mid(0,20),channel_33.mid(0,20));
        curve[4][3]->setSamples(x1.mid(0,20),channel_44.mid(0,20));
        curve[4][4]->setSamples(x1.mid(0,20),channel_55.mid(0,20));
        curve[4][5]->setSamples(x1.mid(0,20),channel_66.mid(0,20));
        curve[5][0]->setSamples(x1.mid(0,20),channel_11.mid(0,20));
        curve[5][1]->setSamples(x1.mid(0,20),channel_22.mid(0,20));
        curve[5][2]->setSamples(x1.mid(0,20),channel_33.mid(0,20));
        curve[5][3]->setSamples(x1.mid(0,20),channel_44.mid(0,20));
        curve[5][4]->setSamples(x1.mid(0,20),channel_55.mid(0,20));
        curve[5][5]->setSamples(x1.mid(0,20),channel_66.mid(0,20));
    }
    ui->qwtPlot->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot->setAxisMaxMinor(QwtPlot::yLeft,5);
    ui->qwtPlot->setAxisAutoScale(QwtPlot::xBottom);
    ui->qwtPlot->replot();


}

void Show::cancelSegmentShow(){

    for(int i=0;i<6;i++){//打开文件直接显示通道图
        curve[0][0]->setSamples(x.mid(0,20),channel_1.mid(0,20));
        curve[0][1]->setSamples(x.mid(0,20),channel_2.mid(0,20));
        curve[0][2]->setSamples(x.mid(0,20),channel_3.mid(0,20));
        curve[0][3]->setSamples(x.mid(0,20),channel_4.mid(0,20));
        curve[0][4]->setSamples(x.mid(0,20),channel_5.mid(0,20));
        curve[0][5]->setSamples(x.mid(0,20),channel_6.mid(0,20));
        curve[1][0]->setSamples(x,channel_1);
        curve[1][1]->setSamples(x,channel_2);
        curve[1][2]->setSamples(x,channel_3);
        curve[1][3]->setSamples(x,channel_4);
        curve[1][4]->setSamples(x,channel_5);
        curve[1][5]->setSamples(x,channel_6);
        curve[2][0]->setSamples(x,channel_1);
        curve[2][1]->setSamples(x,channel_2);
        curve[2][2]->setSamples(x,channel_3);
        curve[2][3]->setSamples(x,channel_4);
        curve[2][4]->setSamples(x,channel_5);
        curve[2][5]->setSamples(x,channel_6);
        curve[3][0]->setSamples(x,channel_1);//打开文件直接显示一个通道图
        curve[3][1]->setSamples(x,channel_2);
        curve[3][2]->setSamples(x,channel_3);
        curve[3][3]->setSamples(x,channel_4);
        curve[3][4]->setSamples(x,channel_5);
        curve[3][5]->setSamples(x,channel_6);
        curve[4][0]->setSamples(x,channel_1);//打开文件直接显示一个通道图
        curve[4][1]->setSamples(x,channel_2);
        curve[4][2]->setSamples(x,channel_3);
        curve[4][3]->setSamples(x,channel_4);
        curve[4][4]->setSamples(x,channel_5);
        curve[4][5]->setSamples(x,channel_6);
        curve[5][0]->setSamples(x,channel_1);//打开文件直接显示一个通道图
        curve[5][1]->setSamples(x,channel_2);
        curve[5][2]->setSamples(x,channel_3);
        curve[5][3]->setSamples(x,channel_4);
        curve[5][4]->setSamples(x,channel_5);
        curve[5][5]->setSamples(x,channel_6);

    }
//        curve->setSamples(x,channel_1);
//        curve2->setSamples(x,channel_2);
//        curve3->setSamples(x,channel_3);
//        curve4->setSamples(x,channel_4);
//        curve5->setSamples(x,channel_5);
//        curve6->setSamples(x,channel_6);
    ui->qwtPlot->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot->replot();
    ui->qwtPlot_2->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot_2->replot();
    ui->qwtPlot_3->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot_3->replot();
    ui->qwtPlot_4->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot_4->replot();
    ui->qwtPlot_5->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot_5->replot();
    ui->qwtPlot_6->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
    ui->qwtPlot_6->replot();








}
void Show::onZoomer1(const QRectF &rect )//第num通道,右键还原图像
{
    if(z1->zoomRectIndex()==0){

        ui->qwtPlot->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小

            ui->qwtPlot->setAxisScale(QwtPlot::xBottom,start,start+interval);
    }
}
void Show::onZoomer2(const QRectF &rect )//第num通道,右键还原图像
{
    if(z2->zoomRectIndex()==0){

        ui->qwtPlot_2->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
        ui->qwtPlot_2->setAxisScale(QwtPlot::xBottom,start,start+interval);
    }
}
void Show::onZoomer3(const QRectF &rect )//第num通道,右键还原图像
{
    if(z3->zoomRectIndex()==0){

        ui->qwtPlot_3->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
            ui->qwtPlot_3->setAxisScale(QwtPlot::xBottom,start,start+interval);
;
    }
}
void Show::onZoomer4(const QRectF &rect )//第num通道,右键还原图像
{
    if(z4->zoomRectIndex()==0){

        ui->qwtPlot_4->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
            ui->qwtPlot_4->setAxisScale(QwtPlot::xBottom,start,start+interval);

    }
}
void Show::onZoomer5(const QRectF &rect )//第num通道,右键还原图像
{
    if(z5->zoomRectIndex()==0){

        ui->qwtPlot_5->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
            ui->qwtPlot_5->setAxisScale(QwtPlot::xBottom,start,start+interval);

    }
}
void Show::onZoomer6(const QRectF &rect )//第num通道,右键还原图像
{
    if(z6->zoomRectIndex()==0){

        ui->qwtPlot_6->setAxisAutoScale(QwtPlot::yLeft);//自动根据数据来设置坐标轴大小
            ui->qwtPlot_6->setAxisScale(QwtPlot::xBottom,start,start+interval);

    }
}


