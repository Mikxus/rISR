# rISR version 0.2.4

rISR (Runtime Interrupt Service Routine) is a C library that allows you to bind interrupt vectors at runtime on the atmega328p chip. It is designed to be easy to use and provides a simple API for binding and un-binding ISRs (Interrupt Service Routines) to interrupt vectors.

## Features
- Bind & unbind interrupt vectors at runtime
- Fully supports Atmega328p's interrupts
- Supports Arduino
- MIT License

## How to use
### Prerequisites
Before you can use the rISR library, you will need to have the following installed on your machine:
- [git](https://scm.com)
- [avr toolchain](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers)

Or if you prefer Arduino framework:

- [Arduino ide](https://www.arduino.cc/en/software) / [Arduino cli](https://arduino.github.io/arduino-cli/0.29/installation/)

### Installation
- Clone the rISR repo
```
git clone https://github.com/Mikxus/rISR.git
```

Or If you're using Arduino, you can also install the library by following these steps:

1. Go to the [releases tab](https://github.com/Mikxus/rISR/releases) on the rISR repository
2. Download the latest version of the library as a .zip file
3. Open the Arduino IDE
4. Go to Sketch > Include Library > Add .ZIP Library
5. Select the downloaded .zip file and click open
6. The library should now be installed and ready to use in the Arduino IDE.

### Example
Next create new main.c or a sketch and copy over the example.
```C
#include "rISR.h"

__attribute__ ((signal)) void __vector_pin_blink()
{
    PORTB ^= 0b00010000;
}

int main() {

    /* Configure timer1 to interrupt as fast as possible */
    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1  = 0;
    PRR &= ~(1 << PRTIM1);
    OCR1A = 1;
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);
    TIMSK1 |= (1 << OCIE1B;

    /* Bind isr to selected interrupt vector */
    risr_bind(TIMER1_COMPB_, __vector_pin_blink);
    sei();

    while (true){};
}
```
**Note** if you're using arduino. Change the ```int main()``` to ```void loop()```

## API reference
Bind an ISR to an interrupt vector.
```C
risr_bind(enum isr_vectors vector, vector_t isr);
```

Un-bind an ISR from an interrupt vector.
```C
risr_unbind(enum isr_vectors vector);
```

## License
This library is licensed under the MIT License. See [LICENSE](https://github.com/Mikxus/rISR/blob/main/LICENSE) file for more information.
