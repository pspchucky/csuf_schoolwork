#include <iostream>
#include <cmath>
using namespace std;

double kineticEnergy(double mass, double vel)
{
	//Define KE, aka Kinetic Energy, our answer.
	double KE;
	
	// KE = ½mv^2 | This is the Kinetic Energy Equation
	KE = (0.5)*mass*pow(vel,2);
	
	//Return the Kinetic Energy
	return KE;
}

int main()
{
	//Define our variables mass and velocity variables.
	double mass, vel;
	
	
	//Prompt the User for Mass and Velocity
	cout << "Mass: ";
	cin >> mass;
	cout << "Velocity: ";
	cin >> vel;
	
	//Output the Kinetic Energy Calculation
	cout << "Kinetic Energy: " << kineticEnergy(mass, vel);
	
	return 0;
}