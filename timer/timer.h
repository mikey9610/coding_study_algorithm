#ifndef TIMER
#define TIMER

#include <stdio.h>
#include <Windows.h>

LARGE_INTEGER frequency;
LARGE_INTEGER start_point;

void measure_start();
double measure_end();

#endif