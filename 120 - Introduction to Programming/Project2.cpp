/*	Phoebe Chiu & Sergio German Jr
	Section 9
	Project 2
	October 27, 2014 
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string	first_name,	// first name
			last_name,	// last name
			product;	// product name 

	int num_items;		// quantity of products being purchased

	double	unit_price,	// unit price of the product
			subtotal,	// subtotal of the purchase
			tax_rate,	// tax rate
			sales_tax,	// sales tax of the purchase
			ship_cost,	// shipping cost	
			total;		// grand total of purchase

	const double SHIP_RATE= 0.09; //shipping rate


	cout << "Welcome to the CSUF online store!" << endl;
	cout << "Enter your first name: ";
	cin >> first_name;
	cout << "Enter your last name: ";
	cin >> last_name;
	cout << "Product name: ";
	cin >> product;
	cout << "Unit price: ";
	cin >> unit_price;
	cout << "Quantity: ";
	cin >> num_items;
	cout << "Sales tax rate (%): ";
	cin >> tax_rate;

	subtotal = unit_price * num_items;			//calculates subtotal
	sales_tax = subtotal * tax_rate /100;		//calculates sales tax
	ship_cost = SHIP_RATE * subtotal;			//calculates cost of shipping
	total = subtotal + sales_tax + ship_cost;	//calculates grand total

	cout << "\n\n-------------INVOICE---------------" << endl;
	cout << "First name: " << first_name << endl;
	cout << "Last name: " << last_name << "\n" << endl;
	cout << left << setw(8) << "Qty";
	cout << left << setw (22) << "Item"; 
	cout << right << setw(10) << "Unit Price" << endl;
	cout << fixed << setprecision(2);
	cout << left << setw(8) << num_items;
	cout << left << setw(22) << product;
	cout << right << setw(10) << unit_price << endl;
	cout << setw(20) << "Subtotal" << right << setw(20) << subtotal << endl;
	cout << setw(21) << "Sales tax" << right << setw(19) << sales_tax << endl;
	cout << setw(20) << "Shipping" << right << setw(20) << ship_cost << endl;
	cout << setw(23) << "Grand total" << right << setw(17) << total << endl;

	return 0;
}


