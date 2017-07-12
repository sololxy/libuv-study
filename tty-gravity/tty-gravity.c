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


// 本项目中看起来像天书一样的字符常量可以参考tty控制相关材料，也可以参考ncurses
// 站点上的介绍：http://www.gnu.org/software/ncurses/ncurses.html


uv_loop_t *loop;
uv_tty_t tty;
uv_timer_t tick;
uv_write_t write_req;
int width, height;
int pos = 0;
char *message = "  Hello TTY  ";

void update(uv_timer_t *req) {
	char data[500];

	uv_buf_t buf;
	buf.base = data;
	buf.len = sprintf(data, "\033[2J\033[H\033[%dB\033[%luC\033[42;37m%s",
		pos,
		(unsigned long)(width - strlen(message)) / 2,
		message);
	uv_write(&write_req, (uv_stream_t*)&tty, &buf, 1, NULL);

	pos++;
	if (pos > height) {
		uv_tty_reset_mode();
		uv_timer_stop(&tick);
	}
}

int main() {
	loop = uv_default_loop();

	uv_tty_init(loop, &tty, 1, 0);
	uv_tty_set_mode(&tty, 0);

	if (uv_tty_get_winsize(&tty, &width, &height)) {
		fprintf(stderr, "Could not get TTY information\n");
		uv_tty_reset_mode();
		return 1;
	}

	fprintf(stderr, "Width %d, height %d\n", width, height);
	uv_timer_init(loop, &tick);
	uv_timer_start(&tick, update, 200, 200);
	return uv_run(loop, UV_RUN_DEFAULT);
}
