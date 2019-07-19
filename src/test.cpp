#include <iostream>
#include <bitset>
int main(){


	using namespace std;

	int result = 0;

	//   0 1 0 1 0 
	int i = 0b0100;
	int j = 0b1101;

	result = i ^ j;

	
	cout << bitset<8>(result) << endl;


	



	return 0;
}