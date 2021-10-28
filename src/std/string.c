#include "math.h"
// #include <stdio.h>

unsigned int _strlen(unsigned char* s){
	unsigned char* si = s;
	unsigned int len = 0;
	while(*si!=0){
		len++;
		si++;
	}
	return len;
}

void _strcatc(unsigned char* a, unsigned char b){
	unsigned int alen = _strlen(a);
	a[alen++] = b;
	a[alen] = 0;
}

void _strcat(unsigned char* a, unsigned char* b){

}

void _strcpy(unsigned char* a, unsigned char* b){
	unsigned char* ai = a;
	unsigned char* bi = b;
	while(*ai!=0 && *bi!=0){
		*ai++ = *bi++;
	}
	if(*ai != 0) *ai=0;
}

void _strncpy(unsigned char* a, unsigned char* b, unsigned int n){
	unsigned char* ai = a;
	unsigned char* bi = b;
	for(unsigned int i = 0; i<n; i++){
		*ai++ = *bi++;
	}
	if(*ai != 0) *ai=0;
}

void _strrev(unsigned char* a){
	unsigned int len = _strlen(a);
	unsigned char b[16];
	unsigned int i;
	for(i = 0; i<len; i++){
		int j = len-i-1;
		b[i] = a[j];
	}
	b[i] = 0;
	_strcpy(a, b);
}

int _ctoi(unsigned char c){
	if(c=='0') return 0;
	else if(c>='1' && c<='9') return c-'1'+1;
	else return 0;
	// return 8;
}

unsigned char _itoc(int i){
	if(i==0) return '0';
	else if(i>=1 && i<=9) return '1'+i-1;
	else return '0';
}

int _atoi(unsigned char* s){
	unsigned int i = 0;
	unsigned int power = 0;
	unsigned char* si = s;
	while(*si!=0){
		unsigned int p = (unsigned int)(_pow(10, power++));
		i += _ctoi(*si) * p;
		si++;
	}
	return i;
	// return 8;
}

void _itoa(unsigned char* a, unsigned int n){
	unsigned int dlen = _dlen(n);
	unsigned int i;
	for(i = 0; i<dlen; i++){
		unsigned int z = _disl(n, i);
		a[i] = _itoc(z);
	}
	a[i] = 0;
	_strrev(a);
}

// int main(){
// 	int z = 123;
// 	unsigned char s[16];
// 	_itoa(s, z);
// 	printf("s=%s\n",s);
// 	return 0;
// }