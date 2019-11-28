/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void *push(node_t *tail, struct proc process)
{
    node_t *temp = malloc(sizeof(node_t));
    temp->process = process;
    temp->next = tail;
    tail = temp;
}

node_t *pop(node_t *tail)
{
    node_t * current = tail;
    //remove if theres only 1 member
    if (tail->next == NULL) {
        free(tail);
        return current;
    }

    //find second last node
    while (current->next->next != NULL) {
        current = current->next;
    }

    //try to remove the last element, the one after our current
    free(current->next);
    current->next = NULL;
    return current;
}