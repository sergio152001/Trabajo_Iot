/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lastDataLabel;
    QLabel *timeElapsedLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(860, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lastDataLabel = new QLabel(centralwidget);
        lastDataLabel->setObjectName(QString::fromUtf8("lastDataLabel"));
        lastDataLabel->setGeometry(QRect(10, 10, 751, 321));
        lastDataLabel->setMinimumSize(QSize(100, 100));
        timeElapsedLabel = new QLabel(centralwidget);
        timeElapsedLabel->setObjectName(QString::fromUtf8("timeElapsedLabel"));
        timeElapsedLabel->setGeometry(QRect(0, 310, 761, 151));
        timeElapsedLabel->setMinimumSize(QSize(100, 100));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 860, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sensor Data Application", nullptr));
        lastDataLabel->setText(QCoreApplication::translate("MainWindow", "\303\232ltimo dato guardado: N/A", nullptr));
        timeElapsedLabel->setText(QCoreApplication::translate("MainWindow", "Tiempo transcurrido: N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
