//#include <stdio.h>

unsigned long _pow(unsigned int a, unsigned int b){
	// Broken Implementation (probably conversion b/w uint and ulong issue??)
	// if(b<0) return 1;
	// else return a*_pow(a,b-1);
	
	// Working Implementation
	unsigned long pow = a;
	for(unsigned int i = 0; i<b; i++){
		pow *= (unsigned long)(a);
	}
	return pow;
}

unsigned int _dlen(unsigned int n){
	if(n==0) return 0;
	else return 1 + _dlen(n/10);
}

unsigned int _disl(unsigned int a, unsigned int b){
	unsigned int top = a;
	for(unsigned int i = 0; i<b+1; i++){
		top /= 10;
	}
	top *= _pow(10, b);
	unsigned int bottom = a - top;
	for(unsigned int i = 0; i<b; i++){
		bottom /= 10;
	}
	return bottom;
}


// unsigned int main(){
// 	unsigned int x = 12345;
// 	unsigned int d = _disl(x, 5);
// 	prunsigned intf("c=%d", d);

// 	return 0;
// }