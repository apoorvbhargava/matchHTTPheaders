all: matchHeaders

matchHeaders:matchHeaders.c
	cc -g -o matchHeaders matchHeaders.c -Wall

clean: 
	rm matchHeaders