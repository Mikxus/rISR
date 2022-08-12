
#include "../../src/rISR.h"
#include <avr/io.h>
#include <stdbool.h>

void __vector_dynamic_isr();
volatile uint8_t isr_variable = 0;

int main()
{
    cli();
    risr_bind(INT0_, __vector_dynamic_isr);
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
//volatile uint8_t isr_variable = 0;

__attribute__((interrupt)) void __vector_dynamic_isr()
{
    isr_variable++;
    risr_clean(); // !REMEMBER to include
    return;
}