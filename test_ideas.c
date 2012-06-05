%top{
        int quit_INDEX = 0, num_vars = 0, num_bracket = 0;
	int num_lines = 0, num_operations = 0, bracket_INDEX = 0;
        void output_analyse();
}
%%
\n     { 
         if (bracket_INDEX != 0)
         {
             printf ("you have error in brackets\n");
             return;
         }
         output_analyse();
        }
"+"|"-"|"/"|"*"   ++num_operations;
"quit"    {
       printf ("i\'m quiting...\n");
       return; 
     }
[a-zA-Z]+    num_vars++;
"("  {
      num_bracket++;
      bracket_INDEX++;
     }
")"  {
      bracket_INDEX--;
      if (bracket_INDEX < 0)
        {
          printf ("you have error in brackets\n");
          return;
        }
     }

%%
void output_analyse()
{
  printf ("\nyou input\nlines = %d,\noperations = %d,\nvars=%d,\nbrackets=%d\n\n",
                        num_lines, num_operations, num_vars, num_bracket);
  num_vars = 0;
  num_bracket = 0;
  num_lines = 0;
  num_operations = 0;      
}
main()
{
        yylex();
}
