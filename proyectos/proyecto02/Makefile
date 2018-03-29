clean:
	rm *.out *.o *.exe || exit 0

red_tape_committeetest: clean
	gcc -c red_tape_committee.c
	gcc -c red_tape_committee_test.c
	gcc -o red_tape_committeetest.exe red_tape_committee.o red_tape_committee_test.o
	./red_tape_committeetest.exe

test: red_tape_committeetest

red_tape_committee: clean
	gcc -c red_tape_committee.c
	gcc -c main.c
	gcc -o red_tape_committee.exe red_tape_committee.o main.o

maintest: red_tape_committee
	./maintest.tcl ./red_tape_committee.exe

run: red_tape_committee
	./red_tape_committee.exe

