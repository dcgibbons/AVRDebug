AVRDebug
========

A Debug Library for AVR Microcontrollers using Arduino. This library provides
some helper functions for logging data to the serial interface, formatting data
and analayzing RAM usage.

To use this library, put this directory in your Arduino libraries folder and
include AVRDebug.h in your sketches, i.e.:

````
#include <AVRDebug.h>
````

An instance of the AVRDebugClass will be created as a global variable named Debug.
To allow this instance to begin using the serial port for debug logging, do
the following in your setup function:

````
Debug.begin(9600);
````

Or whatever serial speed you wish to use for output.

Beginning the debug session will do two things: 1) open a channel to the hardware
serial pins, b) reassign stdout to go to that channel.

You can send output now to stdout as you wish, but the preferred method of sending
output with this library is by using the PRINT macro defined within the library's
header file. This macro is only enabled if NDEBUG is NOT defined, and it will
automatically put your formatting strings into the AVR's program space using the
PSTR macro.

For example:

````
void loop()
{
    if (my_sensor.interrupt())
    {
        PRINT("Interrupt detected on sensor pin %d\n", my_sensor.int_pin());
    }
}
````
