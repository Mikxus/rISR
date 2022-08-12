#ifndef _RISR_H_
#define _RISR_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "default-config.h"


extern volatile void (*isr_vector_table[])(void) ;


/**
 * @brief  List of interrupt vectors.
 * @note
 */
typedef enum
{

#ifdef INT0_vect_used
    INT0_,
#endif

#ifdef INT0_vect_used
    INT1_,
#endif

#ifdef PCINT0_vect_used
    PCINT0_,
#endif

#ifdef PCINT1_vect_used
    PCINT1_,
#endif

#ifdef PCINT2_vect_used
    PCINT2_,
#endif

#ifdef WDT_vect_used
    WDT_,
#endif

#ifdef TIMER2_COMPA_vect_used
    TIMER2_COMPA_,
#endif

#ifdef TIMER2_COMPB_vect_used
    TIMER2_COMPB_,
#endif

#ifdef TIMER2_OVF_vect_used
    TIMER2_OVF_,
#endif

#ifdef TIMER1_CAPT_vect_used
    TIMER1_CAPT_,
#endif

#ifdef TIMER1_COMPA_vect_used
    TIMER1_COMPA_,
#endif

#ifdef TIMER1_COMPB_vect_used
    TIMER1_COMPB_,
#endif

#ifdef TIMER1_OVF_vect_used
    TIMER1_OVF_,
#endif

#ifdef TIMER0_COMPA_vect_used
    TIMER0_COMPA_,
#endif

#ifdef TIMER0_COMPB_vect_used
    TIMER0_COMPB_,
#endif

#ifdef TIMER0_OVF_vect_used
    TIMER0_OVF_,
#endif

#ifdef SPI_STC_vect_used
    SPI_STC_,
#endif

#ifdef USART_RX_vect_used
    USART_RX_,
#endif

#ifdef USART_UDRE_vect_used
    USART_UDRE_,
#endif

#ifdef USART_TX_vect_used
    USART_TX_,
#endif

#ifdef ADC_vect_used
    ADC_,
#endif

#ifdef EE_READY_vect_used
    EE_READY_,
#endif

#ifdef ANALOG_COMP_vect_used
    ANALOG_COMP_,
#endif

#ifdef TWI_vect_used
    TWI_,
#endif

#ifdef SPM_READY_vect_used
    SPM_READY_,
#endif
} isr_vectors;


/**
 * @brief  Binds function pointer to selected isr
 * @note
 * @param  isr_name:        Name of the isr
 * @param  (*isr_func_ptr):   Function pointer to be binded
 * @retval None
 */
extern void risr_bind( isr_vectors isr_name, void (*isr_func_ptr)(void) );

#include "rISR.c"

#ifdef __cplusplus
};
#endif 

#endif
