output: main.o functions.o
	gcc main.o functions.o -o output

main.o: main.c
	gcc -c main.c

functions.o: functions.c lib_header.h
	gcc -c functions.c

clean:
	rm *.o output