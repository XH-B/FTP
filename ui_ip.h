/********************************************************************************
** Form generated from reading UI file 'ip.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IP_H
#define UI_IP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ip
{
public:
    QGridLayout *gridLayout_5;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QTreeWidget *treeWidget;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QPushButton *pushButton_queding;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QLabel *label_2;
    QLineEdit *lineEdit_subnet;
    QLabel *label_4;
    QLineEdit *lineEdit_ip_ipnew;
    QPushButton *pushButton_changeip;
    QLabel *label_6;
    QPushButton *pushButton_auotoip;
    QLabel *label_status;

    void setupUi(QWidget *Ip)
    {
        if (Ip->objectName().isEmpty())
            Ip->setObjectName(QStringLiteral("Ip"));
        Ip->resize(1152, 648);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ip->sizePolicy().hasHeightForWidth());
        Ip->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(Ip);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        widget_4 = new QWidget(Ip);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        treeWidget = new QTreeWidget(widget_2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout_2->addWidget(treeWidget, 2, 1, 1, 1);


        gridLayout_4->addWidget(widget_2, 0, 0, 2, 1);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        pushButton_queding = new QPushButton(widget);
        pushButton_queding->setObjectName(QStringLiteral("pushButton_queding"));
        pushButton_queding->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(pushButton_queding, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_ip = new QLineEdit(widget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(lineEdit_ip, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_subnet = new QLineEdit(widget);
        lineEdit_subnet->setObjectName(QStringLiteral("lineEdit_subnet"));
        lineEdit_subnet->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(lineEdit_subnet, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_ip_ipnew = new QLineEdit(widget);
        lineEdit_ip_ipnew->setObjectName(QStringLiteral("lineEdit_ip_ipnew"));
        lineEdit_ip_ipnew->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(lineEdit_ip_ipnew, 3, 1, 1, 1);

        pushButton_changeip = new QPushButton(widget);
        pushButton_changeip->setObjectName(QStringLiteral("pushButton_changeip"));
        pushButton_changeip->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout->addWidget(pushButton_changeip, 3, 2, 1, 1);


        gridLayout_3->addWidget(widget, 2, 0, 1, 1);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 17));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);


        gridLayout_4->addWidget(widget_3, 0, 1, 1, 1);

        pushButton_auotoip = new QPushButton(widget_4);
        pushButton_auotoip->setObjectName(QStringLiteral("pushButton_auotoip"));
        pushButton_auotoip->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_4->addWidget(pushButton_auotoip, 0, 2, 1, 1);

        label_status = new QLabel(widget_4);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_4->addWidget(label_status, 1, 1, 1, 1);


        gridLayout_5->addWidget(widget_4, 0, 0, 1, 1);


        retranslateUi(Ip);

        QMetaObject::connectSlotsByName(Ip);
    } // setupUi

    void retranslateUi(QWidget *Ip)
    {
        Ip->setWindowTitle(QApplication::translate("Ip", "Form", 0));
        label_5->setText(QApplication::translate("Ip", "\345\275\223\345\211\215\347\275\221\347\273\234\345\220\215\347\247\260\357\274\232", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("Ip", "\345\220\215\347\247\260", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("Ip", "\345\272\217\345\217\267", 0));
        label_3->setText(QApplication::translate("Ip", "\350\246\201\344\277\256\346\224\271\347\232\204\347\275\221\347\273\234\345\220\215\347\247\260\357\274\232", 0));
        lineEdit_name->setText(QString());
        pushButton_queding->setText(QApplication::translate("Ip", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("Ip", "Ip\345\234\260\345\235\200\357\274\232", 0));
        label_2->setText(QApplication::translate("Ip", "\345\255\220\347\275\221\346\216\251\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("Ip", "\346\226\260Ip\345\234\260\345\235\200\357\274\232", 0));
        lineEdit_ip_ipnew->setText(QApplication::translate("Ip", "192.168.10.99", 0));
        pushButton_changeip->setText(QApplication::translate("Ip", "\346\233\264\346\224\271Ip", 0));
        label_6->setText(QApplication::translate("Ip", "\346\211\213\345\212\250\346\233\264\346\224\271IP\345\234\260\345\235\200\357\274\232", 0));
        pushButton_auotoip->setText(QApplication::translate("Ip", "\346\201\242\345\244\215\344\270\272\350\207\252\345\212\250\350\216\267\345\217\226IP", 0));
        label_status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ip: public Ui_Ip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IP_H
