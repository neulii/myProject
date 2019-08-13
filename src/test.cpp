#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <string>
#include <array>




struct Person{
	int age;
	std::string name;
};

void printInt(int myInt){

	std::cout << "int: " << myInt << NL;

}

int sum(int a, int b){

	return a+b;
}







int main(){
	
	std::array<int,10> myArray;

	myArray.at(1);

	std::cout << myArray.size() << NL;

	sum(10,10);

	return EXIT_FAILURE;
	
}
