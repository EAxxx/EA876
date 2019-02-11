LIB=mylib.c
LIBO:=$(LIB:.c=.o)


all:main

main:main.o libmylib.so
	gcc -omain main.o -L./ -lmylib

main.o: main.c
	gcc -c main.c

libmylib.so:mylib.o
	gcc -shared -o libmylib.so $(LIBO)

$(LIBO):$(LIB)
	gcc -fPIC -c $(LIB)

clean:
	rm *.o
	rm *.so
