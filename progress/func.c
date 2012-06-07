#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include "DEF.h"

struct ast* newast(int nodetype, struct ast* l, struct ast* r)
{
  struct ast* a = malloc(sizeof(struct ast));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->l = l;
  a->r = r;
  return a;
}
struct ast* newvar(char v)
{
  struct numval* a = malloc(sizeof(struct numval));
  
  if (!a) 
  {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'K';
  a->var = v;
  return (struct ast* ) a;
}

void eval(struct ast* a)
{
  switch (a->nodetype) {
  case 'K': 
    {
      printf ("%c", ((struct numval* )a)->var); 
      break;
    }
  case '+':
  case '-': 
  case '*':
  case '/': 
    {
      eval(a->l);
      printf("%c",a->nodetype);
      eval(a->r); 
      break;
    }  
  case 'M': 
    {
      printf("(-"); 
      eval(a->l);
      printf(")"); 
      break;
    }
  case 'm':
  case 'c':
  case 'o':
    {
      if (bracket_INDEX != 0)
      {
        mult = newast(a->nodetype,a->l,a->l);
        bracket_INDEX--;
      }
      printf("(");
      eval(mult->l);
      printf("*");
      eval(a->r);
      printf(")");
      break;
    }
  case 'p':
    {
      eval(a->l);
      printf("+");
      eval(mult->l);
      printf("*");
      eval(a->r);
      break;
    }
  case 'n':
    {
      eval(mult->l);
      printf("*");
      eval(a->l);
      printf("-");
      eval(mult->l);
      printf("*");
      eval(a->r);
      break;
    }
  default: printf("\ninternal error: bad node %c\n", a->nodetype);
  }
}

void treefree(struct ast* a)
{
  switch(a->nodetype) {

    /* two subtrees */
  case '+':
  case '-':
  case '*':
  case '/':
  case 'm':
  case 'c':
  case 'o':
  case 'p':
  case 'n':
    treefree(a->r);

    /* one subtree */
  case '|':
  case 'M':
    treefree(a->l);

    /* no subtree */
  case 'K':
    free(a);
    break;
  default: printf("internal error: free bad node %c\n", a->nodetype);
  }
}

void yyerror(char* s, ...)
{
  printf("%d: error: ", yylineno);
  printf("%s", s);
  printf("\n");
}
main()
{
  printf ("Hello, my master.\nType my a \"quit\" for my closing.\n");
  mult = newast ('m', NULL, NULL);
  printf("> ");
  bracket_INDEX;
  return yyparse();
}
