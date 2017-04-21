#include <stdlib.h>
#include <sys/stat.h>
#include "arg_utils.h"

// Program title and version
const char *argp_program_version = "connect_4 1.0";
// Who to contact if bugs are found
const char *argp_program_bug_address = "anyonebutme@notmyproblem.com";

// Documentation string.
char doc[] = "Connect Four - a simple terminal based connect four game.";

// Description of the required arguments we accept.
char args_doc[] = "";

// This option struct is for any optional arguments.
struct argp_option options[] = {{"width",   'w', "NUM", OPTION_ARG_OPTIONAL, "The width of the game board"}, 
                                {"height",  'h', "NUM", OPTION_ARG_OPTIONAL, "The length of the game board"}, 
                                {"square",  's', "NUM", OPTION_ARG_OPTIONAL, "The width and length of the game board"}, 
                                {"connect", 'c', "NUM", OPTION_ARG_OPTIONAL, "The number of pieces to be connected for a win"}, 
                                {"load",    'l', "FILE", OPTION_ARG_OPTIONAL, "Load the last saved game"}, 
                                { 0 }}; 

// Argp requires us to pass these values in via the argp struct
struct argp argp = { options, parse_opt, args_doc, doc };
// Declare a variable called arguments that is also an
// arguments struct.  Remeber - we can't use the struct
// by just describing it.  We also need to make one.  Sort
// of similar to how we instantiate an object in Java.
struct arguments arguments;

// Our custom function for setting up values once they
// have been parsed from the command line args.
error_t parse_opt(int key, char* arg, struct argp_state *state){
	struct arguments *arguments = state->input;
	switch(key){
		case 'w':
			if(arg[0] == '=')
				arguments->width = atoi(arg+1);
			else
				arguments->width = atoi(arg);
			break;
		case 'h':
			if(arg[0] == '=')
				arguments->height = atoi(arg+1);
			else
				arguments->height = atoi(arg);
			break;
		case 's':
			if(arg[0] == '=')
				arguments->square = atoi(arg+1);
			else
				arguments->square = atoi(arg);
			break;
		case 'c':
			if(arg[0] == '=')
				arguments->connect = atoi(arg+1);
			else
				arguments->connect = atoi(arg);
			break;
		case 'l':
			arguments->load = "load";
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

// Here we setup some default values and override them
// if we get new values from the commandline.
struct arguments setup_args(int argc, char** argv){

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	int width = arguments.width;
	int height = arguments.height;
	int square = arguments.square; 
	int connect = arguments.connect;
	int is_args = 0;

	if(square != 0 && (width != 0 || height != 0)){
		printf("Cannot have value for square and width/height.\n");
		exit(1);
	}
	else if(square != 0){
		width = square;
		height = square;
		is_args++;
	}
	else{
		if(arguments.width == 0)
			width = 7;
		else 
			is_args++;

		if(arguments.height == 0)
			height = 7;
		else
			is_args++;
	}

	if(connect == 0){
		connect = 4;
	}
	else
		is_args++;

	if(connect > width && connect > height){
		printf("Connect value selected would be unreachable.\n");
		exit(1);
	}

	if(arguments.load != NULL && is_args > 0){
		printf("Cannot load a game and set parameters.\n");
		exit(1);
	}
	else if(arguments.load != NULL){
		struct stat st;
		char filename[] = "connect_4.txt";
    	stat(filename, &st);
    	int filesize = st.st_size;
    	if(filesize == 0){
    		printf("There is no saved game to load.\n");
    		exit(1);
    	}
	}

	arguments.width = width;
	arguments.height = height;
	arguments.connect = connect;



	return arguments;
} 