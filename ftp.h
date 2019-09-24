#ifndef FTP_H
#define FTP_H

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
#include<QDirModel>
namespace Ui {
class Ftp;
}

class Ftp : public QWidget
{
    Q_OBJECT

public:
    explicit Ftp(QWidget *parent = 0);
    ~Ftp();
    QString ToSpecialEncoding(const QString &InputStr);
    QString FromSpecialEncoding(const QString &InputStr);


    QVector<QString> ftpFileName;//文件名数组：
    QVector<QString> ftpFileName1;

private slots:

    void downloadFile();
    void cancelDownload();//取消下载


    void cancelUpload();
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

    void upLoad1();
    void setIcon(QString fileName,QTreeWidgetItem *newItem);//设置图标
    void refreshFtpFileSlot();//刷新Ftp文件目录
    void refreshLocalFileSlot();
    void changeCd();
    void newDirFtp();
    void newDirLocal();
    bool deleteDirLocal(QString path);
    void deleteFtpFile();
    void reNameLocal();
    void downLoadDirFileSlot();
    void upLoadRefreshSlot();



    void on_pushButton_diconnect_clicked();

private:
    Ui::Ftp *ui;
    QHash<QString, bool> isDirectory;//判断是否为文件夹
    QString currentPath;//本地路径
    QString ftpPath;

    QFtp *ftp;//ftp服务器
    QFile *file;//文件
    QFile *file1;
    QFile *downFile;//下载文件(在本地）
    QFile *upLoadFile;//上传文件(在本地)
    QDirModel  *borwserModel;//设置问价显示的排序方式

    QNetworkSession *networkSession;//网络任务
    QNetworkConfigurationManager manager;//网络配置
    QString downloadPath;//ftp路径
    QProcess *process;



    int connectToHost;
    int login;
    int get;
    int list;
    int flag=0;//检查新建的文件夹是否存在
    void listAllFiles(const QString &downPath);
    void refreshLocalFile();//刷新local文件目录
    void refreshFtpFile();//刷新Ftp文件目录
    void ftpWriteInit(QString key, QString value);//保存密码
    void ftpReadInit(QString key, QString &value);
    int m_totalLength;//文件总长度
    int quanbu;//判断是不是文件夹
    void downLoadDirFile();
};

#endif // FTP_H
