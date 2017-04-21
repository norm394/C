program: connect_4.o arg_utils.o game_utils.o board_utils.o move_utils.o file_utils.o
	gcc -Wall -lm connect_4.o arg_utils.o game_utils.o board_utils.o move_utils.o file_utils.o

connect_4.o: connect_4.c
	gcc -c -Wall connect_4.c

arg_utils.o: arg_utils.c arg_utils.h
	gcc -c -Wall arg_utils.c

game_utils.o: game_utils.c game_utils.h
	gcc -c -Wall game_utils.c

board_utils.o: board_utils.c board_utils.h
	gcc -c -Wall board_utils.c

move_utils.o: move_utils.c move_utils.h
	gcc -c -Wall move_utils.c

file_utils.o: file_utils.c file_utils.h
	gcc -c -Wall file_utils.c

clean:
	rm *.o 
