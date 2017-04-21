/*************************************************************************
* File: game_utils.c
* Author: Norman Cunningham
* Class: CIS 343
* Task: Project 3
*
* Description: The basic utility functions that correspond to the "game"
* 			   operations of the game.
*************************************************************************/
#ifndef GVSU343PROJECT3GU
#define GVSU343PROJECT3GU



/*************************************************************************
* Function: game_setup
*
* Sets the global variables to the arguments. Sets the players symbol.
*
* @args[0] (int rows)     -The number of rows in the board.
* @args[0] (int cols)     -The number of columns in the board.
* @args[0] (char *player) -The current player's symbol.
* @return  (int 0)        -Standard return value upon exit.
*************************************************************************/
int game_setup(int, int, char *);



/*************************************************************************
* Function: game_change_player
*
* Upon a successful completion of a turn by a user, change player symbols
* to allow for the next player too take their turn.
*
* @args[0] (char *player) -The players symbol.
* @return  (int 0)        -Standard return value upon exit.
*************************************************************************/
int game_change_player(char *);



/*************************************************************************
* Function: game_status
*
* Returns whether or not the current player has met a winning condition.
* Calls four separate functions to check winning condition based on, vertical
* columns, horizontal rows, and both diagonals.
*
* @args[0] (char *board)        -The connect four board.
* @args[0] (int position)       -The position of the last piece moved.
* @args[0] (char player)        -The current player's symbol.
* @args[0] (int connect_length) -The number of pieces needed in a row to win.
* @return  (int 0)              -The current player has not won the game.
* @return  (int 1)              -The current player has won the game.
*************************************************************************/
int game_status(char *, int, char, int);



/*************************************************************************
* Function: game_check_vertical
*
* Checks: ( | ) direction.
*
* Check if a vertical column win condition was met for the current player.
* This function checks the next spot below the last moved piece until end
* of board bounds are reached or a different player piece is found. It only 
* vertically checks downwards because it is not possible to place a piece
* underneath another piece.
*
* @args[0] (char *board)  -The connect four board.
* @args[0] (int position) -The position of the last piece moved.
* @args[0] (char player)  -The current player's symbol.
* @return  (int found)    -The number of times the players symbol was found.
*************************************************************************/
int game_check_vertical(char *, int, char);



/*************************************************************************
* Function: game_check_horizontal
*
* Checks: ( - ) direction.
*
* Check if a horizontal row win condition was met for the current player.
* This function checks the next spot to the left and right of the last moved
* piece until edge of board bounds are reached, a different player piece is 
* found, or an empty space if found. 
*
* @args[0] (char *board)  -The connect four board.
* @args[0] (int position) -The position of the last piece moved.
* @args[0] (char player)  -The current player's symbol.
* @return  (int found)    -The number of times the players symbol was found.
*************************************************************************/
int game_check_horizontal(char *, int, char);



/*************************************************************************
* Function: game_check_diagonal_forward
*
* Checks: ( \ ) direction.
*
* Check if a forwards diagonal win condition was met for the current player.
* This function checks the next board position under the condition of position
* plus one row plus one column, and minus one row minus one column.
*
* @args[0] (char *board)  -The connect four board.
* @args[0] (int position) -The position of the last piece moved.
* @args[0] (char player)  -The current player's symbol.
* @return  (int found)    -The number of times the players symbol was found.
*************************************************************************/
int game_check_diagonal_forward(char *, int, char);



/*************************************************************************
* Function: game_check_diagonal_backward
*
* Checks: ( / ) direction.
*
* Check if a backwards diagonal win condition was met for the current player.
* This function checks the next board position under the condition of position
* plus one row minus one column, and minus one row minus one column.
*
* @args[0] (char *board)  -The connect four board.
* @args[0] (int position) -The position of the last piece moved.
* @args[0] (char player)  -The current player's symbol.
* @return  (int found)    -The number of times the players symbol was found.
*************************************************************************/
int game_check_diagonal_backward(char *, int, char);



#endif