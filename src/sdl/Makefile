CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror
LFLAGS = -lSDL2
OBJS = sdl.c sdl_function.c 
OBJ_NAME = sdl_windows

all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)

clean:
	${RM} $(OBJ_NAME)
