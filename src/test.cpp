#include <iostream>
#include <ctime>
#include "Library.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <string>
#include <array>
#include <cassert>
#include <sstream>

//#define DEBUG

enum class Gender{

		Male,
		Female

	};
	

class Person{
	
	private:

	std::string  	m_name;
	unsigned		m_birthYear;
	Gender 			m_gender;

	public: 

	Person(){
		m_name = "noname";
		m_birthYear = 1900;
		m_gender = Gender::Male;

	}

	Person(std::string name, unsigned birthYear, Gender gender){
		m_name = name;
		m_birthYear = birthYear;
		m_gender = gender;

	}

	void printPersonData(){
		std::cout << "Name:       " << m_name << NL;
		std::cout << "Birth Year: " << m_birthYear << NL;
		std::cout << "Gender:     ";

		if(m_gender == Gender::Male){
			std::cout << "Male";
		}  
		else{
			std::cout << "Female";
		}

		std::cout << NL;

	}

	std::string getName(){
		return m_name;
	}

	int getBirthYear(){
		return m_birthYear;
	}

	Gender getGender(){
		return m_gender;
	}
	


};


int main(){
	
	Person neulii;
	Person flo("florian",1988, Gender::Male);

	neulii.printPersonData();
	flo.printPersonData();


	return EXIT_FAILURE;
	
}
