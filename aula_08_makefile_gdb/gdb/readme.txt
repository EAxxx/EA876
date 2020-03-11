Exercicios: GNU debugger

Compilando:
gcc -g fonte.c -o saida_binario

gdb saida_binario

Comandos:
list - mostra codigo-fonte do programa
run - executa programa
break N - insere breakpoint
break N if K - insere breakpoint condicional
step - dá um passo na execução
continue - continua executando após breakpoint
print S - imprime valor de S na tela
info locals - imprime variaveis locais na tela

