
%{
#include <stdlib.h>
void yyerror(char *);

#include "y.tab.h"
%}


%%

[0-9]+  {
          yylval.valor = atoi(yytext);
          return INT;
        }

[+]     {
          return SOMA;
        }

[=]     {
          return EQ;
          }

[a-z]  {
         yylval.rotulo = yytext[0];
         return VAR;
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
