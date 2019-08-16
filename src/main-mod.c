#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, uint64_t (*divfunc)()) {
	return (int)(divfunc(param, 60) >> 32); // return param % 60;
}
