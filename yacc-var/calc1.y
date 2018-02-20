%{
#include <stdio.h>

void yyerror(char *c);
int yylex(void);

int memoria[26];

%}

%token INT SOMA EOL VAR IGUAL
%left SOMA

%%

PROGRAMA:
        PROGRAMA EXPRESSAO EOL { printf("Resultado: %d\n", $2); }
        |
        ;

ATRIBUICAO:
      VAR IGUAL EXPRESSAO {
        memoria[$1] = $3;
        $$ = $3;
      }
    | VAR IGUAL VAR {
        memoria[$1] = memoria[$3];
        $$ = memoria[$3];
      }
    ;

EXPRESSAO:
    INT { $$ = $1;
          }

    | EXPRESSAO SOMA EXPRESSAO {
        printf("Encontrei soma: %d + %d = %d\n", $1, $3, $1+$3);
        $$ = $1 + $3;
        }

    | VAR {
        $$ = memoria[$1];
      }
    | ATRIBUICAO {
        $$ = $1;
      }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
  yyparse();
  return 0;

}
