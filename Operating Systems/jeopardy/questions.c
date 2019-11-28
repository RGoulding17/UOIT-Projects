/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    //Set question catagories
    strcpy(questions[0].category, categories[0]);
    strcpy(questions[1].category, categories[0]);
    strcpy(questions[2].category, categories[0]);
    strcpy(questions[3].category, categories[0]);
    strcpy(questions[4].category, categories[0]);
    strcpy(questions[5].category, categories[1]);
    strcpy(questions[6].category, categories[1]);
    strcpy(questions[7].category, categories[1]);
    strcpy(questions[8].category, categories[1]);
    strcpy(questions[9].category, categories[1]);
    strcpy(questions[10].category, categories[2]);
    strcpy(questions[11].category, categories[2]);
    strcpy(questions[12].category, categories[2]);
    strcpy(questions[13].category, categories[2]);
    strcpy(questions[14].category, categories[2]);
    //set question values
    questions[0].value = 200;
    questions[1].value = 400;
    questions[2].value = 600;
    questions[3].value = 800;
    questions[4].value = 1000;
    questions[5].value = 200;
    questions[6].value = 400;
    questions[7].value = 600;
    questions[8].value = 800;
    questions[9].value = 1000;
    questions[10].value = 200;
    questions[11].value = 400;
    questions[12].value = 600;
    questions[13].value = 800;
    questions[14].value = 1000;

    //set answered bool to false for all questions
    questions[0].answered = false;
    questions[1].answered = false;
    questions[2].answered = false;
    questions[3].answered = false;
    questions[4].answered = false;
    questions[5].answered = false;
    questions[6].answered = false;
    questions[7].answered = false;
    questions[8].answered = false;
    questions[9].answered = false;
    questions[10].answered = false;
    questions[11].answered = false;
    questions[12].answered = false;
    questions[13].answered = false;
    questions[14].answered = false;

    //Set the question and answer for each question
    //Category #1 - programming
    strcpy(questions[0].question, "Hyper Text Markup Language");
    strcpy(questions[0].answer, "html");
    strcpy(questions[1].question, "This programming language is white space oriented");
    strcpy(questions[1].answer, "python");
    strcpy(questions[2].question, "The programming paradigm where an object is represented by a class");
    strcpy(questions[2].answer, "oop");
    strcpy(questions[3].question, "The act of hiding data within a class because other class's don't need it");
    strcpy(questions[3].answer, "encapsulation");
    strcpy(questions[4].question, "A concept where one class shares the structure and behavior defined in another class");
    strcpy(questions[4].answer, "inheritance");

    //Category #2 - algorithms
    strcpy(questions[5].question, "A procedure that calls itself");
    strcpy(questions[5].answer, "recursion");
    strcpy(questions[6].question, "A queue, array, or stack are data structures of the same type");
    strcpy(questions[6].answer, "linear");
    strcpy(questions[7].question, "This notation is used to measure complexity (answer with just the letter)");
    strcpy(questions[7].answer, "o");
    strcpy(questions[8].question, "This search repeatedly divides in half the portion of data where the item your searching for could be");
    strcpy(questions[8].answer, "binary");
    strcpy(questions[9].question, "this search starts at the root of the data and continues down its branches");
    strcpy(questions[9].answer, "tree");

    //Category #3 - database's
    strcpy(questions[10].question, "Applications designed to help the user interact with a database");
    strcpy(questions[10].answer, "dbms");
    strcpy(questions[11].question, "eXtensible Markup Language");
    strcpy(questions[11].answer, "xml");
    strcpy(questions[12].question, "Structured Query Language");
    strcpy(questions[12].answer, "sql");
    strcpy(questions[13].question, "One to One, One to many, Many to many");
    strcpy(questions[13].answer, "relationships");
    strcpy(questions[14].question, "Organized data void of inconsistent dependency and redundancy");
    strcpy(questions[14].answer, "normalization");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("\n%s\t%s\t%s\n", categories[0],categories[1],categories[2]);
    char row1[256] = "",
         row2[256] = "",
         row3[256] = "",
         row4[256] = "",
         row5[256] = "";

    for(int i=0; i<15;i++){
        if(questions[i].value == 200 && questions[i].answered == false){
            strcat(row1, "200 \t\t");
        }else if(questions[i].value == 200 && questions[i].answered == true){
            strcat(row1, "    \t\t");
        }

        if(questions[i].value == 400 && questions[i].answered == false){
            strcat(row2, "400 \t\t");
        }else if(questions[i].value == 400 && questions[i].answered == true){
            strcat(row2, "    \t\t");
        }

        if(questions[i].value == 600 && questions[i].answered == false){
            strcat(row3, "600 \t\t");
        }else if(questions[i].value == 600 && questions[i].answered == true){
            strcat(row3, "    \t\t");
        }

        if(questions[i].value == 800 && questions[i].answered == false){
            strcat(row4, "800 \t\t");
        }else if(questions[i].value == 800 && questions[i].answered == true){
            strcat(row4, "    \t\t");
        }

        if(questions[i].value == 1000 && questions[i].answered == false){
            strcat(row5, "1000\t\t");
        }else if(questions[i].value == 1000 && questions[i].answered == true){
            strcat(row5, "    \t\t");
        }
    }
    printf("%s\n%s\n%s\n%s\n%s\n", row1,row2,row3,row4,row5);
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for(int i=0; i<15;i++){
        if(strcmp(questions[i].category,category) == 0 && questions[i].value == value){
            printf("\nFor $%i,\n%s\n", questions[i].value, questions[i].question);
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
     for(int i=0; i<15;i++){
        if(strcmp(questions[i].category,category) == 0 && questions[i].value == value){
            questions[i].answered = true;
            if(strcmp(questions[i].answer, answer) == 0){
                //answer is correct
                return true;
            }else{
                //answer is wrong
                return false;
            }
        }
    }
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for(int i=0; i<15;i++){
        if(strcmp(questions[i].category,category) == 0 && questions[i].value == value && questions[i].answered == true){
            return true;
        }
    }
    return false;
}

bool game_over(){
    for(int i=0; i<15;i++){
        if(questions[i].answered == false){
            return false;
        }
    }
    return true;
}
