truster.o: truster.h truster.c
	gcc -c truster.c
launch.o: launch.h launch.c truster.h
	gcc -c launch.c
launch: truster.o launch.o
	gcc truster.o launch.o -o launch