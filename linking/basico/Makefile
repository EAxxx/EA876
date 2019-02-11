LIB=interface01.c
LIBO:=$(LIB:.c=.o)


all:main

main:main.o $(LIBO)
	gcc -omain main.o $(LIBO)

main.o: main.c
	gcc -c main.c

$(LIBO):$(LIB)
	gcc -fPIC -c $(LIB)

clean:
	rm *.o
	rm *.so
