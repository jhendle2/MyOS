#ifndef MEMBLOCK_H
#define MEMBLOCK_H

	struct MEMBLOCK{
		size_t size;
		unsigned int free;
		struct MEMBLOCK* next;
	};

#endif