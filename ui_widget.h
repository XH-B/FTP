/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tabWidget_FTP;
    QGridLayout *gridLayout_11;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_connect;
    QWidget *widget_5;
    QGridLayout *gridLayout_8;
    QWidget *widget_9;
    QGridLayout *gridLayout_4;
    QWidget *widget_11;
    QGridLayout *gridLayout_3;
    QTreeWidget *treeWidget_ftp;
    QWidget *widget_7;
    QGridLayout *gridLayout_5;
    QTreeWidget *treeWidget_localfile;
    QWidget *widget_10;
    QGridLayout *gridLayout_10;
    QLabel *label_4;
    QProgressBar *progressBar;
    QPushButton *pushButton_canceldownload;
    QWidget *widget_8;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *comboBox;
    QLabel *label_status;
    QWidget *tabWidget_SHOW;
    QGridLayout *gridLayout_23;
    QWidget *widget_13;
    QGridLayout *gridLayout_15;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_14;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QwtPlot *qwtPlot;
    QWidget *widget_15;
    QGridLayout *gridLayout_16;
    QwtPlot *qwtPlot_2;
    QWidget *widget_16;
    QGridLayout *gridLayout_17;
    QwtPlot *qwtPlot_3;
    QWidget *widget_17;
    QGridLayout *gridLayout_18;
    QwtPlot *qwtPlot_4;
    QWidget *widget_18;
    QGridLayout *gridLayout_19;
    QwtPlot *qwtPlot_5;
    QWidget *widget_19;
    QGridLayout *gridLayout_20;
    QwtPlot *qwtPlot_6;
    QWidget *widget_20;
    QGridLayout *gridLayout_22;
    QWidget *widget_14;
    QGridLayout *gridLayout_12;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QWidget *widget_2;
    QGridLayout *gridLayout_21;
    QPushButton *pushButton_openfile;
    QProgressBar *progressBar_readfile;
    QWidget *widget_12;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_timerange;
    QWidget *widget_3;
    QGridLayout *gridLayout_13;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton_queding;
    QPushButton *pushButton_cancelsegshow;
    QWidget *tab_IP;
    QWidget *tab_k;
    QWidget *tab_translate;
    QWidget *tab;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1171, 676);
        Widget->setAutoFillBackground(true);
        gridLayout_9 = new QGridLayout(Widget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setMouseTracking(true);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget_FTP = new QWidget();
        tabWidget_FTP->setObjectName(QStringLiteral("tabWidget_FTP"));
        gridLayout_11 = new QGridLayout(tabWidget_FTP);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        widget_6 = new QWidget(tabWidget_FTP);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_6->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_connect = new QPushButton(widget_6);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_6->addWidget(pushButton_connect, 0, 2, 1, 1);


        gridLayout_11->addWidget(widget_6, 0, 0, 1, 2);

        widget_5 = new QWidget(tabWidget_FTP);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_8 = new QGridLayout(widget_5);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        gridLayout_4 = new QGridLayout(widget_9);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);

        gridLayout_8->addWidget(widget_9, 0, 0, 1, 1);

        widget_11 = new QWidget(widget_5);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        gridLayout_3 = new QGridLayout(widget_11);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);

        gridLayout_8->addWidget(widget_11, 2, 0, 1, 1);

        treeWidget_ftp = new QTreeWidget(widget_5);
        treeWidget_ftp->setObjectName(QStringLiteral("treeWidget_ftp"));
        treeWidget_ftp->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        treeWidget_ftp->setAutoScrollMargin(16);

        gridLayout_8->addWidget(treeWidget_ftp, 1, 0, 1, 1);


        gridLayout_11->addWidget(widget_5, 1, 0, 1, 1);

        widget_7 = new QWidget(tabWidget_FTP);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        gridLayout_5 = new QGridLayout(widget_7);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        treeWidget_localfile = new QTreeWidget(widget_7);
        treeWidget_localfile->setObjectName(QStringLiteral("treeWidget_localfile"));
        treeWidget_localfile->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(treeWidget_localfile, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_7, 1, 1, 1, 1);

        widget_10 = new QWidget(tabWidget_FTP);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        gridLayout_10 = new QGridLayout(widget_10);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget_10);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_10->addWidget(label_4, 0, 0, 1, 1);

        progressBar = new QProgressBar(widget_10);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        progressBar->setValue(24);

        gridLayout_10->addWidget(progressBar, 0, 1, 1, 1);

        pushButton_canceldownload = new QPushButton(widget_10);
        pushButton_canceldownload->setObjectName(QStringLiteral("pushButton_canceldownload"));
        pushButton_canceldownload->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_10->addWidget(pushButton_canceldownload, 0, 2, 1, 1);


        gridLayout_11->addWidget(widget_10, 2, 0, 1, 1);

        widget_8 = new QWidget(tabWidget_FTP);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        gridLayout_7 = new QGridLayout(widget_8);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        comboBox = new QComboBox(widget_8);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/c.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/d.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon1, QString());
        comboBox->addItem(icon1, QString());
        comboBox->addItem(icon1, QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(67, 0));
        comboBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_7->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout_11->addWidget(widget_8, 2, 1, 1, 1);

        label_status = new QLabel(tabWidget_FTP);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setStyleSheet(QStringLiteral("font: 9pt \"Agency FB\";"));

        gridLayout_11->addWidget(label_status, 3, 0, 1, 1);

        tabWidget->addTab(tabWidget_FTP, QString());
        tabWidget_SHOW = new QWidget();
        tabWidget_SHOW->setObjectName(QStringLiteral("tabWidget_SHOW"));
        gridLayout_23 = new QGridLayout(tabWidget_SHOW);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        widget_13 = new QWidget(tabWidget_SHOW);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        gridLayout_15 = new QGridLayout(widget_13);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        scrollArea = new QScrollArea(widget_13);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 936, 1956));
        gridLayout_14 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        qwtPlot = new QwtPlot(widget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setMinimumSize(QSize(550, 300));
        qwtPlot->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        qwtPlot->setProperty("canvasBackground", QVariant(brush));
        qwtPlot->setProperty("autoReplot", QVariant(true));

        gridLayout_2->addWidget(qwtPlot, 0, 2, 1, 1);


        gridLayout_14->addWidget(widget, 0, 0, 1, 1);

        widget_15 = new QWidget(scrollAreaWidgetContents);
        widget_15->setObjectName(QStringLiteral("widget_15"));
        sizePolicy.setHeightForWidth(widget_15->sizePolicy().hasHeightForWidth());
        widget_15->setSizePolicy(sizePolicy);
        gridLayout_16 = new QGridLayout(widget_15);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        qwtPlot_2 = new QwtPlot(widget_15);
        qwtPlot_2->setObjectName(QStringLiteral("qwtPlot_2"));
        qwtPlot_2->setMinimumSize(QSize(550, 300));
        qwtPlot_2->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_2->setProperty("autoReplot", QVariant(true));

        gridLayout_16->addWidget(qwtPlot_2, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_15, 1, 0, 1, 1);

        widget_16 = new QWidget(scrollAreaWidgetContents);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        sizePolicy.setHeightForWidth(widget_16->sizePolicy().hasHeightForWidth());
        widget_16->setSizePolicy(sizePolicy);
        gridLayout_17 = new QGridLayout(widget_16);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        qwtPlot_3 = new QwtPlot(widget_16);
        qwtPlot_3->setObjectName(QStringLiteral("qwtPlot_3"));
        qwtPlot_3->setMinimumSize(QSize(550, 300));
        qwtPlot_3->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_3->setProperty("autoReplot", QVariant(true));

        gridLayout_17->addWidget(qwtPlot_3, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_16, 2, 0, 1, 1);

        widget_17 = new QWidget(scrollAreaWidgetContents);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        sizePolicy.setHeightForWidth(widget_17->sizePolicy().hasHeightForWidth());
        widget_17->setSizePolicy(sizePolicy);
        gridLayout_18 = new QGridLayout(widget_17);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        qwtPlot_4 = new QwtPlot(widget_17);
        qwtPlot_4->setObjectName(QStringLiteral("qwtPlot_4"));
        qwtPlot_4->setMinimumSize(QSize(550, 300));
        qwtPlot_4->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_4->setProperty("autoReplot", QVariant(true));

        gridLayout_18->addWidget(qwtPlot_4, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_17, 3, 0, 1, 1);

        widget_18 = new QWidget(scrollAreaWidgetContents);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        sizePolicy.setHeightForWidth(widget_18->sizePolicy().hasHeightForWidth());
        widget_18->setSizePolicy(sizePolicy);
        gridLayout_19 = new QGridLayout(widget_18);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        qwtPlot_5 = new QwtPlot(widget_18);
        qwtPlot_5->setObjectName(QStringLiteral("qwtPlot_5"));
        qwtPlot_5->setMinimumSize(QSize(550, 300));
        qwtPlot_5->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_5->setProperty("autoReplot", QVariant(true));

        gridLayout_19->addWidget(qwtPlot_5, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_18, 4, 0, 1, 1);

        widget_19 = new QWidget(scrollAreaWidgetContents);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        sizePolicy.setHeightForWidth(widget_19->sizePolicy().hasHeightForWidth());
        widget_19->setSizePolicy(sizePolicy);
        gridLayout_20 = new QGridLayout(widget_19);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        qwtPlot_6 = new QwtPlot(widget_19);
        qwtPlot_6->setObjectName(QStringLiteral("qwtPlot_6"));
        qwtPlot_6->setMinimumSize(QSize(550, 300));
        qwtPlot_6->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_6->setProperty("autoReplot", QVariant(true));

        gridLayout_20->addWidget(qwtPlot_6, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_19, 5, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_15->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_23->addWidget(widget_13, 0, 0, 1, 1);

        widget_20 = new QWidget(tabWidget_SHOW);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setMaximumSize(QSize(200, 425));
        gridLayout_22 = new QGridLayout(widget_20);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        widget_14 = new QWidget(widget_20);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_14->sizePolicy().hasHeightForWidth());
        widget_14->setSizePolicy(sizePolicy1);
        widget_14->setMaximumSize(QSize(132, 174));
        gridLayout_12 = new QGridLayout(widget_14);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        checkBox = new QCheckBox(widget_14);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"gridline-color: rgb(0, 0, 255);"));

        gridLayout_12->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(widget_14);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_12->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox_3 = new QCheckBox(widget_14);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_12->addWidget(checkBox_3, 2, 0, 1, 1);

        checkBox_4 = new QCheckBox(widget_14);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_12->addWidget(checkBox_4, 3, 0, 1, 1);

        checkBox_5 = new QCheckBox(widget_14);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_12->addWidget(checkBox_5, 4, 0, 1, 1);

        checkBox_6 = new QCheckBox(widget_14);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_12->addWidget(checkBox_6, 5, 0, 1, 1);


        gridLayout_22->addWidget(widget_14, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_20);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(1, 0));
        widget_2->setMaximumSize(QSize(132, 227));
        gridLayout_21 = new QGridLayout(widget_2);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        pushButton_openfile = new QPushButton(widget_2);
        pushButton_openfile->setObjectName(QStringLiteral("pushButton_openfile"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_openfile->sizePolicy().hasHeightForWidth());
        pushButton_openfile->setSizePolicy(sizePolicy2);
        pushButton_openfile->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_21->addWidget(pushButton_openfile, 0, 0, 1, 1);

        progressBar_readfile = new QProgressBar(widget_2);
        progressBar_readfile->setObjectName(QStringLiteral("progressBar_readfile"));
        progressBar_readfile->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        progressBar_readfile->setValue(24);

        gridLayout_21->addWidget(progressBar_readfile, 1, 0, 1, 1);

        widget_12 = new QWidget(widget_2);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        sizePolicy2.setHeightForWidth(widget_12->sizePolicy().hasHeightForWidth());
        widget_12->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(widget_12);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_12);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(114, 12));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_timerange = new QLabel(widget_12);
        label_timerange->setObjectName(QStringLiteral("label_timerange"));
        label_timerange->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(label_timerange, 1, 0, 1, 1);


        gridLayout_21->addWidget(widget_12, 2, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        gridLayout_13 = new QGridLayout(widget_3);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_13->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(widget_3);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_13->addWidget(doubleSpinBox, 0, 1, 1, 1);


        gridLayout_21->addWidget(widget_3, 3, 0, 1, 1);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(widget_4);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(doubleSpinBox_2);


        gridLayout_21->addWidget(widget_4, 4, 0, 1, 1);

        pushButton_queding = new QPushButton(widget_2);
        pushButton_queding->setObjectName(QStringLiteral("pushButton_queding"));
        sizePolicy2.setHeightForWidth(pushButton_queding->sizePolicy().hasHeightForWidth());
        pushButton_queding->setSizePolicy(sizePolicy2);
        pushButton_queding->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_21->addWidget(pushButton_queding, 5, 0, 1, 1);

        pushButton_cancelsegshow = new QPushButton(widget_2);
        pushButton_cancelsegshow->setObjectName(QStringLiteral("pushButton_cancelsegshow"));
        sizePolicy2.setHeightForWidth(pushButton_cancelsegshow->sizePolicy().hasHeightForWidth());
        pushButton_cancelsegshow->setSizePolicy(sizePolicy2);
        pushButton_cancelsegshow->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_21->addWidget(pushButton_cancelsegshow, 6, 0, 1, 1);


        gridLayout_22->addWidget(widget_2, 1, 0, 1, 1);


        gridLayout_23->addWidget(widget_20, 0, 1, 1, 1);

        tabWidget->addTab(tabWidget_SHOW, QString());
        tab_IP = new QWidget();
        tab_IP->setObjectName(QStringLiteral("tab_IP"));
        tabWidget->addTab(tab_IP, QString());
        tab_k = new QWidget();
        tab_k->setObjectName(QStringLiteral("tab_k"));
        tabWidget->addTab(tab_k, QString());
        tab_translate = new QWidget();
        tab_translate->setObjectName(QStringLiteral("tab_translate"));
        tabWidget->addTab(tab_translate, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());

        gridLayout_9->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_3->setText(QApplication::translate("Widget", "FTP \346\234\215\345\212\241\345\231\250\357\274\232", 0));
        lineEdit->setText(QApplication::translate("Widget", "ftp://Goldensun:7622041.@10.108.12.31:21", 0));
        pushButton_connect->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_ftp->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("Widget", "\345\244\247\345\260\217", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("Widget", "\344\277\256\346\224\271\346\227\245\346\234\237", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "\345\220\215\347\247\260", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_localfile->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("Widget", "\345\244\247\345\260\217", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("Widget", "\344\277\256\346\224\271\346\227\245\346\234\237", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Widget", "\345\220\215\347\247\260", 0));
        label_4->setText(QApplication::translate("Widget", "\350\277\233\345\272\246\346\235\241\357\274\232", 0));
        pushButton_canceldownload->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", 0));
        comboBox->setItemText(0, QApplication::translate("Widget", "C\347\233\230", 0));
        comboBox->setItemText(1, QApplication::translate("Widget", "D\347\233\230", 0));
        comboBox->setItemText(2, QApplication::translate("Widget", "E\347\233\230", 0));
        comboBox->setItemText(3, QApplication::translate("Widget", "F\347\233\230", 0));

        label_status->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabWidget_FTP), QApplication::translate("Widget", "FTP", 0));
        checkBox->setText(QApplication::translate("Widget", "\351\200\232\351\201\223\344\270\200", 0));
        checkBox_2->setText(QApplication::translate("Widget", "\351\200\232\351\201\223\344\272\214", 0));
        checkBox_3->setText(QApplication::translate("Widget", "\351\200\232\351\201\223\344\270\211", 0));
        checkBox_4->setText(QApplication::translate("Widget", "\351\200\232\351\201\223\345\233\233", 0));
        checkBox_5->setText(QApplication::translate("Widget", "\351\200\232\351\201\223\344\272\224", 0));
        checkBox_6->setText(QApplication::translate("Widget", "\351\200\232\351\201\223\345\205\255", 0));
        pushButton_openfile->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        label_5->setText(QApplication::translate("Widget", "\346\227\266\351\227\264\350\214\203\345\233\264\357\274\232", 0));
        label_timerange->setText(QString());
        label->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\357\274\232", 0));
        label_2->setText(QApplication::translate("Widget", "\347\273\223\346\235\237\357\274\232", 0));
        pushButton_queding->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", 0));
        pushButton_cancelsegshow->setText(QApplication::translate("Widget", "\345\217\226\346\266\210\345\210\206\346\256\265\346\230\276\347\244\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabWidget_SHOW), QApplication::translate("Widget", "\345\217\257\350\247\206\345\214\226", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_IP), QApplication::translate("Widget", "IP", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_k), QApplication::translate("Widget", "K\357\274\214b", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_translate), QApplication::translate("Widget", "translate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\345\267\245\345\205\267", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
