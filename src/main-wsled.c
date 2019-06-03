#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	ws_led(GPIO1_0, ram + 0x700, param * 3, 1);
	return param;
}
