#ifndef MODEL_CONFIG_DIALOG_H
#define MODEL_CONFIG_DIALOG_H

#include <QDialog>

namespace Ui {
class ModelConfigDialog;
}

class ModelConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelConfigDialog(QWidget *parent = nullptr);
    ~ModelConfigDialog();

    QString apiUrl() const;
    QString apiKey() const;
    QString model() const;
    double temperature() const;
    bool isCustomSelected() const;

private slots:
    void on_useDefaultButton_clicked();
    void on_setCustomButton_clicked();
    void on_resetButton_clicked();  // 重置配置槽函数

private:
    Ui::ModelConfigDialog *ui;
    bool customSelected = false;
};

#endif // MODEL_CONFIG_DIALOG_H
