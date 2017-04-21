/*************************************************************************
* File:   file_utils.h
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*
* Description: The basic utility functions that correspond to the "file"
* 			   operations of the game. 
*************************************************************************/
#ifndef GVSU343PROJECT1
#define GVSU343PROJECT1



/*************************************************************************
* Function: read_file
* 
* Reads a previously loaded game state from the game save file. Creates the
* game board based on the dimensions of the saved game. Fills in the game tiles.
*
* @args[0] (char **board) -Pointer to the connect four board.
* @args[1] (int *cols)    -Pointer to the number of columns in the board.
* @args[2] (int *rows)    -Pointer to the number of rows in the board.
* @args[3] (int *player)  -Pointer to the current player.
* @return  (int 0)        -Load succesful.
* @return  (int 1)        -Load failed(no data to read).
*************************************************************************/
int file_read(char **, int *, int *, int *);



/*************************************************************************
* Function: write_file
* 
* Recieves the playing board, and the board dimensions; saves them to file.
*
* @args[0] (char *board) -The connect four board.
* @args[1] (int cols)    -The number of columns in the board.
* @args[2] (int rows)    -The number of rows in the board.
* @args[3] (int player)  -The current player.
* @return  (int 0)       -Standard return value upon exit.
*************************************************************************/
int file_write(char *, int, int, int);



#endif