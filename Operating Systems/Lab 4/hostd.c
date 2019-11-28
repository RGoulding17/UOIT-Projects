/*
 * Host Dispatcher Shell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Ryan Goulding, Francis Hackenberger, Ryan Schutte, Justin Estaris
 * All rights reserved.
 * 
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "queue.h"
#include "utility.h"
#include "hostd.h"


// Put macros or constants here using #define
#define MEMORY 1024
#define NUM_PRINTERS 2
#define NUM_SCANNERS 1
#define NUM_MODEMS 1
#define NUM_CD_DRIVES 2

// Put global environment variables here
int processCounter = 0;
struct proc processes[];

node_t* processQueue[3];  //queue for all 4 types of user job processes

// Define functions declared in hostd.h here
void getDispatchList(char *argv[]){
    char line[256], *c;
    int dispatchCounter = 0;

    FILE *fp;
    fp = fopen(argv[1], "r");
    
    if (fp) {
        while (fgets(line, sizeof line, fp) != NULL){
            //reset the dispatchCounter
            dispatchCounter = 0;
            //get next variable from file line
            c = strtok(line, ", ");

            while(c != NULL){
                //convert to integer
                int a = atoi(c);

                //choose variable based on counter
                switch(dispatchCounter){
                    case 0:
                        processes[processCounter].arrivalTime = a;
                        break;
                    case 1:
                        processes[processCounter].priority = a;
                        break;
                    case 2:
                        processes[processCounter].processorTime = a;
                        break;
                    case 3:
                        processes[processCounter].Mbytes = a;
                        break;
                    case 4:
                        processes[processCounter].printers = a;
                        break;
                    case 5:
                        processes[processCounter].scanners = a;
                        break;
                    case 6:
                        processes[processCounter].modems = a;
                        break;
                    case 7:
                        processes[processCounter].CDs = a;
                        break;
                }

                //increment the dispatchCounter
                dispatchCounter++;
                //get next number
                c = strtok (NULL, ",");
            }

            //store process in corresponding queue
            //and begin to run processes
            if((processes[processCounter].priority == 0)){
                push(processQueue[0], processes[processCounter]);
            }else if((processes[processCounter].priority == 1)){
                push(processQueue[1], processes[processCounter]);
            }else if((processes[processCounter].priority == 2)){
                push(processQueue[2], processes[processCounter]);
            }else if((processes[processCounter].priority == 3)){
                push(processQueue[3], processes[processCounter]);
            }

            //increment the process count
            ++processCounter;
        }     
        fclose(fp);
    }
}

int main(int argc, char *argv[])
{
    // Load the dispatchlist and store into an array of the struct process
    // Add each process structure instance to the job dispatch list queue
    // Iterate through each item in the job dispatch list, add each process
    // to the appropriate queues
    getDispatchList(argv);
    
    //declare local versions of the constants
    int memoryInUse = 0;
    int printersInUse = 0;
    int scannersInUse = 0;
    int modemsInUse = 0;
    int drivesInUse = 0;

    //declare a local version of the current node & process
    struct proc* currentProcess;
    node_t* currentNode;

    //loops through each queue from real-time to P3
    for(int i = 0; i<=3; i++){
        currentNode = &processQueue[i];

        //while the current queue's next item isn't NULL
        while(currentNode != NULL){
            currentProcess = &processQueue[i]->process;

            printf("\nMBYTES & PRIORITY for %i: %i %i\n",i,&currentProcess->Mbytes, &currentProcess->priority);

            // Allocate the resources for each process before it's executed
            memoryInUse += &currentProcess->Mbytes;
            printersInUse += (printersInUse >= NUM_PRINTERS) ? 0 : &currentProcess->printers;
            scannersInUse += (scannersInUse >= NUM_SCANNERS) ? 0 : &currentProcess->scanners;
            modemsInUse += (modemsInUse >= NUM_MODEMS) ? 0 : &currentProcess->modems;
            drivesInUse += (drivesInUse >= NUM_CD_DRIVES) ? 0 : &currentProcess->CDs;

            // Execute the process binary using fork and exec
            fork();

            // Perform the appropriate signal handling / resource allocation and de-alloaction
            if (&currentProcess->priority != 0){
                //free_mem(resource, size)
            }
            // Repeat until all processes have been executed, all queues are empty
            //set the process queue to the next node
            currentNode = currentNode->next;
        }
        
    }
    return EXIT_SUCCESS;
}