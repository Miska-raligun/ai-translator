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
#include <QtWidgets/QHBoxLayout>
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
    QLineEdit *apiUrlEdit;
    QLineEdit *apiKeyEdit;
    QLineEdit *modelEdit;
    QDoubleSpinBox *temperatureSpinBox;
    QPushButton *setCustomButton;
    QPushButton *useDefaultButton;
    QHBoxLayout *buttonLayout;
    QPushButton *resetButton;

    void setupUi(QDialog *ModelConfigDialog)
    {
        if (ModelConfigDialog->objectName().isEmpty())
            ModelConfigDialog->setObjectName("ModelConfigDialog");
        ModelConfigDialog->resize(400, 213);
        verticalLayout = new QVBoxLayout(ModelConfigDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ModelConfigDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        apiUrlEdit = new QLineEdit(ModelConfigDialog);
        apiUrlEdit->setObjectName("apiUrlEdit");

        verticalLayout->addWidget(apiUrlEdit);

        apiKeyEdit = new QLineEdit(ModelConfigDialog);
        apiKeyEdit->setObjectName("apiKeyEdit");

        verticalLayout->addWidget(apiKeyEdit);

        modelEdit = new QLineEdit(ModelConfigDialog);
        modelEdit->setObjectName("modelEdit");

        verticalLayout->addWidget(modelEdit);

        temperatureSpinBox = new QDoubleSpinBox(ModelConfigDialog);
        temperatureSpinBox->setObjectName("temperatureSpinBox");
        temperatureSpinBox->setMinimum(0.000000000000000);
        temperatureSpinBox->setMaximum(1.000000000000000);
        temperatureSpinBox->setSingleStep(0.100000000000000);
        temperatureSpinBox->setValue(0.300000000000000);

        verticalLayout->addWidget(temperatureSpinBox);

        setCustomButton = new QPushButton(ModelConfigDialog);
        setCustomButton->setObjectName("setCustomButton");

        verticalLayout->addWidget(setCustomButton);

        useDefaultButton = new QPushButton(ModelConfigDialog);
        useDefaultButton->setObjectName("useDefaultButton");

        verticalLayout->addWidget(useDefaultButton);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");

        verticalLayout->addLayout(buttonLayout);

        resetButton = new QPushButton(ModelConfigDialog);
        resetButton->setObjectName("resetButton");

        verticalLayout->addWidget(resetButton);


        retranslateUi(ModelConfigDialog);

        QMetaObject::connectSlotsByName(ModelConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ModelConfigDialog)
    {
        ModelConfigDialog->setWindowTitle(QCoreApplication::translate("ModelConfigDialog", "\346\250\241\345\236\213\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("ModelConfigDialog", "\350\257\267\350\276\223\345\205\245 API \346\250\241\345\236\213\347\233\270\345\205\263\351\205\215\347\275\256\357\274\232", nullptr));
        apiUrlEdit->setPlaceholderText(QCoreApplication::translate("ModelConfigDialog", "API \345\234\260\345\235\200", nullptr));
        apiKeyEdit->setPlaceholderText(QCoreApplication::translate("ModelConfigDialog", "API Key", nullptr));
        modelEdit->setPlaceholderText(QCoreApplication::translate("ModelConfigDialog", "\346\250\241\345\236\213\345\220\215\347\247\260", nullptr));
        setCustomButton->setText(QCoreApplication::translate("ModelConfigDialog", "\350\256\276\347\275\256\346\250\241\345\236\213", nullptr));
        useDefaultButton->setText(QCoreApplication::translate("ModelConfigDialog", "\347\231\275\345\253\226\344\275\234\350\200\205", nullptr));
        resetButton->setText(QCoreApplication::translate("ModelConfigDialog", "\351\207\215\347\275\256\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelConfigDialog: public Ui_ModelConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_CONFIG_DIALOG_H
