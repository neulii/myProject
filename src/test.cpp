#include <iostream>

#define NL '\n'

using std::cout;

struct Point3D{
	double x = 0;
	double y = 0;
	double z = 0;
};

enum class Color{
	Red,
	Blue,
	Orange
};

enum class Type{
	Good,
	Bad
};

void printPoint3D(Point3D point){
	cout << "x: " << point.x << NL;
	cout << "y: " << point.y << NL;
	cout << "z: " << point.z << NL;
}


int main(){

	Type t = Type::Bad;
	Color c = Color::Red;


	cout << static_cast<int>(t) << NL;

	Point3D myPoint;
	printPoint3D(myPoint);

	return EXIT_FAILURE;
	
}


