

all: lex.yy.c y.tab.c
	gcc -omain lex.yy.c y.tab.c -ll

lex.yy.c:calc1.l y.tab.c
	flex calc1.l

y.tab.c:calc1.y
	bison -dy calc1.y

clean:
	rm y.tab.c lex.yy.c y.tab.h main
