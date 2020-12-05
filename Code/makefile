STANDARD = -Wall -Wextra -pedantic -ansi
OPTIMIZE = -O3
SANITIZE= -fsanitize=undefined -fsanitize=address -g3
PROFILE = -pg -g3
SDLC = `sdl-config --cflags`
SDLL = `sdl-config --libs`
CC = gcc


all: quicksrandbuiltin quicksrandnolib quickssortbuiltin quickssortnolib

quicksrandbuiltin : quicks.c
	@$(CC) $(STANDARD) $(OPTIMIZE) -DBUILTIN -DRAND quicks.c -o quicksrandbuiltin
	@/usr/bin/time --format "%U" ./quicksrandbuiltin

quicksrandnolib : quicks.c
	@$(CC) $(STANDARD) $(OPTIMIZE) -DRAND quicks.c -o quicksrandnolib
	@/usr/bin/time --format "%U" ./quicksrandnolib

quickssortbuiltin : quicks.c
	@$(CC) $(STANDARD) $(OPTIMIZE) -DBUILTIN -DSORT quicks.c -o quickssortbuiltin
	@/usr/bin/time --format "%U" ./quickssortbuiltin

quickssortnolib : quicks.c
	@$(CC) $(STANDARD) $(OPTIMIZE) -DSORT quicks.c -o quickssortnolib
	@/usr/bin/time --format "%U" ./quickssortnolib

clean:
	rm -f quicksrandbuiltin quicksrandnolib quickssortbuiltin quickssortnolib
