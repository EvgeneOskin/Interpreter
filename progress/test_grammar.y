%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "test_DEF.h"
%}

%union 
{
  struct ast *a;
  char v;
}
%token <v> VARS
%token EOL QUIT

%type <a> exp factor term

%%
line:
  | line exp EOL  
   { 
    printf("=");
    eval($2);
    treefree($2);
    printf("\n");
   }
  | line EOL { printf("you must type smth whitch make a sense, or type \"quit\"\n"); }
  | line QUIT 
  {
    printf ("i\'m closing...\n"); 
    return; 
  }
  ;
exp: factor
  | exp '+' factor   {  $$ = newast('+', $1,$3); }
  | exp '-' factor   {  $$ = newast('-', $1,$3); }
  ;
factor: term
  | factor '*' term   {  $$ = newast('*', $1,$3); }
  | factor '/' term   {  $$ = newast('/', $1,$3); }
  ;
term: VARS { $$ = newvar ($1); }
  | '(' exp ')' { $$ = $2; }
  | '-' term { $$ = newast ('M', $2, NULL); }
  ;
%%
