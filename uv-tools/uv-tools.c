/** Copyright luoxiangyong. E-mail: solo_lxy@126.com
 * 
 * 学习libnv的测试程序，使用nodejs代码库中的libuv源码编译后测试。nodejs代码取之
 * 这里:https://github.com/nodejs/node ,我使用的是nodejs-8.x。
 *
 * 工程管理使用CMake(http://www.cmake.org)。
 *
 * libuv的教程参考：http://luohaha.github.io/Chinese-uvbook
 */

// 包含标准库文件
#include <stdio.h>

// 包含第三方库文件
#include <uv.h>

// 包含本项目的文件
// ..

uv_loop_t *loop;
uv_tty_t tty;


int wmain(int argc, wchar_t *wargv[]) {
    printf("libuv auxi tools test...\n");
    
	loop = uv_default_loop();
	uv_tty_init(loop, &tty, 1, 0);
	uv_tty_set_mode(&tty, UV_TTY_MODE_NORMAL);

	if (uv_guess_handle(1) == UV_TTY) {
		uv_write_t req;
		uv_buf_t buf;
		buf.base = "\033[41;37m";
		buf.len = strlen(buf.base);
		uv_write(&req, (uv_stream_t*)&tty, &buf, 1, NULL);
	}

	uv_write_t req;
	uv_buf_t buf;
	buf.base = "Hello TTY\n";
	buf.len = strlen(buf.base);
	uv_write(&req, (uv_stream_t*)&tty, &buf, 1, NULL);
	uv_tty_reset_mode();
	
	return uv_run(loop, UV_RUN_DEFAULT);
}
