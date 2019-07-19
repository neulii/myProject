#include <iostream>
#include <bitset>

#include <fstream>

int main(){


	using namespace std;

	ofstream myFile("hallo.txt");

	if(myFile.is_open()){

		myFile << "das ist ein test" << endl ;

		myFile << "noch ein test" << endl;
		myFile.close();
	}


	ifstream readFile()



	return 0;
}