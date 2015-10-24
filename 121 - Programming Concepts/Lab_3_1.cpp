// Third program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int first,second,third,fourth,fifth;
    double answer;
    
    cout << "Enter five test scores: ";
    cin >> first >> second >> third >> fourth >> fifth;
    
    answer = ((first+second+third+fourth+fifth)/(5.0));
    
    cout << "Average=" << answer;
}
