clean:
	rm *.out *.o *.exe || exit 0

infografic: clean
	gcc -c hash.c
	gcc -c infografic.c
	gcc -c main.c
	gcc -o infografic.exe hash.o main.o infografic.o

run: infografic
	./infografic.exe

