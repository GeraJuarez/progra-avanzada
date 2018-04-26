clean:
	rm *.out *.o *.exe || exit 0

utf: clean
	gcc -c main.c
	gcc -o utf.exe main.o

run: utf
	./utf.exe

