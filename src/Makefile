
CC=g++
CFLAGS=-c -Wall -pedantic -std=c++0x -lm
EFLAGS=-Wall -L. -std=c++0x -lm

main: Double.o MinDisk.o Point.o Test.o RandTest.o ToyTest.o Line.o
	$(CC) $(EFLAGS) -o main main.cpp Double.o MinDisk.o Point.o Test.o RandTest.o ToyTest.o Line.o
	
ToyTest.o: ToyTest.cpp ToyTest.h Test.o Point.o MinDisk.o
	$(CC) $(CFLAGS) ToyTest.cpp
	
RandTest.o: RandTest.cpp RandTest.h Test.o Point.o MinDisk.o
	$(CC) $(CFLAGS) RandTest.cpp
	
Test.o: Test.cpp Test.h Point.o MinDisk.o
	$(CC) $(CFLAGS) Test.cpp
	
MinDisk.o: MinDisk.cpp MinDisk.h Line.o Point.o
	$(CC) $(CFLAGS) MinDisk.cpp
	
Line.o: Line.cpp Line.h Point.o
	$(CC) $(CFLAGS) Line.cpp
	
Point.o: Point.cpp Point.h Constants.h
	$(CC) $(CFLAGS) Point.cpp
	
Double.o: Double.cpp Double.h
	$(CC) $(CFLAGS) Double.cpp
	
clean:
	rm *.o
	