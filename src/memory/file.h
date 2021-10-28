#ifndef FILE_H
#define FILE_H

#include <stddef.h>

#define FILE_NAME_LENGTH 27
#define EXT_NAME_LENGTH 5

typedef struct fileptr{
	char name[FILE_NAME_LENGTH];
	char ext[EXT_NAME_LENGTH]

	
	size_t size;
}

#endif // FILE_H