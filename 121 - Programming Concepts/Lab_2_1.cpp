// Second program
#include <iostream>
#include <string>
using namespace std;

const double tax = 0.0675;
const double tip = 0.15;

int main()
{
    double meal_cost,tax_amount,tip_amount,total_bill;
    
    cout << "Enter the cost of the meal: ";
    cin >> meal_cost;
    
	tax_amount = tax*meal_cost;
	tip_amount = tip*meal_cost;
	total_bill = tax_amount+tip_amount+meal_cost;
	
    cout << "Meal cost: $" << meal_cost << endl;
	cout << "Tax amount: $" << tax_amount << endl;
	cout << "Tip amount: $" << tip_amount << endl;
	cout << "Total bill: $" << total_bill << endl;
}