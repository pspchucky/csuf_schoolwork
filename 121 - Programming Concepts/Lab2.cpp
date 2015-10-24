// Lab 2
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string getMedium(int choice);

int main()
{
    int choice, distance;
    double seconds = 0.0;
    
    cout << "Select a medium:" << endl
     << "1. Air" << endl
     << "2. Water" << endl
     << "3. Steel" << endl << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice == 1 || choice == 2 || choice == 3){
        
        cout << "Enter the distance: ";
        cin >> distance;
        
        if(choice == 1){
            cout << "A sound wave takes " << fixed << setprecision(4) << seconds << " seconds to travel " << distance << " feet in " << getMedium(choice) << ".";
        }else if(choice == 2){
            cout << "A sound wave takes " << fixed << setprecision(4) << seconds << " seconds to travel " << distance << " feet in " << getMedium(choice) << ".";
        }else if(choice == 3){
            cout << "A sound wave takes " << fixed << setprecision(4) << seconds << " seconds to travel " << distance << " feet in " << getMedium(choice) << ".";
        }else{
            cout << "The valid choices are 1 through 3. Run the program again and select one of those.";
        }      
    }
}

string getMedium(int choice)
{
    if(choice == 1){
        return "Air";
    }else if(choice == 2){
        return "Water";
    }else if(choice == 3){
        return "Steel";
    }
return "Error: Unknown Medium";
}