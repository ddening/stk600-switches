#include <stdlib.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "switches.h"
#include "uart.h"
#include "utils.h"

typedef void (*fn_switch)( void );

static fn_switch fn_switch_00 = NULL;
static fn_switch fn_switch_01 = NULL;
static fn_switch fn_switch_02 = NULL;

static void _cb_sw00 ( void ) {
    uart_put("SWITCH 00");
}

static void _cb_sw01 ( void ) {
    uart_put("SWITCH 01");
}

static void _cb_sw02 ( void ) {
    uart_put("SWITCH 02");
}

void switch_init( void ) {
   
    fn_switch_00 = &_cb_sw00;
    fn_switch_01 = &_cb_sw01;
    fn_switch_02 = &_cb_sw02;
    
    /* Configure port/pins as OUTPUT/HIGH on default. Pulling LOW triggers an interrupt. */   
    EXT_INT_DDR  = 0x00; // Set all ports as INPUT
    EXT_INT_PORT = (1 << SWITCH00) | (1 << SWITCH01) | (1 << SWITCH00); // Pullup (HIGH)
    
    /* Trigger on falling edge */
    EICRA |= (1 << ISC01) | (1 << ISC00);
    EICRA |= (1 << ISC11) | (1 << ISC10);
    EICRA |= (1 << ISC21) | (1 << ISC20);
    
    /* Activate External Interrupts */
    EIMSK |= (1 << INT0) | (1 << INT1) | (1 << INT2);
  
    sei();
    
    uart_put("Switch Init");
}

ISR(INT0_vect) {
    if (fn_switch_00 != NULL) {
        fn_switch_00();
    }
}

ISR(INT1_vect) {
    if (fn_switch_01 != NULL) {
        fn_switch_01();
    }
}

ISR(INT2_vect) {
    if (fn_switch_02 != NULL) {
        fn_switch_02();
    }
}