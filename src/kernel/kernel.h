#ifndef KERNEL_H
#define KERNEL_H

	void kernel_init(void);

	int atorigin(void);
	void putch(unsigned char ascii_code);
	void setch(unsigned char ascii_code, unsigned int r, unsigned int c);
	unsigned char getch(void);
	int isch(unsigned char c);
	void clr(void);
	void nl(void);

#endif // KERNEL_H