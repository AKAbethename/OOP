PROJECT = lab3

lab3:	lab3.o MyRect.o MyVector.o MyString.o Shape.o Circle.o
	g++ lab3.o MyRect.o MyVector.o MyString.o Shape.o Circle.o -o lab3

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

lab3.o:	lab3.cpp
	g++ -c lab3.cpp -o lab3.o

clean:
	rm	*.o lab3