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
	./robotfieldtest.exe

robotField: clean
	gcc -c booleanparser.c
	gcc -c robot_field.c
	gcc -c main.c
	gcc -o main_robotfield.exe booleanparser.o robot_field.o main.o

maintest: robotField
	./maintest.tcl ./main_robotfield.exe

run: robotField
	./main_robotfield.exe