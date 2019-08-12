#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>

#define NL '\n'
#define TAB '\t'

using std::cout;

int main(){

	int numbers[] = {1000,2,1,100,3,23};
	int numbers2[] = {1000,2,1,100,3,23};
	
	size_t arraySize = sizeof(numbers)/sizeof(numbers[0]);
	

	neulii::selectionSortIntegerArray(numbers2,arraySize);
	neulii::bubbleSortIntegerArray(numbers,arraySize);
	
	neulii::printArrayToConsole(numbers2, arraySize);
	neulii::printArrayToConsole(numbers, arraySize);
	
	
	

	return EXIT_FAILURE;
	
}


