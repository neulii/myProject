#include <iostream>
#include <bitset>

#include <fstream>
#include <vector>
#include <string>

using namespace std;

void printMenu();
void getTextFromUser();

char userInput;
bool userIsInteracting = true;
vector<string> stringToWrite;

int main(){

	system("cls");
	printMenu();
	
	do{

		cin >> userInput;

		switch(userInput){

			//write in file
			case '1':
				cout << "schreiben" << endl;
				
				break;
			
			//read from file
			case '2':
				getTextFromUser();

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

void getTextFromUser(){

	string lineString = "empty";
	bool userInputLoop = true;

	cout << "Geben Sie einen Text ein: " << endl << endl;
	
	cin.clear();
	
	while(userInputLoop){
		getline(cin, lineString);
		if(lineString.length()==0){
			break;
		}
	}
	cout << "end of while" << endl;


	
}