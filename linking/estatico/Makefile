LIB=interface.c
LIBO:=$(LIB:.c=.o)
LIBA:=$(LIB:.c=.a)

all:main

main:main.o $(LIBA)
	gcc -omain main.o $(LIBA)

main.o: main.c
	gcc -c main.c

$(LIBA):$(LIBO)
	ar rcs $(LIBA) $(LIBO)

$(LIBO):$(LIB)
	gcc -c $(LIB)

clean:
	rm *.o
	rm *.a
