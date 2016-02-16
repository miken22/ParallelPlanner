#ifndef TIMER_H
#define TIMER_H
#include <omp.h>

/*
	Written by Michael Nowicki
*/

#define KILLED false
#define SAFE true

class Timer{

private:
	int duration;
	double start_search_time;
	double end_search_time;
public:
	bool is_still_valid();
	double get_search_time();
	void start_timing_search();
	void stop_timing_search();
	Timer() : duration(1800) {}
	Timer(int time) : duration(time) {}
};

#endif
