#ifndef _STRING_H
#define _STRING_H

	void _strlen(unsigned char* s);
	void _strcatc(unsigned char* a, unsigned char b);
	void _strcat(unsigned char* a, unsigned char* b);
	void _strcpy(unsigned char* a, unsigned char* b);
	void _strncpy(unsigned char* a, unsigned char* b, unsigned int n);
	void _strrev(unsigned char* a);

	unsigned int _atoi(unsigned char* s);
	void _itoa(unsigned char* a, unsigned int n);
	unsigned int _ctoi(unsigned char c);
	unsigned char _itoc(unsigned int i);

#endif // _STRING_H