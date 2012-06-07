extern int  yylineno;
void yyerror (char *s, ...);

struct ast 
{
  int nodetype;
  struct ast *l;
  struct ast *r;
};

struct numval
{
  int nodetype;
  char var;
};

struct ast* newast(int nodetype, struct ast *l, struct ast *r);
struct ast* newvar (char v);

void eval (struct ast*);
void treefree (struct ast*);

