#include "math.h"
#include <stdio.h>
#include "../kernel/kernel.h"
#include "type.h"

uint8_t _strlen(uchar_t* s){
	uchar_t* si = s;
	uint8_t len = 0;
	while(*si!=0){
		len++;
		si++;
	}
	return len;
}

void _strcatc(uchar_t* a, uchar_t b){
	uint8_t alen = _strlen(a);
	a[alen++] = b;
	a[alen] = 0;
}

void _strcat(uchar_t* a, uchar_t* b){

}

void _strcpy(uchar_t* a, uchar_t* b){
	uchar_t* ai = a;
	uchar_t* bi = b;
	while(*ai!=0 && *bi!=0){
		*ai++ = *bi++;
	}
	if(*ai != 0) *ai=0;
	printf("a=%s, b=%s\n",a,b);
}

void _strncpy(uchar_t* a, uchar_t* b, uint8_t n){
	uchar_t* ai = a;
	uchar_t* bi = b;
	for(uint8_t i = 0; i<n; i++){
		*ai++ = *bi++;
	}
	if(*ai != 0) *ai=0;
}

void _strrev(uchar_t* a){
	uint8_t len = _strlen(a);
	uchar_t b[16];
	uint8_t i;
	for(i = 0; i<len; i++){
		int j = len-i-1;
		b[i] = a[j];
	}
	b[i] = 0;
	_strcpy(a, b);
}

int _ctoi(uchar_t c){
	if(c=='0') return 0;
	else if(c>='1' && c<='9') return c-'1'+1;
	else return 0;
	// return 8;
}

uchar_t _itoc(int i){
	if(i==0) return '0';
	else if(i>=1 && i<=9) return '1'+i-1;
	else return '0';
}

int _atoi(uchar_t* s){
	uint8_t res = 0;
	for(uint8_t i = 0; s[i] != '\0'; i++){
		res = res * 10 + _ctoi(s[i]);
	}
	return res;
}

void _itoa(uchar_t* a, uint8_t n){
	uint8_t i = 0;
	if(n==0) a[i++] = '0';
	while(n){
		uint8_t r = n % 10;

		if(r >= 10) a[i++] = _itoc(r - 10);
		else a[i++] = _itoc(r);

		n /= 10;
	}
	a[i] = 0;
	_strrev(a);
}

// int main(){
// 	int z = 123;
// 	uchar_t s[16];
// 	_itoa(s, z);
// 	printf("s=%s\n",s);
// 	return 0;
// }