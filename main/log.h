#ifndef LOG_H
#define LOG_H
#include <stdio.h>

#define LOG(str) printf("[LOG] %s\n", str)
#define DEBUG(str) printf("[DEBUG] %s\n", str)
#define ERROR(str) fprintf(stderr, "[ERROR] %s\n", str)

#endif