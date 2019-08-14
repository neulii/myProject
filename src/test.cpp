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
#include <chrono>

//#define DEBUG



class Person
{
public:

	//an enum to define the gender of the person
	enum class Gender
	{

		Male,	//for male
		Female	//for female

	};
	

private:

	std::string  	m_name = "noname";
	unsigned		m_birthYear = 1900;
	Gender 			m_gender = Gender::Male;

public: 

	Person() 
	{
	}

	Person(std::string name, unsigned birthYear, Gender gender)
		: m_name(name), m_birthYear(birthYear), m_gender(gender)
	{
	
	}

	void printPersonData() const{
		std::cout << "Name:       " << m_name << NL;
		std::cout << "Birth Year: " << m_birthYear << NL;
		std::cout << "Gender:     ";

		if(m_gender == Gender::Male)
		{
			std::cout << "Male";
		}  
		else
		{
			std::cout << "Female";
		}

		std::cout << NL;

	}

	std::string getName() const
	{
		return m_name;
	}

	int getBirthYear() const
	{
		return m_birthYear;
	}

	Gender getGender() const
	{
		return m_gender;
	}
	


};


int main()
{

	

	Person neulii;
	Person flo("florian",1988, Person::Gender::Male);

	




	Person mama = Person("mama",1961,Person::Gender::Female);
	
	
	

	return EXIT_FAILURE;
	
}
