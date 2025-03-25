#include "model_config_dialog.h"
#include "ui_model_config_dialog.h"
#include <QSettings>
#include <QMessageBox>

ModelConfigDialog::ModelConfigDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModelConfigDialog)
{
    ui->setupUi(this);

    QSettings settings("MiniTranslator", "UserConfig");
    ui->apiUrlEdit->setText(settings.value("apiUrl").toString());
    ui->apiKeyEdit->setText(settings.value("apiKey").toString());
    ui->modelEdit->setText(settings.value("model").toString());
    ui->temperatureSpinBox->setValue(settings.value("temperature", 0.3).toDouble());
}

ModelConfigDialog::~ModelConfigDialog()
{
    delete ui;
}

QString ModelConfigDialog::apiUrl() const {
    return ui->apiUrlEdit->text();
}

QString ModelConfigDialog::apiKey() const {
    return ui->apiKeyEdit->text();
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

void ModelConfigDialog::on_useDefaultButton_clicked()
{
    QSettings settings("MiniTranslator", "UserConfig");
    settings.setValue("customSelected", false);
    customSelected = false;
    accept();
}

void ModelConfigDialog::on_setCustomButton_clicked()
{
    if (ui->apiKeyEdit->text().isEmpty() ||
        ui->apiUrlEdit->text().isEmpty() ||
        ui->modelEdit->text().isEmpty()) {
        QMessageBox::warning(this, "错误", "请填写完整的模型配置信息！");
        return;
    }

    QSettings settings("MiniTranslator", "UserConfig");
    settings.setValue("apiUrl", ui->apiUrlEdit->text());
    settings.setValue("apiKey", ui->apiKeyEdit->text());
    settings.setValue("model", ui->modelEdit->text());
    settings.setValue("temperature", ui->temperatureSpinBox->value());
    settings.setValue("customSelected", true);
    customSelected = true;
    accept();
}

void ModelConfigDialog::on_resetButton_clicked()
{
    QSettings settings("MiniTranslator", "UserConfig");
    settings.clear();
    settings.sync();
    QMessageBox::information(this, "配置已重置", "所有配置已清除，将在下次启动时重新配置。");
    reject(); // 关闭窗口并通知主窗口配置被取消
}
