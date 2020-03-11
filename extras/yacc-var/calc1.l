
%{
#include <stdlib.h>
void yyerror(char *);

#include "y.tab.h"
%}

%%

[a-z]  {
          yylval = yytext[0] - 'a';
          return VAR;
        }

[0-9]+  {
          yylval = atoi(yytext);
          return INT;
        }

[=]    {
          return IGUAL;
       }

[+]     {
          return SOMA;
        }

\n   {
         return EOL;
       }

[ \t]+ ;

.     {yyerror("Token nao reconhecido!\n");}

%%

int yywrap() {
  return 1;
}
