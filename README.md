# 这个项目代码质量极差，已被弃用。

## 简介

基于 [LemonLime](https://github.com/Project-LemonLime/Project_LemonLime) 的仿 NOI 加密自测系统。仅支持 Linux，NOI Linux 2.0 可用。

加密方法：将文件改名为 secret 然带密码后压缩到 zip 文件，改名为 .in/ans/out/cdf 之后使用，加密比赛配置文件与输入输出文件。checker 与交互库不加密。详见 demo。

密码为 src/core/decrypt.h 内名为 LEMON_KEY 的宏。

## 功能

- 隐藏了较多功能，保留核心评测功能；
- 比赛配置文件，设置文件只读；
- 比赛配置文件与数据文件加密；
- 修改图标；
- 变成深色；
- 修改标题。
