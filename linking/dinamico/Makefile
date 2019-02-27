LIB?=mylib.c
# O comando:
# make LIB=outracoisa.c
# redefine LIB naquela execucao sem ter que modificar o Makefile
LIBO:=$(LIB:.c=.o)


all:main

main:main.o libmylib.so
	gcc -omain main.o -L./ -lmylib

main.o: main.c
	gcc -c main.c

libmylib.so:$(LIBO)
	gcc -shared -o libmylib.so $(LIBO)

$(LIBO):$(LIB)
	gcc -fPIC -c $(LIB)

clean:
	rm *.o
	rm *.so
