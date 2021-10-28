// #include <stdio.h>
#include <stddef.h>

#include "memblock.h"

#define MAX_BLOCKS 1024

struct MEMBLOCK HEAP[MAX_BLOCKS];

struct MEMBLOCK* HEAPFREELIST = (void*)HEAP;

void init_block(){
	HEAPFREELIST->size = MAX_BLOCKS-sizeof(struct MEMBLOCK);
	HEAPFREELIST->free = 1;
	HEAPFREELIST->next = NULL;
}

void split(struct MEMBLOCK* fitting_slot, size_t size){
	struct MEMBLOCK* new = (void*)((void*)fitting_slot + size + sizeof(struct MEMBLOCK));
	new->size = (fitting_slot->size)-size-sizeof(struct MEMBLOCK);
	new->free = 1;
	new->next = fitting_slot->next;
	fitting_slot->size = size;
	fitting_slot->free = 0;
	fitting_slot->next = new;
}

void* malloc(size_t noOfBytes){
	struct MEMBLOCK *curr, *prev;

	void* result;

	if(!(HEAPFREELIST->size)){
		init_block();
		// printf("Init Block\n");
	}

	curr = HEAPFREELIST;

	while((((curr->size)<noOfBytes)||((curr->free)==0)) && (curr->next!=NULL)){
		prev=curr;
		curr=curr->next;
		// printf("Checked block\n");
	}

	if((curr->size)==noOfBytes){
		curr->free = 0;
		result = (void*)(++curr);
		// printf("Exact fitting block allocated\n");
		return result;
	}

	else if((curr->size)>(noOfBytes+sizeof(struct MEMBLOCK))){
		split(curr, noOfBytes);
		result=(void*)(++curr);
		// printf("Fitting block allocated with a split\n");
		return result;
	}

	else{
		result = NULL;
		// printf("No sufficient memory to allocated\n");
		return result;
	}
}

void merge(){
	struct MEMBLOCK *curr, *prev;
	curr = HEAPFREELIST;
	//while((curr->next)!=NULL){
	while(curr && curr->next){
		if((curr->free) && (curr->next->free)){
			curr->size += (curr->next->size)+sizeof(struct MEMBLOCK);
			curr->next = curr->next->next;
		}
		prev = curr;
		curr = curr->next;
	}
}

void free(void* ptr){
	if(((void*)HEAP<=ptr)&&(ptr<=(void*)(HEAP+MAX_BLOCKS))){
		struct MEMBLOCK* curr = ptr;
		--curr;
		curr->free = 1;
		merge();
	}
	else{
		// printf("Please provide a valid pointer allocated by _malloc\n");
	}
}


// int main(){
// 	printf("Hello.\n");

// 	int* nums = _malloc(sizeof(int) * 5);
// 	nums[0] = 1;
// 	nums[1] = 2;
// 	nums[2] = 3;
// 	nums[3] = 4;
// 	nums[4] = 5;

// 	for(int i = 0; i<5; i++){
// 		printf("%d\n",nums[i]);
// 	}

// 	_free(nums);

// 	return 0;
// }