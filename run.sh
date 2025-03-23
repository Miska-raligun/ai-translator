#!/bin/bash

# 脚本所在目录（确保无论在哪运行都能找到 mouse_watcher.py 和 translator）
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# 激活 Python 虚拟环境
source translator_env/bin/activate

# 启动鼠标监听器（后台运行）
echo "🖱️  启动鼠标监听器..."
python3 mouse_watcher.py > mouse_output.log 2>&1 &
WATCHER_PID=$!

# 启动 Qt 程序
echo "🚀 启动翻译工具..."
./translator

# 当 Qt 程序关闭后，自动杀掉监听器
echo "🛑  关闭监听器 (PID: $WATCHER_PID)..."
kill $WATCHER_PID
