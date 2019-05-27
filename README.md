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
And U=USR(#700,0) to go!  

## Kawakudari example



## License

CC BY 4.0 http://ichigojam.net/  
