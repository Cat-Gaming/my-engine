#ifndef DISPLAYSERVER_H
#define DISPLAYSERVER_H

#ifdef __linux__
#include "x11/x11_displayserver.h"
#else
#error Platform not supported!
#endif

#endif