%{
#include <stdio.h>

void yyerror(char *c);
int yylex(void);

int mem[26];

%}

%union
{
  int valor;
  char rotulo;
};

%token VAR EQ INT SOMA EOL
%type <rotulo> VAR
%type <valor> INT
%left SOMA

%%

PROGRAMA:
        PROGRAMA EXPRESSAO EOL { printf("Resultado: %d\n", $<valor>2); }
        | PROGRAMA COMANDO EOL { printf("Executei comando\n"); }
        |
        ;

COMANDO:
    VAR EQ EXPRESSAO { printf("Atribuicao de %d para %c\n", $<valor>3,
    $<rotulo>1);
    mem[$<rotulo>1-'a'] = $<valor>3; }
    ;

EXPRESSAO:
    VAR { $<valor>$ = mem[$<rotulo>1 - 'a']; }
    | INT { $<valor>$ = $<valor>1;
          }

    | EXPRESSAO SOMA EXPRESSAO  {
        printf("Encontrei soma: %d + %d = %d\n", $<valor>1, $<valor>3,
        $<valor>1+$<valor>3);
        $<valor>$ = $<valor>1 + $<valor>3;
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
