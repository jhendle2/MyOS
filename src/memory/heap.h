#ifndef HEAP_H
#define HEAP_H

	#include "memblock.h"

	void init_block();
	void split_block(struct MEMBLOCK* fitting_slot, size_t size);
	void* malloc(size_t noOfBytes);
	void merge_blocks();
	void free(void* ptr);

#endif