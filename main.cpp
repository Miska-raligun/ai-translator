#include "mainwindow.h"
#include <QApplication>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QFont font("WenQuanYi Micro Hei", 10);
    QApplication::setFont(font);

    MainWindow w;
    w.setWindowTitle("小灯翻译!!!!!");
    w.show();
    return a.exec();
}
