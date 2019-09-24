/********************************************************************************
** Form generated from reading UI file 'show.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_H
#define UI_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_Show
{
public:
    QGridLayout *gridLayout_7;
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
    QGridLayout *gridLayout_6;
    QWidget *widget_14;
    QGridLayout *gridLayout_12;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QWidget *widget_12;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_timerange;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSpinBox *spinBox;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QProgressBar *progressBar_readfile;
    QPushButton *pushButton_openfile;

    void setupUi(QWidget *Show)
    {
        if (Show->objectName().isEmpty())
            Show->setObjectName(QStringLiteral("Show"));
        Show->resize(1170, 680);
        gridLayout_7 = new QGridLayout(Show);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        widget_13 = new QWidget(Show);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        gridLayout_15 = new QGridLayout(widget_13);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        scrollArea = new QScrollArea(widget_13);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 959, 1956));
        gridLayout_14 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
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
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        qwtPlot_2 = new QwtPlot(widget_15);
        qwtPlot_2->setObjectName(QStringLiteral("qwtPlot_2"));
        qwtPlot_2->setMinimumSize(QSize(550, 300));
        qwtPlot_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        qwtPlot_2->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_2->setProperty("autoReplot", QVariant(true));

        gridLayout_16->addWidget(qwtPlot_2, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_15, 1, 0, 1, 1);

        widget_16 = new QWidget(scrollAreaWidgetContents);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        sizePolicy.setHeightForWidth(widget_16->sizePolicy().hasHeightForWidth());
        widget_16->setSizePolicy(sizePolicy);
        gridLayout_17 = new QGridLayout(widget_16);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        qwtPlot_3 = new QwtPlot(widget_16);
        qwtPlot_3->setObjectName(QStringLiteral("qwtPlot_3"));
        qwtPlot_3->setMinimumSize(QSize(550, 300));
        qwtPlot_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        qwtPlot_3->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_3->setProperty("autoReplot", QVariant(true));

        gridLayout_17->addWidget(qwtPlot_3, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_16, 2, 0, 1, 1);

        widget_17 = new QWidget(scrollAreaWidgetContents);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        sizePolicy.setHeightForWidth(widget_17->sizePolicy().hasHeightForWidth());
        widget_17->setSizePolicy(sizePolicy);
        gridLayout_18 = new QGridLayout(widget_17);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        qwtPlot_4 = new QwtPlot(widget_17);
        qwtPlot_4->setObjectName(QStringLiteral("qwtPlot_4"));
        qwtPlot_4->setMinimumSize(QSize(550, 300));
        qwtPlot_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        qwtPlot_4->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_4->setProperty("autoReplot", QVariant(true));

        gridLayout_18->addWidget(qwtPlot_4, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_17, 3, 0, 1, 1);

        widget_18 = new QWidget(scrollAreaWidgetContents);
        widget_18->setObjectName(QStringLiteral("widget_18"));
        sizePolicy.setHeightForWidth(widget_18->sizePolicy().hasHeightForWidth());
        widget_18->setSizePolicy(sizePolicy);
        gridLayout_19 = new QGridLayout(widget_18);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        qwtPlot_5 = new QwtPlot(widget_18);
        qwtPlot_5->setObjectName(QStringLiteral("qwtPlot_5"));
        qwtPlot_5->setMinimumSize(QSize(550, 300));
        qwtPlot_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        qwtPlot_5->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_5->setProperty("autoReplot", QVariant(true));

        gridLayout_19->addWidget(qwtPlot_5, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_18, 4, 0, 1, 1);

        widget_19 = new QWidget(scrollAreaWidgetContents);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        sizePolicy.setHeightForWidth(widget_19->sizePolicy().hasHeightForWidth());
        widget_19->setSizePolicy(sizePolicy);
        gridLayout_20 = new QGridLayout(widget_19);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        qwtPlot_6 = new QwtPlot(widget_19);
        qwtPlot_6->setObjectName(QStringLiteral("qwtPlot_6"));
        qwtPlot_6->setMinimumSize(QSize(550, 300));
        qwtPlot_6->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        qwtPlot_6->setProperty("canvasBackground", QVariant(brush));
        qwtPlot_6->setProperty("autoReplot", QVariant(true));

        gridLayout_20->addWidget(qwtPlot_6, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_19, 5, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_15->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_13, 0, 0, 1, 1);

        widget_20 = new QWidget(Show);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setMaximumSize(QSize(200, 425));
        gridLayout_6 = new QGridLayout(widget_20);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        widget_14 = new QWidget(widget_20);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_14->sizePolicy().hasHeightForWidth());
        widget_14->setSizePolicy(sizePolicy1);
        widget_14->setMaximumSize(QSize(132, 174));
        gridLayout_12 = new QGridLayout(widget_14);
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


        gridLayout_6->addWidget(widget_14, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_20);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(1, 0));
        widget_2->setMaximumSize(QSize(132, 227));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        widget_12 = new QWidget(widget_2);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_12->sizePolicy().hasHeightForWidth());
        widget_12->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(widget_12);
        gridLayout->setSpacing(0);
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
        label_timerange->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_timerange, 1, 0, 1, 1);


        gridLayout_5->addWidget(widget_12, 2, 0, 1, 1);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(widget_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout_3->addWidget(spinBox, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_3, 3, 0, 1, 1);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        spinBox_2 = new QSpinBox(widget_4);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout_4->addWidget(spinBox_2, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_4, 4, 0, 1, 1);

        progressBar_readfile = new QProgressBar(widget_2);
        progressBar_readfile->setObjectName(QStringLiteral("progressBar_readfile"));
        progressBar_readfile->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        progressBar_readfile->setValue(24);

        gridLayout_5->addWidget(progressBar_readfile, 1, 0, 1, 1);

        pushButton_openfile = new QPushButton(widget_2);
        pushButton_openfile->setObjectName(QStringLiteral("pushButton_openfile"));
        sizePolicy2.setHeightForWidth(pushButton_openfile->sizePolicy().hasHeightForWidth());
        pushButton_openfile->setSizePolicy(sizePolicy2);
        pushButton_openfile->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(pushButton_openfile, 0, 0, 1, 1);


        gridLayout_6->addWidget(widget_2, 1, 0, 1, 1);


        gridLayout_7->addWidget(widget_20, 0, 1, 1, 1);


        retranslateUi(Show);

        QMetaObject::connectSlotsByName(Show);
    } // setupUi

    void retranslateUi(QWidget *Show)
    {
        Show->setWindowTitle(QApplication::translate("Show", "Form", 0));
        checkBox->setText(QApplication::translate("Show", "\350\231\232\346\213\237\347\244\272\346\263\242\345\231\250\344\270\200", 0));
        checkBox_2->setText(QApplication::translate("Show", "\350\231\232\346\213\237\347\244\272\346\263\242\345\231\250\344\272\214", 0));
        checkBox_3->setText(QApplication::translate("Show", "\350\231\232\346\213\237\347\244\272\346\263\242\345\231\250\344\270\211", 0));
        checkBox_4->setText(QApplication::translate("Show", "\350\231\232\346\213\237\347\244\272\346\263\242\345\231\250\345\233\233", 0));
        checkBox_5->setText(QApplication::translate("Show", "\350\231\232\346\213\237\347\244\272\346\263\242\345\231\250\344\272\224", 0));
        checkBox_6->setText(QApplication::translate("Show", "\350\231\232\346\213\237\347\244\272\346\263\242\345\231\250\345\205\255", 0));
        label_5->setText(QApplication::translate("Show", "\346\227\266\351\227\264\350\214\203\345\233\264\357\274\232", 0));
        label_timerange->setText(QString());
        label->setText(QApplication::translate("Show", "\345\274\200\345\247\213\357\274\232", 0));
        label_2->setText(QApplication::translate("Show", "\351\227\264\351\232\224\357\274\232", 0));
        pushButton_openfile->setText(QApplication::translate("Show", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class Show: public Ui_Show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_H
