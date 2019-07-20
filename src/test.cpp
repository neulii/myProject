#include <iostream>
#include <bitset>

#include <fstream>
#include <vector>
#include <string>

//checking cls/clear command for different operating systems
#if defined _WIN32
	#define clearScreen "\"cls\""
#elif defined __APPLE__
	#define clearScreen "\"clear\""
#endif


using namespace std;

void printMenu();
void getTextFromUser();
void showBufferText();

char userInput;
bool userIsInteracting = true;
vector<string> stringToWrite;

int main(){

	system(clearScreen);
	
	
	do{

		printMenu();
		cin >> userInput;
		system(clearScreen);

		switch(userInput){

			case '0':
				cout << "Programm Ende erreicht" << endl;
				userIsInteracting = false;
				break;

			//write in file
			case '1':
				getTextFromUser();
				
				break;
			
			//read from file
			case '2':
				break;


			case '3':
				showBufferText();
				cout << endl << endl;
				break;

			default: 
				system(clearScreen);
				
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
	cout << "3 - Text im Buffer anzeigen" << endl;
	cout << "==================" << endl;
	cout << "0 - Beenden" << endl << endl;

	cout << "Eingabe: ";

}

void getTextFromUser(){

	string lineString = "empty";
	bool userInputLoop = true;

	cout << "Geben Sie einen Text ein (Beenden mit Leerzeile): " << endl << endl;
	
	//entfernt die letzte eingabetaste
	getchar();
	
	while(userInputLoop){
		getline(cin, lineString);
		if(lineString.length()==0){
			break;
		}
		else {
			//cout << "eingefuegt" << endl;
			stringToWrite.push_back(lineString);

		}

	}	
}

void showBufferText(){
	cout << "Text im Buffer: " << endl << endl;
	
	for(int i = 0; i < stringToWrite.size();i++){
		cout << stringToWrite.at(i) << endl;
	}
}