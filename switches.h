#ifndef SWITCHES_H_
#define SWITCHES_H_

#define EXT_INT_PORT PORTC
#define EXT_INT_DDR DDRC

#define SWITCH00 0x00
#define SWITCH01 0x01
#define SWITCH02 0x02

void switch_init( void );

#endif /* SWITCHES_H_ */