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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *MainLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddLeft_Button;
    QPushButton *RemoveLeft_Button;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *Adjust_Label;
    QSlider *Adjust_Slider;
    QFrame *line_5;
    QPushButton *RemoveRigth_Button;
    QPushButton *AddRight_Button;
    QFrame *line_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *LeftImage_Label;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *MixedImage_Label;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_7;
    QLabel *RightImage_Label;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *SaveAnimation_Button;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_3;
    QPushButton *SaveImage_Button;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(913, 606);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setContextMenuPolicy(Qt::NoContextMenu);
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        MainLayout = new QVBoxLayout();
        MainLayout->setSpacing(5);
        MainLayout->setObjectName(QStringLiteral("MainLayout"));
        MainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        AddLeft_Button = new QPushButton(centralWidget);
        AddLeft_Button->setObjectName(QStringLiteral("AddLeft_Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddLeft_Button->sizePolicy().hasHeightForWidth());
        AddLeft_Button->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(AddLeft_Button);

        RemoveLeft_Button = new QPushButton(centralWidget);
        RemoveLeft_Button->setObjectName(QStringLiteral("RemoveLeft_Button"));
        sizePolicy1.setHeightForWidth(RemoveLeft_Button->sizePolicy().hasHeightForWidth());
        RemoveLeft_Button->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(RemoveLeft_Button);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        Adjust_Label = new QLabel(centralWidget);
        Adjust_Label->setObjectName(QStringLiteral("Adjust_Label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Adjust_Label->sizePolicy().hasHeightForWidth());
        Adjust_Label->setSizePolicy(sizePolicy2);
        Adjust_Label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_2->addWidget(Adjust_Label);

        Adjust_Slider = new QSlider(centralWidget);
        Adjust_Slider->setObjectName(QStringLiteral("Adjust_Slider"));
        sizePolicy2.setHeightForWidth(Adjust_Slider->sizePolicy().hasHeightForWidth());
        Adjust_Slider->setSizePolicy(sizePolicy2);
        Adjust_Slider->setMinimumSize(QSize(150, 22));
        Adjust_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Adjust_Slider);


        horizontalLayout->addLayout(verticalLayout_2);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        RemoveRigth_Button = new QPushButton(centralWidget);
        RemoveRigth_Button->setObjectName(QStringLiteral("RemoveRigth_Button"));
        sizePolicy1.setHeightForWidth(RemoveRigth_Button->sizePolicy().hasHeightForWidth());
        RemoveRigth_Button->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(RemoveRigth_Button);

        AddRight_Button = new QPushButton(centralWidget);
        AddRight_Button->setObjectName(QStringLiteral("AddRight_Button"));
        sizePolicy1.setHeightForWidth(AddRight_Button->sizePolicy().hasHeightForWidth());
        AddRight_Button->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(AddRight_Button);


        MainLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        MainLayout->addWidget(line_2);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 887, 468));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        LeftImage_Label = new QLabel(scrollAreaWidgetContents);
        LeftImage_Label->setObjectName(QStringLiteral("LeftImage_Label"));
        sizePolicy.setHeightForWidth(LeftImage_Label->sizePolicy().hasHeightForWidth());
        LeftImage_Label->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(LeftImage_Label);

        horizontalSpacer_3 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        line_6 = new QFrame(scrollAreaWidgetContents);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_6);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        MixedImage_Label = new QLabel(scrollAreaWidgetContents);
        MixedImage_Label->setObjectName(QStringLiteral("MixedImage_Label"));
        sizePolicy.setHeightForWidth(MixedImage_Label->sizePolicy().hasHeightForWidth());
        MixedImage_Label->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(MixedImage_Label);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        line_7 = new QFrame(scrollAreaWidgetContents);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_7);

        horizontalSpacer_7 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        RightImage_Label = new QLabel(scrollAreaWidgetContents);
        RightImage_Label->setObjectName(QStringLiteral("RightImage_Label"));
        sizePolicy.setHeightForWidth(RightImage_Label->sizePolicy().hasHeightForWidth());
        RightImage_Label->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(RightImage_Label);

        horizontalSpacer_8 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        scrollArea->setWidget(scrollAreaWidgetContents);

        MainLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);

        MainLayout->addLayout(horizontalLayout_2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        MainLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SaveAnimation_Button = new QPushButton(centralWidget);
        SaveAnimation_Button->setObjectName(QStringLiteral("SaveAnimation_Button"));
        sizePolicy1.setHeightForWidth(SaveAnimation_Button->sizePolicy().hasHeightForWidth());
        SaveAnimation_Button->setSizePolicy(sizePolicy1);
        SaveAnimation_Button->setMinimumSize(QSize(175, 28));

        horizontalLayout_3->addWidget(SaveAnimation_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        SaveImage_Button = new QPushButton(centralWidget);
        SaveImage_Button->setObjectName(QStringLiteral("SaveImage_Button"));
        sizePolicy1.setHeightForWidth(SaveImage_Button->sizePolicy().hasHeightForWidth());
        SaveImage_Button->setSizePolicy(sizePolicy1);
        SaveImage_Button->setMinimumSize(QSize(175, 28));

        horizontalLayout_3->addWidget(SaveImage_Button);


        MainLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(MainLayout, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        AddLeft_Button->setText(QApplication::translate("MainWindowClass", "Dodaj", Q_NULLPTR));
        RemoveLeft_Button->setText(QApplication::translate("MainWindowClass", "Usu\305\204", Q_NULLPTR));
        Adjust_Label->setText(QApplication::translate("MainWindowClass", "Dopasuj", Q_NULLPTR));
        RemoveRigth_Button->setText(QApplication::translate("MainWindowClass", "Usu\305\204", Q_NULLPTR));
        AddRight_Button->setText(QApplication::translate("MainWindowClass", "Dodaj", Q_NULLPTR));
        LeftImage_Label->setText(QString());
        MixedImage_Label->setText(QString());
        RightImage_Label->setText(QString());
        SaveAnimation_Button->setText(QApplication::translate("MainWindowClass", "Zapisz animacj\304\231 wynikow\304\205", Q_NULLPTR));
        SaveImage_Button->setText(QApplication::translate("MainWindowClass", "Zapisz obraz wynikowy", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
