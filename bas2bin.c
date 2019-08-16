// IchigoJam BASIC txt -> bin (1024B) 
// license: CC BY http://ichigojam.net/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNumber(char* s) {
	char c = *s;
	s++;
	if (c >= '0' && c <= '9') { // number
		int value = 0;
		for (;;) {
			value = value * 10 + (c - '0');
			c = *s;
			s++;
			if (c < '0' || c > '9')
				break;
		}
		return value;
	} else {
		return -1;
	}
}
void deleteEnter(char* s) {
	for (;;) {
		if (*s == 0)
			break;
		if (*s == '\r' || *s == '\n') {
			*s = 0;
			return;
		}
		s++;
	}
}
char* getBody(char* s) {
	for (;;) {
		char c = *s;
		if (c == ' ') {
			return s + 1;
		}
		if (c == 0)
			return 0;
		s++;
	}
}

int file_length(char* fn) {
	FILE* fp = fopen(fn, "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fclose(fp);
	return size;
}

void err() {
	printf("bas2bin {--nopadding --limit4k } [bas file] [bin file]\n");
	exit(1);
}
int main(int argc, char** argv) {
	if (argc < 3) {
		err();
	}

	int padding = 1;
	int limit = 1024;
	const char* fnbas = NULL;
	const char* fnbin = NULL;
	for (int i = 1; i < argc; i++) {
		const char* p = argv[i];
		if (*p == '-') {
			if (strcmp(p, "--nopadding") == 0) {
				padding = 0;
			} else if (strcmp(p, "--limit4k") == 0) {
				limit = 4096;
			}
		} else {
			if (fnbas == NULL) {
				fnbas = p;
			} else if (fnbin == NULL) {
				fnbin = p;
			}
		}
	}
	if (fnbas == NULL || fnbin == NULL) {
		err();
	}
//	printf("%s %s %d %d\n", fnbas, fnbin, padding, limit);
	
	FILE* in = fopen(fnbas, "rb");
	FILE* out = fopen(fnbin, "wb");
	char line[256];
	int blen = 0;
	for (;;) {
		if (!fgets(line, 256, in)) {
			break;
		}
		deleteEnter(line);
		if (!strlen(line)) {
			continue;
		}
		int num = getNumber(line);
		if (num <= 0) {
			printf("error: %s\n", line);
			return 1;
		}
		char* body = getBody(line);
		int len = strlen(body);
		int align = len & 1; // align 2byte
		
		putc(num & 0xff, out); // num
		putc(num >> 8, out);
		putc(len + align, out); // len
		fputs(body, out); // body
		putc(0, out);
		if (align)
			putc(0, out);
		blen += 3 + len + align + 1;
		
		printf("%d %s\n", num, body);
	}
	fclose(in);
	
	if (blen > limit) {
		fclose(out);
		printf("over %d (size = %d)\n", limit, blen);
		return 1;
	}
	if (padding) {
		for (int i = 0; i < limit - blen; i++) {
			putc(0, out);
		}
	}

	fclose(out);
	return 0;
}
