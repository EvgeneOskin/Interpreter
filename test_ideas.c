%top{
	int num_lines = 0, num_operations = 0;
}
%%
\n      ++num_lines;
"+"     |
"-"     |
"/"     |
"*"     ++num_operations;
%%
main()
{
	yylex();
	printf( "\nlines = %d, operations = %d\n",
	num_lines, num_operations );
}
