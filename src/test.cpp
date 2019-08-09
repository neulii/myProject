#include <iostream>

#define NL '\n'



int getValueFromUser(){
	int inputNumber = 0; 
	std::cout << "enter your number: " << NL;
	std::cin >> inputNumber;
	//test;
	

	return inputNumber;

}

void showNumber(int number){

	std::cout << "number: " << number << NL;

}

int main(){

	int number = getValueFromUser();

	showNumber(number);
	 
	return EXIT_FAILURE;
	
}
