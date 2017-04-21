/*************************************************************************
* File: file_utils.h
* Author: Norman Cunningham
* Class: CIS 343
* Task: Project 1
*
* Description: For this project you will create a utility that will take
* as its parameters two filenames. The two filenames will be an input file
* and an output file. When the program completes, the input file will have
* all of its text written in reverse to the output file. 
*************************************************************************/

#ifndef GVSU343PROJECT1
#define GVSU343PROJECT1

/*************************************************************************
* --- Function: read_file ---
* 
* Recieves a file name, and a pointer to the memory address of a pointer
* to the message(buffer) that is to be wrote to. Opens the file to read
* from. Calculates the amount of space that needs to be allocated. Read
* contents from the file and store them in buffer. Then close the file.
*************************************************************************/
int read_file(char *filename, char **buffer);


/*************************************************************************
* --- Function: write_file ---
* 
* Recieves a file name, a message, and the size of the message. Opens the
* file to write to, writes the message to the file, then closes the file.
*************************************************************************/
int write_file(char *filename, char *buffer, int size);


/*************************************************************************
* --- Function: reverse_buffer  ---
*
* Takes the buffer and uses the bitwise exclusive OR assignment operator 
* to reverse the buffer. 'hello' become 'olleh'.
*************************************************************************/
int reverse_buffer(char *buffer);

#endif