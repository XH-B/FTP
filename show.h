#ifndef SHOW_H
#define SHOW_H

#include <QWidget>
#include"plotlines.h"
#include <QWidget>
#include<QStackedWidget>
#include<QTableWidget>
#include<QAction>
#include<QDebug>
#include<QFileDialog>
#include<QFile>
#include <QVector>
#include <QTime>




#include <QWidget>
#include <QFtp>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTreeWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QtNetwork>
#include <QFtp>
#include <QDialog>
#include <QHash>
#include <QNetworkConfigurationManager>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QProgressDialog>
#include <QFileDialog>
#include <QDir>
#include <QProcess>
#include <QFileInfo>
#include <QFileInfoList>
#include <QMenu>
#include <QDebug>
#include <QStringList>
#include<QString>
#include<QtAlgorithms>



#include <qwt_plot_layout.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include<zoomer.h>  //自己写的zoomer
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>


#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>
#include <qpen.h>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>
#include <qwt_magnifier.h>

namespace Ui {
class Show;
}

class Show : public QWidget
{
    Q_OBJECT

public:
    explicit Show(QWidget *parent = 0);
    ~Show();
    QAction *action1;
    QVector<double> channel_1;
    QVector<double> channel_2;
    QVector<double> channel_3;
    QVector<double> channel_4;
    QVector<double> channel_5;
    QVector<double> channel_6;
    QVector<double> channel[6];
    QString fileName;
    QString hz;
    QwtPlotCurve *curve[6][6];
//    QwtPlotCurve *curve;
//    QwtPlotCurve *curve2;
//    QwtPlotCurve *curve3;
//    QwtPlotCurve *curve4;
//    QwtPlotCurve *curve5;
//    QwtPlotCurve *curve6;
    QPolygonF points1,points2,points3,points4,points5,points6;
    QVector<double> x1;
    QVector<double> channel_11;
    QVector<double> channel_22;
    QVector<double> channel_33;
    QVector<double> channel_44;
    QVector<double> channel_55;
    QVector<double> channel_66;



    QVector<double> x;//x轴坐标



    int j;
    int start;
    int interval;
    int sumLine;
    double multiple;

    Zoomer *z1;//6个图的放大缩小控件
    Zoomer *z2;
    Zoomer *z3;
    Zoomer *z4;
    Zoomer *z5;
    Zoomer *z6;
    int isFilesize;//判断文件大小
    //QwtPlotZoomer m_zoomer;
   // QwtPlotPanner m_panner;

private slots:

    void showItem(const QVariant &itemToInfo,bool on);
    void readFile(const QString &fa);
    void showTimeRange();//显示时间范围
    void cancelSegmentShow();
    void segmentShow();
    void onZoomer1(const QRectF &rect);
    void onZoomer2(const QRectF &rect);
    void onZoomer3(const QRectF &rect);
    void onZoomer4(const QRectF &rect);
    void onZoomer5(const QRectF &rect);
    void onZoomer6(const QRectF &rect);

    void changeChart();
    void changeChart1();
    void changeInterval();
private:
    Ui::Show *ui;
};

#endif // SHOW_H
