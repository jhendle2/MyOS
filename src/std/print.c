#include "./string.h"
#include "../kernel/kernel.h"

// #include <stddef.h>
// #include "../memory/heap.h"

// #include <stdio.h>

// void _putch(unsigned char c){
// 	printf("%c", c);
// }

void printc(unsigned char c){
	putch(c);
}

void prints(unsigned char* s){
	unsigned int i = 0;
	while (s[i] != '\0') {
		putch(s[i++]);
	}
}

void printd(unsigned int d){
	unsigned char dstr[16];
	// unsigned char* dstr = (unsigned char*)malloc(sizeof(unsigned char) * 32);
	for(unsigned int i = 0; i<8; i++) dstr[i] = 0;
	dstr[7] = 0;
	_itoa(dstr, d);
	prints(dstr);
	// putch('1');
}