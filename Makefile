CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror
DEBUG = -g #-fsanitize=address
CPPFLAGS = _GNU_SOURCE
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm

MODULES   = entities parser sdl game_loop
SRC_DIR   = $(addprefix src/, $(MODULES))
SRC       = $(foreach sdir, $(SRC_DIR), $(wildcard $(sdir)/*.c))
INCLUDES  = $(addprefix -I,$(SRC_DIR))
OBJ = $(SRC:.c=.o)

BIN = game
BROWSER = chromium

.DEFAULT_GOAL := check
.PHONY: all clean test doc

all: $(SRC)
	$(CC) $(INCLUDES) -D$(CPPFLAGS) $(CFLAGS) $(DEBUG) $(SRC) -o ${BIN} $(LDFLAGS)

clean:
	${RM} ${OBJ} ${BIN}
	rm -rf doc

doc:
	doxygen src/Doxyfile
	$(BROWSER) doc/html/index.html

check: all
	./$(BIN) tests/maps/level2.map

test: all
	echo 'No test suite written yet'
