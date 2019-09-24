/********************************************************************************
** Form generated from reading UI file 'translate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATE_H
#define UI_TRANSLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Translate
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QProgressBar *progressBar;

    void setupUi(QWidget *Translate)
    {
        if (Translate->objectName().isEmpty())
            Translate->setObjectName(QStringLiteral("Translate"));
        Translate->resize(1106, 679);
        gridLayout_2 = new QGridLayout(Translate);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QWidget(Translate);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 2);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 1, 0, 1, 2);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Translate);

        QMetaObject::connectSlotsByName(Translate);
    } // setupUi

    void retranslateUi(QWidget *Translate)
    {
        Translate->setWindowTitle(QApplication::translate("Translate", "Form", 0));
        pushButton->setText(QApplication::translate("Translate", "\350\257\273\345\217\226\346\226\207\344\273\266", 0));
        pushButton_2->setText(QApplication::translate("Translate", "\350\275\254\346\215\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Translate: public Ui_Translate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATE_H
