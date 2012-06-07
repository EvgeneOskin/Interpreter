%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "DEF.h"
%}

%union 
{
  struct ast* a;
  char v;
}
%token <v> VARS
%token EOL QUIT
%token OP CP
%token Error_exit

%type <a> exp factor term bracket IB_exp

%%
line:
  | line exp EOL  
   { 
    printf("=");
    eval($2);
    treefree($2);
    printf("\n> ");
   }
  | line EOL { printf("you must type smth whitch make a sense, or type \"quit\"\n> "); }
  | line QUIT 
  {
    printf ("i\'m closing...\n"); 
    return; 
  }
  | line Error_exit { printf("\n> ");}
  ;
exp: bracket
  | exp '+' bracket  {  $$ = newast ('+', $1, $3); }
  | exp '-' bracket  {  $$ = newast ('-', $1, $3); }
  ;
bracket: factor
  | factor OP IB_exp ')'
  {
    $$ = newast ('o', $1, $3);
    bracket_INDEX++;
  }
  | '(' IB_exp CP factor
  {
    $$ = newast ('c', $4, $2);
    bracket_INDEX++;
  }
  | factor OP IB_exp CP factor
  {
    $$ = newast ('m', newast('*',$1,$5), $3);
    bracket_INDEX++;
  }
  ; 
IB_exp: factor
  | IB_exp '+' factor { $$ = newast ('p', $1, $3); }
  | IB_exp '-' factor { $$ = newast ('n', $1, $3); }
  ;
factor: term
  | factor '*' term   {  $$ = newast ('*', $1, $3); }
  | factor '/' term   {  $$ = newast ('/', $1, $3); }
  ;
term: VARS { $$ = newvar ($1); }
  | '-' term { $$ = newast ('M', $2, NULL); }
  ;
%%
