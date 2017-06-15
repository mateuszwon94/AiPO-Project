/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *AddLeft_Button;
    QPushButton *RemoveLeft_Button;
    QPushButton *AddRight_Button;
    QPushButton *RemoveRigth_Button;
    QSlider *Adjust_Slider;
    QLabel *Adjust_Label;
    QPushButton *SaveImage_Button;
    QPushButton *SaveAnimation_Button;
    QLabel *LeftImage_Label;
    QLabel *MixedImage_Label;
    QLabel *RightImage_Label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(600, 400);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AddLeft_Button = new QPushButton(centralWidget);
        AddLeft_Button->setObjectName(QStringLiteral("AddLeft_Button"));
        AddLeft_Button->setGeometry(QRect(10, 10, 71, 31));
        RemoveLeft_Button = new QPushButton(centralWidget);
        RemoveLeft_Button->setObjectName(QStringLiteral("RemoveLeft_Button"));
        RemoveLeft_Button->setGeometry(QRect(90, 10, 71, 31));
        AddRight_Button = new QPushButton(centralWidget);
        AddRight_Button->setObjectName(QStringLiteral("AddRight_Button"));
        AddRight_Button->setGeometry(QRect(522, 10, 71, 31));
        RemoveRigth_Button = new QPushButton(centralWidget);
        RemoveRigth_Button->setObjectName(QStringLiteral("RemoveRigth_Button"));
        RemoveRigth_Button->setGeometry(QRect(442, 10, 71, 31));
        Adjust_Slider = new QSlider(centralWidget);
        Adjust_Slider->setObjectName(QStringLiteral("Adjust_Slider"));
        Adjust_Slider->setGeometry(QRect(170, 20, 261, 21));
        Adjust_Slider->setOrientation(Qt::Horizontal);
        Adjust_Label = new QLabel(centralWidget);
        Adjust_Label->setObjectName(QStringLiteral("Adjust_Label"));
        Adjust_Label->setGeometry(QRect(270, 10, 55, 16));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Adjust_Label->sizePolicy().hasHeightForWidth());
        Adjust_Label->setSizePolicy(sizePolicy);
        SaveImage_Button = new QPushButton(centralWidget);
        SaveImage_Button->setObjectName(QStringLiteral("SaveImage_Button"));
        SaveImage_Button->setGeometry(QRect(10, 300, 171, 28));
        SaveAnimation_Button = new QPushButton(centralWidget);
        SaveAnimation_Button->setObjectName(QStringLiteral("SaveAnimation_Button"));
        SaveAnimation_Button->setGeometry(QRect(420, 300, 171, 28));
        LeftImage_Label = new QLabel(centralWidget);
        LeftImage_Label->setObjectName(QStringLiteral("LeftImage_Label"));
        LeftImage_Label->setGeometry(QRect(10, 50, 161, 241));
        MixedImage_Label = new QLabel(centralWidget);
        MixedImage_Label->setObjectName(QStringLiteral("MixedImage_Label"));
        MixedImage_Label->setGeometry(QRect(210, 50, 161, 241));
        RightImage_Label = new QLabel(centralWidget);
        RightImage_Label->setObjectName(QStringLiteral("RightImage_Label"));
        RightImage_Label->setGeometry(QRect(430, 50, 161, 241));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        AddLeft_Button->setText(QApplication::translate("MainWindowClass", "Dodaj", Q_NULLPTR));
        RemoveLeft_Button->setText(QApplication::translate("MainWindowClass", "Usu\305\204", Q_NULLPTR));
        AddRight_Button->setText(QApplication::translate("MainWindowClass", "Dodaj", Q_NULLPTR));
        RemoveRigth_Button->setText(QApplication::translate("MainWindowClass", "Usu\305\204", Q_NULLPTR));
        Adjust_Label->setText(QApplication::translate("MainWindowClass", "Dopasuj", Q_NULLPTR));
        SaveImage_Button->setText(QApplication::translate("MainWindowClass", "Zapisz obraz wynikowy", Q_NULLPTR));
        SaveAnimation_Button->setText(QApplication::translate("MainWindowClass", "Zapisz animacj\304\231 wynikow\304\205", Q_NULLPTR));
        LeftImage_Label->setText(QString());
        MixedImage_Label->setText(QString());
        RightImage_Label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
