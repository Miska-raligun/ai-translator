/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mytextedit.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    MyTextEdit *sourceTextEdit;
    QHBoxLayout *modeLayout;
    QLabel *modeLabel;
    QComboBox *modeComboBox;
    QPushButton *modelConfigButton;
    QTextEdit *resultTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(365, 420);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        sourceTextEdit = new MyTextEdit(centralwidget);
        sourceTextEdit->setObjectName("sourceTextEdit");

        verticalLayout->addWidget(sourceTextEdit);

        modeLayout = new QHBoxLayout();
        modeLayout->setObjectName("modeLayout");
        modeLabel = new QLabel(centralwidget);
        modeLabel->setObjectName("modeLabel");

        modeLayout->addWidget(modeLabel);

        modeComboBox = new QComboBox(centralwidget);
        modeComboBox->addItem(QString());
        modeComboBox->addItem(QString());
        modeComboBox->setObjectName("modeComboBox");

        modeLayout->addWidget(modeComboBox);

        modelConfigButton = new QPushButton(centralwidget);
        modelConfigButton->setObjectName("modelConfigButton");

        modeLayout->addWidget(modelConfigButton);


        verticalLayout->addLayout(modeLayout);

        resultTextEdit = new QTextEdit(centralwidget);
        resultTextEdit->setObjectName("resultTextEdit");
        resultTextEdit->setReadOnly(true);

        verticalLayout->addWidget(resultTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mini Translator", nullptr));
        sourceTextEdit->setProperty("placeholderText", QVariant(QCoreApplication::translate("MainWindow", "Enter text to translate...", nullptr)));
        modeLabel->setText(QCoreApplication::translate("MainWindow", "\350\247\246\345\217\221\346\250\241\345\274\217\357\274\232", nullptr));
        modeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217 1\357\274\210\345\267\246\351\224\256\346\214\211\344\275\217 + \345\220\214\346\227\266\345\217\263\351\224\256\357\274\211", nullptr));
        modeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217 2\357\274\210\346\232\202\344\270\215\346\224\257\346\214\201\357\274\211", nullptr));

        modelConfigButton->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\236\213\351\205\215\347\275\256", nullptr));
        resultTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Translation will appear here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
