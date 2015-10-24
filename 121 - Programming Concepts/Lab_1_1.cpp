// First program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int bb_cost,bb_total,answer;
    
    cout << "Number of baseballs purchased: ";
    cin >> bb_total;
    
    cout << "Cost of baseball: ";
    cin >> bb_cost;
    
    answer = bb_total*bb_cost;
    
    cout << "Total cost is $" << answer;
}