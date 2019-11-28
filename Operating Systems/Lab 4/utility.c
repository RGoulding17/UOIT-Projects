/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Ryan Goulding, Francis Hackenberger, Ryan Schutte, Justin Estaris
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int remainingMemory = MEMORY;	// amount of free memory
resources firstBlock = NULL;

// Creates a new memory block
resources newBlock() {
	resources newBlock = malloc(sizeof(resources));
	newBlock->next = NULL;
	newBlock->previous = NULL;
	newBlock->allocated = 0;
	newBlock->size = 0;
	newBlock->offset = 0;

	return newBlock;
}

int alloc_mem(resources res, int size)
{
    // initialize memory if its the first time allocating
	if (remainingMemory == MEMORY && firstBlock == NULL) {
		firstBlock = newBlock();
		firstBlock->size = MEMORY;
		firstBlock->offset = 0;
	}

	if (remainingMemory < size) {
		printf("Out of memory!\n");
		return NULL;
	}
		
	resources head = firstBlock; // pointer to loop through memory blocks
	resources memory = NULL;
	
	// loop through the list of memory blocks until a big enough memory block is found or end of memory reached
	while(head != NULL && ( (!head->allocated && head->size < size) ||
			head->allocated )){
		// if end of memory is reached, return null
		if( (head->offset + head->size) > MEMORY)
			return NULL;
		head = head->next;
	}

	//If head is null then end of memory reached
	if (head != NULL) {
		if(!head->allocated && head->size > size) {
			 //TODO: allocate memory block to new process and resize it
			memory = head;
			memory->allocated = 1;
			remainingMemory -= size;
		} else {
			memory = head;
			memory->allocated = 1;
			remainingMemory -= memory->size;
		}
	}

	return memory->offset; // return location where memory is allocated at
}

free_mem(resources res)
{
	if(res == NULL){ // passed empty block
		return;
	} 
		
	if(MEMORY){
		printf("Memory freed: offset: %d  memory: %dMB\n", res->offset, res->size);
	}
		
	res->allocated = 0;
	remainingMemory += res->size;
	
	// if prev. block is free, merge and set the pointer to point to the merged block
	if(res->previous != NULL && !res->previous->allocated) {
		merge_mem(res->previous, res);
		res = res->previous;
	}
	
	// if next block is free, merge them
	if(res->next != NULL && !res->next->allocated) {
		merge_mem(res, res->next);
	}
}

_Bool merge_mem(resources prevRes, resources nextRes) {
	// redirect pointers
	prevRes->next = nextRes->next;
	if(nextRes->next != NULL){
		nextRes->next->previous = prevRes;
	}
	
	// free memory
	prevRes->size += nextRes->size;
	free(nextRes);
	nextRes = NULL;
	return 1;
}
