#include <iostream>
#include <ctime>
#include "Library.h"

#define NL '\n'
#define TAB '\t'

using std::cout;


int main(){

	std::srand(static_cast<unsigned long>(std::time(nullptr)));
	int numbers[100];

	for (int i = 1; i<=100; i++){
		numbers[i] = neulii::getRandomInt(0,100);



	}

	for (int i = 1; i<=100; i++){
		cout << numbers[i] << TAB;
		if(i%10==0){
			cout << NL;
		}
	}

	return EXIT_FAILURE;
	
}


