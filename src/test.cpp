#include <iostream>
#include <ctime>

#define NL '\n'

using std::cout;

int main(){

	std::srand(static_cast<unsigned long>(std::time(nullptr)));

	for (int i = 1; i<=100; i++){

		cout << std::rand() << "\t" ;

		if(i%5==0){
			cout << NL;

		}
	}

	return EXIT_FAILURE;
	
}


