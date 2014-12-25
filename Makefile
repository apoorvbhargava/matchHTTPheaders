all: matchHeaders

matchHeaders:matchHeaders.c
	cc -o matchHeaders matchHeaders.c -Wall

clean: 
	rm matchHeaders *.out