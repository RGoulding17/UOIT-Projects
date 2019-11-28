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
#include <stdbool.h>
#include <ctype.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here
int NUM_PLAYERS = 0;
char questionAnswer[BUFFER_LEN] = "";       //used to hold the answer from the user

// Processes the answer from the user containing what is or who is and tokenizes it
void tokenize(char *input){
    char *token;
    const char s[2] = " ";

    token = strtok(input, s);

    while(token != NULL ) {
        if(strtok(NULL, s) != NULL){
            token = strtok(NULL, s);
        }else{
            break;
        }
    }

    strcpy(questionAnswer, token);
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players, int winningScore, char *winningName){
    system("clear");

    printf("\t\t GAME OVER!\n\t\t============\n");

    for(int i=0; i<NUM_PLAYERS; i++){
        printf("%s's score: $%i\n", players[i].name, players[i].score);
        if(players[i].score > winningScore){
            strcpy(winningName, players[i].name);
            winningScore = players[i].score;
        }
    }
    
    printf("\nThe winner is %s! with a score of $%i", winningName, winningScore);
}

int main(int argc, char *argv[])
{
     //Variables
    int game_state = 1;                         //used to keep the game in a infinite loop, until the game is over
    int questionValue = 0;                      //question value of the question being answered
    int winningScore = 0;                       //holds the winner score
    char questionPlayer[BUFFER_LEN] = "";       //used to hold the player who's answering from the user
    char questionCatagory[BUFFER_LEN] = "";     //used to hold the category choice from the user
    char buffer[BUFFER_LEN] = { 0 };            // Buffer for user input
    char tempName[BUFFER_LEN] = "";             //Temp variable for verifying names
    char winningName[BUFFER_LEN] = "";          //holds the winners name
    bool unanswered = true;                     //used in while loop to verify that a question hasnt been answered
    struct player *players;                     //a struct of players, holding information like name and score

    //clear the screen and display the title
    system("clear");
    printf("\t\t\t Welcome to Jeopardy!\n\t\t\t======================\n");

    //Set how many people are playing
    printf("How many people are playing? ");
    scanf("%i", &NUM_PLAYERS);

    if(NUM_PLAYERS > 4 || NUM_PLAYERS < 1){
        while(NUM_PLAYERS > 4 || NUM_PLAYERS < 1){
            printf("Only a maximum of 4 players can play, please enter a new number: ");
            scanf("%i", &NUM_PLAYERS);
        }
    }

    //declare players struct and set it to the size of the number of players 
    players = malloc(sizeof(struct player)*NUM_PLAYERS);

    printf("Great! So we have %i player(s) playing today\n", NUM_PLAYERS);

    // Prompt for players names
    for(int i=0;i<NUM_PLAYERS;i++){
        printf("Enter player #%i's name: ", i+1);
        scanf("%s", tempName);

        if(player_exists(players, NUM_PLAYERS, tempName) == false){
            strcpy(players[i].name, tempName);
            players[i].score = 0;
        }else{
            printf("Name already exsits, Please enter another\n");
            --i;
        }        
    }

    // Display the game introduction and initialize the questions
    initialize_game();

    while (game_state)
    {
        strcpy(questionPlayer, "");
        strcpy(questionCatagory, "");
        strcpy(questionAnswer, "");
        questionValue = 0;
        unanswered = true;

        //display the board
        display_categories();

        while(unanswered){
            //choose a player
            printf("Whose choosing the question?(pick amongst yourselves) ");
            scanf("%s",questionPlayer);

            //choose's a question
            printf("What category of questions do you want? ");
            scanf("%s",questionCatagory);

            printf("What value of question do you want? ");
            scanf("%i",&questionValue);

            if(player_exists(players, NUM_PLAYERS, questionPlayer) == false){
                printf("player does not exist, enter another name\n");
            }else if(already_answered(questionCatagory, questionValue) == true){
                printf("question has already been answered, pick again\n");
            }else if(strcmp(questionCatagory,"programming") != 0 && strcmp(questionCatagory,"algorithms") != 0 && strcmp(questionCatagory,"databases") != 0){
                printf("category choice does not exist\n");
            }else if(questionValue != 200 && questionValue != 400 && questionValue != 600 && questionValue != 800 && questionValue != 1000){
                printf("value choice does not exist\n");
            }else{
                unanswered = false;
            }
        }

        //display the question
        display_question(questionCatagory, questionValue);  

        //take the players input
        scanf(" %[^\n]%*c", questionAnswer);

        //tokenize and tolower the user input, as well as remove spacing
        tokenize(questionAnswer);

        //remove excess text from the screen
        system("clear");

        //validate player input to answer
        //mark question as answered
        //give or remove points depending on correctness
        if(valid_answer(questionCatagory, questionValue, questionAnswer) == true){
            //add points to player
            printf("Correct! $%i added to %s's score\n", questionValue, questionPlayer);
            update_score(players, NUM_PLAYERS, questionPlayer, questionValue);
        }else{
            //remove points from player
            printf("Incorrect! $%i removed from %s's score\n", questionValue, questionPlayer);
            update_score(players, NUM_PLAYERS, questionPlayer, questionValue*-1);
        }

        //if there are no more questions, set the game state to 0
        if(game_over() == true){
            game_state = 0;
        }
    }
    
    // Display the final results and exit
    show_results(players, NUM_PLAYERS, winningScore, winningName);

    free(players);
    return EXIT_SUCCESS;
}
