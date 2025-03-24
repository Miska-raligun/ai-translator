#include "model_config_dialog.h"
#include "ui_model_config_dialog.h"
#include <QMessageBox>

ModelConfigDialog::ModelConfigDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ModelConfigDialog) {
    ui->setupUi(this);
    setWindowTitle("模型配置");
}

ModelConfigDialog::~ModelConfigDialog() {
    delete ui;
}

QString ModelConfigDialog::apiKey() const {
    return ui->apiKeyEdit->text();
}

QString ModelConfigDialog::apiUrl() const {
    return ui->apiUrlEdit->text();
}

QString ModelConfigDialog::model() const {
    return ui->modelEdit->text();
}

double ModelConfigDialog::temperature() const {
    return ui->temperatureSpinBox->value();
}

bool ModelConfigDialog::isCustomSelected() const {
    return customSelected;
}

void ModelConfigDialog::on_useDefaultButton_clicked() {
    customSelected = false;
    accept();
}

void ModelConfigDialog::on_setCustomButton_clicked() {
    if (ui->apiKeyEdit->text().isEmpty() ||
        ui->apiUrlEdit->text().isEmpty() ||
        ui->modelEdit->text().isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写完整的模型配置信息！");
        return;
    }
    customSelected = true;
    accept();
}
