# 🌍 Qt Translator Tool

一个基于 Qt6 开发的跨平台桌面翻译应用，支持自动识别语言并翻译为中文。用户只需在任意应用中选中一段文本，并通过鼠标“左键选中 + 同时按下右键”的操作，即可自动触发翻译，轻松快捷，免去繁琐的复制粘贴。

几乎完全使用chatgpt完成。

---

## ✨ 功能亮点

- 🧠 **自动识别语言**：支持英文、日文、韩文等多种语言输入，自动翻译为简体中文
- 🖱️ **鼠标手势触发翻译**：左键选中 + 同时右键，快速触发翻译操作
- 📋 **自动复制选中文本**：输入框中选中即自动复制，便于监听器统一处理
- 🔗 **兼容 OpenAI 风格翻译接口**：支持如 DeepSeek、ChatGPT 等 API
- 🪟 **简洁双栏 UI**：上栏为原文，下栏为翻译结果，界面干净，操作直观
- 🖥️ **支持多平台运行**：WSL、原生 Linux、Windows 全平台兼容

---

## 📁 项目结构

```
translator/
├── main.cpp                         # 主程序入口
├── mainwindow.{h,cpp,ui}           # 主窗口界面与逻辑
├── openai_translator.{h,cpp}       # 封装的翻译调用类
├── mytextedit.{h,cpp}              # 自定义 QTextEdit，屏蔽默认右键菜单
├── mouse_watcher.py                # Python 鼠标监听器
├── run_translator.sh               # WSL/Linux 一键启动脚本
├── install_dependencies.sh         # 安装依赖脚本（Linux）
├── translator.pro                  # Qt 工程文件
```

---

## ⚙️ 安装依赖（Linux / WSL）

推荐使用以下脚本自动安装所有依赖：

```bash
bash install_dependencies.sh
```

或手动安装：

```bash
sudo apt update
sudo apt install -y qt6-base-dev qt6-tools-dev-tools qt6-tools-dev python3 python3-pip xclip
pip3 install --user pynput pyperclip
```

---

## 🚀 构建与运行（Linux）

```bash
qmake6
make
./translator
```

或使用脚本自动运行（含监听器）：

```bash
./run_translator.sh
```

---

## 🐍 鼠标监听器说明

项目中的 `mouse_watcher.py` 使用 `pynput` 监听鼠标事件，配合 `pyperclip` 获取剪贴板内容：

- 鼠标左键选中文本 → 自动复制到剪贴板
- 同时按下右键 → 启动监听器读取内容 → Qt 应用自动粘贴并触发翻译

监听器作为子进程由 Qt 自动启动，无需手动运行。

---

## 🔑 配置翻译 API

在 `MainWindow` 构造函数中设置：

```cpp
translator->setApiKey("你的 API 密钥");
translator->setApiUrl("https://api.deepseek.com/v1/chat/completions"); // 示例接口
```

你可使用兼容 OpenAI API 的服务（如 DeepSeek、OpenRouter、MoonShot 等）。

---

## 📄 License

MIT License - 欢迎学习与使用，禁止滥用他人 API 密钥。

---

## 🤝 联系与贡献

如果你喜欢这个项目，欢迎 ⭐Star、Fork 或提交 Pull Request。  
欢迎提出功能建议或 Bug 反馈，一起完善这个轻量好用的桌面翻译工具 😄

