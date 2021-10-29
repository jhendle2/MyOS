#include "../kernel/kernel.h"
#include "../kernel/sys_props.h"

#include "../std/type.h"
#include "../std/string.h"
#include "../std/print.h"
#include "../std/datetime.h"

// #include <stddef.h>
// #include "../memory/heap.h"


uchar_t shell_buffer[64];
uint8_t shell_buffer_index;

void clean_shell_buffer(){
	for(uint8_t i = 0; i<64; i++){
		shell_buffer[i] = 0;
	}
}

void append_shell_buffer(uchar_t c){
	if(shell_buffer_index<63){
		shell_buffer[shell_buffer_index++] = c;
		shell_buffer[shell_buffer_index] = 0;
	}
	else{
		shell_buffer_index = 0;
		shell_buffer[shell_buffer_index++] = c;
		shell_buffer[shell_buffer_index] = 0;
	}
}

void shell_buffer_backspace(){
	if(shell_buffer_index>0){
		if(shell_buffer_index<63)
			shell_buffer[shell_buffer_index] = 0;
		shell_buffer_index--;
	}
}

void shell_buffer_submit(){
	
}


/**************************************/

uchar_t* CURRENT_DIR_STR = "HOME/";

#ifndef SHELL_HEADER
	#define SHELL_HEADER ">"
#endif


void prompt(){
	prints(CURRENT_DIR_STR);
	prints(SHELL_HEADER);
}

void keyboard_handler_main(void)
{
	uchar_t last_char = getch();
	if(last_char == '\b'){
		// putch('?');
		shell_buffer_backspace();
	}
	if(last_char == '\n' || atorigin()){
		prints(shell_buffer);
		shell_buffer_submit();
		nl();
		prompt();
	}
	if(isch(last_char)){
		append_shell_buffer(last_char);
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

	prints("Today is ");
	print_date(SYS_DATE);
	nl();
	prompt();

	kernel_init();
}