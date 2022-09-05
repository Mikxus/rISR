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
#ifndef _RISR_H_
#define _RISR_H_

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#ifdef ARDUINO
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif 

extern volatile void runtime_bad_isr(void);
extern volatile void (*isr_vector_table[])(void) ;


/**
 * @brief  List of interrupt vectors.
 * @note
 */
typedef enum
{

#if defined(INT0_used) || defined(INT0_unsafe)
    INT0_,
    #define enum_used
#endif

#if defined(INT1_used) || defined(INT1_unsafe)
    INT1_,
    #define enum_used
#endif

#if defined(PCINT0_used) || defined(PCINT0_unsafe)
    PCINT0_,
    #define enum_used
#endif

#if defined(PCINT1_used) || defined(PCINT1_unsafe)
    PCINT1_,
    #define enum_used
#endif

#if defined(PCINT2_used) || defined(PCINT2_unsafe)
    PCINT2_,
    #define enum_used
#endif

#if defined(WDT_used) || defined(WDT_unsafe)
    WDT_,
    #define enum_used
#endif

#if defined(TIMER2_COMPA_used) || defined(TIMER2_COMPA_unsafe)
    TIMER2_COMPA_,
    #define enum_used
#endif

#if defined(TIMER2_COMPB_used) || defined(TIMER2_COMPB_unsafe)
    TIMER2_COMPB_,
    #define enum_used
#endif

#if defined(TIMER2_OVF_used) || defined(TIMER2_OVF_unsafe)
    TIMER2_OVF_,
    #define enum_used
#endif

#if defined(TIMER1_CAPT_used) || defined(TIMER1_CAPT_unsafe)
    TIMER1_CAPT_,
    #define enum_used
#endif

#if defined(TIMER1_COMPA_used) || defined(TIMER1_COMPA_unsafe)
    TIMER1_COMPA_,
    #define enum_used
#endif
#if defined(TIMER1_COMPB_used) || defined(TIMER1_COMPB_unsafe)
    TIMER1_COMPB_,
    #define enum_used
#endif

#if defined(TIMER1_OVF_used) || defined(TIMER1_OVF_unsafe)
    TIMER1_OVF_,
    #define enum_used
#endif

#if defined(TIMER0_COMPA_used) || defined(TIMER0_COMPA_unsafe)
    TIMER0_COMPA_,
    #define enum_used
#endif

#if defined(TIMER0_COMPB_used) || defined(TIMER0_COMPB_unsafe)
    TIMER0_COMPB_,
    #define enum_used
#endif

#if defined(TIMER0_OVF_used) || defined(TIMER0_OVF_unsafe)
    TIMER0_OVF_,
    #define enum_used
#endif

#if defined(SPI_STC_used) || defined(SPI_STC_unsafe)
    SPI_STC_,
    #define enum_used
#endif

#if defined(USART_RX_used) || defined(USART_RX_unsafe)
    USART_RX_,
    #define enum_used
#endif

#if defined(USART_UDRE_used) || defined(USART_UDRE_unsafe)
    USART_UDRE_,
    #define enum_used
#endif

#if defined(USART_TX_used) || defined(USART_TX_unsafe)
    USART_TX_,
    #define enum_used
#endif

#if defined(ADC_used) || defined(ADC_unsafe)
    ADC_,
    #define enum_used
#endif

#if defined(EE_READY_used) || defined(EE_READY_unsafe)
    EE_READY_,
    #define enum_used
#endif

#if defined(ANALOG_COMP_used) || defined(ANALOG_COMP_unsafe)
    ANALOG_COMP_,
    #define enum_used
#endif

#if defined(TWI_used) || defined(TWI_unsafe)
    TWI_,
    #define enum_used
#endif

#if defined(SPM_READY_used) || defined(SPM_READY_unsafe)
    SPM_READY_,
    #define enum_used
#endif
} isr_vectors;


#ifndef enum_used
    #error rISR: No interrupt vectors defined.
#endif
#undef enum_used


/**
 * @brief  Binds function pointer to selected isr
 * @note
 * @param  isr_name:        Name of the isr
 * @param  (*isr_func_ptr):   Function pointer to be binded
 * @retval None
 */
extern void risr_bind( isr_vectors isr_name, void (*isr_func_ptr)(void) );

/**
 * @brief  Unbinds the selected isr vector
 * @note   
 * @param  isr_name: 
 * @retval None
 */
void risr_unbind( isr_vectors isr_name );


#ifndef ARDUINO         // Idk doesn't compile if included in arduino ide...
    #include "rISR.c"
#endif

#ifdef __cplusplus
};
#endif 

#endif
