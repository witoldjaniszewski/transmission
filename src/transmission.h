#ifndef TRANSMISSION_H
#define TRANSMISSION_H

typedef enum{
	UP,
	NONE,
	DOWN,
	ERROR
} shift_t;

typedef enum{
	OK,
	WARNING,
	FAILURE
} status_t;
shift_t getShift(int RPM, double slope, int* status);

#endif // TRANSMISSION_H
