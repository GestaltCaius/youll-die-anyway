CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror 
DEBUG = -g -fsanitize=address 
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

MODULES   = entities parser sdl game_loop 
SRC_DIR   = $(addprefix src/, $(MODULES))
SRC       = $(foreach sdir, $(SRC_DIR), $(wildcard $(sdir)/*.c))
INCLUDES  = $(addprefix -I,$(SRC_DIR))
OBJ = $(SRC:.c=.o)

BIN = game
BROWSER = chromium

.DEFAULT_GOAL := all
.PHONY: all clean test doc

all: $(SRC)
	$(CC) $(INCLUDES) $(CFLAGS) $(SRC) -o ${BIN} $(LDFLAGS)

clean:
	${RM} ${OBJ} ${BIN}
	rm -rf doc

doc:
	doxygen src/Doxyfile
	$(BROWSER) doc/html/index.html

test: all
	echo 'No test suite written yet'
