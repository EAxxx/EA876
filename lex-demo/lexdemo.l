%{

/*
   As secoes do codigo-fonte sao divididas por %%, da seguinte forma:

   SECAO 1 - DEFINICOES
   %%
   SECAO 2 - REGRAS
   %%
   SECAO 3 - SUBROTINAS

   */

  /* Os delimitadores %{ e %} separam codigo C na secao de definicoes */

#include <stdio.h>
#include <string.h>

/* Criteiros de desempate:
   1 - Maior match
   2 - Regra que vem antes */
%}


LETRA   [a-zA-Z]
DIGITO  [0-9]

PALAVRA  {LETRA}+
INTEIRO  {DIGITO}+

%%


{INTEIRO} { printf("Inteiro! %d\n", atoi(yytext));}
-{INTEIRO} { printf("Inteiro negativo %d\n", atoi(yytext)); }

[a-zA-Z]+ { printf("Encontrei a palavra %s\n", yytext); } /* yytext e o texto que
                                                           deu match na
                                                           expressao regular */

[[:space:]]+ ;
[[:^space:]]+ ;

[.\n]* ;


%%

int main() {
  yylex();
  return 0;
}
