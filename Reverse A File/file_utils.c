/*************************************************************************
* File: file_utilis.c
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
#include <sys/stat.h>
#include "file_utils.h"

/*************************************************************************
* --- Function: read_file ---
* 
* Recieves a file name, and a pointer to the memory address of a pointer
* to the message(buffer) that is to be wrote to. Opens the file to read
* from. Calculates the amount of space that needs to be allocated. Read
* contents from the file and store them in buffer. Then close the file.
*************************************************************************/
int read_file(char *filename, char **buffer) {

	// Open the file, handle errors.
	FILE *file; 
	if((file = fopen(filename, "rb")) == NULL) {
		perror("Error opening file");
		exit(0);
	}

	// Determine the size of the file.
	struct stat st;
    stat(filename, &st);
    int filesize = st.st_size;

	// Allocate memory for the buffer based on file size, handle errors.
	*buffer = malloc((filesize + 1) * sizeof(*buffer));
	if(*buffer == NULL) {
		fprintf(stderr, "Memory allocation failed");
		exit(0);
	}

	// Read from file, store contents into buffer.
	fread(*buffer, sizeof(char), filesize, file);
	(*buffer)[filesize] = '\0';

	// Close the file, handle errors
	if (fclose(file) != 0) {
		perror("Error closing file");
	}

	return filesize;
}



/*************************************************************************
* --- Function: write_file ---
* 
* Recieves a file name, a message, and the size of the message. Opens the
* file to write to, writes the message to the file, then closes the file.
*************************************************************************/
int write_file(char *filename, char *buffer, int size) {

	// Open the file, handle errors.
	FILE *file;
	if((file = fopen(filename, "wb")) == NULL) {
		perror("Error opening file");
	}

	// Write the contents of buffer to file.
	fwrite(buffer, 1, size, file);

	// Close the file, handle errors.
	if (fclose(file) != 0) {
		perror("Error closing file");
	}

	return 0;
}



/*************************************************************************
* --- Function: reverse_buffer  ---
*
* Takes the buffer and uses the bitwise exclusive OR assignment operator 
* to swap the places of two characters within the array. Character 'a' 
* being the first character in the array, and character b being the last
* character in the array. Example code calculation below-
*
* int x = 'k';
* int y = 'w';
*
* Ascii character 'k' = 107 in base_10, 1101011 in base_2.
* Ascii character 'w' = 119 in base_10, 1110111 in base_2.
*
* 1) x ^= y in base_2 is (1101011 XOR 1110111) which equals 0011100.
* 2) y ^= x in base_2 is (1110111 XOR 0011100) which equals 1101011. // Y
* 3) x ^= y in base_2 is (0011100 XOR 1101011) which equals 1110111. // X
*
* int x = 1101011 before, and 1110111 after.
* int y = 1110111 before, and 1101011 after. 
*
* Thus we can see that by using XOR on two characters we can essentially
* swap the values at their memory locations.
*************************************************************************/
int reverse_buffer(char *buffer) {

	int a = 0;
	int b = 0;
	b = (strlen(buffer) - 1);
	for(a = 0; a < b; a++, b--) {
		buffer[a] ^= buffer[b];
		buffer[b] ^= buffer[a];
		buffer[a] ^= buffer[b];
	}

	return 0;


}