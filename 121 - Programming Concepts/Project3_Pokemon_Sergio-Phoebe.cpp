/***************************************************
Sergio German Jr && Phoebe Chiu

A Pokemon Battleground simulator

What are the challenging aspects of the project?
 -> The challenging aspects of this project was trying to remember how to generate random numbers and making sure the pointers work out.
****************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
using namespace std;

class Pokemon
{
	private:
		string name;
		string move;
		int hp;
	public:
		//Constructor
		Pokemon(string name_, string move_){
				name = name_;
				move = move_;
				hp = 10;
		}
	
		string getName(){ return name; }; //Returns the pokemon's name
		string getMove(){ return move; }; //Returns the pokemon's move

		void setName(string &);
		void setMove(string &); //Prototypes
		void damageTaken(int &);

		/**********************************************
		*					isAlive					  *
		* Checks if the pokemon's hp is above 0 and   *
		* returns if alive or not in boolean		  *
		***********************************************/
		int isAlive(){ 
			if(hp <= 0){ 
				return false; 
			}else{ 
				return true; 
			}
		}
		/**********************************************
		*					attack					  *
		* This function generates a random integer    *
		* from 1 - 4 to determine the attack strength *
		* and returns the attack strength, and outputs*
		* the pokemon's name and move it used         *
		***********************************************/
		int attack(){
			 int attack_strength = rand() % 4 + 1;
			 cout << name << " uses " << move << endl;
			 return attack_strength;
		}
};

/**********************************************
*				Pokemon::damageTaken		  *
* This function inputs a integer and lowers   *
* the pokemon's	HP by how much damage is taken*
***********************************************/
void Pokemon::damageTaken(int &dmg)
{
	cout << name << " has taken " << dmg << " points damage" << endl;
	hp = hp-dmg;
	cout << name << "\'s hp is at " << hp << "." << endl << endl;  
}

/**********************************************
*				Pokemon::setName			  *
* This function inputs a string and sets the  *
* pokemon's new name					      *
***********************************************/
void Pokemon::setName(string &name_)
{
	name = name_;
}


/**********************************************
*				Pokemon::setMove			  *
* This function inputs a string and sets the  *
* pokemon's new move					      *
***********************************************/
void Pokemon::setMove(string &move_)
{
	move = move_;
}

/**********************************************
*				battleground				  *
* This function inputs 2 'Pokemon' classes	  *
* and attack each other in turns until one    *
* of their HPs reaches 0 and below			  *
***********************************************/
void battleground(Pokemon* &One, Pokemon* &Two)
{
	int val = 0;

	while(One->isAlive() && Two->isAlive()){
		val = One->attack();
		Two->damageTaken(val);
		if(Two->isAlive()){
			val = Two->attack();
			One->damageTaken(val);
		}else{
			break;
		}
	}
	
	if(One->isAlive()){
		cout << Two->getName() << " has fainted" << endl;
		cout << One->getName() << " won the battle" << endl << endl;
	}else if(Two->isAlive()){
		cout << One->getName() << " has fainted" << endl;
		cout << Two->getName() << " won the battle" << endl << endl;
	}
}

int main()
{
	//Seed the random function
	srand(time(NULL));
	
	//Create the Pokemon
	Pokemon *PokemonA = new Pokemon("Charizard", "Flamethrower");
	Pokemon *PokemonB = new Pokemon("Blastoise", "WaterBlast");

	//Introduction
	cout << "Welcome to the Pokemon Arena" << endl;
	cout << "We have " << PokemonA->getName() << " and " << PokemonB->getName() << " today" << endl << endl;
	
	//Initialize the battle
	battleground(PokemonA, PokemonB);
	
	//Deallocate the pokemon
	delete PokemonA;
	delete PokemonB;

	return 0;
}
