/*************************************************************************
* File:   file_utils.h
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*
* Description: The basic utility functions that correspond to the "board"
* 			   operations of the game. 
*************************************************************************/
#ifndef GVSU343PROJECT3BU
#define GVSU343PROJECT3BU



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
int board_setup(int, int, char **, int);



/*************************************************************************
* Function: board_clear
* 
* Clears the current board to all empty spaces.
*
* @args[0] (char *board) -The connect four board.
* @return  (int 0)    	 -Standard return value upon exit.
*************************************************************************/
int board_clear(char *);



/*************************************************************************
* Function: board_print
* 
* GUI display of the board tiles and the player pieces inside them.
*
* @args[0] (char *board) -The connect four board.
* @return  (int 0)    -Standard return value upon exit.
*************************************************************************/
int board_print(char *);




/*************************************************************************
* Function: board_print_horizontal_line
* 
* Prints a straight horizonatal line across the screen.
* 
* @args[0] (void)
* @return  (int 0) -Standard return value upon exit.
*************************************************************************/
int board_print_horizontal_line();




/*************************************************************************
* Function: board_refresh
*
* Clears the console, reprints the board to console. 
*
* @args[0] (char *board) -The connect four board.
* @return  (int 0)       -Standard return value upon exit.
*************************************************************************/
int board_refresh(char *);



#endif