/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Ryan Goulding, Francis Hackenberger, Ryan Schutte, Justin Estaris
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

// The amount of available memory
#define MEMORY 1024

// Resources structure containing integers for each resource constraint and an
// array of 1024 for the memory
struct res {
	int offset;				//Location of memory block	
	int size;				//Size of the memory block		
	_Bool allocated;		//Indicates whether the block is currently allocated to a process
	struct res * next;		//Pointer to next block of memory
	struct res * previous;	//Pointer to previous block of memory
};
typedef struct res Res;
typedef Res * resources;

// Processes structure containing all of the process details parsed from the 
// input file, should also include the memory address (an index) which indicates
// where in the resources memory array its memory was allocated
// linked list structure for queue 
typedef struct proc{
    int arrivalTime;
    int priority;
    int processorTime;
    int Mbytes;
    int printers;
    int scanners;
    int modems;
    int CDs;
}proc;

// Function to allocate a contiguous chunk of memory in your resources structure
// memory array, always make sure you leave the last 64 values (64 MB) free, should
// return the index where the memory was allocated at
extern int alloc_mem(resources res, int size);

// Function to free the allocated contiguous chunk of memory in your resources
// structure memory array, should take the resource struct
extern free_mem(resources res);

// Function to merge memory block
// return true if merge is sucessful, false if unsucessful.
extern _Bool merge_mem(resources prevRes, resources nextRes);


#endif /* UTILITY_H_ */