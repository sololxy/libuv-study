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


#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

int main() {
    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    printf("Now quitting.\n");
    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);
    return 0;
}
