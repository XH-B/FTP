/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QAction *actionKb;
    QAction *actionIP;
    QAction *actiontrans;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;
    QMenuBar *menubar;
    QMenu *menuFTP;
    QMenu *menushow;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(800, 600);
        actionKb = new QAction(main_window);
        actionKb->setObjectName(QStringLiteral("actionKb"));
        actionIP = new QAction(main_window);
        actionIP->setObjectName(QStringLiteral("actionIP"));
        actiontrans = new QAction(main_window);
        actiontrans->setObjectName(QStringLiteral("actiontrans"));
        centralwidget = new QWidget(main_window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedWidget->addWidget(page_5);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        main_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(main_window);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFTP = new QMenu(menubar);
        menuFTP->setObjectName(QStringLiteral("menuFTP"));
        menushow = new QMenu(menubar);
        menushow->setObjectName(QStringLiteral("menushow"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        main_window->setMenuBar(menubar);
        statusbar = new QStatusBar(main_window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        main_window->setStatusBar(statusbar);

        menubar->addAction(menuFTP->menuAction());
        menubar->addAction(menushow->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu_2->addAction(actionKb);
        menu_2->addAction(actionIP);
        menu_2->addAction(actiontrans);

        retranslateUi(main_window);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "MainWindow", 0));
        actionKb->setText(QApplication::translate("main_window", "Kb", 0));
        actionIP->setText(QApplication::translate("main_window", "IP\351\205\215\347\275\256", 0));
        actiontrans->setText(QApplication::translate("main_window", "\346\240\274\345\274\217\350\275\254\345\214\226", 0));
        menuFTP->setTitle(QApplication::translate("main_window", "FTP", 0));
        menushow->setTitle(QApplication::translate("main_window", "\345\217\257\350\247\206\345\214\226", 0));
        menu_2->setTitle(QApplication::translate("main_window", "\345\267\245\345\205\267", 0));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
