// PA 4 areas.cpp 
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
   double number, anothernumber, answer = 0;
   
   cout << "Program to calculate areas of objects" << endl << endl;
   // WRITE STATEMENTS HERE TO DISPLAY THE 4 MENU CHOICES.
   cout << setw(19) << "1 -- square" << endl;
   cout << setw(19) << "2 -- circle" << endl;
   cout << setw(27) << "3 -- right triangle" << endl;
   cout << setw(17) << "4 -- quit" << endl;
   // WRITE A STATEMENT HERE TO INPUT THE USER'S MENU CHOICE.
   cin >> option;
   // USE AN IF/ELSE IF STATEMENT TO OBTAIN ANY NEEDED INPUT INFORMATION 
   // AND COMPUTE AND DISPLAY THE AREA FOR EACH VALID MENU CHOICE.
   // IF AN INVALID MENU CHOICE WAS ENTERED, AN ERROR MESSAGE SHOULD
   // BE DISPLAYED.
   if(option == 1)
   {
	   cout << "Enter a side of the square: ";
	   cin >> number;
	   answer = number*number;
	   cout << "\nArea = " << answer << endl;
   }else if(option == 2){
	   cout << "Enter the radius of the circle: ";
	   cin >> number;
	   answer = PI*(pow(number,2));
	   cout << "\nArea = " << answer << endl;
   }else if(option == 3){
	   cout << "Enter the base of the triangle: ";
	   cin >> number;
	   cout << "Enter the height of the triangle: ";
	   cin >> anothernumber;
	   answer = (number*anothernumber)/2;
	   cout << "\nArea = " << answer << endl;
   }else if(option == 4){
   }else{
	   cout << "\nInvalid menu option! (Enter a number from 1 - 4)" << endl;
   }
      
   return 0;
}
