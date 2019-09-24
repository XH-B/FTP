/********************************************************************************
** Form generated from reading UI file 'up.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UP_H
#define UI_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_up
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *up)
    {
        if (up->objectName().isEmpty())
            up->setObjectName(QStringLiteral("up"));
        up->resize(567, 365);
        progressBar = new QProgressBar(up);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(80, 130, 351, 41));
        progressBar->setValue(24);

        retranslateUi(up);

        QMetaObject::connectSlotsByName(up);
    } // setupUi

    void retranslateUi(QWidget *up)
    {
        up->setWindowTitle(QApplication::translate("up", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class up: public Ui_up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UP_H
