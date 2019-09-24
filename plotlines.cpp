#include "plotlines.h"

PlotLines::PlotLines(QWidget *parent) : QwtPlot(parent)

{

    setTitle("chart");
    QwtPlotCanvas *canvas=new QwtPlotCanvas();
    canvas->setPalette(Qt::white);
    canvas->setBorderRadius(10);
    setCanvas(canvas);
    //plotLayout()->setAlignCanvasToScale(true);


    setAxisTitle(QwtPlot::yLeft,"ylabel");
    setAxisTitle(QwtPlot::xBottom,"xlabel");
    setAxisScale(QwtPlot::yLeft,0,10);
    setAxisScale(QwtPlot::xBottom,0,10);


    QwtPlotGrid *grid=new QwtPlotGrid;
    grid->enableX(true);
    grid->enableY(true);
    grid->setMajorPen(Qt::black,0,Qt::DotLine);
    grid->attach(this);

    QPolygonF points1,points2;
    points1<<QPoint(1,1)<<QPoint(2,2)<<QPoint(4,3)<<QPoint(6,4)<<QPoint(4,5);
    points2<<QPoint(1,2)<<QPoint(2,3)<<QPoint(3,4)<<QPoint(4,5)<<QPoint(5,6);


    QwtPlotCurve *curve= new QwtPlotCurve("curve");
    curve->setPen(Qt::blue ,2);
    curve->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    QwtSymbol *symbool=new QwtSymbol(QwtSymbol::Ellipse,QBrush(Qt::yellow),QPen(Qt::red,2),QSize(6,6));
    curve->setSymbol(symbool);
    curve->setSamples(points1);
    curve->attach(this);
    curve->setLegendAttribute(curve->LegendShowLine);


    QwtPlotCurve *curve2= new QwtPlotCurve("curve2");
    curve2->setSamples(points2);
    curve2->attach(this);
    curve2->setLegendAttribute(curve->LegendShowLine);


    QwtLegend *legend=new QwtLegend;
    legend->setDefaultItemMode(QwtLegendData::Checkable);
    insertLegend(legend,QwtPlot::RightLegend);
    connect(legend,SIGNAL(checked(QVariant,bool,int)),SLOT(showItem(QVariant,bool)));


    QwtPlotItemList items=itemList(QwtPlotItem::Rtti_PlotCurve);
    for(int i=0;i<items.size();i++){
        if(i==0){
            const QVariant itemInfo=itemToInfo(items[i]);
            QwtLegendLabel *legendLabel=qobject_cast<QwtLegendLabel*>(legend->legendWidget(itemInfo));
            if(legendLabel){
                legendLabel->setChecked(true);

            }
            items[i]->setVisible(true);
        }
        else{
            items[i]->setVisible(false);

        }
    }
    this->resize(600,400);
    this->replot();
    setAutoReplot(true);







}

void PlotLines::showItem(const QVariant &itemInfo,bool on){
    QwtPlotItem *plotItem=infoToItem(itemInfo);
    if(plotItem){
        plotItem->setVisible(on);
    }
}
