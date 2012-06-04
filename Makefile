all:
	flex test_ideas.c 
	gcc lex.yy.c -o lex_compiled -lfl
