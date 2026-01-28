PROJECT = lab2

CFLAGS = -fsanitize=address -g -Wall
LDFLAGS = -fsanitize=address

lab2:	lab2.o MyRect.o MyVector.o MyString.o Shape.o Circle.o
	g++ lab2.o MyRect.o MyVector.o MyString.o Shape.o Circle.o -o lab2

MyRect.o:	MyRect.cpp
	g++ -c MyRect.cpp -o MyRect.o

MyVector.o:	MyVector.cpp
	g++ -c MyVector.cpp -o MyVector.o

MyString.o:	MyString.cpp
	g++ -c MyString.cpp -o MyString.o

Shape.o:	Shape.cpp
	g++ -c Shape.cpp -o Shape.o

Circle.o:	Circle.cpp
	g++ -c Circle.cpp -o Circle.o

lab2.o:	lab2.cpp
	g++ -c lab2.cpp -o lab2.o

clean:
	rm	*.o lab2

.PHONY: clean