#include "Timer.h"
/*
	Written by Michael Nowicki
*/


bool Timer::is_still_valid() {
	double run_time = omp_get_wtime() - start_search_time;
	if (run_time < duration) {
		return SAFE;
	}
	return KILLED;
}

double Timer::get_search_time() {
	return (end_search_time - start_search_time);
}

void Timer::start_timing_search() {
	start_search_time = omp_get_wtime();
}

void Timer::stop_timing_search() {
	end_search_time = omp_get_wtime();
}
