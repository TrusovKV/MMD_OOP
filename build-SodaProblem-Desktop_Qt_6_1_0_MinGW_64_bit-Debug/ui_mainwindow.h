/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "renderarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    renderArea *rho;
    renderArea *p;
    renderArea *v;
    renderArea *T;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton;
    QLineEdit *N_text;
    QLineEdit *Time_text;
    QLineEdit *Adibatic_text;
    QLineEdit *To_text;
    QLineEdit *From_text;
    QLineEdit *v2_text;
    QLineEdit *v1_text;
    QLineEdit *p1_text;
    QLineEdit *p2_text;
    QLineEdit *rho1_text;
    QLineEdit *rho2_text;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rho = new renderArea(centralwidget);
        rho->setObjectName(QString::fromUtf8("rho"));
        rho->setGeometry(QRect(270, 0, 241, 181));
        rho->setFrameShape(QFrame::StyledPanel);
        rho->setFrameShadow(QFrame::Raised);
        p = new renderArea(centralwidget);
        p->setObjectName(QString::fromUtf8("p"));
        p->setGeometry(QRect(530, 0, 241, 181));
        p->setFrameShape(QFrame::StyledPanel);
        p->setFrameShadow(QFrame::Raised);
        v = new renderArea(centralwidget);
        v->setObjectName(QString::fromUtf8("v"));
        v->setGeometry(QRect(270, 200, 241, 181));
        v->setFrameShape(QFrame::StyledPanel);
        v->setFrameShadow(QFrame::Raised);
        T = new renderArea(centralwidget);
        T->setObjectName(QString::fromUtf8("T"));
        T->setGeometry(QRect(530, 200, 241, 181));
        T->setFrameShape(QFrame::StyledPanel);
        T->setFrameShadow(QFrame::Raised);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 100, 31, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 140, 31, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 31, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 140, 31, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 100, 31, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 180, 31, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 320, 31, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 280, 31, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 360, 31, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(130, 360, 31, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(110, 320, 81, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 420, 93, 28));
        N_text = new QLineEdit(centralwidget);
        N_text->setObjectName(QString::fromUtf8("N_text"));
        N_text->setGeometry(QRect(20, 390, 61, 22));
        Time_text = new QLineEdit(centralwidget);
        Time_text->setObjectName(QString::fromUtf8("Time_text"));
        Time_text->setGeometry(QRect(110, 390, 61, 22));
        Adibatic_text = new QLineEdit(centralwidget);
        Adibatic_text->setObjectName(QString::fromUtf8("Adibatic_text"));
        Adibatic_text->setGeometry(QRect(110, 340, 61, 22));
        To_text = new QLineEdit(centralwidget);
        To_text->setObjectName(QString::fromUtf8("To_text"));
        To_text->setGeometry(QRect(20, 340, 61, 22));
        From_text = new QLineEdit(centralwidget);
        From_text->setObjectName(QString::fromUtf8("From_text"));
        From_text->setGeometry(QRect(20, 300, 61, 22));
        v2_text = new QLineEdit(centralwidget);
        v2_text->setObjectName(QString::fromUtf8("v2_text"));
        v2_text->setGeometry(QRect(110, 200, 61, 22));
        v1_text = new QLineEdit(centralwidget);
        v1_text->setObjectName(QString::fromUtf8("v1_text"));
        v1_text->setGeometry(QRect(10, 200, 61, 22));
        p1_text = new QLineEdit(centralwidget);
        p1_text->setObjectName(QString::fromUtf8("p1_text"));
        p1_text->setGeometry(QRect(10, 120, 61, 22));
        p2_text = new QLineEdit(centralwidget);
        p2_text->setObjectName(QString::fromUtf8("p2_text"));
        p2_text->setGeometry(QRect(110, 120, 61, 22));
        rho1_text = new QLineEdit(centralwidget);
        rho1_text->setObjectName(QString::fromUtf8("rho1_text"));
        rho1_text->setGeometry(QRect(10, 160, 61, 22));
        rho2_text = new QLineEdit(centralwidget);
        rho2_text->setObjectName(QString::fromUtf8("rho2_text"));
        rho2_text->setGeometry(QRect(110, 160, 61, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "p1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "rho1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "v1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "rho2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "p2", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "v2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Adiabatic coef", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
