#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	int res;
	uint8_t buf[0x100];

	// change flash!
	disable_irq();
	int sec = flash_blankCheck(6, 6) == IAPRESULT_CMD_SUCCESS ? 6 : 7;
	const int sec5 = 5;
	
	// copy sec5 + newdata -> sec
	for (int i = 0; i < 16; i++) {
		if (i == 15) { // only PCG
			memcpy(buf, (uint8_t*)(ram + 0x700), 0x100);
		} else {
			memcpy(buf, (uint8_t*)(sec5 * 0x1000 + 0x100 * i), 0x100);
		}
		flash_prepare(sec, sec);
		flash_copyRAMtoFlash((uint8_t*)(sec * 0x1000 + 0x100 * i), buf, 0x100); // 256byteずつ
	}

	// erase sector5
	flash_prepare(sec5, sec5);
	flash_erase(sec5, sec5);

	// copy sec -> sector5
	for (int i = 0; i < 16; i++) {
		memcpy(buf, (void*)(sec * 0x1000 + 0x100 * i), 0x100);
		flash_prepare(sec5, sec5);
		flash_copyRAMtoFlash((uint8_t*)(sec5 * 0x1000 + 0x100 * i), buf, 0x100); // 256byteずつ
	}

	// erase sec
	flash_prepare(sec, sec);
	res = flash_erase(sec, sec);

	enable_irq();
	return res;
}
