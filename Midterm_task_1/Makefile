CC=gcc
C_FLAGS= -Wall -fsanitize=address,undefined -Werror -pedantic -g -lm
.PHONY: all clean
all: main.c
	${CC} -o main main.c ${C_FLAGS}
clean:
	-rm -rf ${TARGETS} ${OBJECTS}
