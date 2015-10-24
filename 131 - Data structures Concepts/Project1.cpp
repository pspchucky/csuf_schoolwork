//Sergio German Jr
//Kent Palmer
//CPSC131-7

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

//Constant values that will never change through out the program
const int maxrow = 2;
const int maxtier = 4;
const int teamsize = maxrow * maxtier;

class TeamDesks { //The TeamDesks Object
	private:
		int max_row = 0, max_tier = 0, max_size = 0;
		string **team = NULL;
	public:
		TeamDesks(int maxRow, int maxTier, int maxSize) {
			max_row = maxRow;
			max_tier = maxTier;
			max_size = maxSize;
			team = new string*[max_tier]; //New Array of string pointers (All the tiers)
			for (int i = 0; i < max_tier; i++) {
				team[i] = new string[max_row]; //New Array of string for each tier
			}

			for (int i = 0; i < max_tier; i++) { //Go through all pointers
				for (int j = 0; j < max_row; j++) { //And initialize all row values to blank.
					team[i][j] = "";
				}
			}
		}

		int getMaxRow() { return max_row; };
		int getMaxTier() { return max_tier; };
		int getMaxSize() { return max_size; };
		int getInitialsRow(string initials) { //Return the row the initials are in
			for (int i = 0; i < max_tier; i++) {
				for (int j = 0; j < max_row; j++) {
					if (team[i][j] == initials)
						return j;
				}
			}
			return 0;
		};
		int getInitialsTier(string initials) { //Return the tier the initials are in
			for (int i = 0; i < max_tier; i++) {
				for (int j = 0; j < max_row; j++) {
					if (team[i][j] == initials)
						return i;
				}
			}
			return 0;
		};
		void printAll() {
			int counter = 0;
			for (int i = 0; i < max_tier; i++) { //Go through all pointers
				for (int j = 0; j < max_row; j++) { //And initialize all row values to blank.
					++counter;
					cout << "#" << counter << "| "
						<< "team[" << j << "][" << i << "] = " << team[i][j] << endl;
				}
			}
		};
		void insertMember(int Row, int Tier, string Initials) { team[Tier][Row] = Initials; };
		bool removeMember(string initialsToDelete){
			for (int i = 0; i < max_tier; i++) {
				for (int j = 0; j < max_row; j++) {
					if (team[i][j] == initialsToDelete) {
						team[i][j] = "";
						return true;
					}
				}
			}
			return false;
		};
		bool memberExists(string initials) {
			for (int i = 0; i < max_tier; i++) {
				for (int j = 0; j < max_row; j++) {
					if(team[i][j] == initials)
						return true;
				}
			}
			return false;
		};
		string getMember(int Row, int Tier) { return team[Tier][Row]; };
};

class TeamNow { //The TeamList Object
	private:
		int teamSize;
		string *teamArray;
		string *newTeamArray = nullptr;
	public:
		TeamNow(int Size) {
			teamSize = Size;
			teamArray = new string[teamSize];
		};
		string getMember(int x) { return teamArray[x]; };
		int findMember(string initials) {
			for (int i = 0; i < teamSize; i++) {
				if(teamArray[i] == initials)
					return i;
			}
			return -1;
		};
		int getMaxTeamSize(){ return teamSize; };
		void setMember(int x, string initials){ teamArray[x] = initials; };
		void printAll() {
			for (int i = 0; i < teamSize; i++) {
				cout << "#" << i+1 << "| " << teamArray[i] << endl;
			}
		};
		void removeMember(int x) {
			//Remove the 'x' element
			teamArray[x] = "";
			//Shift remaining elements...
			for (int i = x; i < teamSize; i++) {
				if (i == teamSize-1) { //Handle the last iteration
					teamArray[i] = "";
					break;
				}
				teamArray[i] = teamArray[i+1]; //Get current and replace with next
			}
			
			cout << "Complete. Showing updated table" << endl << endl;
			printAll();
		};
		void expandTeam() {
			teamSize = teamSize + 1; //update teamsize
			newTeamArray = new string[teamSize]; //Allocate our new array
			for (int i = 0 ; i < teamSize-1; i++  ) { //Feed old array data into the new, expanded one
				newTeamArray[i] = teamArray[i];
			}
			teamArray = nullptr; //abandon the old array data
			teamArray = new string[teamSize]; //allocate a new array based on the new size
			for (int i = 0; i < teamSize; i++) { //Feed the data back into the original array
				teamArray[i] = newTeamArray[i];
			}
			delete [] newTeamArray; //delete the data now that it was transfered
			newTeamArray = nullptr; //initialize it back to default values
		}
		void sort() {
			//Sorting algorithm: Bubble Sort
			string temp;
			for (int i = 0; i <= teamSize - 2; i++) {
				for (int j = 0; j <= teamSize - 2 - i; j++) {
					if (teamArray[j] > teamArray[j+1]) {
						temp = teamArray[j];
						teamArray[j] = teamArray[j+1];
						teamArray[j+1] = temp;
					}
				}
			}
			cout << "Sorting for TeamNow complete." << endl;
		}
};

//Prototype functions
void AddInitialsToSort(TeamNow&);
void DeleteInitialsInSort(TeamNow);
void DeleteMember(TeamDesks);
void FillSeats(TeamDesks);
void FindInitialsInSort(TeamNow);
void FindMember(TeamDesks);
void FindPairs(TeamDesks);
void OneDToTwoDArray(TeamDesks&, TeamNow&);
void ReplaceInitialsInSort(TeamNow);
void SortTeam(TeamDesks, TeamNow);
void UpdateSeats(TeamDesks);
void TwoDToOneDArray(TeamDesks&, TeamNow&);
bool checkInitials(string);
bool checkRowTier(int, int, int &);

int main()
{
	int choice;
	int hasPopulated = false; //Has the user filled the database yet?
	int hasSorted = false; //Has the user sorted the database into the TeamList object yet?
	TeamDesks TheTeam(maxrow, maxtier, teamsize);
	TeamNow TheTeamNow(teamsize);

	do{
		cout << "--------------------" << endl;
		cout << "1| Fill" << endl;
		cout << "2| Update" << endl;
		cout << "3| Delete" << endl;
		cout << "4| Find" << endl;
		cout << "5| Sort" << endl;
		cout << "6| (TeamNow) Display" << endl;
		cout << "7| (TeamDesks) Display " << endl;
		if (hasSorted) {
			cout << "8| Sorted 1D to 2D array" << endl;
			cout << "9| (TeamNow) Insert" << endl;
			cout << "10| (TeamNow) Delete" << endl;
			cout << "11| (TeamNow) Replace" << endl;
			cout << "12| (TeamNow) Find" << endl;
			cout << "13| 2D to 1D array" << endl;
		}
		cout << "0| Exit" << endl;
		cout << "--------------------" << endl;
		cout << "Enter a choice: ";

		while (!(cin >> choice)) { //Verify any non-integer values aren't entered
			cout << "Input error: Try again: " << endl << "Enter a choice: ";
			cin.clear(); //Flush cin
			cin.ignore(INT_MAX, '\n'); //to prevent looping
		}

		cout << endl;
		switch (choice) {
			case 0:
				cout << "Exiting..." << endl;
				break;
			case 1:
				FillSeats(TheTeam);
				hasPopulated = true;
				break;
			case 2:
				if (hasPopulated)
					UpdateSeats(TheTeam);
				else
					cout << "All the seats are empty; Nothing can be updated..." << endl;
				break;
			case 3:
				if (hasPopulated)
					DeleteMember(TheTeam);
				else
					cout << "All the seats are empty; Nothing can be deleted..." << endl;
				break;
			case 4:
				if (hasPopulated)
					FindMember(TheTeam);
				else
					cout << "All the seats are empty; Nothing to search for..." << endl;
				break;
			case 5:
				if (hasPopulated) {
					SortTeam(TheTeam, TheTeamNow);
					hasSorted = true;
				}
				else
					cout << "All the seats are empty; Nothing to sort..." << endl;
				break;
			case 6:
				if (hasSorted) {
					cout << "Displaying..." << endl << endl;
					TheTeamNow.printAll();
				}
				else
					cout << "TeamNow is empty; Nothing to display..." << endl;
				break;
			case 7:
				if (hasPopulated) {
					cout << "Displaying..." << endl << endl;
					TheTeam.printAll();
				}
				else
					cout << "All the seats are empty; Nothing to display..." << endl;
				break;
			case 8:

				if (hasSorted) {
					cout << "1D array into 2D array" << endl << endl;
					OneDToTwoDArray(TheTeam,TheTeamNow);
					break;
				}
			case 9:
				if (hasSorted) {
					cout << "Inserting..." << endl << endl;
					AddInitialsToSort(TheTeamNow);
					break;
				}
			case 10:
				if (hasSorted) {
					cout << "Deleting..." << endl;
					DeleteInitialsInSort(TheTeamNow);
					break;
				}
			case 11:
				if (hasSorted) {
					cout << "Replacing..." << endl;
					ReplaceInitialsInSort(TheTeamNow);
					break;
				}
			case 12:
				if (hasSorted) {
					cout << "Finding..." << endl;
					FindInitialsInSort(TheTeamNow);
					break;
				}
			case 13:
				if (hasSorted) {
					TwoDToOneDArray(TheTeam, TheTeamNow);
					cout << "2D array has been placed into 1D fill" << endl;
					cout << "Displaying current 1D array: " << endl << endl;
					TheTeamNow.printAll();
					break;
				}
			default:
				cout << "Invalid choice! Try again." << endl;
				break;
		}
	} while(choice != 0);
	return 0;
}

void AddInitialsToSort(TeamNow &TeamNow) {
	string initialsToAdd = "";
	int NewSize = TeamNow.getMaxTeamSize()+1;
	cout << "Expanding to " << NewSize << endl;
	TeamNow.expandTeam(); //Expand the TeamNow object

	while (checkInitials(initialsToAdd) == false) {
		cout << "Enter the initial of the student to add " << endl << "Enter (To be added initial): ";
		cin >> initialsToAdd;
		cout << endl; //Cosmetics
	}
	TeamNow.setMember(NewSize-1, initialsToAdd);
	cout << "'" << initialsToAdd << "' was added to the database." << endl;

	cout << "Resorting TeamNow to keep consitency..." << endl;
	TeamNow.sort();
	cout << "Displaying new table" << endl;
	TeamNow.printAll();

	cout << endl << "Complete. Re-opening Menu..." << endl;
}

void DeleteInitialsInSort(TeamNow TeamNow) {
	string initialsToDelete = "";

	while (checkInitials(initialsToDelete) == false) {
		cout << "Enter the initial of the student to delete " << endl << "Enter (To be deleted initial): ";
		cin >> initialsToDelete;
		cout << endl; //Cosmetics
	}
	if (TeamNow.findMember(initialsToDelete) == -1) {
		cout << "Invalid initials to delete! Failure." << endl;
	} else {
		TeamNow.removeMember(TeamNow.findMember(initialsToDelete));
		cout << "'" << initialsToDelete << "' was removed from the database." << endl;
		cout << endl << "Complete. Re-opening Menu..." << endl;
	}


}

void DeleteMember(TeamDesks TeamDesks) {
	int departed = 0; //How many students to delete
	string initialsToDelete = "";

	cout << "How many students will be deleted? " << endl << "Enter (Students to delete): ";
	while (departed <= 0 || departed > TeamDesks.getMaxSize()) {
		while (!(cin >> departed)) { //Verify any non-integer values aren't entered
			cout << "Input error: Try again: " << endl << "Enter (Students to delete): ";
			cin.clear(); //Flush cin
			cin.ignore(INT_MAX, '\n'); //to prevent looping
		}
		if (departed <= TeamDesks.getMaxSize() && departed > 0) {
			break;
		}
		else {
			cout << "Out of Range Error: Try again: " << endl << "Enter (Students to delete): ";
		}
	}
	cout << departed << " students to delete." << endl << endl;
	for (int i = 0; i < departed; i++) {
		cout << "Deleting student #" << i + 1 << endl << endl;
		while (checkInitials(initialsToDelete) == false) { 
			cout << "Enter the initial of the student to delete " << endl << "Enter (To be deleted initial): ";
			cin >> initialsToDelete;
			cout << endl; //Cosmetics
		}

		if (TeamDesks.memberExists(initialsToDelete)) {
			TeamDesks.removeMember(initialsToDelete);
			cout << "Farewell to '" << initialsToDelete << "'" << ". They have been deleted from the database." << endl << endl;
		}
		else {
			cout << "Member '" << initialsToDelete
				<< "' does not exist in the database." << endl
				<< "Try again later" << endl;
		}

		initialsToDelete = "";
	}
	cout << endl << "Complete. Re-opening Menu..." << endl;

}

void FillSeats(TeamDesks TeamDesks) {
	int row = 0, tier = 0;
	int tmp = 1; //To prevent the function from outputing a range error when the user has not entered anything yet
	string initials = "";
	for (int i = 0; i <= TeamDesks.getMaxSize() - 1; i++) {
		/*
		The chkInitials(string initials) function takes the initials and
		outputs anything wrong with the initials. If all conditions are
		met, it breaks this while loop and moves onto the row/tier check.
		*/
		while (checkInitials(initials) == false) { //Keep running the Initials Check function until it determines the inputted initials are safe to use.
			cout << "Initials of Team Members: " << endl << "Enter (3 character initial): ";
			cin >> initials;
			cout << endl; //Cosmetics
		}
		/*
		The chkRowTier(int row, int tier) function takes the row and
		tier and outputs anything wrong with them. If all conditions are
		met, it breaks this while loop and moves onto the insertion.
		*/
		cout << "What is the row and tier: " << endl << "Enter (row & tier): ";
		while (checkRowTier(row, tier, tmp) == false) {
			while (!(cin >> row >> tier)) { //Verify any non-integer values aren't entered
				cout << "Input error: Try again: " << endl << "Enter (row & tier): ";
				cin.clear(); //Flush cin
				cin.ignore(INT_MAX, '\n'); //to prevent looping
			}
		}
		cout << endl;
		//Both inputs were checked, now to insert the entry!
		//cout << "teamDesks[" << row-1 << "][" << tier-1 << "] = " << initials << endl << endl;
		TeamDesks.insertMember(row-1, tier-1, initials);

		//To be safe that the previous values will not make it to the next iteration.
		initials = "";
		row = -1;
		tier = -1;
		tmp = 1;
	}

	cout << endl << "All data acquired, printing out current set..." << endl << endl;

	TeamDesks.printAll();

	cout << endl << "Complete. Re-opening Menu..." << endl;


}

void FindInitialsInSort(TeamNow TeamNow) {
	string initialsToFind = "";

	while (checkInitials(initialsToFind) == false) {
		cout << "Enter the initial of the student to find " << endl << "Enter (To be found initial): ";
		cin >> initialsToFind;
		cout << endl; //Cosmetics
	}

	if (TeamNow.findMember(initialsToFind) == -1) {
		cout << "'" << initialsToFind << "' is NOT on the team." << endl;
	}
	else {
		cout << "'" << initialsToFind << "' is on the team." << endl;

	}

	cout << endl << "Complete. Re-opening Menu..." << endl;
}

void FindMember(TeamDesks TeamDesks) {
	string memberToFind = "";

	while (checkInitials(memberToFind) == false) { //Keep running the Initials Check function until it determines the inputted initials are safe to use.
		cout << "Enter the initial of the student to find " << endl << "Enter (Student to Find): ";
		cin >> memberToFind;
		cout << endl; //Cosmetics
	}

	if (TeamDesks.memberExists(memberToFind)) {
		cout << "Member '" << memberToFind << "' is on the team.";
	}
	else {
		cout << "Member '" << memberToFind << "' is NOT on the team.";
	}

	cout << endl << "Complete. Re-opening Menu..." << endl;

}

void OneDToTwoDArray(TeamDesks &TeamDesks, TeamNow &TeamNow) {
	int choice = 0, pointer = 0; 
	cout << "How to fill row or tier?" << endl
		<< "1| By Row" << endl
		<< "2| By Tier" << endl
		<< "Enter (1 or 2): ";

	while (choice <= 0 || choice > 2) {
		while (!(cin >> choice)) { //Verify any non-integer values aren't entered
			cout << "Input error: Try again: " << endl << "How to fill row or tier?" << endl
				<< "1| By Row" << endl
				<< "2| By Tier" << endl
				<< "Enter (1 or 2): ";
			cin.clear(); //Flush cin
			cin.ignore(INT_MAX, '\n'); //to prevent looping
		}
		if (choice <= 2 && choice > 0) {
			break;
		} else {
			cout << "Out of Range Error: Try again: " << endl << "How to fill row or tier?" << endl
				<< "1| By Tier" << endl
				<< "2| By Row" << endl
				<< "Enter (1 or 2): ";
		}
	}
	if (choice == 1) {
		cout << "By Tier Selected." << endl;
		for (int i = 0; i < TeamDesks.getMaxRow(); i++) {
			for (int j = 0; j < TeamDesks.getMaxTier(); j++) {
				if (TeamNow.getMember(pointer) != "" && pointer < TeamDesks.getMaxSize()-1) {
					TeamDesks.insertMember(i,j, TeamNow.getMember(pointer));
					pointer++;
				}
			}
		}
	} else if (choice == 2) {
		cout << "By Row Selected." << endl;
		for (int i = 0; i < TeamDesks.getMaxTier(); i++) {
			for (int j = 0; j < TeamDesks.getMaxRow(); j++) {
				if (TeamNow.getMember(pointer) != "" && pointer < TeamDesks.getMaxSize() - 1) {
					TeamDesks.insertMember(j, i, TeamNow.getMember(pointer));
					pointer++;
				}
			}
		}
	}
	else {
		cout << "An unknown error occured." << endl;
	}
	cout << "Displaying new table..." << endl << endl;

	TeamDesks.printAll();
	cout << endl << endl;
	TeamNow.printAll();
	cout << endl << "Complete. Re-opening Menu..." << endl;
}

void ReplaceInitialsInSort(TeamNow TeamNow) {
	int departed = 0;
	string oldInitials = "";
	string newInitials = "";
	cout << "How many students have departed? " << endl << "Enter (Students that left): ";
	while (departed <= 0 || departed > TeamNow.getMaxTeamSize()) {
		while (!(cin >> departed)) { //Verify any non-integer values aren't entered
			cout << "Input error: Try again: " << endl << "Enter (Students that left): ";
			cin.clear(); //Flush cin
			cin.ignore(INT_MAX, '\n'); //to prevent looping
		}
		if (departed <= TeamNow.getMaxTeamSize() && departed > 0) {
			break;
		}
		else {
			cout << "Out of Range Error: Try again: " << endl << "Enter (Students that left): ";
		}
	}
	cout << departed << " students have departed." << endl << endl;
	for (int i = 0; i < departed; i++) {
		cout << "Replacing student #" << i + 1 << endl << endl;
		while (checkInitials(oldInitials) == false) { //Keep running the Initials Check function until it determines the inputted initials are safe to use.
			cout << "Enter the old student's initial " << endl << "Enter (Old student's initial): ";
			cin >> oldInitials;
			cout << endl; //Cosmetics
		}
		while (checkInitials(newInitials) == false) { //Keep running the Initials Check function until it determines the inputted initials are safe to use.
			cout << "Enter the new student's initial " << endl << "Enter (New student's initial): ";
			cin >> newInitials;
			cout << endl; //Cosmetics
		}

		if (TeamNow.findMember(oldInitials) != -1) {
			TeamNow.setMember(TeamNow.findMember(oldInitials), newInitials);
			cout << "'" << oldInitials << "'" << " has been modified to '" << newInitials << "'" << endl << endl;
		} else {
			cout << "Member '" << oldInitials
				<< "' does not exist in the database." << endl
				<< "Try again later" << endl;
		}
		cout << "Resorting TeamNow to keep consitency..." << endl;
		TeamNow.sort();

		cout << "Displaying new table" << endl;
		TeamNow.printAll();

		oldInitials = "";
		newInitials = "";
	}

	cout << endl << "Complete. Re-opening Menu..." << endl;
}

void TwoDToOneDArray(TeamDesks &TeamDesks, TeamNow &TeamNow) {
	int pointer = 0;
	for (int i = 0; i < TeamDesks.getMaxTier(); i++) {
		for (int j = 0; j < TeamDesks.getMaxRow(); j++) {
			if (TeamDesks.getMember(j, i) != "") {
				if (pointer >= TeamDesks.getMaxSize()) {
					break;
				}
				TeamNow.setMember(pointer, TeamDesks.getMember(j, i));
				pointer++;
			}
		}
	}
}

void SortTeam(TeamDesks TeamDesks, TeamNow TeamNow) {
	cout << "Sorting team..." << endl; 

	TwoDToOneDArray(TeamDesks, TeamNow);

	cout << "Unsorted TeamNow array" << endl;
	TeamNow.printAll();

	//Sorting algorithm: Bubble Sort
	string temp;
    for(int i = 0; i <= TeamDesks.getMaxSize()-2; i++) {
        for(int j = 0; j <= TeamDesks.getMaxSize()-2-i; j++) {
            if(TeamNow.getMember(j) > TeamNow.getMember(j+1)) {
				temp = TeamNow.getMember(j);
				TeamNow.setMember(j, TeamNow.getMember(j + 1));
				TeamNow.setMember((j + 1), temp);
            }
        }
    }

	cout << endl << "Sorted TeamNow array" << endl;
	TeamNow.printAll();
	cout << endl << "Complete. Re-opening Menu..." << endl;
}

void UpdateSeats(TeamDesks TeamDesks) {
	int departed = 0; //How many students have left
	string oldInitials = "";
	string newInitials = "";

	cout << "How many students have departed? " << endl << "Enter (Students that left): ";
	while(departed <= 0 || departed > TeamDesks.getMaxSize()){
		while (!(cin >> departed)) { //Verify any non-integer values aren't entered
			cout << "Input error: Try again: " << endl << "Enter (Students that left): ";
			cin.clear(); //Flush cin
			cin.ignore(INT_MAX, '\n'); //to prevent looping
		}
		if (departed <= TeamDesks.getMaxSize() && departed > 0) {
			break;
		} else {
			cout << "Out of Range Error: Try again: " << endl << "Enter (Students that left): ";
		}
	}
	cout << departed << " students have departed." << endl << endl;
	for (int i = 0; i < departed; i++) {
		cout << "Replacing student #" << i+1 << endl << endl;
		while (checkInitials(oldInitials) == false) { //Keep running the Initials Check function until it determines the inputted initials are safe to use.
			cout << "Enter the old student's initial " << endl << "Enter (Old student's initial): ";
			cin >> oldInitials;
			cout << endl; //Cosmetics
		}
		while (checkInitials(newInitials) == false) { //Keep running the Initials Check function until it determines the inputted initials are safe to use.
			cout << "Enter the new student's initial " << endl << "Enter (New student's initial): ";
			cin >> newInitials;
			cout << endl; //Cosmetics
		}

		if (TeamDesks.memberExists(oldInitials)) {
			int row = TeamDesks.getInitialsRow(oldInitials);
			int tier = TeamDesks.getInitialsTier(oldInitials);
			TeamDesks.insertMember(row, tier, newInitials);
			cout << "'" << oldInitials << "'" << " has been modified to '" << newInitials << "'" << endl << endl;
		} else {
			cout << "Member '" << oldInitials
				<< "' does not exist in the database." << endl
				<< "Try again later" << endl;
		}

		oldInitials = "";
		newInitials = "";
	}
	cout << endl << "Complete. Re-opening Menu..." << endl;
}

bool checkInitials(string initials) {
	if (initials.length() == 0) { //Are the initials blank?
		return false;
	} else if (initials.length() > 3 || initials.length() < 3) { //Are the initials longer than 3 or less than 3 letters?
		cout << "Sorry, '" + initials + "' is not 3 letters long." << endl;
		return false;
	} else { //The initials are 3 characters long? Ok, are they all letters?
		for (int j = 0; j < initials.length(); j++) { //For all letters in 'initials'
			if (isalpha(initials[j]) == 0) { //Is the character in question a number?
				cout << "Sorry, '" << initials << "' contains one or more non-alpha characters." << endl;
				return false;
			}
		}
		//If the 'initials' are 3 LETTERS long, then it's safe to say the initials have been checked!
		return true;
	}
}

bool checkRowTier(int row, int tier, int& tmp) {
	if (tmp == 1) {
		tmp = 0;
		return false;
	}
	if (row <= 0 || tier <= 0) {
		if (row <= 0)
			cout << "The row is out of bounds! It must be between 1 to " << maxrow << endl;
		if (tier <= 0)
			cout << "The tier is out of bounds! It must be between 1 to " << maxtier << endl;
		cout << "What is the row and tier: ";
		return false;
	}
	else if (row > maxrow || tier > maxtier) {
		if (row > maxrow)
			cout << "The row is out of bounds! It must be between 1 to " << maxrow << endl;
		if (tier > maxtier)
			cout << "The tier is out of bounds! It must be between 1 to " << maxtier << endl;
		cout << "What is the row and tier: ";
		return false;
	}
	else {
		//If the row and tier are both in range, then end the while loop.
		return true;
	}
}
