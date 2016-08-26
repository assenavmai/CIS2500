
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g -Iinclude


music:
	gcc $(CFLAGS) -Iinclude src/main.c src/linkedList.c src/functions.c -o bin/run

test: 
	gcc $(CFLAGS) src/listTest.c src/linkedList.c -o bin/listTest

clean:
	@ rm *.o
