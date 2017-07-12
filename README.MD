![solo-studio](https://github.com/sololxy/solo-word-count/blob/master/img/solo-studio.png)

Copyright luoxiangyong.

E-mail: solo_lxy@126.com

本项目是学习libuv的源码及相关资料的,libuv的源码和编译方式直接使用nodejs v8.x版本。

# nodejs v8.x下载编译（windows)
1. 到 https://github.com/nodejs/node下载nodejs-8.x 的代码
2. 安装[Microsoft Visual Studio 2017(社区版还是免费的)](https://www.visualstudio.com/zh-hans/thank-you-downloading-visual-studio/?sku=Community&rel=15)
3. cd /path/to/nodejs-8 && vcbuild.bat vs2017 release

编译成功的文件在/path/to/nodejs-8/[Relase| Debug]文件夹下。

# 安装CMake
地址：https://www.cmake.org v3.9

# 测试libuv代码

1. git clone https://github.com/sololxy/libuv-study.github
2. cd /path/to/libuv-study && cmake
3. enjoying ;)
