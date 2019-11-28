/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Ryan Goulding, Francis Hackenberger, Ryan Schuette, Justin Estaris
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here
char pwd[BUFFER_LEN];
char shellPath[BUFFER_LEN];

// Define functions declared in myshell.h here
//displays the readme help file
void display_help(void){
    char c;
    FILE *fptr;
    fptr = fopen("readme.md", "r");
    c = fgetc(fptr);
    
    while (c != EOF){
        printf ("%c", c);
        c = fgetc(fptr);
    }
}

//clear the screen
void clear_screen(void){
    system("clear");
}

//pauses the program until enter is pressed with nothing else
void pause_shell(void){
    char input[256] = "";
    printf("System is paused, press enter to continue.\n");
    while(1){
        fgets(input,sizeof(input),stdin);
        if(input[0]=='\n'){printf("System unpaused\n"); break;}
    }
}

//echo's the message passed
void echo_message(char *message){
    printf("=>%s\n", message);
}

//lists all files in the directory given
void list_directory(char *listDirectory){
    DIR *directory;
    struct dirent *direntStruct;  
    directory = opendir(strtok(listDirectory, "\n"));

    if (directory != NULL){
        printf("----files----\n");
        while ((direntStruct = readdir(directory))){
            //don't write windows hidden files
            if(strcmp(direntStruct->d_name, ".")!=0 && strcmp(direntStruct->d_name, "..")!=0){
                printf("%s\n",direntStruct->d_name);
            }
        }
        closedir(directory);
        printf("-------------\n");
    }else{
        printf("Couldn't open the directory\n");
    }
}

//sets the current working directory
void current_directory(char *newDirectory){
    DIR *directory;
    directory = opendir(strtok(newDirectory, "\n"));

    if (directory != NULL){
        printf("Now working in: %s\n",newDirectory);
        closedir(directory);
        chdir(strtok(newDirectory, "\n"));
    }else{
        printf("Directory does not exist\n");
    }
}

//gets the current working directory
void set_current_directory(void){
    getcwd(pwd, BUFFER_LEN);
}

//displays all environment strings
void enviroment_vars(void){
    printf("-Enviroment Variables-\n");
    printf("PWD: %s\n", pwd);
    printf("SHELL: %s\n", shellPath);
}

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };
    char argHolder[BUFFER_LEN] = "";

    //wipe screen and announce that the shell has started
    system("clear");
    printf("Shell Started, enter a command or type 'help'\n");

    //set the enviroment var PWD & set PATH to the running program's location
    set_current_directory();
    getcwd(shellPath, BUFFER_LEN);

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
        char *token;
        strcpy(command, strtok(buffer, " "));   

        token = command;

        //empty argument holder
        memset(argHolder, 0, 255);

        while(token != NULL){
            token = strtok(NULL, " ");
            if(token != NULL){
                strcat(argHolder, token);
                strcat(argHolder, " ");
            }else{
                break;
            }   
        }

        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0){
            current_directory(argHolder);
            set_current_directory();
        }else if(strcmp(command, "cd\n") == 0){
            set_current_directory();
            printf("%s\n",pwd);
        }else if(strcmp(command, "help\n") == 0){
            display_help();
		}else if (strcmp(command, "quit\n") == 0){
            printf("Goodbye\n");
            return EXIT_SUCCESS;
        }else if (strcmp(command, "clr\n") == 0){
            clear_screen();
        }else if (strcmp(command, "echo") == 0){
            echo_message(argHolder);
        }else if (strcmp(command, "pause\n") == 0){
            pause_shell();
        }else if(strcmp(command, "dir") == 0){
            list_directory(argHolder);
        }else if(strcmp(command, "environ\n") == 0){
            enviroment_vars();
        }else{
            printf("Unsupported command, type 'help' to display the manual\n");
        }
    }
    return EXIT_SUCCESS;
}
