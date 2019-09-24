/********************************************************************************
** Form generated from reading UI file 'ftp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTP_H
#define UI_FTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ftp
{
public:
    QGridLayout *gridLayout_5;
    QWidget *widget_6;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_diconnect;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *widget_5;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget_ftp;
    QWidget *widget_7;
    QGridLayout *gridLayout_2;
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

    void setupUi(QWidget *Ftp)
    {
        if (Ftp->objectName().isEmpty())
            Ftp->setObjectName(QStringLiteral("Ftp"));
        Ftp->resize(1144, 658);
        gridLayout_5 = new QGridLayout(Ftp);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        widget_6 = new QWidget(Ftp);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        gridLayout_3 = new QGridLayout(widget_6);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_6);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_connect = new QPushButton(widget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_4->addWidget(pushButton_connect, 0, 0, 1, 1);

        pushButton_diconnect = new QPushButton(widget);
        pushButton_diconnect->setObjectName(QStringLiteral("pushButton_diconnect"));
        pushButton_diconnect->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_4->addWidget(pushButton_diconnect, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget, 0, 2, 1, 1);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget_6);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_5->addWidget(widget_6, 0, 0, 1, 3);

        widget_5 = new QWidget(Ftp);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout = new QGridLayout(widget_5);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget_ftp = new QTreeWidget(widget_5);
        treeWidget_ftp->setObjectName(QStringLiteral("treeWidget_ftp"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget_ftp->sizePolicy().hasHeightForWidth());
        treeWidget_ftp->setSizePolicy(sizePolicy);
        treeWidget_ftp->setMinimumSize(QSize(560, 537));
        treeWidget_ftp->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        treeWidget_ftp->setAutoScrollMargin(16);

        gridLayout->addWidget(treeWidget_ftp, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget_5, 1, 0, 1, 2);

        widget_7 = new QWidget(Ftp);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        gridLayout_2 = new QGridLayout(widget_7);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidget_localfile = new QTreeWidget(widget_7);
        treeWidget_localfile->setObjectName(QStringLiteral("treeWidget_localfile"));
        sizePolicy.setHeightForWidth(treeWidget_localfile->sizePolicy().hasHeightForWidth());
        treeWidget_localfile->setSizePolicy(sizePolicy);
        treeWidget_localfile->setMinimumSize(QSize(560, 537));
        treeWidget_localfile->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(treeWidget_localfile, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget_7, 1, 2, 1, 1);

        widget_10 = new QWidget(Ftp);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        gridLayout_10 = new QGridLayout(widget_10);
        gridLayout_10->setSpacing(0);
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


        gridLayout_5->addWidget(widget_10, 2, 0, 1, 1);

        widget_8 = new QWidget(Ftp);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        gridLayout_7 = new QGridLayout(widget_8);
        gridLayout_7->setSpacing(0);
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


        gridLayout_5->addWidget(widget_8, 2, 2, 2, 1);

        label_status = new QLabel(Ftp);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_5->addWidget(label_status, 3, 0, 1, 1);


        retranslateUi(Ftp);

        QMetaObject::connectSlotsByName(Ftp);
    } // setupUi

    void retranslateUi(QWidget *Ftp)
    {
        Ftp->setWindowTitle(QApplication::translate("Ftp", "Form", 0));
        pushButton_connect->setText(QApplication::translate("Ftp", "\350\277\236\346\216\245", 0));
        pushButton_diconnect->setText(QApplication::translate("Ftp", "\346\226\255\345\274\200", 0));
        label_3->setText(QApplication::translate("Ftp", "FTP \346\234\215\345\212\241\345\231\250\357\274\232", 0));
        lineEdit->setText(QApplication::translate("Ftp", "10.108.13.65", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_ftp->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("Ftp", "\345\244\247\345\260\217/Kb", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("Ftp", "\344\277\256\346\224\271\346\227\245\346\234\237", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Ftp", "\345\220\215\347\247\260", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_localfile->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("Ftp", "\345\244\247\345\260\217/Kb", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("Ftp", "\344\277\256\346\224\271\346\227\245\346\234\237", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Ftp", "\345\220\215\347\247\260", 0));
        label_4->setText(QApplication::translate("Ftp", "\350\277\233\345\272\246\346\235\241\357\274\232", 0));
        pushButton_canceldownload->setText(QApplication::translate("Ftp", "\345\217\226\346\266\210", 0));
        comboBox->setItemText(0, QApplication::translate("Ftp", "C\347\233\230", 0));
        comboBox->setItemText(1, QApplication::translate("Ftp", "D\347\233\230", 0));
        comboBox->setItemText(2, QApplication::translate("Ftp", "E\347\233\230", 0));
        comboBox->setItemText(3, QApplication::translate("Ftp", "F\347\233\230", 0));

        label_status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ftp: public Ui_Ftp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTP_H
