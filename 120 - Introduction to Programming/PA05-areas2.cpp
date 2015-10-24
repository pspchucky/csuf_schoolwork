// PA 5 areas2.cpp 
// Calculates areas of objects
// Sergio German Jr
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{  
   // DEFINE THE NAMED CONSTANT PI HERE AND SET ITS VALUE TO 3.14159
   const double PI = 3.14159;
   // DECLARE ALL NEEDED VARIABLES HERE. GIVE EACH ONE A DESCRIPTIVE
   // NAME AND AN APPROPRIATE DATA TYPE. 
   int option;
   double answer = 0;
  
do{
   cout << "Program to calculate areas of objects" << endl << endl;
   // WRITE STATEMENTS HERE TO DISPLAY THE 4 MENU CHOICES.
   cout << setw(19) << "1 -- square" << endl;
   cout << setw(19) << "2 -- circle" << endl;
   cout << setw(27) << "3 -- right triangle" << endl;
   cout << setw(17) << "4 -- quit" << endl;
    cin >> option;
   if(option == 1)
   {
	   double side;
	   cout << "Enter a side of the square: ";
	   cin >> side;
	   answer = side*side;
	   cout << "\nArea = " << answer << endl;
   }else if(option == 2){
	   double radius; 
	   cout << "Enter the radius of the circle: ";
	   cin >> radius;
	   answer = PI*(pow(radius,2));
	   cout << "\nArea = " << answer << endl;
   }else if(option == 3){
	   double base, height;
	   cout << "Enter the base of the triangle: ";
	   cin >> base;
	   cout << "Enter the height of the triangle: ";
	   cin >> height;
	   answer = (base*height)/2;
	   cout << "\nArea = " << answer << endl;
   }else if(option == 4){
   }else{
	   cout << "\nInvalid menu option! (Enter a number from 1 - 4)" << endl;
   }
  }
   while( option != 4 );
   return 0;
}
