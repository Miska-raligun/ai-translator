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
    void onZoomIn();      // 新增：放大字体
    void onZoomOut();     // 新增：缩小字体
    void writeSettings(); // 保存ui偏好
    void readSettings();  // 读取ui偏好

private:
    enum TriggerMode {
        Mode_MouseCombo = 0,
        Mode_AltAfterSelect = 1
    };

    void updateFontSize(); // 新增：更新字体大小函数

    Ui::MainWindow *ui;
    OpenAITranslator *translator;
    QProcess *mouseWatcher;
    InputHook *hook;

    // 新增字体相关成员变量
    int m_currentFontSize = 12;   // 当前字体大小
    const int m_minFontSize = 8;  // 最小字体大小
    const int m_maxFontSize = 36; // 最大字体大小
    const int m_fontSizeStep = 2; // 字体变化步长
};

#endif // MAINWINDOW_H

