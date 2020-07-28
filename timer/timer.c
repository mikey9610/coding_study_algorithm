#include "timer.h"

void measure_start() {
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_point);
}

double measure_end() {
	LARGE_INTEGER end_point;
	QueryPerformanceCounter(&end_point);
	return (end_point.QuadPart-start_point.QuadPart)*1000.0/frequency.QuadPart;
}