all:
	bison -d grammar.y
	flex flex.l
	gcc grammar.tab.c lex.yy.c func.c -o interpreter -lfl
