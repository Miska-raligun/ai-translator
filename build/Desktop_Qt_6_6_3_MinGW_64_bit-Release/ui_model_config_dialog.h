/********************************************************************************
** Form generated from reading UI file 'model_config_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_CONFIG_DIALOG_H
#define UI_MODEL_CONFIG_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *useDefaultButton;
    QGroupBox *customGroupBox;
    QFormLayout *formLayout;
    QLabel *label_1;
    QLineEdit *apiUrlEdit;
    QLabel *label_2;
    QLineEdit *apiKeyEdit;
    QLabel *label_3;
    QLineEdit *modelEdit;
    QLabel *label_4;
    QPushButton *setCustomButton;
    QDoubleSpinBox *temperatureSpinBox;

    void setupUi(QDialog *ModelConfigDialog)
    {
        if (ModelConfigDialog->objectName().isEmpty())
            ModelConfigDialog->setObjectName("ModelConfigDialog");
        ModelConfigDialog->resize(422, 253);
        verticalLayout = new QVBoxLayout(ModelConfigDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ModelConfigDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        useDefaultButton = new QPushButton(ModelConfigDialog);
        useDefaultButton->setObjectName("useDefaultButton");

        verticalLayout->addWidget(useDefaultButton);

        customGroupBox = new QGroupBox(ModelConfigDialog);
        customGroupBox->setObjectName("customGroupBox");
        formLayout = new QFormLayout(customGroupBox);
        formLayout->setObjectName("formLayout");
        label_1 = new QLabel(customGroupBox);
        label_1->setObjectName("label_1");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_1);

        apiUrlEdit = new QLineEdit(customGroupBox);
        apiUrlEdit->setObjectName("apiUrlEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, apiUrlEdit);

        label_2 = new QLabel(customGroupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        apiKeyEdit = new QLineEdit(customGroupBox);
        apiKeyEdit->setObjectName("apiKeyEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, apiKeyEdit);

        label_3 = new QLabel(customGroupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        modelEdit = new QLineEdit(customGroupBox);
        modelEdit->setObjectName("modelEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, modelEdit);

        label_4 = new QLabel(customGroupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        setCustomButton = new QPushButton(customGroupBox);
        setCustomButton->setObjectName("setCustomButton");

        formLayout->setWidget(4, QFormLayout::FieldRole, setCustomButton);

        temperatureSpinBox = new QDoubleSpinBox(customGroupBox);
        temperatureSpinBox->setObjectName("temperatureSpinBox");
        temperatureSpinBox->setMinimum(0.000000000000000);
        temperatureSpinBox->setMaximum(1.000000000000000);
        temperatureSpinBox->setSingleStep(0.100000000000000);
        temperatureSpinBox->setValue(0.300000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, temperatureSpinBox);


        verticalLayout->addWidget(customGroupBox);


        retranslateUi(ModelConfigDialog);

        QMetaObject::connectSlotsByName(ModelConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ModelConfigDialog)
    {
        ModelConfigDialog->setWindowTitle(QCoreApplication::translate("ModelConfigDialog", "\346\250\241\345\236\213\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("ModelConfigDialog", "\350\257\267\351\200\211\346\213\251\346\250\241\345\236\213\351\205\215\347\275\256\346\226\271\345\274\217\357\274\232", nullptr));
        useDefaultButton->setText(QCoreApplication::translate("ModelConfigDialog", "\347\231\275\345\253\226\344\275\234\350\200\205\357\274\210\344\275\277\347\224\250\345\206\205\347\275\256\346\250\241\345\236\213\357\274\211", nullptr));
        customGroupBox->setTitle(QCoreApplication::translate("ModelConfigDialog", "\350\207\252\345\256\232\344\271\211\346\250\241\345\236\213\351\205\215\347\275\256", nullptr));
        label_1->setText(QCoreApplication::translate("ModelConfigDialog", "API URL", nullptr));
        label_2->setText(QCoreApplication::translate("ModelConfigDialog", "API Key", nullptr));
        label_3->setText(QCoreApplication::translate("ModelConfigDialog", "\346\250\241\345\236\213\345\220\215\347\247\260", nullptr));
        label_4->setText(QCoreApplication::translate("ModelConfigDialog", "Temperature", nullptr));
        setCustomButton->setText(QCoreApplication::translate("ModelConfigDialog", "\350\256\276\347\275\256\346\250\241\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelConfigDialog: public Ui_ModelConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_CONFIG_DIALOG_H
