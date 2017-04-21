/*************************************************************************
* File: reverse.c
* Author: Norman Cunningham
* Class: CIS 343
* Task: Project 1
*
* Description: For this project you will create a utility that will take
* as its parameters two filenames. The two filenames will be an input file
* and an output file. When the program completes, the input file will have
* all of its text written in reverse to the output file. 
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

/*************************************************************************
* --- Main Function ---
* 
* Recieves two command line arguments, the first is a file that is to be 
* reversed, the second will be the first file reversed. 
*************************************************************************/
int main(int argc, char **argv) {

	if(argc != 3) {
		printf("Invalid number of arguments for program: %s\n", argv[0]);
		return 0;
	}

	char *regularfile = argv[1];
	char *reversefile = argv[2];
	char *buffer = NULL;
	int filesize = 0;

	// Read the contents of the file and store it to buffer.
	filesize = read_file(regularfile, &buffer);

	// Take the buffer and reverses it.
	reverse_buffer(buffer);

	// Store the contents of buffer onto the reversed file.
	write_file(reversefile, buffer, filesize);

	// Deallocate buffers memory.
	free(buffer);
	return 0;
}