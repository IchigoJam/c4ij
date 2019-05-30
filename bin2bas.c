#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int err() {
	printf("bin2bas {--offset n} {--nolineno} {--startaddress n} [bin file]\n");
	exit(1);
	return 1;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		err();
	}

	int offset = 0;
	int nolineno = 0;
	int startaddress = 0x700;
	const char* fnbin = NULL;
	for (int i = 1; i < argc; i++) {
		const char* p = argv[i];
		if (*p == '-') {
			if (strcmp(p, "--offset") == 0) {
				if (i + 1 >= argc) {
					return err();
				}
				offset = atol(argv[++i]);
			}
			if (strcmp(p, "--nolineno") == 0) {
				nolineno = 1;
			}
			if (strcmp(p, "--startaddress") == 0) {
				if (i + 1 >= argc) {
					return err();
				}
				startaddress = atol(argv[++i]);
			}
		} else {
			fnbin = p;
		}
	}
	if (fnbin == NULL) {
		return err();
	}

	FILE* fp = fopen(fnbin, "rb");
	if (!fp) {
		printf("can't open file\n");
		return 1;
	}
	for (int i = 0; i < offset; i++) {
		int n = fgetc(fp);
		if (n == EOF) {
			return 0;
		}
	}

	char buf[30];
	int address = startaddress;
	int first = 1;
	int line = 10;
	for (;;) {
		int n = fgetc(fp);
		if (n == EOF)
			break;
		if (address % 32 == 0 || first) {
			first = 0;
			if (nolineno) {
				printf("\nPOKE#%03X", address);
			} else {
				printf("\n%d POKE#%03X", line, address);
			}
			line += 10;
		}
		address++;
		printf(",%d", n);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
