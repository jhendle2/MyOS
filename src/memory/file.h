#ifndef FILE_H
#define FILE_H

#include <stddef.h>

#include "../std/datetime.h"

#define FILE_NAME_LENGTH 27
#define EXT_NAME_LENGTH 5
#define PATH_LENGTH 128

struct file_block{
	uint8_t is_exec;
	void* data;
	uint8_t (*src)(uint8_t argc, uchar_t** argv);
};

struct file_t{
	char name[FILE_NAME_LENGTH];
	char ext[EXT_NAME_LENGTH]

	struct perms{
		uint8_t write : 1;
		uint8_t read: 1;
		uint8_t exec: 1;
	};

	struct file_t* parent;

	uint8_t num_children;
	struct file_t** children;

	size_t size;

};

#endif // FILE_H