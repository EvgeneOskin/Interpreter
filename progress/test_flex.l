%{
  #include "test_grammar.tab.h"
%}

%%
"+"|"-"|"*"|"/"    { return yytext[0]; }
"*("|")*"          { printf("you type a bracket with multiple"); }
"quit"             { return QUIT; }
[a-zA-Z]           {
                     yylval.v = yytext [0];
                     return VARS;
                    }  
\n                  { return EOL; }
[ \t]               {}
.                   { printf ("I don't understandem what you want\n %s", yytext); }
