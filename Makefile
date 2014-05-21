all:
	gcc -o example example.c debug.c -std=c99
clean:
	rm example
