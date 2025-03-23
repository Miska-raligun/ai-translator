#include "mytextedit.h"

#include <QContextMenuEvent>

MyTextEdit::MyTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
}

void MyTextEdit::contextMenuEvent(QContextMenuEvent *event)
{
    // 什么也不做，阻止弹出右键菜单
    // 你也可以添加自定义菜单在这里
}
