/*
 * MIT License
 * 
 * Copyright (c) 2022 Mikko Heinänen
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "fast_dynamic_config.h"
#include "../../src/rISR.h"
#include <avr/io.h>
#include <stdbool.h>


void __vector_pin_blink();

int main()
{
    cli();
    /* Setup timer1 compb interrupt to trigger on every clock cycle */
    TCCR1A = 0;                            // set entire TCCR1A register to 0
    TCCR1B = 0;                            // same for TCCR1B
    TCNT1  = 0;                            // initialize counter value to 0 
    PRR &= ~( 1 << PRTIM1 );               // Enable timer1

    OCR1A = 1;
    TCCR1B |= (1 << WGM12);                // turn on CTC mode
    TCCR1B |= (1 << CS10);                 // No prescaler
    TIMSK1 |= (1 << OCIE1B);               // Enable timer1  

    DDRB = 0b00010000;                     // Set pin to output                    

    bind_isr(TIMER1_COMPB_, __vector_pin_blink);
    sei();

    while (true){};
}

/* Exammple isr for unsafe dynamic interrupts. */
__attribute__((naked)) void __vector_pin_blink()
{
    __asm__ (
        "push   r18           \n\t"
        "in     r18, %[sreg]  \n\t"
        "push   r18           \n\t"
        "push   r19           \n\t"
        "ldi    r19, 0b00010000 \n\t"
        "in     r18, %[portb] \n\t"
        "eor    r18, r19      \n\t"
        "out    %[portb], r18 \n\t"
        "pop    r19           \n\t"
        "pop    r18           \n\t"
        "out    %[sreg], r18  \n\t"
        "pop    r18           \n\t"
        "pop    r31           \n\t"
        "pop    r30           \n\t"
        "reti                     "
        :
        : [sreg] "I" (_SFR_IO_ADDR(SREG)),
          [portb] "I" (_SFR_IO_ADDR(PORTB))
        : "memory"
        );
}