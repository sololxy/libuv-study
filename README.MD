![solo-studio](https://github.com/sololxy/solo-word-count/blob/master/img/solo-studio.png)

Copyright luoxiangyong.

E-mail: solo_lxy@126.com

[libuv](http://libuv.org)是 Node 的新跨平台抽象层，用于抽象 Windows 的 IOCP 及 Unix
的libev。作者打算在这个库的包含所有平台的差异性。

代码在：https://github.com/libuv/libuv

文档在：http://docs.libuv.org/en/v1.x/

**特性：**

- 非阻塞 TCP 套接字
- 非阻塞命名管道
- UDP
- 定时器
- 子进程生成
- 通过 uv_getaddrinfo 实现异步 DNS
- 异步文件系统 API：uv_fs_* 高分辨率时间：uv_hrtime
- 正在运行程序路径查找：uv_exepath
- 线程池调度：uv_queue_work
- TTY控制的ANSI转义代码: uv_tty_t
- 文件系统事件现在支持 inotify, ReadDirectoryChangesW 和 kqueue
- 进程间的 IPC 与套接字共享：uv_write2

**已受支持的平台：**
- Microsoft Windows 操作系统，如 Windows XP SP2。使用 Visual Studio 或 MinGW 构建
- Linux  使用 GCC 工具链
- MacOS 使用 GCC 或 XCode 工具链
- Solaris 121 或之后版本，使用 GCC 工具链

本项目是学习libuv的源码及相关资料的,libuv的源码和编译方式直接使用nodejs v8.x版本。

# 环境准备

## Window

### nodejs v8.x下载编译（windows)
1. 到 https://github.com/nodejs/node下载nodejs-8.x 的代码
2. 安装[Microsoft Visual Studio 2017(社区版还是免费的)](https://www.visualstudio.com/zh-hans/thank-you-downloading-visual-studio/?sku=Community&rel=15)
3. cd /path/to/nodejs-8 && vcbuild.bat vs2017 release

编译成功的文件在/path/to/nodejs-8/[Relase| Debug]文件夹下。


## MinGW64
> pacman -S mingw-w64-x86_64-libuv # 安装libuv开发库


# 安装CMake
地址：https://www.cmake.org v3.9

# 测试libuv代码

1. git clone https://github.com/sololxy/libuv-study.github
2. cd /path/to/libuv-study && cmake
3. enjoying ;)
