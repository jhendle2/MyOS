#ifndef ARGS_H
#define ARGS_H

#include "type.h"

#define ARG_LENGTH 16

// typedef struct ARG{
// 	unsigned char str[ARG_LEN];
// } ARG;

uint8_t parse_args(uchar_t** out, uchar_t arg_str[64]); // split a string of args into ARG struct array

#endif