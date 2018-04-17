clean:
	rm *.out *.o *.exe || exit 0

test: iestest

ies: clean
	gcc -c ies.c
	gcc -c hash.c
	gcc -c main.c
	gcc -o ies.exe ies.o hash.o main.o

run: ies
	./ies.exe

