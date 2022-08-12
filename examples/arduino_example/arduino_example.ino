#include "example_config.h"
#include <rISR.h>

#define led_pin 13

volatile bool pin_state = 0;

__attribute__ ((interrupt)) void __vector_example() 
{  
  pin_state ^= 1;
  digitalWrite( led_pin, pin_state );
}


void setup () {
  pinMode( led_pin, OUTPUT );
}


void loop () {
  cli();
  risr_bind( TIMER1_COMPA_, __vector_example );

  while (true);
}
