all: foo.c
	make clean
	gcc foo.c

run: foo.c
	make clean
	gcc foo.c 
	./a.out

clean:
	touch bar
	rm bar

