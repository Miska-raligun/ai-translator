#!/bin/bash

echo "🔧 正在更新系统软件包索引..."
sudo apt update

echo "📦 安装 Qt6 编译环境和基础组件..."
sudo apt install -y qt6-base-dev qt6-tools-dev-tools qt6-tools-dev

echo "🐍 安装 Python3 和所需模块..."
sudo apt install -y python3 python3-pip

echo "🔌 安装剪贴板支持（xclip）..."
sudo apt install -y xclip

echo "🐍 安装 Python 包 pynput + pyperclip..."
pip3 install --user pynput pyperclip

echo "✅ 所有依赖安装完成！"

echo "📌 接下来你可以执行以下命令构建项目："
echo "    qmake6"
echo "    make"
echo "    ./translator"
