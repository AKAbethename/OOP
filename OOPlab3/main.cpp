#include <iostream>
#include <vector>
int main(){
//	int* A = new int(10);
//	int* B = new int(20);
//	int* C = new int(30);
	std::vector <int*> V;
	V.push_back(new int(10));
	V.push_back(new int(20));
	V.push_back(new int(30));

}
