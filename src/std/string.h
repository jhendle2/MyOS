#ifndef _STRING_H
#define _STRING_H

#include "type.h"

	void _strlen(uchar_t* s);
	void _strcatc(uchar_t* a, uchar_t b);
	void _strcat(uchar_t* a, uchar_t* b);
	void _strcpy(uchar_t* a, uchar_t* b);
	void _strncpy(uchar_t* a, uchar_t* b, uint8_t n);
	void _strrev(uchar_t* a);

	uint8_t _atoi(uchar_t* s);
	void _itoa(uchar_t* a, uint8_t n);
	uint8_t _ctoi(uchar_t c);
	uchar_t _itoc(uint8_t i);

#endif // _STRING_H