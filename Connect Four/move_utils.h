/*************************************************************************
* File:   move_utils.h
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*
* Description: The basic utility functions that correspond to the "move"
* 			   operations of the game.
*************************************************************************/
#ifndef GVSU343PROJECT3MU
#define GVSU343PROJECT3MU



/*************************************************************************
* Function: move_setup
*
* Sets the global variables to the arguments.
*
* @args[0] (int rows) -The number of rows in the board.
* @args[1] (int cols) -The number of columns in the board.
* @return  (int 0)    -Standard return value upon exit.
*************************************************************************/
int move_setup(int, int);




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
int move_receive();




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
int move_validate(char *, int);




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
int move_execute(char *, int, char, int *);



/*************************************************************************
* Function: move_return_number
*
* Is passed a character array and determines if it is a valid number. 
* Does not count whitespaces. Will return the character array as an integer.
* Any none digits charaters found within the character array will result 
* in a return of -1, not a valid number.
*
* @args[0] (char *param) -The user input to check.
* @return  (int -1)      -The input was not an integer.
* @return  (int value)   -The input was an integer, reurns that intger.
*************************************************************************/
int move_return_number(char *);



#endif