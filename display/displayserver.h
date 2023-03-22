#ifndef DISPLAYSERVER_H
#define DISPLAYSERVER_H

#ifdef __linux__
#include "x11/x11_displayserver.h"
#elif _WIN32
#include "win32/win32_displayserver.h"
#else
#error Platform not supported!
#endif

#endif