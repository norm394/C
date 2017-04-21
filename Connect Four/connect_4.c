/*************************************************************************
* File:   connect_4.c
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "arg_utils.h"
#include "game_utils.h"
#include "board_utils.h"
#include "move_utils.h"
#include "file_utils.h"

// Prototype
int setup(int, int, char **, char *, int);

/*************************************************************************
* Function: main
*
* The main function that holds the game loop. Calls various other functions
* to execute tasks related to the game.
*
* @args[0] (int argc)   -The number of command line arguments.
* @args[0] (int **argv) -The vector of command line arguments.
* @return  (int 0)      -Standard return value upon exit.
*************************************************************************/
int main(int argc, char **argv){

	// Local variables
	char *board = NULL;
	int position;
	int connect_length;
	int move;
	int move_status;
	char player;
	
	struct arguments args_setup;
	args_setup = setup_args(argc, argv);

	int rows = args_setup.height;
	int cols = args_setup.width;

	// Load a previous game save or start a new game.
	if(args_setup.load != NULL){
		file_read(&board, &rows, &cols, &connect_length);
		setup(rows, cols, &board, &player, 1);
		printf("Game was loaded\n\n");
	}
	else {
		setup(rows, cols, &board, &player, 0);
		connect_length = args_setup.connect;
	}

	// Display the board.
	board_refresh(board);

	// Outer Game Loop:
	while(1){

		// Inner Game Loop:
		while(1){

			// Display the board.
			board_refresh(board);

			// Get a move from the current player, evaluate the input, 
			// repeat for invalid inputs/saves/loads.
			do{

				// Reset the move status, prompt the current player.
				move_status = 0;
				printf("Player %c: ", player);

				// Get the current players move choice.
				move = move_receive();

				// Check the move for condition; save/load/quit/move.
				if (move == -2){
					// Save.
					file_write(board, rows, cols, connect_length);
					board_refresh(board);
					printf("Game was saved\n\n");
				}
				else if(move == -3){
					// Load.
					int read = file_read(&board, &rows, &cols, &connect_length);
					if(read == 0){
						setup(rows, cols, &board, &player, 1);
						board_refresh(board);
						printf("Game was loaded\n\n");
					}						
					else
						printf("There is no saved game to load.\n");
				}
				else if(move == -4){
					// Quit.
					free(board);
					return 0;
				}
				else{
					// Check if the move is valid given the state of the board.
					move_status = move_validate(board, move);
					board_refresh(board);
					if(!move_status)
						printf("Invalid Entry. Please Try Again.\n\n");
				}
			}
			while(move_status == 0);

			// The move was valid so we execute.
			move_execute(board, move, player, &position);

			// Check if the last move satisfied a win condition. If so,
			// break the inner game loop.
			if(game_status(board, position, player, connect_length))
				break;

			// Change players.
			game_change_player(&player);

		}

		// Outer loop, means a win coindition was met. Refresh the board.
		//board_refresh(board);
		printf("\nPlayer %c Wins!!\n\n", player);
		
		// Prompt the user if they want to play again, 'y' means yes,
		// any other combination means no.
		printf("Enter 'y' to play again, any other key to exit\n");
		char c, d;
		int i = 0;
		do{	
			c = fgetc(stdin);
			if(i++ == 0)
				d = c;
		}while(c != '\n');

		// The user did not want to play again, break the outer loop, free
		// the boards memory, return main to exit the program.
		if (d != 'y' || i > 2)
			break;

		// The user wants to play again, so reset the board to null.
		board_clear(board);
	}

	// Free the boards memory before exiting.
	if(board != NULL)
		free(board);
	
	return 0;
}

/*************************************************************************
* Function: setup
*
* Setup is used to setup the game. Its main function it to pass arguments 
* for other areas to initialize the board size. This allows to pass board 
* size arguments once durring the setup phase versus every function call.
*
* @args[0] (int rows)     -The number of rows in the board.
* @args[1] (int cols)     -The number of columns in the board.
* @args[2] (char **board) -The connect four board.
* @args[3] (char *player) -The current player's symbol.
* @args[4] (int op)       -Zero for new blank board, one skip board init.
* @return  (int 0)        -Standard return value upon exit.
*************************************************************************/
int setup(int rows, int cols, char **board, char *player, int op){

	game_setup(rows, cols, player);
	board_setup(rows, cols, board, op);
	move_setup(rows, cols);

	return 0;
}