
// This menu-driven program finds areas of squares, circles, 
// snd right triangles. It adds value-returning functions to
// the program

#include <iostream>
using namespace std;

// Function proptotypes
void displayMenu();
int getChoice(int, int);
double findSquareArea();
double findCircleArea();
double findTriangleArea();

const double PI = 3.14159;

int main()
{         
   int choice;           // User's menu choice
   
   do
   {  // Display the menu and get the user's menu choice
      displayMenu();
      choice = getChoice(1, 4);
   
      // Call the appropriate function to find and display 
      // the area of the user's chosen object
      if (choice == 1)                              
         cout << "Area = " << findSquareArea() << endl;
      else if (choice == 2)                        
         cout << "Area = " << findCircleArea() << endl;
      else if (choice == 3)                         
         cout << "Area = " << findTriangleArea() << endl;
      // else choice must be 4, so do nothing
   } while (choice != 4);
   
   return 0;
}

/*****     displayMenu     *****/ 
void displayMenu()
{
   cout << "\n\nProgram to calculate areas of different objects \n\n";
   cout << "        1 -- square \n"
        << "        2 -- circle \n"
        << "        3 -- right triangle \n"
        << "        4 -- quit \n\n";
}

/*****     getChoice     *****/
int getChoice(int min, int max)
{
   int input;
   
   // Get and validate the input
   cin >> input;
   while (input < min || input > max)
   {  cout << "Invalid input. Enter an integer between "
           << min << " and " << max << ": ";
      cin  >> input;
   }
   return input;
}

/*****     findSquareArea     *****/ 
double findSquareArea()
{  double side,          // Length of a side of a square
          area;          // Area of a square

   cout << "Length of the square's side: ";
   cin  >> side;
   area = side * side;   // The area variable could now be eliminated 
   return area;          // and these last 2 lines could be replaced with 
}                        // return (side * side);

/*****     findCircleArea     *****/ 
double findCircleArea()
{  double radius,        // Radius of a circle
          area;          // Area of a circle

   cout << "Radius of the circle: ";
   cin  >> radius;
   area = PI * radius * radius;  // The area variable could now be eliminated 
   return area;                  // and these last 2 lines could be replaced with 
}                                // return (PI * radius * radius);

/*****     findTriangleArea     *****/ 
double findTriangleArea()
{  double base,          // Length of base of a right triangle
          height,        // Height of a right triangle
          area;          // Area of a triangle
          
   cout << "Base of the triangle: ";   
   cin  >> base;
   cout << "Height of the triangle: ";
   cin  >> height;
   area = .5 * base * height;  // The area variable could now be eliminated 
   return area;                // and these last 2 lines could be replaced with 
}                              // return (.5 * base * height);
