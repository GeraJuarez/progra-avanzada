clean:
	rm *.out *.o *.exe || exit 0

forbidden_sumtest: clean
	gcc -c forbidden_sum.c
	gcc -c forbidden_sum_test.c
	gcc -o forbidden_sumtest.exe forbidden_sum.o forbidden_sum_test.o
	./forbidden_sumtest.exe

test: forbidden_sumtest

forbidden_sum: clean
	gcc -c forbidden_sum.c
	gcc -c main.c
	gcc -o forbidden_sum.exe forbidden_sum.o main.o

maintest: forbidden_sum
	./maintest.tcl ./forbidden_sum.exe

run: forbidden_sum
	./forbidden_sum.exe

