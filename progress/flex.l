%{
  #include "grammar.tab.h"
%}

%%
"*"                {  return yytext[0]; }
"*("               {  return OP;  }
")*"               {  return CP; }
"+"|"-"|"/"|")"|"("  {  return yytext[0]; }
"quit"             {
                     return QUIT; }
[a-zA-Z]           {
                     yylval.v = yytext [0];
                     return VARS;
                    }  
\n                  {
                     return EOL; }
[ \t]               {}
.                   {
                      printf ("I don't understand what you want.", yytext);
                      return Error_exit;
                    }
