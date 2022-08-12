#include <avr/io.h>


.section .data
.global isr_vector_table

/* Interrupt vector struct */
isr_vector_table:
    #ifdef INT0_vect_used
    .word runtime_bad_isr
    #endif

    #ifdef INT0_vect_used
    .word runtime_bad_isr
    #endif

    #ifdef PCINT0_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef PCINT1_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef PCINT2_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef WDT_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER2_COMPA_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER2_COMPB_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER2_OVF_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER1_CAPT_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER1_COMPA_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER1_COMPB_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER1_OVF_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER0_COMPA_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER0_COMPB_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TIMER0_OVF_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef SPI_STC_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef USART_RX_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef USART_UDRE_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef USART_TX_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef ADC_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef EE_READY_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef ANALOG_COMP_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef TWI_vect_used
    .word runtime_bad_isr
    #endif
    
    #ifdef SPM_READY_vect_used
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
