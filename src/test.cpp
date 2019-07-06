#include <iostream>

class BaseClass{
	
	public:

		void showMessage(){

			std::cout << "message from baseclass" << std::endl;
		}


};

class DerivedClass : public BaseClass{

	public:
		void showMessage(){
			std::cout << "message from derivedClass" << std::endl;
		}

};

int main(){

	DerivedClass test;

	test.showMessage();



	return 0;
}