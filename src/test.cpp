#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>
#include <iterator>
#include <string>

#define NL '\n'
#define TAB '\t'

using std::cout;

int main(){


	const char* test = "supertest";

	cout << test << NL;

	*test = "hallo";



	return EXIT_FAILURE;
	
}
