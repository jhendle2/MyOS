#include "type.h"
#include "args.h"
#include "string.h"
// #include <string.h>

#include <stdlib.h>
#include <stdio.h>

uint8_t parse_args(uchar_t** out, uchar_t arg_str[64]){
	uchar_t* temp_str = (uchar_t*)malloc(ARG_LENGTH * sizeof(uchar_t));
	//temp_arg->str[0] = 0;
	uint8_t temp_str_index = 0;
	uint8_t out_index = 0;
	for(uint8_t i = 0; i<64; i++){
		if(!arg_str[i]){
			temp_str[temp_str_index] = 0;
			printf("1: %s\n",temp_str);
			_strcpy(out[out_index++],temp_str);
			break;
		}

		if(arg_str[i] == ' ' || arg_str[i] == '\n' ||
								arg_str[i] == '\t'){
			temp_str[temp_str_index] = 0;
			temp_str_index = 0;
			printf("2: %s\n", temp_str);
			_strcpy(out[out_index++],temp_str);
		}
		else{
			temp_str[temp_str_index++] = arg_str[i];
		}
	}

	for(uint8_t i = 0; i<out_index; i++){
		printf("<%d : %s\n",i,out[i]);
	}
	return out_index;
}

int main(){
	uchar_t arg_str[64] = "this is a test";
	uchar_t** argv = (uchar_t**)malloc(sizeof(uchar_t*)*16);
	for(uint8_t i = 0; i<16; i++){
		argv[i] = (uchar_t*)malloc(sizeof(uchar_t)*ARG_LENGTH);
	}
	uint8_t argc = parse_args(argv, arg_str);
	for(uint8_t i = 0; i<argc; i++){
		printf("%d : %s\n",i,argv[i]);
	}
	return 0;
}