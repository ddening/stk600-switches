#ifndef SWITCHES_H_
#define SWITCHES_H_

#include <avr/io.h>

/* SPI Port Declaration */
#if defined(__AVR_ATmega1284P__)
#   define EXT_INT_PORT PORTD
#   define EXT_INT_DDR DDRD
#   define SWITCH00 0x00
#   define SWITCH01 0x01
# elif defined(__AVR_ATmega2560__)
#   define EXT_INT_PORT PORTD
#   define EXT_INT_DDR DDRD
#   define SWITCH00 0x00
#   define SWITCH01 0x01
#   define SWITCH02 0x02
#   define SWITCH03 0x03
#else
#  if !defined(__COMPILING_AVR_LIBC__)
#    warning "Microcontroller not defined."
#  endif
#endif

void switch_init( void );

#endif /* SWITCHES_H_ */