#include <stdlib.h>
#include <stdint.h>
#include <avr/interrupt.h>

#include "switches.h"
#include "uart.h"

typedef void (*fn_switch)( void );

static fn_switch fn_switch_01 = NULL;
static fn_switch fn_switch_02 = NULL;
static fn_switch fn_switch_03 = NULL;

void switch_init( void ) {
    
    // Setup Pin Change Interrupts ...
    
    fn_switch fn_switch_01 = NULL;
    fn_switch fn_switch_02 = NULL;
    fn_switch fn_switch_03 = NULL;
}

ISR(PCINT0_vect) {
    if (fn_switch_01 != NULL) {
        fn_switch_01();
    }
}

ISR(PCINT1_vect) {
    if (fn_switch_02 != NULL) {
        fn_switch_02();
    }
}

ISR(PCINT2_vect) {
    if (fn_switch_03 != NULL) {
        fn_switch_03();
    }
}