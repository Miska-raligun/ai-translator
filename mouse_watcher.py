from pynput import mouse
import pyperclip
import time
import sys

# 强制使用 xclip 作为剪贴板接口，避免掉进 Windows PowerShell 的坑
pyperclip.set_clipboard('xclip')

pressed = set()

def on_click(x, y, button, pressed_flag):
    if pressed_flag:
        pressed.add(button)
        if mouse.Button.left in pressed and mouse.Button.right in pressed:
            time.sleep(0.1)
            try:
                text = pyperclip.paste()
                print(f"[TRANSLATE_TRIGGER]{text}")
                sys.stdout.flush()
            except Exception as e:
                print(f"Clipboard Error: {e}")
                sys.stdout.flush()
    else:
        if button in pressed:
            pressed.remove(button)

with mouse.Listener(on_click=on_click) as listener:
    listener.join()

