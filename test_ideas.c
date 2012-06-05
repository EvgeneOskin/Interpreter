%top{
        int quit_INDEX = 0, num_vars = 0, num_bracket = 0;
	int num_lines = 0, num_operations = 0;
}
%%
\n     { 
         printf ("\nyou input\nlines = %d,\noperations = %d,\nvars=%d,\nbrackets=%d\n\n",
                        num_lines, num_operations, num_vars, num_bracket);
         num_vars = 0;
         num_bracket = 0;
         num_lines = 0;
         num_operations = 0;
        }
"+"|"-"|"/"|"*"   ++num_operations;
[a-pr-zA-Z]+    num_vars++;
"("  num_bracket++;
q    {
       printf ("i\'m quiting...\n");
       return; 
     }
%%
main()
{
        yylex();
}
