typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned short uint16_t;
typedef short int16_t;

typedef void (*IJFUNC_P0)();
typedef void (*IJFUNC_P1)(uint32_t n);
typedef void (*IJFUNC_P1S)(const char* s);
typedef void (*IJFUNC_P2)(uint32_t x, uint32_t y);
typedef uint32_t (*IJFUNC_P0R)();
typedef uint32_t (*IJFUNC_P1R)(uint32_t n);
typedef uint32_t (*IJFUNC_P2R)(uint32_t x, uint32_t y);

#define rnd(n) ((IJFUNC_P1R)(void*)(uint32_t)*(uint16_t*)0xC0)((n))
#define sin(n) ((IJFUNC_P1R)(void*)(uint32_t)*(uint16_t*)0xC2)((n))
#define putc(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xC4)((n))
#define putnum(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xC6)((n))
#define putstr(p) ((IJFUNC_P1S)(void*)(uint32_t)*(uint16_t*)0xC6)((p))
#define inkey() ((IJFUNC_P0R)(void*)(uint32_t)*(uint16_t*)0xCA)()
#define cls() ((IJFUNC_P0)(void*)(uint32_t)*(uint16_t*)0xCC)()
#define locate(x, y) ((IJFUNC_P2)(void*)(uint32_t)*(uint16_t*)0xCE)((x), (y))
#define scr(x, y) ((IJFUNC_P2R)(void*)(uint32_t)*(uint16_t*)0xD0)((x), (y))
#define pset(x, y) ((IJFUNC_P2)(void*)(uint32_t)*(uint16_t*)0xD2)((x), (y))
#define scroll(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xD4)((n))
#define wait(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xD6)((n))
#define out(x, y) ((IJFUNC_P2)(void*)(uint32_t)*(uint16_t*)0xD8)((x), (y))
#define in() ((IJFUNC_P0R)(void*)(uint32_t)*(uint16_t*)0xDA)()
#define pwm(x, y, z) ((IJFUNC_P3)(void*)(uint32_t)*(uint16_t*)0xDC)((x), (y), (z))
#define ana() ((IJFUNC_P0R)(void*)(uint32_t)*(uint16_t*)0xDE)()
#define uputc(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xD6)((n))

#define KEY_LEFT 28
#define KEY_RIGHT 29
#define KEY_UP 30
#define KEY_DOWN 31
#define KEY_SPACE 32
