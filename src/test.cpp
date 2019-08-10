#include <iostream>
#include <ctime>

#define NL '\n'

using std::cout;

int main(){

	std::srand(static_cast<unsigned long>(std::time(nullptr)));

	for (int i = 1; i<=100; i++){
		
		const int range = 6;
		const int begin = 0;
		int rn = 0;
		
		int number = 0;
		number = std::rand();

		rn = number % (range-begin+1) +begin;
		cout << rn << "\t";

		if(i%5==0){
			cout << NL;

		}
	}

	return EXIT_FAILURE;
	
}


