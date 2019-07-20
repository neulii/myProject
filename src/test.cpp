#include <iostream>
#include <bitset>

#include <fstream>
#include <vector>
#include <string>
#include "Library.h"

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

ofstream output;
string file;
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

			//exit program
			case '0':
				cout << "Programm Ende erreicht" << endl;
				userIsInteracting = false;
				break;

			//input text from console
			case '1':
				getTextFromUser();
				
				break;
			
			//read from file
			case '2':
				break;

			//show added text to console
			case '3':
				showBufferText();
				cout << endl << endl;
				break;
			
			//write text from buffer to file
			case '4':
			
				

				system(clearScreen);
				cout << "Geben Sie einen Dateinamen an: ";
				
				//clear newline
				getchar();
				
				//get filname
				getline(cin, file);
			
				//add file extension
				file.append(".txt");
				
				
				//open file
				output.open(file);
				
				//write lines into file
				for(unsigned i = 0; i<stringToWrite.size();i++){
					output << stringToWrite.at(i) << endl;
				}
				
				//close file
				output.close();

				cout << "Datei wurde geschrieben!" << endl << endl;
			

				break;

			default: 
				system(clearScreen);
				
				cout << "Eingabe nicht erkannt" << endl <<endl;
				
		}
	}while(userIsInteracting);

	return 0;
}

void printMenu(){

	cout << "Was wollen Sie tun?" << endl<<endl;
	cout << "1 - Text eingeben" << endl;
	cout << "2 - Datei lesen" << endl;
	cout << "3 - Text im Buffer anzeigen" << endl;
	cout << "4 - Text im Buffer in Datei Schreiben" << endl;
	cout << "=====================================" << endl;
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
			stringToWrite.push_back(lineString);
		}
	}	
}

void showBufferText(){
	cout << "Text im Buffer: " << endl << endl;
	
	neulii::printStringVec(stringToWrite);

}