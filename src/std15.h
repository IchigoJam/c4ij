typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned long long uint64_t;
typedef long long  int64_t;

typedef void (*IJFUNC_P0)();
typedef void (*IJFUNC_P1)(uint32_t n);
typedef void (*IJFUNC_P1S)(const char* s);
typedef void (*IJFUNC_P2)(uint32_t x, uint32_t y);
typedef void (*IJFUNC_P3)(uint32_t x, uint32_t y, uint32_t z);
typedef uint32_t (*IJFUNC_P0R)();
typedef uint32_t (*IJFUNC_P1R)(uint32_t n);
typedef uint32_t (*IJFUNC_P2R)(uint32_t x, uint32_t y);
typedef uint32_t (*IJFUNC_P3R)(uint32_t x, uint32_t y, uint32_t z);
typedef void (*IJFUNC_MEMCLEAR)(uint8_t* dst, int len);
typedef void (*IJFUNC_MEMCPY)(uint8_t* dst, const uint8_t* src, int len);
typedef uint32_t (*IJFUNC_FLASH2)(uint32_t cmd, const uint8_t* src, uint8_t* dst, uint32_t len);
typedef void (*IJFUNC_WS_LED)(uint32_t countrepeat, const uint8_t* data, uint32_t gpiomask);

#define rnd(n) ((IJFUNC_P1R)(void*)(uint32_t)*(uint16_t*)0xC0)((n))
#define sin(n) ((IJFUNC_P1R)(void*)(uint32_t)*(uint16_t*)0xC2)((n))
#define putc(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xC4)((n))
#define putnum(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xC6)((n))
#define putstr(p) ((IJFUNC_P1S)(void*)(uint32_t)*(uint16_t*)0xC8)((p))
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
#define ana(n) ((IJFUNC_P1R)(void*)(uint32_t)*(uint16_t*)0xDE)((n))
#define uputc(n) ((IJFUNC_P1)(void*)(uint32_t)*(uint16_t*)0xE0)((n))
#define memclear(dst, len) ((IJFUNC_MEMCLEAR)(void*)(uint32_t)*(uint16_t*)0xE4)((dst), (len))
#define memcpy(dst, src, len) ((IJFUNC_MEMCPY)(void*)(uint32_t)*(uint16_t*)0xE6)((dst), (src), (len))
#define flash1(cmd, startsector, endsector) ((IJFUNC_P3R)(void*)(uint32_t)*(uint16_t*)0xE8)((cmd), (startsector), (endsector))
#define flash2(cmd, dst, src, len) ((IJFUNC_FLASH2)(void*)(uint32_t)*(uint16_t*)0xEA)((cmd), (src), (dst), (len))
#define ws_led(countrepeat, data, gpiomask) ((IJFUNC_WS_LED)(void*)(uint32_t)*(uint16_t*)0xEE)((countrepeat), (data), (gpiomask))

enum IAP_command {
	IAPCommand_Prepare_sector_for_write_operation = 50,
	IAPCommand_Copy_RAM_to_Flash,
	IAPCommand_Erase_sector,
	IAPCommand_Blank_check_sector,
	IAPCommand_Read_part_ID,
	IAPCommand_Read_Boot_Code_version,
	IAPCommand_Compare,
	IAPCommand_Reinvoke_ISP,
	IAPCommand_Read_UID,
	IAPCommand_Erase_page,
	IAPCommand_EEPROM_Write = 61,
	IAPCommand_EEPROM_Read,
};

enum IAP_result {
	IAPRESULT_CMD_SUCCESS = 0,
	IAPRESULT_INVALID_COMMAND,
	IAPRESULT_SRC_ADDR_ERROR,
	IAPRESULT_DST_ADDR_ERROR,
	IAPRESULT_SRC_ADDR_NOT_MAPPED, // = 4
	IAPRESULT_DST_ADDR_NOT_MAPPED,
	IAPRESULT_COUNT_ERROR,
	IAPRESULT_INVALID_SECTOR,
	IAPRESULT_SECTOR_NOT_BLANK, // = 8, blankCheck
	IAPRESULT_SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION, // 9 need prepare to erase
	IAPRESULT_COMPARE_ERROR,
	IAPRESULT_BUSY,
	IAPRESULT_PARAM_ERROR,
	IAPRESULT_ADDR_ERROR,
	IAPRESULT_ADDR_NOT_MAPPED,
	IAPRESULT_CMD_LOCKED,
	IAPRESULT_INVALID_CODE,
	IAPRESULT_INVALID_BAUD_RATE,
	IAPRESULT_INVALID_STOP_BIT,
	IAPRESULT_CODE_READ_PROTECTION_ENABLED,
};

static inline void enable_irq()		{ __asm volatile ("cpsie i"); }
static inline void disable_irq()	{ __asm volatile ("cpsid i"); }

#define flash_blankCheck(start, end) flash1(IAPCommand_Blank_check_sector, start, end)
#define flash_prepare(start, end) flash1(IAPCommand_Prepare_sector_for_write_operation, start, end)
#define flash_erase(start, end) flash1(IAPCommand_Erase_sector, start, end)
#define flash_copyRAMtoFlash(flash, ram, size) flash2(IAPCommand_Copy_RAM_to_Flash, flash, ram, size)
#define flash_compare(flash, ram, size) flash2(IAPCommand_Compare, flash, ram, size)

#define LEFT 28
#define RIGHT 29
#define UP 30
#define DOWN 31
#define SPACE 32

#define GPIO1 0x50010000
#define GPIO_OUT1	(GPIO1 + (1 << (0 + 2))) // OUT1 = 0x50010004
#define GPIO_OUT2	(GPIO1 + (1 << (1 + 2)))
#define GPIO_OUT3	(GPIO1 + (1 << (2 + 2)))
#define GPIO_OUT4	(GPIO1 + (1 << (3 + 2)))
#define GPIO_LED	(GPIO1 + (1 << (5 + 2))) // LED
