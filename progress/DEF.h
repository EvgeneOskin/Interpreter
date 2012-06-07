extern int  yylineno;
void yyerror (char *s, ...);

int bracket_INDEX;

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

struct ast*  mult;

void eval (struct ast*);
void treefree (struct ast*);

