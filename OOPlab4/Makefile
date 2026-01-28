PROJECT = lab4

lab3:	lab4.o MyRect.o MyVector.o MyString.o Shape.o Circle.o Point.o
	g++ lab4.o MyRect.o MyVector.o MyString.o Shape.o Circle.o Point.o -o lab4

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

Point.o:	Point.cpp
	g++ -c Point.cpp -o Point.o

lab4.o:	lab4.cpp
	g++ -c lab4.cpp -o lab4.o

clean:
	rm	*.o lab4