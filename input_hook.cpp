#include "input_hook.h"
#include <QGuiApplication>
#include <QClipboard>
#include <QMetaObject>
#include <QDebug>

HHOOK InputHook::mouseHook = nullptr;
bool InputHook::leftPressed = false;
InputHook* InputHook::instance = nullptr;
int InputHook::triggerMode = 0;

InputHook::InputHook(QObject *parent) : QObject(parent) {
    instance = this;
}

InputHook::~InputHook() {
    stopHook();
}

void InputHook::startHook() {
    if (triggerMode == 0) {
        mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, nullptr, 0);
        if (!mouseHook) {
            qDebug() << "❌ Failed to install mouse hook";
        } else {
            qDebug() << "✅ Mouse hook installed";
        }
    }
}

void InputHook::stopHook() {
    if (mouseHook) {
        UnhookWindowsHookEx(mouseHook);
        mouseHook = nullptr;
    }
}

void InputHook::registerHotkey(HWND hwnd) {
    if (RegisterHotKey(hwnd, HOTKEY_ID, MOD_CONTROL | MOD_SHIFT, 0x54)) {
        qDebug() << "✅ Registered global hotkey Ctrl+Shift+T";
    } else {
        qDebug() << "❌ Failed to register hotkey";
    }
}

void InputHook::unregisterHotkey(HWND hwnd) {
    UnregisterHotKey(hwnd, HOTKEY_ID);
}

LRESULT CALLBACK InputHook::mouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        if (wParam == WM_LBUTTONDOWN) {
            leftPressed = true;
        } else if (wParam == WM_LBUTTONUP) {
            leftPressed = false;
        } else if (wParam == WM_RBUTTONDOWN && leftPressed && triggerMode == 0) {
            // 模式 1：左键按住 + 右键触发翻译
            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event(0x43, 0, 0, 0);
            keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            Sleep(100); // 等剪贴板更新

            QMetaObject::invokeMethod(instance, [=]() {
                QString text = QGuiApplication::clipboard()->text();
                if (!text.isEmpty()) {
                    emit instance->translateTrigger();
                } else {
                    // 没有内容，手动写入提示到剪贴板，主程序会显示它
                    QGuiApplication::clipboard()->setText("未检测到剪贴板内容，请确保目标文字已选中及触发正确。");
                    emit instance->translateTrigger();
                }

                // 清空剪贴板（无论是否翻译）
                QGuiApplication::clipboard()->clear();
            }, Qt::QueuedConnection);

            return 1; // 阻止右键菜单弹出
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}
