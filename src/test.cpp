#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <string>

#define NL '\n'
#define TAB '\t'

using std::cout;

int main(){

	std::string* names;

	unsigned numberOfNames = 0;
	std::string nameInput;

	cout << "How many names to store: ";
	std::cin >> numberOfNames;
	std::cin.ignore(10000,'\n');


	names = new std::string[numberOfNames];


	for(unsigned i = 0; i<numberOfNames; i++){
		cout << "Name " << i << ": ";
		std::getline(std::cin, names[i]);


	}

	cout << NL<< NL;
	cout << "names you entered:" << NL;
	cout << "=========================" << NL;

	



	for (unsigned i = 0; i<numberOfNames; i++){
		std::cout << "name " << i <<": "<< names[i] << NL;

	}
	
	

	return EXIT_FAILURE;
	
}
