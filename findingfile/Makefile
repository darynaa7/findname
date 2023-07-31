all: myProgram

myProgram: findingfile.o libfindfile.a
	g++ -o myProgram findingfile.o -L. -lfindfile

findingfile.o: findingfile.cpp ../findfile/findfile.h
	g++  -c -o findingfile.o findingfile.cpp -I../findfile

libfindfile.a: ../findfile/findfile.o
	ar rcs libfindfile.a ../findfile/findfile.o

../findfile/findfile.o: ../findfile/findfile.cpp ../findfile/findfile.h
	g++  -c -o ../findfile/findfile.o ../findfile/findfile.cpp

clean:
	rm -f myProgram *.o *.a
