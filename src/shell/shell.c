#include "../kernel/kernel.h"

#include "../std/string.h"
#include "../std/print.h"
#include "../std/datetime.h"

#include <stddef.h>
#include "../memory/heap.h"

char* CURRENT_DIR_STR = "HOME/";

#ifndef SHELL_HEADER
	#define SHELL_HEADER ">"
#endif


void prompt(){
	prints(CURRENT_DIR_STR);
	prints(SHELL_HEADER);
}

void keyboard_handler_main(void)
{
	unsigned char last_char = getch();
	if(last_char == '\n' || atorigin()){
		prompt();
	}
	if(isch(last_char)){
		putch(last_char);
	}
}


void update_dir(char* dir_str){
	_strcpy(CURRENT_DIR_STR, dir_str);
}


void shell_init(void){
	const char *welcome = "|~~~<MYOS BOOTING UP...>~~~|";
	clr();
	prints(welcome);
	nl();
	

	unsigned int* k = (int*)malloc(sizeof(unsigned int) * 5);
	k[0] = 1;
	k[1] = 3;
	k[2] = 5;
	k[3] = 7;
	k[4] = 9;
	// printd(k[0]);
	// printd(k[1]);
	// printd(k[2]);
	// printd(k[3]);
	// printd(k[4]);
	unsigned char k0 = _itoc(k[0]);
	unsigned char k1 = _itoc(k[1]);
	unsigned char k2 = _itoc(k[2]);
	unsigned char k3 = _itoc(k[3]);
	unsigned char k4 = _itoc(k[4]);

	// putch(k0);
	// putch(k1);
	// putch(k2);
	// putch(k3);
	// putch(k4);

	printd(k[0]);
	printd(k[1]);
	printd(k[2]);
	printd(k[3]);
	printd(k[4]);

	unsigned char date_str[11] = "12/10/2021";
	std_date d1 = MMDDYYYY_to_date(date_str);
	print_date(d1);

	// char* dir_str = "TEST";
	// update_dir(dir_str);
	prompt();

	kernel_init();
}