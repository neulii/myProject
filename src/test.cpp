#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>

#define NL '\n'
#define TAB '\t'

using std::cout;

int main(){

	int numbers[] = {22,66,10,1,66,4000,100,3,20,444};
	size_t arraySize = sizeof(numbers)/sizeof(numbers[0]);
	neulii::printArrayToConsole(numbers, arraySize);

	std::sort(numbers, numbers+arraySize);
	
	//neulii::sortIntegerArray(numbers,arraySize);

	neulii::printArrayToConsole(numbers, arraySize);
	
	

	return EXIT_FAILURE;
	
}


