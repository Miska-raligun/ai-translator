#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openai_translator.h"
#include <QProcess>
#include <QClipboard>
#include <QGuiApplication>
#include "mytextedit.h"
#include "input_hook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
    ~MainWindow();

private slots:
    void on_translateButton_clicked();
    void on_modelConfigButton_clicked();

private:
    enum TriggerMode {
        Mode_MouseCombo = 0,
        Mode_AltAfterSelect = 1
    };

    Ui::MainWindow *ui;
    OpenAITranslator *translator;
    QProcess *mouseWatcher;
    InputHook *hook;
};

#endif // MAINWINDOW_H

