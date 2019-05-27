# C_for_IchigoJam

c4ij - C language for IchigoJam!

Let's make BASIC program in C language on your PC!  
This tool provide to convert IchigoJam BASIC to bin file.  

## Minimum example

```
#include <std15.h>  

__attribute__ ((section(".main")))  
int main(int param, int ram, int rom, int (*divfunc)()) {  
	return rnd(x);  
}  
```

## How to use

Edit src/main.c  
Check commands with src/std15.h  

```
$ make  
```

Send POKE commands to IchigoJam. (main.bas)  
And ?USR(#700,0) to go!  

## Kawakudari example

```
#include <std15.h>

__attribute__ ((section(".main")))
int main(int param, int ram, int rom, int (*divfunc)()) {
	cls();
	int x = 15;
	for (;;) {
		locate(x, 5);
		putc('O');
		locate(rnd(32), 23);
		putc('*');
		putc(10);
		wait(3);
		
		int c = inkey();
		if (c == KEY_LEFT)
			x--;
		if (c == KEY_RIGHT)
			x++;
		if (scr(x, 5))
			break;
	}
	return x;
}
```

## License

CC BY 4.0 http://ichigojam.net/  
