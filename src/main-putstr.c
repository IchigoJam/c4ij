#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, uint64_t (*divfunc)()) {
	putstr("aaaaaaaa\n");
	return 0;
}
