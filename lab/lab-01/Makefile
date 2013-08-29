
CC = icc
FC = ifort
OPT = -02

build: timing.o dummy.o triad.f90
	$(FC) $(OPT) timing.o dummy.o triad.f90 -o triad  

timing.o: timing.c
	$(CC) $(OPT) -c timing.c

dummy.o: dummy.c
	$(CC) $(OPT) -c dummy.c

clean:
	rm -f *.o

check:
	/curc/tools/grading/scripts/check




