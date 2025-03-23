#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化翻译器
    translator = new OpenAITranslator(this);
    translator->setApiKey("sk-***");  // 你的密钥
    translator->setApiUrl("https://api.siliconflow.cn/v1/chat/completions/"); // 你的API地址

    // 翻译按钮点击
    connect(ui->translateButton, &QPushButton::clicked,
            this, &MainWindow::on_translateButton_clicked);

    // 翻译成功信号
    connect(translator, &OpenAITranslator::translationFinished,
            this, [=](const QString &result) {
                ui->resultTextEdit->setPlainText(result);
            });

    // 翻译失败信号
    connect(translator, &OpenAITranslator::translationFailed,
            this, [=](const QString &err) {
                ui->resultTextEdit->setPlainText("Translation failed: " + err);
            });

    // 启动监听器脚本
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

    connect(ui->sourceTextEdit, &QTextEdit::selectionChanged, this, [=]() {
        QString selectedText = ui->sourceTextEdit->textCursor().selectedText();
        if (!selectedText.isEmpty()) {
            QClipboard *clipboard = QGuiApplication::clipboard();
            clipboard->setText(selectedText);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_translateButton_clicked()
{
    QString sourceText = ui->sourceTextEdit->toPlainText();
    translator->translateText(sourceText);
}
