
CC = g++ -O2 -Wno-deprecated 

tag = -i

ifdef linux
tag = -n
endif

main: Record.o Comparison.o ComparisonEngine.o Schema.o File.o DBFile.o y.tab.o lex.yy.o main.o
	$(CC) -o main Record.o Comparison.o ComparisonEngine.o Schema.o File.o DBFile.o y.tab.o lex.yy.o main.o -lfl
	
main.o : main.cc
	$(CC) -g -c main.cc
	
Comparison.o : Comparison.cc
	$(CC) -g -c Comparison.cc
	
ComparisonEngine.o : ComparisonEngine.cc
	$(CC) -g -c ComparisonEngine.cc
	
File.o : File.cc
	$(CC) -g -c File.cc

Record.o : Record.cc
	$(CC) -g -c Record.cc

Schema.o : Schema.cc
	$(CC) -g -c Schema.cc

DBFile.o : DBFile.cc
	$(CC) -g -c DBFile.cc
	
y.tab.o: Parser.y
	yacc -d Parser.y
	sed $(tag) y.tab.c -e "s/  __attribute__ ((__unused__))$$/# ifndef __cplusplus\n  __attribute__ ((__unused__));\n# endif/" 
	g++ -c y.tab.c

lex.yy.o: Lexer.l
	lex  Lexer.l
	gcc  -c lex.yy.c

clean: 
	rm -f *.o
	rm -f *.out
	rm -f y.tab.c
	rm -f lex.yy.c
	rm -f y.tab.h
