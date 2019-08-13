#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <string>
#include <array>


typedef int (*myfuncPointer_t)(int,int);
typedef void(*printIntMunber_t)(int);

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

int min(int a, int b){
	return a-b;
}

void executeFunction(myfuncPointer_t m, int a, int b){

	std::cout <<m(a,b) << NL;
}


int main(int argc, char* argv[]){
	
	int number = std::atoi(argv[1]);

	
	std::cout << "parameter: " << number << NL;

	// myfuncPointer_t sub = &min;
	// myfuncPointer_t add = &sum;

	// executeFunction(sub, 1,20);
	// executeFunction(add,100,100);

 
	








	return EXIT_FAILURE;
	
}
