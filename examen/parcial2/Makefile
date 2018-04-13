clean:
	rm *.out *.o *.exe || exit 0

save-humanity: clean
	gcc -c main.c
	gcc -o save-humanity.exe main.o

run: save-humanity
	./save-humanity.exe

