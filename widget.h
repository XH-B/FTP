#ifndef WIDGET_H
#define WIDGET_H

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
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>


#include <qwt_legend.h>
#include <qwt_legend_label.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>
#include <qpen.h>
#include <qwt_symbol.h>
#include <qwt_picker_machine.h>
#include<qwt_magnifier.h>




#include<QFlags>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QAction *action1;
    QVector<double> channel_1;
    QVector<double> channel_2;
    QVector<double> channel_3;
    QVector<double> channel_4;
    QVector<double> channel_5;
    QVector<double> channel_6;
    QVector<double> x;
    QString fileName;
    QString hz;
    QwtPlotCurve *curve;
    QwtPlotCurve *curve2;
    QwtPlotCurve *curve3;
    QwtPlotCurve *curve4;
    QwtPlotCurve *curve5;
    QwtPlotCurve *curve6;
    QPolygonF points1,points2,points3,points4,points5,points6;
    QVector<double> x1;
    QVector<double> channel_11;
    QVector<double> channel_22;
    QVector<double> channel_33;
    QVector<double> channel_44;
    QVector<double> channel_55;
    QVector<double> channel_66;


    int j;
    double start;
    double end;
    //QwtPlotZoomer m_zoomer;
   // QwtPlotPanner m_panner;


    //*****************************************************************
    QString ToSpecialEncoding(const QString &InputStr);
    QString FromSpecialEncoding(const QString &InputStr);


    QVector<QString> ftpFileName;
























private slots:

    void showItem(const QVariant &itemToInfo,bool on);
    void readFile(const QString &fa);
    void showTimeRange();//显示时间范围
    void cancelSegmentShow();
    //**************************************************************






    void connectOrDisconnect();
    void downloadFile();
    void cancelDownload();//取消下载
    void connectToFtp();

    void ftpCommandFinished(int commandId, bool error);
    //void ftpCommandFinished1(int commandId, bool error);
    void ftpCommandStarted(int a);
    void addToList(const QUrlInfo &urlInfo);
    void processItem(QTreeWidgetItem *item, int column);
    void cdToParent();
    void cdToParentLocal();
    void updateDataTransferProgress(qint64 readBytes,
                                    qint64 totalBytes);
    void enableDownloadButton();
    void enableConnectButton();


    void showFileInfoList(QFileInfoList list); //根据获取的QFileInfoList显示本地目录
    void slotDirShowLocal(QTreeWidgetItem *item);   //由双击的文件确定新的目录
    void slotShow(QDir dir);
    void ftpRightMenu(QPoint pos);
    void localRightMenu(QPoint pos);
    void upLoad();
    void setIcon(QString fileName,QTreeWidgetItem *newItem);//设置图标
    void refreshFtpFileSlot();//刷新Ftp文件目录
    void refreshLocalFileSlot();
    void changeCd();
    void newDirFtp();
    void newDirLocal();
    bool deleteDirLocal(QString path);
    void deleteFtpFile();
    void reNameLocal();




private:
    Ui::Widget *ui;





    QHash<QString, bool> isDirectory;//判断是否为文件夹
    QString currentPath;//本地路径
    QString ftpPath;

    QFtp *ftp;//ftp服务器
    QFile *file;//文件
    QFile *file1;
    QFile *downFile;//下载文件
    QFile *upLoadFile;//上传文件

    QNetworkSession *networkSession;//网络任务
    QNetworkConfigurationManager manager;//网络配置
    QString downloadPath;//ftp路径

    int connectToHost;
    int login;
    int get;
    int list;
    void listAllFiles(const QString &downPath);
    void refreshLocalFile();//刷新local文件目录
    void refreshFtpFile();//刷新Ftp文件目录
    void ftpWriteInit(QString key, QString value);//保存密码
    void ftpReadInit(QString key, QString &value);
    int m_totalLength;//文件总长度

};

#endif // WIDGET_H
