/*
 * Debug Helpers for Arduino
 * 
 * Copyright (C) 2014 David Chadwick Gibbons
 * All Rights Reserved
 *
 * See the file LICENSE for copying permission.
 */
 
#ifndef AVR_DEBUG_H
#define AVR_DEBUG_H

#if ARDUINO < 100
#error "Arduino Version 1.0 required"
#endif

#include <Arduino.h>
#include <stdio.h>

#ifndef NDEBUG
#define PRINT(string, ...)  printf_P(PSTR(string), ##__VA_ARGS__)
#else
#define PRINT(string, ...)
#endif

class AVRDebugClass
{
  public:
    void begin(uint16_t serial_speed);
    int freeram() const;
    const char *hexdump(uint8_t *data, int length) const;
};

extern AVRDebugClass Debug;

#endif
