CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -lm

all: mathlib-test

mathlib-test: mathlib-test.o e.o euler.o madhava.o viete.o newton.o bbp.o
	$(CC) -o mathlib-test mathlib-test.o e.o euler.o madhava.o viete.o newton.o bbp.o $(LFLAGS)

mathlib-test.o: mathlib-test.c mathlib.h e.c euler.c madhava.c viete.c newton.c bbp.c
	$(CC) $(CFLAGS) -c mathlib-test.c e.c euler.c madhava.c viete.c newton.c bbp.c

clean:
	rm -f mathlib-test mathlib-test.o e.o euler.o madhava.o viete.o newton.o bbp.o

format:
	clang-format -i -style=file *.[ch]
