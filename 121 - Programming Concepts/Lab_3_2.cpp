#include <iostream>

using namespace std;

/**********************************************************
 *                         sum                            
 * This function adds two parameters and return the result  
 *  Demonstrate default arguments 			
 *********************************************************/
double sum(double a, double b=10) {
	double c = a+b;
	return c;
}

/**********************************************************
 *                         sum                            
 * This function demonstrates template function		
 *********************************************************/
template <class T>
T sum (T a, T b) {
	return a+b;

}

/**********************************************************
	An overloading function for sum that takes in 3 arguments
	instead of two and return an integer type
 *********************************************************/
int sum (int a, int b, int c) {
	return a+b+c;
}


/**********************************************************
	A sum function that use pass by reference option for its
	arguments. The first argument cannot be modified due to
	pass by reference with const
 *********************************************************/

double sumReference(const double &a, double &b) {
	cout << &a << endl;
	//cannt modify the value
	//a++;
	b++;
	return a+b;
}


/**********************************************************
	This function doesnt have a return type.
 *********************************************************/
void printHello () {
	cout << "hello world " << endl;
}

int main() {

	
	double a =5;
	double b = 7;

	//double total = sum(a);
	
	//demonstrate template function
	//int z = sum<int>(5,12);
	double x = sum<double>(8.6,9.9);

	//int z = sum(8,9);
	//int x = sum(10,11,12);

	cout << x << endl;
	//cout << c << endl;
	printHello();

	return 0;
}

