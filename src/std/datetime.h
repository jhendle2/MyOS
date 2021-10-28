#ifndef DATETIME_H
#define DATETIME_H

typedef struct std_date{
	unsigned int month: 4;
	unsigned int day : 5;
	unsigned int year: 12;
} std_date;

typedef struct std_time{
	unsigned int military: 1;
	unsigned int pm: 1;

	unsigned int hour: 5;
	unsigned int min: 6;
	unsigned int sec: 6;
	unsigned int subsec: 5;
} std_time;

std_date MMDDYYYY_to_date(unsigned char mmddyy[11]);
void print_date(std_date date);

#endif // DATETIME_H