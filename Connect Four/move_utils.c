/*************************************************************************
* File:   move_utils.c
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*
* Description: The basic utility functions that correspond to the "move"
* 			   operations of the game.
*************************************************************************/
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "move_utils.h"

// Global Varibales
int board_rows;
int board_cols; 

/*************************************************************************
* Function: move_setup
*
* Sets the global variables to the arguments.
*
* @args[0] (int rows) -The number of rows in the board.
* @args[1] (int cols) -The number of columns in the board.
* @return  (int 0)    -Standard return value upon exit.
*************************************************************************/
int move_setup(int rows, int cols){

	board_rows = rows;
	board_cols = cols;

	return 0;
}

/*************************************************************************
* Function: move_receive
*
* Prompts the player to enter a value corresponding to the column they want
* to drop their piece at. Reads from command line until a new line character
* is found. Only stores the first four characters found. If the user enters
* less than four characters, null characters are added to fill the remaining
* space. Return values vary based on user input. Options are save, load, quit,
* a valid integer i, or -1 for a not integer.
*
* @args    (void)
* @return  (int -2) -Return value for "save" operation.
* @return  (int -3) -Return value for "load" operation.
* @return  (int -4) -Return value for "quit" operation.
* @return  (int i)  -See return for function: move_return_number.
*************************************************************************/
int move_receive(){

	// Promt user.
	printf("Enter A Column Number.\n\n");
	
	// Create array to store user input, read from teminal until newline.
	char input[4];
	char c;
	int i = 0;
	while((c = fgetc(stdin)) != '\n'){
		if(i < 4){
			input[i] = c;
			i++;
		}
	}

	// If user input was less than four characters fill the remaining array
	// space with null characters.
	for(; i < 4; i++){
		input[i] = '\0';
	}

	// Check user input for special cases, return reflection of case.
	if(!strcmp(input, "save")){
		return -2;
	}
	else if(!strcmp(input, "load")){
		return -3;
	}
	else if(!strcmp(input, "quit")){
		return -4;
	}

	// Pass a pointer of the user input array to verify that the input is indeed
	// an integer value. If not an integer, return -1, else return the value.
	char *temp = input;
	i = move_return_number(temp);

	return i;
}

/*************************************************************************
* Function: move_validate
*
* Check that the move is within the range of valid columns. Decrement the 
* value of move to fit with the board index(starts at zero, while columns
* start at 1). Check that at least the "top" position of the selected column
* is an open spot. If so, return 1, else 0 for an invalid move.
*
* @args[0] (char *board) -The connect four board.
* @args[0] (int move)    -The column the user selected.
* @return  (int 0)       -The move was not valid.
* @return  (int 1)       -The move was valid.
*************************************************************************/
int move_validate(char *board, int move){

	// Check that the move fits the column bounds.
	if(move > 0 && move <= board_cols){

		// Decrement because array index starts at zero, while gui index
		// starts at one. User entered based on gui.
		move--;

		// Check that the top position of the selected column is open.
		if(*(board + move) == ' ')
			return 1;
	}

	return 0;
}

/*************************************************************************
* Function: move_execute
*
* Given that at least the top row of the user selected column is open, check
* to see how fas doen the piece would drop. Once another piece is found, or 
* we reach bleow the bottom of the board, place the piece ubove that condition.
*
* @args[0] (char *board)   -The connect four board.
* @args[1] (int move)      -The column selected.
* @args[2] (char player)   -The player who selected the move.
* @args[3] (int *position) -The position the piece ends at.
* @return  (int)           -Standard return value upon exit.
*************************************************************************/
int move_execute(char *board, int move, char player, int *position){
	
	// Decrement move to have move match array indexing.
	move--;

	// Loop until another piece is found, or out of bounds condition.
	int j = 1;
	while((*(board + (move + (j * board_cols)))) == ' '){
		j++;
		if(j == (board_rows)){
			break;
		}
	}

	// Decrement to place piece one highed than the break condition.
	j--;

	// Place the piece.
	*(board + (move + (j * board_cols))) = player;

	// Store the location of that piece.
	*position = (move + (j * board_cols));
	
	return 0;	
}

/*************************************************************************
* Function: move_return_number
*
* Is passed a character array and determines if it is a valid number. 
* Does not count whitespaces. Will return the character array as an integer.
* Any none digits charaters found within the character array will result 
* in a return of -1, not a valid number.
*
* @args[0] (char *input) -The user input to check.
* @return  (int -1)      -The input was not an integer.
* @return  (int value)   -The input was an integer, reurns that intger.
*************************************************************************/
int move_return_number(char *input){

	char c;          // Character to run through the array.
	int value = 0;   // The number interpretation of input.
	int pow_val = 0; // The current exponent.
	int is_num = 0;  // Boolean for is input an integer.
	int i;           // Incrementer for the loop.

	// Loop through input backwards. Store the character in c.
	for(i = sizeof(input) - 1; i >= 0; i--){
		c = *(input + i);

		if(isspace(c) || c == '\0'){
			// Do Nothing.
		}
		else if(isdigit(c)){
			// Calculate the value given its significance position.
			int x = c - '0';
			int y = (int) pow(10, pow_val++);
			value = value + (x * y);
		}
		else{
			is_num++;
		}
	}

	// Return based on if the input was an integer.
	if(is_num != 0)
		return -1;
	else
		return value;
}