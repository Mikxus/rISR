# rISR version 0.2.4

rISR (Runtime Interrupt Service Routine) is a C library that allows you to bind interrupt vectors at runtime on the atmega328p chip. It is designed to be easy to use and provides a simple API for binding and un-binding ISRs (Interrupt Service Routines) to interrupt vectors.
## Features

- Bind & unbind interrupt vectors at runtime
- Fully supports Atmega328p's interrupts
- Supports Arduino
- MIT License

### Prerequisites
Before you can use the rISR library, you will need to have the following installed on your machine:
- [git](https://scm.com)
- [avr toolchain](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers)

Or if you prefer Arduino framework:

- [Arduino ide](https://www.arduino.cc/en/software) / [Arduino cli](https://arduino.github.io/arduino-cli/0.29/installation/)

## How to install

1. Clone the rISR repo
```
git clone https://github.com/Mikxus/rISR.git
```

Or If you're using Arduino, you can also install the library by following these steps:

1. Go to the releases tab on the rISR repository
2. Download the latest version of the library as a .zip file
3. Open the Arduino IDE
4. Go to Sketch > Include Library > Add .ZIP Library
5. Select the downloaded .zip file and click open
6. The library should now be installed and ready to use in the Arduino IDE.



## Example
```C
#include "rISR.h"

__attribute__((naked)) void my_isr()
{
    // Isr code here
}

int main() {

    /* Bind isr to selected interrupt vector */
    
    cli();
    risr_bind(TIMER1_COMPB_, __vector_pin_blink);
    sei();

    while (true){};
}
```

## API reference
```
risr_bind(enum ISR_Vectors vector, vector_t isr): Bind an ISR to an interrupt vector.
```
```
risr_unbind(enum ISR_Vectors vector): Un-bind an ISR from an interrupt vector.
```

## License

This library is licensed under the MIT License. See LICENSE file for more information.
