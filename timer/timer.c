#include "timer.h"

LARGE_INTEGER frequency;
LARGE_INTEGER start_point;

void measure_start() {
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_point);
}

double measure_end() {
	LARGE_INTEGER end_point;
	QueryPerformanceCounter(&end_point);
	return (end_point.QuadPart-start_point.QuadPart)*1000.0/frequency.QuadPart;
}