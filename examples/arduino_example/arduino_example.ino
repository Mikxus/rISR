#include <rISR.h>

/**
 * @file Example runtime binding of interrupt.
 * @note   To use the interrupt TIMER1_COMPB_ you need to uncomment TIMER1_COMPB_used in
 *         /path to library/rISR/src/config.h
 */


#define led_pin 12
volatile bool pin_state = 0;

__attribute__ ((signal)) void __vector_example() 
{  
  pin_state ^= 1;
  digitalWrite( led_pin, pin_state );
}


void setup () {
  pinMode( led_pin, OUTPUT );
}


void loop () {

  cli();
  /* Sets timer1 to interrupt at the rate of ~ 16 mhz / 150 + interrupt execution time */
  TCCR1A = 0;                            // set entire TCCR1A register to 0
  TCCR1B = 0;                            // same for TCCR1B
  TCNT1  = 0;                            // initialize counter value to 0 
  PRR &= ~( 1 << PRTIM1 );               // Enable timer1

  OCR1A = 150;
  TCCR1B |= (1 << WGM12);                // turn on CTC mode
  TCCR1B |= (1 << CS10);                 // No prescaler
  TIMSK1 |= (1 << OCIE1B);               // Enable timer1  
  
  bind_isr( TIMER1_COMPB_, __vector_example );
  sei();

  while (true);
}
