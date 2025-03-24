#ifndef MODEL_CONFIG_DIALOG_H
#define MODEL_CONFIG_DIALOG_H

#include <QDialog>

namespace Ui {
class ModelConfigDialog;
}

class ModelConfigDialog : public QDialog {
    Q_OBJECT

public:
    explicit ModelConfigDialog(QWidget *parent = nullptr);
    ~ModelConfigDialog();

    QString apiKey() const;
    QString apiUrl() const;
    QString model() const;
    double temperature() const;
    bool isCustomSelected() const;

private slots:
    void on_useDefaultButton_clicked();
    void on_setCustomButton_clicked();

private:
    Ui::ModelConfigDialog *ui;
    bool customSelected = false;
};

#endif // MODEL_CONFIG_DIALOG_H
