#include "datetime.h"
#include "string.h"
#include "print.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

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

	// int month = 1, day=1, year=1999;
	std_date date = {month, day, year};
	return date;
}


void print_date(std_date date){
	printd(date.day);
	printc(':');
	printd(date.month);
	printc(':');
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