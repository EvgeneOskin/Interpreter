all:
	bison -d test_grammar.y
	flex test_flex.l
	gcc test_grammar.tab.c lex.yy.c test_func.c -o book_compiled -lfl
