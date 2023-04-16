#include <stdlib.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "switches.h"
#include "w204.h"
#include "uart.h"

typedef void (*fn_switch)( void );

static fn_switch fn_switch_00 = NULL;
static fn_switch fn_switch_01 = NULL;
static fn_switch fn_switch_02 = NULL;
static fn_switch fn_switch_03 = NULL;

void switch_init( void ) {
   
    fn_switch_00 = &w204_shift_cursor_left;
    fn_switch_01 = &w204_shift_cursor_right;
    fn_switch_02 = &w204_shift_display_left;
    fn_switch_03 = &w204_shift_display_right;
       
    #ifdef SWITCH00
    EXT_INT_DDR &= ~(1 << SWITCH00);       // Configure port as INPUT
    EXT_INT_PORT |= (1 << SWITCH00);       // Pullup (HIGH)
    EICRA |= (1 << ISC01) | (1 << ISC00);  // Trigger on falling edge
    EIMSK |= (1 << INT0);                  // Activate External Interrupt
    #endif
    
    #ifdef SWITCH01
    EXT_INT_DDR &= ~(1 << SWITCH01);       // Configure port as INPUT
    EXT_INT_PORT |= (1 << SWITCH01);       // Pullup (HIGH)
    EICRA |= (1 << ISC11) | (1 << ISC10);  // Trigger on falling edge
    EIMSK |= (1 << INT1);                  // Activate External Interrupt
    #endif
    
    #ifdef SWITCH02
    EXT_INT_DDR &= ~(1 << SWITCH02);       // Configure port as INPUT
    EXT_INT_PORT |= (1 << SWITCH02);       // Pullup (HIGH)
    EICRA |= (1 << ISC21) | (1 << ISC20);  // Trigger on falling edge
    EIMSK |= (1 << INT2);                  // Activate External Interrupt
    #endif
    
    #ifdef SWITCH03
    EXT_INT_DDR &= ~(1 << SWITCH03);       // Configure port as INPUT
    EXT_INT_PORT |= (1 << SWITCH03);       // Pullup (HIGH)
    EICRA |= (1 << ISC31) | (1 << ISC30);  // Trigger on falling edge
    EIMSK |= (1 << INT3);                  // Activate External Interrupt
    #endif 
}

#ifdef SWITCH00
ISR(INT0_vect) {
    if (fn_switch_00 != NULL) {
        fn_switch_00();
    }
}
#endif

#ifdef SWITCH01
ISR(INT1_vect) {
    if (fn_switch_01 != NULL) {
        fn_switch_01();
    }
}
#endif

#ifdef SWITCH02
ISR(INT2_vect) {
    if (fn_switch_02 != NULL) {
        fn_switch_02();
    }
}
#endif

#ifdef SWITCH03
ISR(INT3_vect) {
    if (fn_switch_03 != NULL) {
        fn_switch_03();
    }
}
#endif