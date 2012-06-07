#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include "test_DEF.h"

struct ast* newast(int nodetype, struct ast *l, struct ast *r)
{
  struct ast *a = malloc(sizeof(struct ast));
  
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
  struct numval *a = malloc(sizeof(struct numval));
  
  if (!a) 
  {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'K';
  a->var = v;
  return (struct ast *) a;
}

void eval(struct ast *a)
{
  switch (a->nodetype) {
  case 'K': 
    {
      printf ("%c", ((struct numval *)a)->var); break;
    }
  case '+':
    {
      eval(a->l);
      printf("+");
      eval(a->r); 
      break;
    }  
  case '-': 
    {
      eval(a->l);
      printf("-");
      eval(a->r); 
      break;
    } 
  case '*':
    {
      eval(a->l);
      printf("*");
      eval(a->r); 
      break;
    } 
  case '/': 
    {
      eval(a->l);
      printf("/");
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
  default: printf("internal error: bad node %c\n", a->nodetype);
  }
}

void treefree(struct ast *a)
{
  switch(a->nodetype) {

    /* two subtrees */
  case '+':
  case '-':
  case '*':
  case '/':
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

void yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

int
main()
{
  printf ("Hello, my master\ntype my a \"quit\" for my closing\n");
  return yyparse();
}
