#ifndef BIN_H
#define BIN_H

#include "../std/type.h"
#include "../std/args.h"

uint8_t (*COMMAND_LIST[32])(uint8_t argc, uchar_t** argv); // Array to func pointers of installed commands

#define MAX_APPLICATIONS 32
struct APPLICATION_LOOKUP_TABLE{
	uint8_t length;

	uchar_t names[MAX_APPLICATIONS];

	uint8_t (*applications[MAX_APPLICATIONS])(uint8_t argc, uchar_t** argv);
} APPLICATION_LOOKUP_TABLE;

#endif