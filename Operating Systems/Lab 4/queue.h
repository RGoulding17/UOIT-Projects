/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Ryan Goulding, Francis Hackenberger, Ryan Schutte, Justin Estaris
 * All rights reserved.
 * 
 */
#ifndef QUEUE_H_
#define QUEUE_H_

#include "utility.h"

typedef struct node {
    struct proc process;
    struct node* next;
} node_t;

// Add a new process to the queue, returns the address of the next node added
// to the linked list
extern void *push(node_t *tail, struct proc process);
extern node_t *pop(node_t *tail);


#endif /* QUEUE_H_ */