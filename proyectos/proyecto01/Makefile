clean:
	rm *.out *.o *.exe || exit 0

parsertest: clean
	gcc -c booleanparcer.c
	gcc -c test_robotfield.c
	gcc -o robotfieldtest.exe booleanparcer.o test_robotfield.o
	./robotfieldtest

test: clean
	gcc -c booleanparcer.c
	gcc -c robot_field.c
	gcc -c test_robotfield.c
	gcc -o robotfieldtest.exe booleanparcer.o test_robotfield.o robot_field.o
	./robotfieldtest