#define TIMER1_COMPA_vect_used

#include "../../src/rISR.h"
#include <avr/io.h>
#include <stdbool.h>


void __vector_dynamic_isr();
volatile uint8_t isr_variable = 0;

int main()
{
    cli();
    risr_bind(TIMER1_COMPA_, __vector_dynamic_isr);
    sei();

    while (true)
    {
        if (isr_variable == 255)
        {
            return 0;
        }
    };
}

/* Example isr */
__attribute__((interrupt)) void __vector_dynamic_isr()
{
    isr_variable++;
    return;
}