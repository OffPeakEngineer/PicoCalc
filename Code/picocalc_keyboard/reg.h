#ifndef REG_H
#define REG_H

#include <stdbool.h>
#include <stdint.h>

enum reg_id
{
  REG_ID_VER = 0x01, // fw version
  REG_ID_CFG = 0x02, // config
  REG_ID_INT = 0x03, // interrupt status
  REG_ID_KEY = 0x04, // key status
  REG_ID_BKL = 0x05, // backlight
  REG_ID_DEB = 0x06, // debounce cfg
  REG_ID_FRQ = 0x07, // poll freq cfg
  REG_ID_RST = 0x08, // reset
  REG_ID_FIF = 0x09, // fifo
  REG_ID_BK2 = 0x0A, //keyboard backlight
  REG_ID_BAT = 0x0b,// battery
  REG_ID_C64_MTX = 0x0c,// read c64 matrix
  REG_ID_C64_JS = 0x0d, // joystick io bits
  REG_ID_LAST,
};

#define CFG_OVERFLOW_ON   (1 << 0) //When a FIFO overflow happens, should the new entry still be pushed, overwriting the oldest one. If 0 then new entry is lost.
#define CFG_OVERFLOW_INT  (1 << 1) //Should an interrupt be generated when a FIFO overflow happens
#define CFG_CAPSLOCK_INT  (1 << 2) //Should an interrupt be generated when Caps Lock is toggled.
#define CFG_NUMLOCK_INT   (1 << 3) //Should an interrupt be generated when Num Lock is toggled.
#define CFG_KEY_INT     (1 << 4)
#define CFG_PANIC_INT   (1 << 5)
#define CFG_REPORT_MODS   (1 << 6) // Should Alt, Sym and Shifts be reported as well
#define CFG_USE_MODS    (1 << 7) // Should Alt, Sym and Shifts modify the keys reported
// CFG_STICKY_MODS // Pressing and releasing a mod affects next key pressed

#define INT_OVERFLOW    (1 << 0)
#define INT_CAPSLOCK    (1 << 1)
#define INT_NUMLOCK     (1 << 2)
#define INT_KEY       (1 << 3)
#define INT_PANIC     (1 << 4)

#define KEY_CAPSLOCK    (1 << 5)
#define KEY_NUMLOCK     (1 << 6)
#define KEY_COUNT_MASK    0x1F  //0x1F == 31

#define VER_VAL       ((VERSION_MAJOR << 4) | (VERSION_MINOR << 0))

#define WRITE_MASK (1<<7)

uint8_t reg_get_value(enum reg_id reg);
void reg_set_value(enum reg_id reg, uint8_t value);
bool reg_is_bit_set(enum reg_id reg, uint8_t bit);
void reg_set_bit(enum reg_id reg, uint8_t bit);
void reg_init(void);

#endif
