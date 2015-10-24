#include <iostream>
using namespace std;

bool isPrime(int num)
{
	for(int i = 2; i<num; i++){	 //Count up to the given num starting from 2.
		if(num % i == 0){ //Check to see if given num is divisible by i.
			return false; //If divisible, break the loop and return Not Prime.
		}
	}
	//Otherwise if not divisible, return Prime
	return true;
}


int main()
{
	//Define variable num. The number we are checking for prime-ability.
	int num;

	//Prompt the User for a number to check prime-ability
	cout << "Enter a number: ";
	cin >> num;
	
	//Output whether prime or not.
	if(isPrime(num) == true)
	{
		cout << num <<  " is prime." << endl;
	}else{
		cout << num <<  " is not prime." << endl;
	}
	system("pause");
	return 0;
}