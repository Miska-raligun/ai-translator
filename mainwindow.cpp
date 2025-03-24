#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model_config_dialog.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint); // 窗口悬浮置顶
    ui->modeComboBox->setCurrentIndex(0);    // 默认选中模式1

    connect(ui->modelConfigButton, &QPushButton::clicked,
            this, &MainWindow::on_modelConfigButton_clicked);

    // 初始化翻译器
    translator = new OpenAITranslator(this);
    // 🚀 启动弹出模型配置对话框
    QTimer::singleShot(0, this, [=]() {
        ModelConfigDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            if (dialog.isCustomSelected()) {
                translator->setApiKey(dialog.apiKey());
                translator->setApiUrl(dialog.apiUrl());
                translator->setModel(dialog.model());
                translator->setTemperature(dialog.temperature());
            } else {
                translator->setApiKey("your-api-key");
                translator->setApiUrl("https://api.siliconflow.cn/v1/chat/completions");
                translator->setModel("Pro/deepseek-ai/DeepSeek-V3");
                translator->setTemperature(0.3);
            }
        } else {
            close(); // 用户关闭配置窗口时，关闭主窗口
        }
    });

    InputHook::triggerMode = 0;

    //connect(ui->translateButton, &QPushButton::clicked,
            //this, &MainWindow::on_translateButton_clicked);

    connect(translator, &OpenAITranslator::translationFinished, this, [=](const QString &result) {
        ui->resultTextEdit->setPlainText(result);
        QGuiApplication::clipboard()->clear(); // 翻译完成后清空剪贴板
    });

    connect(translator, &OpenAITranslator::translationFailed, this, [=](const QString &err) {
        ui->resultTextEdit->setPlainText("Translation failed: " + err);
    });

    connect(ui->sourceTextEdit, &QTextEdit::selectionChanged, this, [=]() {
        QString selectedText = ui->sourceTextEdit->textCursor().selectedText();
        if (!selectedText.isEmpty()) {
            QClipboard *clipboard = QGuiApplication::clipboard();
            clipboard->setText(selectedText);
        }
    });

#ifdef Q_OS_WIN
    connect(ui->modeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [=](int index) {
        InputHook::triggerMode = index;
        qDebug() << "切换到触发模式:" << index;

        if (index == 0) {
            hook->stopHook();
            hook->startHook();
            hook->unregisterHotkey(HWND(winId()));
        } else {
            hook->stopHook();
            hook->registerHotkey(HWND(winId()));
        }
    });

    hook = new InputHook(this);
    connect(hook, &InputHook::translateTrigger, this, [=]() {
        QString text = QGuiApplication::clipboard()->text();
        if (!text.isEmpty()) {
            ui->sourceTextEdit->setPlainText(text);
            translator->translateText(text);
        } else {
            ui->resultTextEdit->setPlainText("未检测到剪贴板内容，请确保目标文字已选中。");
        }
        QGuiApplication::clipboard()->clear(); // 模式1：翻译后清空
    });

    hook->startHook();
#else
    mouseWatcher = new QProcess(this);
    mouseWatcher->start("python3", QStringList() << "mouse_watcher.py");

    connect(mouseWatcher, &QProcess::readyReadStandardOutput, this, [=]() {
        QString output = mouseWatcher->readAllStandardOutput();
        if (output.contains("[TRANSLATE_TRIGGER]")) {
            QString text = output.section("[TRANSLATE_TRIGGER]", 1).trimmed();
            ui->sourceTextEdit->setPlainText(text);
            translator->translateText(text);
        }
    });
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
#ifdef Q_OS_WIN
    hook->unregisterHotkey(HWND(winId()));
    delete hook;
#endif
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG *msg = static_cast<MSG *>(message);
    if (msg->message == WM_HOTKEY && msg->wParam == 0x1001 && InputHook::triggerMode == 1) {
        keybd_event(VK_CONTROL, 0, 0, 0);
        keybd_event(0x43, 0, 0, 0);
        keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

        Sleep(100);
        QString text = QGuiApplication::clipboard()->text();
        if (!text.isEmpty()) {
            ui->sourceTextEdit->setPlainText(text);
            translator->translateText(text);
        } else {
            ui->resultTextEdit->setPlainText("未检测到剪贴板内容，请确保目标文字已选中。");
        }

        QGuiApplication::clipboard()->clear();
        return true;
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::on_translateButton_clicked()
{
    QString sourceText = ui->sourceTextEdit->toPlainText();
    translator->translateText(sourceText);
}

void MainWindow::on_modelConfigButton_clicked()
{
    ModelConfigDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.isCustomSelected()) {
            translator->setApiKey(dialog.apiKey());
            translator->setApiUrl(dialog.apiUrl());
            translator->setModel(dialog.model());
            translator->setTemperature(dialog.temperature());
        } else {
            translator->setApiKey("your-api-key");
            translator->setApiUrl("https://api.siliconflow.cn/v1/chat/completions");
            translator->setModel("Pro/deepseek-ai/DeepSeek-V3");
            translator->setTemperature(0.3);
        }
    }
}
