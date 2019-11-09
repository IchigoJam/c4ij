#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	// ファイルの1番目だけ残して削除、ファイル復活にはIchigoJamのリブートが必要
	disable_irq();
	int sec = flash_blankCheck(6, 6) == IAPRESULT_CMD_SUCCESS ? 6 : 7;
	int res;
	int saved = sec == 7 ? 6 : 7;
	uint8_t buf[0x100];
	for (int i = 0; i < 4; i++) {
		memcpy(buf, (void*)(saved * 0x1000 + 0x100 * i), 0x100);
		flash_prepare(sec, sec);
		flash_copyRAMtoFlash((uint8_t*)(sec * 0x1000 + 0x100 * i), buf, 0x100); // 256byteだけ
	}
	// erase saved
	flash_prepare(saved, saved);
	res = flash_erase(saved, saved);

	enable_irq();
	return res;

	/*
	*/

	/*
	// erase sector5
	flash_prepare(5, 5);
	flash_erase(5, 5);
	*/

	/*
	// sector6を消すサンプル
	if (flash_blankCheck(6, 6) == IAPRESULT_SECTOR_NOT_BLANK) {
		flash_prepare(6, 6); // blankcheckせずにprepare呼ぶと固まる
		flash_erase(6, 6); //
		return 1;
	}
	*/

//	return sec;
}
