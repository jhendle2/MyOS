#include "datetime.h"
#include "string.h"
#include "print.h"

unsigned int month_days[12] = {
	31, // Jan
	28, // Feb
	31, // Mar
	30, // Apr
	31, // May
	30, // Jun
	31, // Jul
	31, // Aug
	30, // Sep
	31, // Oct
	30, // Nov
	31  // Dec
};

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

static unsigned int is_leap_year(unsigned int year){
	return (year%400==0 || (year%4==0 && year%100!=0));
}

// MM/DD/YYYY -> 10 chars + 1 null char
std_date MMDDYYYY_to_date(unsigned char mmddyy[11]){
	unsigned char month_str[3];
	unsigned char day_str[3];
	unsigned char year_str[5];

	month_str[0] = mmddyy[0];
	month_str[1] = mmddyy[1];
	month_str[2] = 0;
	
	day_str[0] = mmddyy[3];
	day_str[1] = mmddyy[4];
	day_str[2] = 0;

	year_str[0] = mmddyy[6];
	year_str[1] = mmddyy[7];
	year_str[2] = mmddyy[8];
	year_str[3] = mmddyy[9];
	year_str[4] = 0;

	unsigned int month = _atoi(month_str);
	unsigned int day = _atoi(day_str);
	unsigned int year = _atoi(year_str);

	// int month = 12, day=10, year=2021;
	std_date date = {month, day, year};
	return date;
}


std_date next_date(std_date current_date){
	unsigned int month = current_date.month;
	unsigned int day = current_date.day;
	unsigned int year = current_date.year;

	day += 1;

	if(day > month_days[month-1]){
		day = 1;
		month++;
	}

	if(month > 12){
		month = 1;
		year++;
	}

	if(year > 9999){
		year = 0;
	}

	std_date next = {month, day, year};
	return next;
}

std_date prev_date(std_date current_date){
	unsigned int month = current_date.month;
	unsigned int day = current_date.day;
	unsigned int year = current_date.year;

	day -= 1;

	if(day == 0){
		if(month == 1){
			month = 12;
			year = year-1 ? year>0 : 9999;
		}
		else{
			month = month-1;
		}
		day = month_days[month-1];
	}

	std_date next = {month, day, year};
	return next;
}

void print_date(std_date date){
	printd(date.month);
	printc('/');
	printd(date.day);
	printc('/');
	printd(date.year);
}

// int main(){
// 	printf("intro\n");
// 	char date_str[11] = "12/10/2021";
// 	std_date d1 = MMDDYYYY_to_date(date_str);
// 	print_date(d1);
// 	return 0;
// }


/*
 This library is broken ;(
 Pls fix.
*/