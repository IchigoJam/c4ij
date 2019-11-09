#include <std15.h>

// wirte to #E00 on IchigoJam
static const uint8_t PS2_KB_MAP_JP[] = {
0x01,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x71,0x31,0x20,0x20,0x20,0x7a,0x73,0x61,0x77,0x32,0x20,0x20,0x63,0x78,0x64,0x65,0x34,0x33,0x20,0x20,0x20,0x76,0x66,0x74,0x72,0x35,0x20,0x20,0x6e,0x62,0x68,0x67,0x79,0x36,0x20,0x20,0x20,0x6d,0x6a,0x75,0x37,0x38,0x20,0x20,0x2c,0x6b,0x69,0x6f,0x30,0x39,0x20,0x20,0x2e,0x2f,0x6c,0x3b,0x70,0x2d,0x20,0x20,0x5c,0x3a,0x20,0x40,0x5e,0x20,0x20,0x20,0x20,0x0a,0x5b,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x08,0x20,0x20,0x31,0x5c,0x34,0x37,0x20,0x20,0x20,0x30,0x2e,0x32,0x35,0x36,0x38,0x1b,0x20,0x20,0x2b,0x33,0x2d,0x2a,0x39,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x51,0x21,0x20,0x20,0x20,0x5a,0x53,0x41,0x57,0x22,0x20,0x20,0x43,0x58,0x44,0x45,0x24,0x23,0x20,0x20,0x20,0x56,0x46,0x54,0x52,0x25,0x20,0x20,0x4e,0x42,0x48,0x47,0x59,0x26,0x20,0x20,0x20,0x4d,0x4a,0x55,0x27,0x28,0x20,0x20,0x3c,0x4b,0x49,0x4f,0x30,0x29,0x20,0x20,0x3e,0x3f,0x4c,0x2b,0x50,0x3d,0x20,0x20,0x5f,0x2a,0x20,0x60,0x7e,0x20,0x20,0x20,0x20,0x0a,0x7b,0x20,0x7d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x08,0x20,0x20,0x31,0x7c,0x34,0x37,0x20,0x20,0x20,0x30,0x2e,0x32,0x35,0x36,0x38,0x1b,0x20,0x20,0x2b,0x33,0x2d,0x2a,0x39,0x00,
};
// write to #F00 on IchigoJam
static const uint8_t PS2_KB_MAP_US[] = {
0x00,0x00,0x60,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x60,0x20,0x20,0x20,0x20,0x20,0x20,0x71,0x31,0x20,0x20,0x20,0x7a,0x73,0x61,0x77,0x32,0x20,0x20,0x63,0x78,0x64,0x65,0x34,0x33,0x20,0x20,0x20,0x76,0x66,0x74,0x72,0x35,0x20,0x20,0x6e,0x62,0x68,0x67,0x79,0x36,0x20,0x20,0x20,0x6d,0x6a,0x75,0x37,0x38,0x20,0x20,0x2c,0x6b,0x69,0x6f,0x30,0x39,0x20,0x20,0x2e,0x2f,0x6c,0x3b,0x70,0x2d,0x20,0x20,0x5c,0x27,0x20,0x5b,0x3d,0x20,0x20,0x20,0x20,0x0a,0x5d,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x08,0x20,0x20,0x31,0x20,0x34,0x37,0x20,0x20,0x20,0x30,0x2e,0x32,0x35,0x36,0x38,0x20,0x20,0x20,0x2b,0x33,0x2d,0x2a,0x39,0x00,0x7e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7e,0x20,0x20,0x20,0x20,0x20,0x20,0x51,0x21,0x20,0x20,0x20,0x5a,0x53,0x41,0x57,0x40,0x20,0x20,0x43,0x58,0x44,0x45,0x24,0x23,0x20,0x20,0x20,0x56,0x46,0x54,0x52,0x25,0x20,0x20,0x4e,0x42,0x48,0x47,0x59,0x5e,0x20,0x20,0x20,0x4d,0x4a,0x55,0x26,0x2a,0x20,0x20,0x3c,0x4b,0x49,0x4f,0x29,0x28,0x20,0x20,0x3e,0x3f,0x4c,0x3a,0x50,0x5f,0x20,0x20,0x5f,0x22,0x20,0x7b,0x2b,0x20,0x20,0x20,0x20,0x0a,0x7d,0x20,0x7c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x08,0x20,0x20,0x31,0x20,0x34,0x37,0x20,0x20,0x20,0x30,0x2e,0x32,0x35,0x36,0x38,0x20,0x20,0x20,0x2b,0x33,0x2d,0x2a,0x39,0x00,
};

/*
./bin2bas --startaddress 3328 --nolineno obj/c4ij.bin
POKE#D00 ...
*/

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	const int sec5 = 5; // last sector of IchigoJam OS
	const int keymap = 7;

	// param #E00 or #F00
	param = (*(uint8_t*)(sec5 * 0x1000 + 0x100 * keymap) + 0xe) * 0x100;

	int res;
	uint8_t buf[0x100];

	// PS/2キーボードマップ変更
	disable_irq();
	int sec = flash_blankCheck(6, 6) == IAPRESULT_CMD_SUCCESS ? 6 : 7;
	
	// erase buffer
	//flash_prepare(sec, sec);
	//flash_erase(sec, sec);

	// copy sec5 + newps2map -> sec
	for (int i = 0; i < 16; i++) {
//		const uint8_t* src;
		if (i == keymap) { // keymap のみ変更
//			src = PS2_KB_MAP_US;
			//memcpy(buf, (void*)PS2_KB_MAP_US, 0x100);
			//memcpy(buf, PS2_KB_MAP_JP, 0x100);
			//memcpy(buf, (uint8_t*)(ram + 0xf00), 0x100);
			memcpy(buf, (uint8_t*)(ram + param), 0x100);
		} else {
			memcpy(buf, (uint8_t*)(sec5 * 0x1000 + 0x100 * i), 0x100);
//			src = buf;
		}
		flash_prepare(sec, sec);
//		flash_copyRAMtoFlash((uint8_t*)(sec * 0x1000 + 0x100 * i), src, 0x100); // 256byteずつ
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
	return param;
}
