#include <iostream>
#include <bitset>

#include <fstream>
#include <vector>

using namespace std;

void printMenu();

char userInput;
bool userIsInteracting = true;
string stringToWrite;

int main(){

	system("cls");
	printMenu();
	
	do{

		cin >> userInput;

		switch(userInput){

			//write in file
			case '1':
				cout << "schreiben" << endl;
				stringToWrite = getTextFromUser();
				break;
			
			//read from file
			case '2':
				break;

			case '0':
				cout << "Programm Ende erreicht" << endl;
				userIsInteracting = false;
				break;

			default: 
				system("cls");
				
				cout << "Eingabe nicht erkannt" << endl <<endl;
			
				printMenu();

		}
	}while(userIsInteracting);



	return 0;
}

void printMenu(){

	cout << "Was wollen Sie tun?" << endl<<endl;
	cout << "1 - Datei schreiben" << endl;
	cout << "2 - Datei lesen" << endl;
	cout << "==================" << endl;
	cout << "0 - Beenden" << endl << endl;

	cout << "Eingabe: ";

}

getTextFromUser(){

	
}