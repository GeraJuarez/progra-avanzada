clean:
	rm *.out *.o *.exe || exit 0

parsertest: clean
	gcc -c booleanparser.c
	gcc -c test_robotfield.c
	gcc -o robotfieldtest.exe booleanparser.o test_robotfield.o
	./robotfieldtest.exe

test: clean
	gcc -c booleanparser.c
	gcc -c robot_field.c
	gcc -c test_robotfield.c
	gcc -o robotfieldtest.exe booleanparser.o test_robotfield.o robot_field.o
	./robotfieldtest