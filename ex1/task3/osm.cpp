#include "osm.h"
#include <sys/time.h>
#include<cmath>
#include <unistd.h>
#include <iostream>

#define DEFAULT_ITERATIONS 50000
#define ROOLING_FACTOR 10

int osm_init()
{
	return 0;
}

double osm_operation_time(unsigned int osm_iterations)
{
	unsigned int iterations = osm_iterations > 0  ? osm_iterations : DEFAULT_ITERATIONS;
	iterations = std::ceil(iterations/ROOLING_FACTOR);
	timeval t1 = {0}, t2 = {0}, res = {0};
	double runningTime = 0;
	int a = 0;
	double avgRunningTime = -1;
	int success1, success2;
	success1 = 0;
	success2 = 0;
	success1 = gettimeofday(&t1, NULL);
	for(unsigned int i = 0; i < iterations; i++)
	{
		a=0;
		a=1;
		a=2;
		a=3;
		a=4;
		a=5;
		a=6;
		a=7;
		a=8;
		a=9;
	}
	success2 = gettimeofday(&t2, NULL);
	if (success1 == -1 || success2 == -1)
	{
		return -1;
	}
	timersub(&t2,&t1, &res);
	runningTime= res.tv_sec*(10^6) + res.tv_usec; //total time in micro-seconds
	avgRunningTime = (runningTime/(iterations*ROOLING_FACTOR) )*1000; //average time in nano-seconds
	return avgRunningTime;
}

void emptyFunction() {}

double osm_function_time(unsigned int osm_iterations)
{
	unsigned int iterations = osm_iterations > 0  ? osm_iterations : DEFAULT_ITERATIONS;
	iterations = std::ceil(iterations/ROOLING_FACTOR);
	timeval t1 = {0}, t2 = {0}, res = {0};
	double runningTime = 0;
	double avgRunningTime = -1;
	int success1, success2;
	success1 = 0;
	success2 = 0;
	success1 = gettimeofday(&t1, NULL);
	for(unsigned int i = 0; i < iterations; i++)
	{
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
		emptyFunction();
	}
	success2 = gettimeofday(&t2, NULL);
	if (success1 == -1 || success2 == -1)
	{
		return -1;
	}
	timersub(&t2,&t1, &res);
	runningTime= res.tv_sec*(10^6) + res.tv_usec; //total time in micro-seconds
	avgRunningTime = (runningTime/(iterations*ROOLING_FACTOR) )*1000; //average time in nano-seconds
	return avgRunningTime;
}


double osm_syscall_time(unsigned int osm_iterations)
{
	unsigned int iterations = osm_iterations > 0  ? osm_iterations : DEFAULT_ITERATIONS;
	iterations = std::ceil(iterations/ROOLING_FACTOR);
	timeval t1 = {0}, t2 = {0}, res = {0};
	double runningTime = 0;
	double avgRunningTime = -1;
	int success1, success2;
	success1 = 0;
	success2 = 0;
	success1 = gettimeofday(&t1, NULL);
	for(unsigned int i = 0; i < iterations; i++)
	{
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
	}
	success2 = gettimeofday(&t2, NULL);
	if (success1 == -1 || success2 == -1)
	{
		return -1;
	}
	timersub(&t2,&t1, &res);
	runningTime= res.tv_sec*(10^6) + res.tv_usec; //total time in micro-seconds
	avgRunningTime = (runningTime/(iterations*ROOLING_FACTOR) )*1000; //average time in nano-seconds
	return avgRunningTime;
}


timeMeasurmentStructure measureTimes (unsigned int osm_iterations)
{
	timeMeasurmentStructure measurements;
	gethostname(measurements.machineName, HOST_NAME_MAX);
	measurements.instructionTimeNanoSecond = osm_operation_time(osm_iterations);
	measurements.functionTimeNanoSecond = osm_function_time(osm_iterations);
	measurements.trapTimeNanoSecond = osm_syscall_time(osm_iterations);
	measurements.functionInstructionRatio = measurements.functionTimeNanoSecond/measurements.instructionTimeNanoSecond;
	measurements.trapInstructionRatio = measurements.trapTimeNanoSecond/measurements.instructionTimeNanoSecond;
	return measurements;
}
