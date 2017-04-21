/*************************************************************************
* File:   file_utilis.c
* Author: Norman Cunningham
* Class:  CIS 343
* Task:   Project 3
*
* Description: The basic utility functions that correspond to the "file"
* 			   operations of the game. 
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "file_utils.h"

/*************************************************************************
* Function: read_file
* 
* Reads a previously loaded game state from the game save file. Creates the
* game board based on the dimensions of the saved game. Fills in the game tiles.
*
* @args[0] (char **board) -Pointer to the connect four board.
* @args[1] (int *cols)    -Pointer to the number of columns in the board.
* @args[2] (int *rows)    -Pointer to the number of rows in the board.
* @args[3] (int *player)  -Pointer to the number needed to win.
* @return  (int 0)        -Load succesful.
* @return  (int 1)        -Load failed(no data to read).
*************************************************************************/
int file_read(char **board, int *rows, int *cols, int *connect){

	// Open the file, handle errors.
	FILE *file; 
	char filename[] = "connect_4.txt";
	if((file = fopen(filename, "r")) == NULL) {
		perror("Error opening file");
		exit(0);
	}

	// Determine the size of the file.
	struct stat st;
    stat(filename, &st);
    int filesize = st.st_size;

    // Read from the file if there is data to read.
    if (filesize > 0){
    	free(*board);

    	int i = 0;
    	char c;
    	char *ptr;
    	char temp[10];
    	int point;
    	do { 

    		// NOTE: ifs go 0, 2, 4 because they're skipping '\n' characters.

 
    		if(i == 0){
    			// Get the row length.
    			fgets(temp, 10, file);
    			sscanf (temp, "%d", &point);
    			*rows = point;		
    		}
    		else if(i == 1){
    			// Get the column length.
    			fgets(temp, 10, file);
    			sscanf (temp, "%d", &point);
    			*cols = point;
    		}
    		else if (i == 2){
    			// Get the connect length.
    			fgets(temp, 10, file);
    			sscanf (temp, "%d", &point);
    			*connect = point;
    		}
    		else if (i == 3){
    			// Allocate memory based on board dimensions.
    			*board = malloc(((*rows) * (*cols)) * sizeof(char));
    			ptr = *board;

    		}
    		else if(i > 3 && i < ((*rows * *cols) + 4)){
    			// Read the tile data.
    			c = fgetc(file);
    			if (c != 'X' && c != 'O')
    				c = ' ';
    			*(ptr + (i - 4)) = c;
    		}
    		else{
    			c = fgetc(file);
    		}
    		i++;
		}
		while (c != EOF);
	}
	else{
		return 1;
	}

	// Close the file, handle errors
	if (fclose(file) != 0) {
		perror("Error closing file");
	}

	return 0;
}



/*************************************************************************
* Function: write_file
* 
* Recieves the playing board, and the board dimensions; saves them to file.
*
* @args[0] (char *board) -The connect four board.
* @args[1] (int cols)    -The number of columns in the board.
* @args[2] (int rows)    -The number of rows in the board.
* @args[3] (int player)  -The number needed to win.
* @return  (int 0)       -Standard return value upon exit.
*************************************************************************/
int file_write(char *board, int cols, int rows, int connect){

	// Open the file, handle errors.
	FILE *file;
	char filename[] = "connect_4.txt";
	if((file = fopen(filename, "w")) == NULL) {
		perror("Error opening file");
		while(1);
	}

	// Write the contents of buffer to file.
	fprintf(file, "%d\n", cols);
	fprintf(file, "%d\n", rows);
	fprintf(file, "%d\n", connect);
	fprintf(file, "%s\n", board);

	// Close the file, handle errors.
	if (fclose(file) != 0) {
		perror("Error closing file");
	}

	return 0;
}

