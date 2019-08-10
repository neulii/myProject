#include <iostream>
#include <bitset>

#define NL '\n'


int main(){

	const unsigned char hungry	= 1 << 0; //0000_0001
	const unsigned char angry 	= 1 << 1; //0000_0010
	const unsigned char men 	= 1 << 4; //0001_0000
	const unsigned char woman  	= 1 << 5; //0010_0000

	unsigned char options = (0 | hungry);
	options = options | angry;

	options = options | woman;
	

	std::cout << std::bitset<8>(options) << NL;





	return EXIT_FAILURE;
	
}
