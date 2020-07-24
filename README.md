# C for IchigoJam

c4ij - C language for IchigoJam!

Let's make programs with C language on your PC!  
This tool provide to convert IchigoJam BASIC to bin file.  
* Only IchigoJam 1.4b9 or higher for LPC1114  

see also  
https://fukuno.jig.jp/2580  

## Minimum example

```
#include <std15.h>  

__attribute__ ((section(".main")))  
int main(int param, int ram, int rom, uint64_t (*divfunc)()) {  
	return rnd(x);  
}  
```

## How to use

In the beginning. Edit settings on Makefile for your environment.  

There are 2 methods  
 1. bin file to POKE commands. max 512byte  
 2. pack the bin file to wirte to Flash. max 3kbyte or 7kbyte  

Edit src/main.c  
Check commands with src/std15.h  
* warning! const resource can't use only 7kbyte flash mode  

```
$ make poke
```

Send POKE commands to IchigoJam. (main.bas)  
And ?USR(#700,0) to go!  

```
$ make write
```

Run on your IchigoJam rapidly!


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
