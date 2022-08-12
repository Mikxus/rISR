#ifdef __cplusplus
extern "C"
{
#endif

/* Dynamic interrupt routine for every isr */
#ifdef INT0_vect_used
    ISR(INT0_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[INT0_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef INT1_vect_used
    ISR(INT1_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[INT1_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef PCINT0_vect_used
    ISR(PCINT0_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[PCINT0_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef PCINT1_vect_used
    ISR(PCINT1_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[PCINT1_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef PCINT2_vect_used
    ISR(PCINT2_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[PCINT2_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef WDT_vect_used
    ISR(WDT_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[WDT_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER2_COMPA_vect_used
    ISR(TIMER2_COMPA_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER2_COMPA_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER2_COMPB_vect_used
    ISR(TIMER2_COMPB_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER2_COMPB_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER2_OVF_vect_used
    ISR(TIMER2_OVF_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER2_OVF_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER1_CAPT_vect_used
    ISR(TIMER1_CAPT_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER1_CAPT_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER1_COMPA_vect_used
    ISR(TIMER1_COMPA_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER1_COMPA_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER1_COMPB_vect_used
    ISR(TIMER1_COMPB_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER1_COMPB_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER1_OVF_vect_used
    ISR(TIMER1_OVF_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER1_OVF_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER0_COMPA_vect_used
    ISR(TIMER0_COMPA_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER0_COMPA_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER0_COMPB_vect_used
    ISR(TIMER0_COMPB_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER0_COMPB_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TIMER0_OVF_vect_used
    ISR(TIMER0_OVF_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER1_OVF_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef SPI_STC_vect_used
    ISR(SPI_STC_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[SPI_STC_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef USART_RX_vect_used
    ISR(USART_RX_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[USART_RX_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef USART_UDRE_vect_used
    ISR(USART_UDRE_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[USART_UDRE_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef USART_TX_vect_used
    ISR(USART_TX_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TIMER1_COMPB_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef ADC_vect_used
    ISR(ADC_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[ADC_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef EE_READY_vect_used
    ISR(EE_READY_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[EE_READY_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef ANALOG_COMP_vect_used
    ISR(ANALOG_COMP_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[ANALOG_COMP_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef TWI_vect_used
    ISR(TWI_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        (*isr_vector_table[TWI_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef SPM_READY_vect_used
    ISR(SPM_READY_vect, ISR_NAKED)
    {
        __asm__(
            "push r30   \n\t"
            "push r31       ");
        volatile void (*vect_ptr)() = isr_vector_table[SPM_READY_])();
        __asm__(
            "pop r31    \n\t"
            "pop r30    \n\t"
            "reti");
    }
#endif

#ifdef __cplusplus
};
#endif