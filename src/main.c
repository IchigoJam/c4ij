#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	cls();
	int x = 15;
	int score = 0;
	for (;;) {
		locate(x, 5);
		putc(236);
		locate(rnd(32), 23);
		putc('*');
		putc(10);
		wait(3);
		
		int c = inkey();
		if (c == LEFT)
			x--;
		if (c == RIGHT)
			x++;
		if (scr(x, 5))
			break;
		score++;
	}
	return score;
}
