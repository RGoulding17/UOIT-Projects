/*
 * Banker's Algorithm for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Ryan Goulding, Francis Hackenberger, Justin Estaris
 * All rights reserved.
 * 
 */

// Includes
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include "banker.h"

// Constants
#define NUM_CUSTOMERS 5
#define NUM_RESOURCES 3

// Colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

// Global Environment Variables
pthread_mutex_t lock;                         // Create mutex lock
int available[NUM_RESOURCES];                 // Available amount of each resource
int maximum[NUM_CUSTOMERS][NUM_RESOURCES];    // Maximum demand of each customer
int allocation[NUM_CUSTOMERS][NUM_RESOURCES]; // Amount currently allocated to each customer
int need[NUM_CUSTOMERS][NUM_RESOURCES];       // Remaining need of each customer

bool systemState(){
    bool isFinished = true;
    bool customerFinishedArray[NUM_CUSTOMERS];

    int resourceArray[NUM_RESOURCES];
    int index = 0;
    int finishIndex = -1;
    int prev = -1;
      
    // Set customers finished to false
    for(int i = 0; i < NUM_CUSTOMERS; i++)
        customerFinishedArray[i] = false;

    // Set resource array to the available resources
    for(int i = 0; i < NUM_RESOURCES; i++)
        resourceArray[i] = available[i];
        
    while(index < NUM_CUSTOMERS){ // Loop through all customers
        prev = finishIndex;
        for(int i = 0; i < NUM_CUSTOMERS; i++){
            if(customerFinishedArray[i] == false){
                for(int j = 0; j < NUM_RESOURCES; j++){
                    if(need[i][j] > resourceArray[j])
                        isFinished = false;
                }
                
                if(isFinished){
                    finishIndex = i;
                    for(int j = 0; j < NUM_RESOURCES; j++)
                        resourceArray[j] += allocation[i][j];

                    customerFinishedArray[i] = true;
                    isFinished = true;
                    index++;
                    break;
                }
            }
        }

        for(int i = 0; i < NUM_CUSTOMERS; i++){
            if(customerFinishedArray[i] == false)
                break;
        }

        if(prevFinishIndex == finishIndex)
            return false;
    }

    return true;
}

bool request_res(int n_customer, int request[]){
    bool isSafe = true;

    printf(BLU "\nCustomer #%i requesting resources\n" RESET, n_customer);
    for(int i=0;i<NUM_RESOURCES;i++)
        printf("%i ", request[i]);
    printf("\n");

    for(int i = 0; i < NUM_RESOURCES; i++){
        if(request[i] <= need[n_customer][i]){
            if(request[i] > available[i]){ // System is unsafe
                printf("System state: " RED "UNSAFE\n\n" RESET);
                return false;
            } else{
                for(int j = 0; j < NUM_RESOURCES; j++){
                    available[j] -= request[j];
                    need[n_customer][j] -= request[j];
                    allocation[n_customer][j] += request[j];
                }

                isSafe = systemState();
                if(isSafe){ // System is safe
                    printf("System state: " GRN "SAFE\n" RESET);
                    printf("Resources: " GRN "ACCEPTED\n" RESET);
                    printf("Resources post-release\n");

                    for(int i = 0; i< NUM_RESOURCES; i++)
                        printf("%i ",available[i]);
                    printf("\n");

                    return true;
                } else{ // System is unsafe
                    printf("System state: " RED "UNSAFE\n" RESET);
                    printf("Resources: " RED "DENIED\n" RESET);
                    for(int j = 0; j< NUM_RESOURCES; j++){
                        available[j] += request[j];
                        need[n_customer][j] += request[j];
                        allocation[n_customer][j] -= request[j];
                    }
                    return false;
                }
            }
        }else{
            return false;
        }
    }
    return true;
}

bool release_res(int n_customer, int release[]){
    printf(BLU "\nCustomer #%i releasing resources\n" RESET, n_customer);
    for(int i = 0; i < NUM_RESOURCES; i++){
        printf("%i ", release[i]);        
        allocation[n_customer][i] -= release[i];
        available[i] += release[i];
        need[n_customer][i] += release[i];
    }
    printf("\n");
    for(int i = 0; i < NUM_RESOURCES; i++)
        printf("%i ", available[i]);
    printf("\n");

    return true;
}

void *customerRequest(void *custNum){
    int customerNumber = *(int*)custNum;
    bool resourcesGranted = false;
    bool resourcesReleased = false;
    int request[NUM_RESOURCES];
    
    while(true){ // Loop indefinitely
        for(int i = 0; i < NUM_RESOURCES; i++)
            request[i] = rand() % (maximum[customerNumber][i] + 1); // request random number of resources

        pthread_mutex_lock(&lock); // Lock
            resourcesGranted = request_res(customerNumber, request); // Request resources (returns true/false)
        pthread_mutex_unlock(&lock); // Unlock
        
        if(resourcesGranted){ // Resources have been acquired, proceed to release resources
            resourcesGranted = false;
            pthread_mutex_lock(&lock); // Lock
                resourcesReleased = release_res(customerNumber, request); // Release resources (returns true/false)
            pthread_mutex_unlock(&lock); // Unlock

            if(resourcesReleased){
                printf(BLU "\nCustomer #%i finished\n" RESET, customerNumber);
                for(int i = 0; i < NUM_RESOURCES; i++){
                    need[customerNumber][i] = 0;
                    maximum[customerNumber][i] = 0;
                }

                printf("Maximum needs after finishing\n");
                for(int i = 0; i < NUM_CUSTOMERS; i++){
                    for(int j = 0; j < NUM_RESOURCES; j++)
                        printf("%3d ", maximum[i][j]);
                    printf("| "); 
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
    // Initializations
    srand(time(NULL));                        // Seed random number generator
    int randomMax;                            // Create random maximum
    pthread_t customerThreads[NUM_CUSTOMERS]; // Initialize threads with number of customers
    pthread_mutex_init(&lock, NULL);          // Initialize mutex lock 

    // Read in arguments from CLI, NUM_RESOURCES is the number of arguments   
    // Allocate the available resources and print maximum needs
    printf(BLU "\nMaximum needs for each customer\n" RESET);
    for (int i = 0; i < NUM_RESOURCES; i++) {
        available[i] = (int) strtol(argv[i+1], (char **)NULL, 10);
        for(int j = 0; j < NUM_CUSTOMERS; j++) {
            allocation[j][i] = 0;
            randomMax = rand() % (available[i] + 1); // Create random maximum within range of available resources               
            maximum[j][i] = randomMax;
            need[j][i] = maximum[j][i];
            printf("%i ", maximum[i][j]);
        }
        printf("| "); 
    }
    printf("\n");

    // Run the threads continually
    // The threads will request and then release random numbers of resources
    for(int index = 0; index < NUM_CUSTOMERS; index++){
        int *customerNumber = malloc(sizeof(*customerNumber)); // number represeting a customer
        *customerNumber = index;
        pthread_create(&customerThreads[index], NULL, &customerRequest, customerNumber);
    }
    
    // Collect and join finished threads
    for(int i = 0; i < NUM_CUSTOMERS; i++)
        pthread_join(customerThreads[i], NULL);
    
    pthread_mutex_destroy(&lock); // Destroy the mutex lock

    return EXIT_SUCCESS;
}