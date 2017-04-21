/*************************************************************************
* File:   board_utils.c
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*
* Description: The basic utility functions that correspond to the "board"
* 			   operations of the game. 
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "board_utils.h"

// Global Variables.
int board_rows;
int board_cols; 
int board_size;

/*************************************************************************
* Function: board_setup
* 
* Sets the global variables, gets enough memory to store the board.
*
* @args[0] (int rows)    -The number of rows in the board.
* @args[1] (int cols)    -The number of columns in the board.
* @args[2] (char *board) -The connect four board.
* @args[3] (int op)      -Setup a new board or not.
* @return  (int 0)    	 -Standard return value upon exit.
*************************************************************************/
int board_setup(int rows, int cols, char **board, int op){

	board_rows = rows;
	board_cols = cols; 
	board_size = rows * cols;

	if (!op){
		*board = (char *) malloc(board_size * sizeof(char));
		board_clear(*board);
	}
	
	return 0;
}

/*************************************************************************
* Function: board_clear
* 
* Clears the current board to all empty spaces.
*
* @args[0] (char *board) -The connect four board.
* @return  (int 0)    	 -Standard return value upon exit.
*************************************************************************/
int board_clear(char *board){

	char *ptr;
	for(ptr = board; ptr < board + board_size; ptr++)
		*ptr = ' ';
	
	return 0;
}

/*************************************************************************
* Function: board_print
* 
* GUI display of the board tiles and the player pieces inside them.
* Only prints column numbers nicely up to a value of 99, anything above
* that will start to overflow.
*
* @args[0] (char *board) -The connect four board.
* @return  (int 0)       -Standard return value upon exit.
*************************************************************************/
int board_print(char *board){

	char *ptr = board;
	int i;
	for(i = 0; i < board_size; i++){
		if(i % board_cols == 0){
			printf("\n");
			board_print_horizontal_line();
			printf("|");
		}	
		printf("%c", *ptr++);
		printf("|");
	}
	printf("\n");
	board_print_horizontal_line();

	int column_number = 1;
	int tens = 0;
	for(i = 0; i < (board_cols * 2) + 1; i++){
		if(i % 2){
			if(column_number % 10 == 0){
				tens++;
			}
			column_number++;
			printf(" %d", tens);
		}
	}
	printf("\n");
	column_number = 1;
	for(i = 0; i < (board_cols * 2) + 1; i++){
		if(i % 2){
			if(column_number == 10){
				column_number = 0;
			}
			printf(" %d", column_number++);
		}
	}

	return 0;
}

/*************************************************************************
* Function: board_print_horizontal_line
* 
* Prints a straight horizonatal line across the screen.
* 
* @args[0] (void)
* @return  (int 0) -Standard return value upon exit.
*************************************************************************/
int board_print_horizontal_line(){

	int i;
	for(i = 0; i < (board_cols * 2) + 1; i++){
		printf("-");
	}
	printf("\n");

	return 0;
}

/*************************************************************************
* Function: board_refresh
*
* Clears the console, reprints the board to console. 
*
* @args[0] (char *board) -The connect four board.
* @return  (int 0)       -Standard return value upon exit.
*************************************************************************/
int board_refresh(char *board){
	system("clear");
	board_print(board);
	printf("\n\n");

	return 0;
}