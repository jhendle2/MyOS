/*
* Copyright (C) 2014  Arjun Sreedharan
* License: GPL version 2 or higher http://www.gnu.org/licenses/gpl.html
*/
#include "./io/keyboard.h"

/* there are 25 lines each of 80 columns; each element takes 2 bytes */
#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define KB_ENTER_LOC 0x1C
#define KB_BACKSPACE_LOC 0x0E

extern unsigned char keyboard_map[128];
extern void keyboard_handler(void);
extern char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);
extern void load_idt(unsigned long *idt_ptr);


char *vidptr = (char*)0xb8000;
/* current cursor location */
unsigned int current_loc = 0;
/* video memory begins at address 0xb8000 */


struct IDT_entry {
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};

struct IDT_entry IDT[IDT_SIZE];

unsigned char last_key;

void idt_init(void)
{
	unsigned long keyboard_address;
	unsigned long idt_address;
	unsigned long idt_ptr[2];

	/* populate IDT entry of keyboard's interrupt */
	keyboard_address = (unsigned long)keyboard_handler;
	IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
	IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
	IDT[0x21].zero = 0;
	IDT[0x21].type_attr = INTERRUPT_GATE;
	IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

	/*     Ports
	*	 PIC1	PIC2
	*Command 0x20	0xA0
	*Data	 0x21	0xA1
	*/

	/* ICW1 - begin initialization */
	write_port(0x20 , 0x11);
	write_port(0xA0 , 0x11);

	/* ICW2 - remap offset address of IDT */
	/*
	* In x86 protected mode, we have to remap the PICs beyond 0x20 because
	* Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	*/
	write_port(0x21 , 0x20);
	write_port(0xA1 , 0x28);

	/* ICW3 - setup cascading */
	write_port(0x21 , 0x00);
	write_port(0xA1 , 0x00);

	/* ICW4 - environment info */
	write_port(0x21 , 0x01);
	write_port(0xA1 , 0x01);
	/* Initialization finished */

	/* mask interrupts */
	write_port(0x21 , 0xff);
	write_port(0xA1 , 0xff);

	/* fill the IDT descriptor */
	idt_address = (unsigned long)IDT ;
	idt_ptr[0] = (sizeof (struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16 ;

	load_idt(idt_ptr);
}

void kb_init(void)
{
	/* 0xFD is 11111101 - enables only IRQ1 (keyboard)*/
	write_port(0x21 , 0xFD);
}

void kernel_init(void){
	idt_init();
	kb_init();
}

int atorigin(void){
	return (current_loc==0);
}

void clr(void)
{
	unsigned int i = 0;
	while (i < SCREENSIZE) {
		vidptr[i++] = ' ';
		vidptr[i++] = 0x07;
	}
}

void nl(void)
{
	unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
	current_loc = current_loc + (line_size - current_loc % (line_size));
}

void blnkspc(int i){
	vidptr[i] = ' ';
	vidptr[i] = 0x07;
}

void spc(void){
	vidptr[current_loc++] = ' ';
	vidptr[current_loc++] = 0x07;
}


void setch(unsigned char ascii_code, unsigned int r, unsigned int c){
	int i = r*COLUMNS_IN_LINE*BYTES_FOR_EACH_ELEMENT + c*BYTES_FOR_EACH_ELEMENT;
	if(i >= 0 && i<=SCREENSIZE){
		vidptr[i++] = ascii_code;
		vidptr[i] = 0x07;		
	}
}

void putch(unsigned char ascii_code){
	if(current_loc < SCREENSIZE){
		vidptr[current_loc++] = ascii_code;
		vidptr[current_loc++] = 0x07;		
	}
	else{
		clr();
		current_loc = 0;
	}
}

void bkspc(void){
	if(vidptr[current_loc-2]!='>'){
		current_loc--;
		current_loc--;
		vidptr[current_loc++] = ' ';
		vidptr[current_loc++] = 0x07;
		current_loc--;
		current_loc--;
	}
}

int isch(unsigned char c){
	return (c>=32 && c<=126);
}

void blink_cursor(void){
	static enum state{cursor_ON, cursor_OFF} last_state = cursor_OFF;
	if(last_state == cursor_ON){
		bkspc();
		last_state = cursor_OFF;
	}
	else{
		bkspc();
		last_state = cursor_ON;
	}
}

unsigned char getch(void){
	unsigned char status;
	char keycode;

	/* write EOI */
	write_port(0x20, 0x20);

	status = read_port(KEYBOARD_STATUS_PORT);
	/* Lowest bit of status will be set if buffer is not empty */
	if (status & 0x01) {
		keycode = read_port(KEYBOARD_DATA_PORT);

		// last_key = keyboard_map[keycode];
		if(keycode < 0){
			// char c[2] = {last_key, '\0'};
			// kprint(c);
			return 0;
		}

		if(keycode == KB_ENTER_LOC) {
			nl();
			return '\n';
		}

		if(keycode == KB_BACKSPACE_LOC){
			bkspc();
			return 0;
		}

		unsigned char ascii_code = keyboard_map[(unsigned char) keycode];
		// putch(ascii_code);
		//blink_cursor();
		return ascii_code;
	}
	return 0;
}
