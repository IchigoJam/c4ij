#include <std15.h>

/*
100 @HSV2RGB:R=V:G=V:B=V:IF S=0 RTN
110 D=H/60%6:C=V-(59-H%60)*V/60*S/100:E=V-H%60*V/60*S/100:F=V*(100-S)/100
120 IF!DG=C:B=F
130 IFD=1R=E:B=F
140 IFD=2R=F:B=C
150 IFD=3R=F:G=E
160 IFD=4R=C:G=F
170 IFD=5G=F:B=E
180 RTN
*/
void hsv2rgb(int h, int s, int v, uint8_t* grb, uint64_t (*divfunc)()) {
	int r = v, g = v, b = v;
	if (s == 0)
		return;
	int d = divfunc((uint32_t)divfunc(h, 60), 6) >> 32;
	int hmod60 = divfunc(h, 60) >> 32;
	int c = v - (uint32_t)divfunc((59 - hmod60) * v * s, 6000);
	int e = v - (uint32_t)divfunc(hmod60 * v * s, 6000);
	int f = (uint32_t)divfunc(v * (100 - s), 100);
	if (d == 0) {
		g = c;
		b = f;
	} else if (d == 1) {
		r = e;
		b = f;
	} else if (d == 2) {
		r = f;
		b = c;
	} else if (d == 3) {
		r = f;
		g = e;
	} else if (d == 4) {
		r = c;
		g = f;
	} else {
		g = f;
		b = e;
	}
	grb[0] = g;
	grb[1] = r;
	grb[2] = b;
}

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, uint64_t (*divfunc)()) {
	const int v = 50;
	const int n = 20;
	uint8_t* grb = (uint8_t*)(ram + 0x800);
	int h = 0;
	for (;;) {
		for (int i = 0; i < n; i++) {
			hsv2rgb(h + i * 5, 100, v, grb + i * 3, divfunc);
		}
		ws_led(3 * n, grb, GPIO_OUT1);
		if (inkey() == 27)
			break;
		h++;
	}
	return 0;
}
