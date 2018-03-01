clean:
	rm *.out *.o *.exe || exit 0

validnumber: clean
	gcc -c validnumber.c
	gcc -c main.c
	gcc -o main_validnumber.exe validnumber.o main.o

maintest: validnumber
	./maintest.tcl ./main_validnumber.exe

run: validnumber
	./main_validnumber.exe