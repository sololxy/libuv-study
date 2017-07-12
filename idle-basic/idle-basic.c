/** Copyright luoxiangyong. E-mail: solo_lxy@126.com
 *
 * 学习libnv的测试程序，使用nodejs代码库中的libuv源码编译后测试。nodejs代码取之
 * 这里:https://github.com/nodejs/node ,我使用的是nodejs-8.x。
 *
 * 工程管理使用CMake(https://www.cmake.org)。
 *
 * libuv的教程参考：http://luohaha.github.io/Chinese-uvbook
 */

// 包含标准库文件
#include <stdio.h>

// 包含第三方库文件
#include <uv.h>

// 包含本项目的文件
// ..

int64_t counter = 0;

void wait_for_a_while(uv_idle_t* handle) {
    counter++;

    printf("%d ", counter);

    if (counter >= 1000)
        uv_idle_stop(handle);
}

int main() {
    uv_idle_t idler;

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    printf("Idling...\n");
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_loop_close(uv_default_loop());
    return 0;
}
