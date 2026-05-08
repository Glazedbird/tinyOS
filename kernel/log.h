#pragma once

#include "uart.h"

#define DEBUG

#ifdef DEBUG
#define LOG(msg) uartwrite("[DEBUG] "); uartwrite(msg); uartwrite("\n")
#else
#define LOG(msg) 
#endif