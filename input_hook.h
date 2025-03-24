#ifndef INPUTHOOK_H
#define INPUTHOOK_H

#include <QObject>
#include <windows.h>

class InputHook : public QObject {
    Q_OBJECT
public:
    explicit InputHook(QObject *parent = nullptr);
    ~InputHook();

    void startHook();               // 启动钩子（模式 1）
    void stopHook();                // 停止钩子
    void registerHotkey(HWND hwnd); // 注册热键（模式 2）
    void unregisterHotkey(HWND hwnd);

    static int triggerMode;

signals:
    void translateTrigger();  // 模式 1：左键+右键触发信号

private:
    static LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam);

    static HHOOK mouseHook;
    static bool leftPressed;
    static InputHook *instance;

    static const int HOTKEY_ID = 0x1001;
};

#endif // INPUTHOOK_H
