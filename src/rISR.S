/*
 ; MIT License
 ; 
 ; Copyright (c) 2022 Mikko Heinänen
 ; 
 ; Permission is hereby granted, free of charge, to any person obtaining a copy
 ; of this software and associated documentation files (the "Software"), to deal
 ; in the Software without restriction, including without limitation the rights
 ; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 ; copies of the Software, and to permit persons to whom the Software is
 ; furnished to do so, subject to the following conditions:
 ; 
 ; The above copyright notice and this permission notice shall be included in all
 ; copies or substantial portions of the Software.
 ; 
 ; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 ; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 ; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 ; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 ; SOFTWARE.
 */

#include <avr/io.h>

#ifdef ARDUINO
#include "config.h"
#endif

.section .data
.global isr_vector_table

/* Interrupt vector struct */
isr_vector_table:
    #if defined(INT0_used) || defined(INT0_unsafe)
    .word runtime_bad_isr
    #endif

    #if defined(INT0_used) || defined(INT0_unsafe)
    .word runtime_bad_isr
    #endif

    #if defined(PCINT0_used) || defined(PCINT1_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(PCINT1_used) || defined(PCINT1_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(PCINT2_used) || defined(PCINT2_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(WDT_used) || defined(WDT_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER2_COMPA_used) || defined(TIMER2_COMP_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER2_COMPB_used) || defined(TIMER2_COMPB_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER2_OVF_used) || defined(TIMER2_OVF_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER1_CAPT_used) || defined(TIMER1_CAPT_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER1_COMPA_used) || defined(TIMER1_COMPA_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER1_COMPB_used) || defined(TIMER1_COMPB_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER1_OVF_used) || defined(TIMER1_OVF_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER0_COMPA_used) || defined(TIMER0_COMPA_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER0_COMPB_used) || defined(TIMER0_COMPB_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TIMER0_OVF_used) || defined(TIMER0_OVF_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(SPI_STC_used) || defined(SPI_STC_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(USART_RX_used) || defined(USART_RX_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(USART_UDRE_used) || defined(USART_UDRE_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(USART_TX_used) || defined(USART_TX_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(ADC_used) || defined(ADC_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(EE_READY_used) || defined(EE_READY_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(ANALOG_COMP_used) || defined(ANALOG_COMP_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(TWI_used) || defined(TWI_unsafe)
    .word runtime_bad_isr
    #endif
    
    #if defined(SPM_READY_used) || defined(SPM_READY_unsafe)
    .word runtime_bad_isr
    #endif

/*  Uncomment if you need to know the size of the table */
 ;
 ;    #define table_lenght . - isr_vector_table
 ;    
 ; .global isr_vector_table_size
 ; isr_vector_table_size:
 ;   .byte table_lenght



/*
 * @args isr_vectors isr_name, void *isr_func_ptr
 *
 * isr_func_ptr:
 *      r22: low byte
 *      r23: high byte
 *  
 * isr_name:
 *      r24: byte
 *      r25: unused
 *
 */
.section .text
.global risr_bind
risr_bind:
    lsl r24

    ldi ZL, lo8( isr_vector_table )
    ldi ZH, hi8( isr_vector_table )

    add ZL, r24
    adc ZH, r1

    st Z+, r22
    st z, r23

    ret

/* Default isr */
.global runtime_bad_isr
runtime_bad_isr:
    reti

/* Ensure our vector table is copied to memory */
.global __do_copy_data
