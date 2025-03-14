/*************************************************************************
* Title		: switches.h
* Author	: Dimitri Dening
* Created	: 11.04.2023
* Software	: Microchip Studio V7
* Hardware	: Atmega2560, STK600
* License	: MIT License
* Usage		: see Doxygen manual
*
*       Copyright (C) 2023 Dimitri Dening
*
*       Permission is hereby granted, free of charge, to any person obtaining a copy
*       of this software and associated documentation files (the "Software"), to deal
*       in the Software without restriction, including without limitation the rights
*       to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*       copies of the Software, and to permit persons to whom the Software is
*       furnished to do so, subject to the following conditions:
*
*       The above copyright notice and this permission notice shall be included in all
*       copies or substantial portions of the Software.
*
*       THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*       IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*       FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*       AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*       LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*       OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*       SOFTWARE.
*
*************************************************************************/

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
//#   define SWITCH00 0x00
//#   define SWITCH01 0x01
#   define SWITCH02 0x02
#   define SWITCH03 0x03
#else
#  if !defined(__COMPILING_AVR_LIBC__)
#    warning "Microcontroller not defined."
#  endif
#endif

typedef void (*fn_switch)(void);

void switch_init(void);
void assign_switch_function(uint8_t switch_id, fn_switch function);

#endif /* SWITCHES_H_ */