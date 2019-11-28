/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef MYSHELL_H_
#define MYSHELL_H_

// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);

extern void display_help(void);
extern void clear_screen(void);
extern void pause_shell(void);
extern void enviroment_vars(void);
extern void list_directory(char *listDirectory);
extern void current_directory(char *newDirectory);
extern void get_current_directory(void);
extern void echo_message(char *message);

#endif /* MYSHELL_H_ */