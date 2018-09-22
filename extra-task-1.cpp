#include <iostream>
#include "assert.h"

using namespace std;

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2)/(60*60);
}

double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	if (hours < 0)
	{
		throw exception();
	}
	return hours - ((int)hours / 24) * 24;
}

int get_hours(int seconds)
{
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	return (seconds / 60) % 60;
}

int get_seconds(int seconds)
{
	return seconds % 60;
}

double time_to_utc(int utc_offset, double time)
{
	return to_24_hour_clock(time - utc_offset);
}

double time_from_utc(int utc_offset, double time)
{
	return to_24_hour_clock(time + utc_offset + 24);
}

int main()
{
	//task 1
	assert(seconds_difference(1800.0, 3600.0) == 1800);
	assert(seconds_difference(3600.0, 1800.0) == -1800);
	assert(seconds_difference(1800.0, 2160.0) == 360);
	assert(seconds_difference(1800.0, 1800.0) == 0);
	//task 2
	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	assert(hours_difference(1800.0, 2160.0) == 0.1);
	assert(hours_difference(1800.0, 1800.0) == 0);
	//task 3
	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	assert(to_float_hours(1, 0, 36) == 1.01);
	//task 4
	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(48) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(4) == 4);
	assert(to_24_hour_clock(28.5) == 4.5);
	//task 5
	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);
	//task 6
	assert(time_to_utc(+0, 12.0) == 12);
	assert(time_to_utc(+1, 12.0) == 11);
	assert(time_to_utc(-1, 12.0) == 13);
	assert(time_to_utc(-11, 18.0) == 5);
	assert(time_to_utc(-1, 0.0) == 1);
	assert(time_to_utc(-1, 23.0) == 0);
	//task 7
	assert(time_from_utc(+0, 12.0) == 12);
	assert(time_from_utc(+1, 12.0) == 13);
	assert(time_from_utc(-1, 12.0) == 11);
	assert(time_from_utc(+6, 6.0) == 12);
	assert(time_from_utc(-7, 6.0) == 23);
	assert(time_from_utc(-1, 0.0) == 23);
	assert(time_from_utc(-1, 23.0) == 22);
	assert(time_from_utc(+1, 23.0) == 0);
	//system("pause");
}
