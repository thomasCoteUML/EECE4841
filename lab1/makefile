# Makefile for Thomas Cote to be used in UML:EECE4841	

all: prog

prog: lab1.o CoteLib.o
	gcc -o lab1 lab1.o CoteLib.o 
	
%.o: %.c
	gcc -c -w lab1.c CoteLib.c CoteLib.h
	
clean:
	rm -f *.o *.gch
