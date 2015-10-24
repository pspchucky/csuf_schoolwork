#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string upperCaseIt(string); // use pass by reference
bool sameString(string, string); // use pass by reference with const 


int main()
{
	//Prompt for both names.
	cout << "Enter the 1st name: ";
	cin >> name1;
	cout << "Enter the 2nd name: ";
	cin >> name2;

	if(sameString(name1,name2) == true){
		cout << "The strings are the same.";
	}else{
		cout << "The strings are not the same.";
	}

	return 0;	
}

string upperCaseIt(string Str)
{
	string Str_Upper = "";
	for(int i = 0; i < Str.length(); i++){
		Str_Upper+=toupper(Str[i])
	}
	return Str_Upper;
}

bool sameString(string Str1, string Str2)
{
	if(upperCaseIt(Str1) == upperCaseIt(Str2))
	{
		return true;
	}else
	{
		return false;
	}
}