/*
 * Debug Helpers for Arduino
 * 
 * Copyright (C) 2013 David Chadwick Gibbons
 * All Rights Reserved
 *
 * See the file LICENSE for copying permission.
 */
 
#include "AVRDebug.h"

static FILE uartout = { 0 };

static int uart_putchar(char c, FILE *stream)
{
  Serial.write(c);
  return 0;
}

void AVRDebugClass::begin(uint16_t speed)
{
  Serial.begin(speed);
  Serial.println("Debug starting...");
  
  // fill in the UART file descriptor with pointer to writer.
  fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);

  // The uart is the standard output device STDOUT.
  stdout = &uartout; 
}

int AVRDebugClass::freeram() const
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

const char *AVRDebugClass::hexdump(uint8_t *data, int length) const
{
  static char buffer[64];

  int n = 0;

  for (int i = 0; i < length; i++) 
  {
    n += snprintf(&buffer[n], sizeof(buffer) - n, "%02x ", data[i]);
  }

  for (int i = 0; i < length; i++) 
  {
    n += snprintf(&buffer[n], sizeof(buffer) - n, "%c", isprint(data[i]) ? (const char)data[i] : '.');
  }

  return buffer;
}

/* Singleton instance of this class */
AVRDebugClass Debug;
