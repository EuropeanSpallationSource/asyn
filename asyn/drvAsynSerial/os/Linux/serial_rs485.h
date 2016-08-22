#ifndef SERIAL_RS485
#define SERIAL_RS485

#include <sys/ioctl.h>
#include <linux/serial.h>

#define TIOCGRS485      0x542E
#define TIOCSRS485      0x542F

/* Older Linux systems don't support RS485. 
 * Test for this by seeing if serial.h defined SER_RS485_ENABLED */
#ifdef SER_RS485_ENABLED
  #define ASYN_RS485_SUPPORTED      1
#else
  #define SER_RS485_ENABLED         0x1
  #define SER_RS485_RTS_ON_SEND     0x2
  #define SER_RS485_RTS_AFTER_SEND  0x4
  struct serial_rs485 {
    epicsUInt32 flags;
    epicsUInt32 delay_rts_before_send;
    epicsUInt32 delay_rts_after_send;
    epicsUInt32 padding[5]; /* reserved, must be 0 */

    xx
  };
#endif

#endif

