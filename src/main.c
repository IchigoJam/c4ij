#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	cls();
	int x = 15;
	for (;;) {
		locate(x, 5);
		putc('O');
		locate(rnd(32), 23);
		putc('*');
		putc(10);
		wait(3);
		
		int c = inkey();
		if (c == KEY_LEFT)
			x--;
		if (c == KEY_RIGHT)
			x++;
		if (scr(x, 5))
			break;
	}
	return x;
}
