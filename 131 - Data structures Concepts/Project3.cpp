/*

    Sergio German Jr
    Dr. Kent Palmer
    CPSC 131-07
    Project 3
    10/26/2015
	Compatible in Windows OS machines only
*/
#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <windows.h>
#define INT_MAX 2147483647
using namespace std;

/*
 C++11 compatibility function, to_string( val )
 Original function from: DevSolar
 via: http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
 Converts any inputted value into a string in. Used to work with C++98 and below
 */
#include <sstream>
#define to_string( x ) dynamic_cast<ostringstream&>((ostringstream() << dec << x )).str()


/*
	Classroom Settings
	Change the # of seats, teams, pairs, and students
	that may fit in a given classroom
*/
	const int maxSeats = 30;
	const int maxTeams = 4;
	const int maxPairs = (maxSeats/2);
	const int maxStudents = maxSeats;
//Ensure a number is entered, otherwise output given string variable 'error' and ask again
void checkForNumber(int & num, string error)
{
    while (!(cin >> num)) {
        cout << error;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void validateRange(int & num, int start, int end)
{
	checkForNumber(num,"Not a valid number, Try again (" + to_string(start) + "-" + to_string(end) + "): ");
    while (!(num >= start) || !(num <= end) ) {
			if((num >= start) || (num <= end))
				cout << "Out of range error, Try again (" << start << "-" << end << "): ";
				checkForNumber(num,"Not a valid number, Try again (" + to_string(start) + "-" + to_string(end) + "): ");
    }
}

void validateRange(int & num, string error, int start, int end)
{
	checkForNumber(num, error);
    while (!(num >= start) || !(num <= end) ) {
			if((num >= start) || (num <= end))
				cout << "Out of range error, Try again (" << start << "-" << end << "): ";
				checkForNumber(num, error);
    }
}

void checkForBlankLine(string & x)
{
	while (x == "") {
		getline(cin,x);
		if(x == "")
			cout << "Empty Input detected! Try again: ";
		else
			break;
	}
		
}

int prompt(string question, string options[], int numOptions)
{
	int tmp = 0;
	cout << endl << question << endl << "- - - - - - - - - - - - - - -" << endl;
	for (int i = 0; i < numOptions; i++) cout << (i+1) << ")" << ' ' << options[i] << endl;
	cout << "Enter (1-" << to_string(numOptions) << "): ";
	validateRange(tmp, ("Invalid option, please enter a valid option (1-" + to_string(numOptions) + "): "), 1, numOptions );
	return tmp;
}
//The Student class; Identify a student and themselves; Exercise 3.1 (part 1)
class Student
{
	private:
		string fname;
		string lname;
		string nameInitials;
		int seatNum;
		int teamNum;
		int pairNum;
		bool present;
		string major;
		Student *next;
		Student *prev;
	public:
		//Constructor
		Student(string FName, string LName, string initials, int seat, int team, int pair, string mjr){
			fname = FName;
			lname = LName;
			nameInitials = initials;
			seatNum = seat;
			teamNum = team;
			pairNum = pair;
			major = mjr;
			present = true;
			next = nullptr;
			prev = nullptr;
		}
		//Getter functions
		string getFName() { return fname; };
		string getLName() { return lname; };
		string getInitials(){ return nameInitials; };
		int getSeat(){ return seatNum; };
		int getTeam(){ return teamNum; };
		int getPair(){ return pairNum; };
		bool getPresence() { return present; };
		string getMajor(){ return major; };
		Student * getNext(){ return next; };
		Student * getPrev() { return prev; };
		string getInfo() { return ("\nStudent Name: " + fname + " " + lname + "\nStudent initials: " + nameInitials + "\nSeat number: " + to_string(seatNum) + "\nTeam number: " + to_string(teamNum) + "\nPair number: " + to_string(pairNum) + "\nMajor: " + major + "\nPresent: " + ( present == true ? "Yes" : "No") + "\nPrev Address: " + to_string(prev) + "\nCurrent Address: " + to_string(this) + "\nNext Address: " + to_string(next)); };
		//Setter functions
		void setFName(string x) { fname = x; };
		void setLName(string x) { lname = x; };
		void setInitials(string x){ nameInitials = x; };
		void setSeat(int x) { seatNum = x; };
		void setTeam(int x) { teamNum = x; };
		void setPair(int x) { pairNum = x; };
		void setMajor(string x){ major = x; };
		void setPresence(bool x){ present = x; };
		void setNext(Student * x){ next = x; };
		void setPrev(Student * x) { prev = x; };
		void printInfo() {
			cout << endl << "Student name: " << fname << ' ' << lname
				<< endl << "Student initials: " << nameInitials
				<< endl << "Seat number: " << seatNum
				<< endl << "Team number: " << teamNum
				<< endl << "Pair number: " << pairNum
				<< endl << "Major: " << major
				<< endl << "Present: " << ( present == true ? "Yes" : "No")
				<< endl << "Prev Address: " << prev
				<< endl << "Current Address: " << this
				<< endl << "Next Address: " << next << endl;
		};
};

//The ClassroomList class; Store and organize an 'N' amount of students
class ClassroomList
{
	private:
		Student * head;
		Student * tail;
		int size;
		int seatTrackerSize;
		bool * seatTracker;
		bool warnSort;
		string lastSortedBy;
	public:
		//Constructor
		ClassroomList() {
			head = nullptr;
			tail = nullptr;
			size = 0;
			seatTrackerSize = 0;
			seatTracker = new bool[seatTrackerSize];
			warnSort = false;
			lastSortedBy = "none";
			cout << "An empty ClassroomList object has been created!" << endl;
		}
		//Getter Functions
		Student * getHead() { return head; };
		Student * getTail() { return tail; };
		int getSeatTrackerSize() { return seatTrackerSize; };
		int getSize() { return size; };
		int getStudentNum(Student * find)
		{
			Student * tmp = head;
			for (int i = 0; i < size; i++) {
				if(find == tmp)
					return (i+1);
				else if(tmp->getNext() != nullptr)
					tmp = tmp->getNext();
				else
					return -1;
			}
			return 0;
		}
		bool * getSeatTracker() { return seatTracker; };
		void setLastSortedBy(string x) { lastSortedBy = x; warnSort = false; };
		void verifyOrder()
		{
			if (lastSortedBy != "none" && warnSort == false) { //Has there been any sorting done and have we been warned?
				Student * tmp = head;
				//Convert sorted method string to int
				int sortedBy = (lastSortedBy == "Initials" ? 1 : (lastSortedBy == "Last name" ? 2 : ( lastSortedBy == "First name" ? 3 : ( lastSortedBy == "Major" ? 4 : (lastSortedBy == "Seat Number" ? 5 : 0) ) ) ) );
				int condition = 0;

				//Go through DLL and see if the sorting is still intact
				for (int i = 0; i < size; i++)
				{
					if(tmp->getNext() != nullptr){
						if ( ( (sortedBy == 1 ? (tmp->getInitials() < tmp->getNext()->getInitials()) : ( sortedBy == 2 ? (tmp->getLName() < tmp->getNext()->getLName()) : ( sortedBy == 3 ? (tmp->getFName() < tmp->getNext()->getFName()) : ( sortedBy == 4 ? (tmp->getMajor() < tmp->getNext()->getMajor()) : ( sortedBy == 5 ? ((tmp->getSeat()+1) != (tmp->getNext()->getSeat())) : 0 ) ) ) ) )  > 0)) {
							cout << endl << "**********----------**********" << endl << "WARNING: The list is no longer in order by " << lastSortedBy <<"!\nConsider re-sorting soon..." << endl << "**********----------**********" << endl << endl;
							warnSort = true;
							break;
						}else if(warnSort == false) tmp = tmp->getNext();
						else break;
					} else break;
				}

			}
		}
		//Exercise 3.22: Order Students in Alphabetical order by Initials, by Last Name, by First name, or by Major OR Seat Number
		void sortBy(int x)
		{
			warnSort = false; //Reset sort warning
			Student * current = nullptr;
			Student * trail = nullptr;
			Student * temp = nullptr;
			switch (x)
			{
				case 1:
					lastSortedBy = "Initials";
					break;
				case 2:
					lastSortedBy = "Last name";
					break;
				case 3:
					lastSortedBy = "First name";
					break;
				case 4:
					lastSortedBy = "Major";
					break;
				case 5:
					lastSortedBy = "Seat Number";
					break;
			}
			//Sorting algorithm: Bubble Sort (Least -> Greatest)
			cout << "Sorting by " << lastSortedBy << "..." << endl;

			for(int i = 0; i < size; ++i) {
				current = head;
			    for(int j=0;j<size-1-i;j++ ){
					while (current->getNext() != nullptr) {
						//Debug what comparisons the ternary string is doing.
						//cout <<  '(' << (to_string((x == 1 ? current->getInitials() : (x==2 ? current->getLName() : (x==3 ? current->getFName() : ( x == 4 ? current->getMajor() : "ERROR")))) )) <<  " < " << (to_string((x == 1 ? current->getNext()->getInitials() :(x==2 ? current->getNext()->getLName() : (x==3 ? current->getNext()->getFName() : ( x == 4 ? current->getNext()->getMajor() : "ERROR")))))) << ") || (" <<  (to_string(( x == 5 ? current->getNext()->getSeat() : 0))) << " > " << (to_string(current->getSeat())) <<  ')' << endl;
						if(( (x == 1 ? current->getInitials() : (x==2 ? current->getLName() : (x==3 ? current->getFName() : ( x == 4 ? current->getMajor() : "ERROR")))) > (x == 1 ? current->getNext()->getInitials() :(x==2 ? current->getNext()->getLName() : (x==3 ? current->getNext()->getFName() : ( x == 4 ? current->getNext()->getMajor() : "ERROR"))))) ||  (( x == 5 ? current->getNext()->getSeat() : 0) > current->getSeat()) ){
							string tmp = "";
							//Swap FName
							tmp = current->getFName();
							current->setFName(current->getNext()->getFName());
							current->getNext()->setFName(tmp);

							//Swap LName
							tmp = current->getLName();
							current->setLName(current->getNext()->getLName());
							current->getNext()->setLName(tmp);
							
							//Swap Initials
							tmp = current->getInitials();
							current->setInitials(current->getNext()->getInitials());
							current->getNext()->setInitials(tmp);

							//Swap Major
							tmp = current->getMajor();
							current->setMajor(current->getNext()->getMajor());
							current->getNext()->setMajor(tmp);

							//Swap seatNum
							int tmp2 = current->getSeat();
							current->setSeat(current->getNext()->getSeat());
							current->getNext()->setSeat(tmp2);

							//Swap teamNum
							tmp2 = current->getTeam();
							current->setTeam(current->getNext()->getTeam());
							current->getNext()->setTeam(tmp2);

							//Swap pairNum
							tmp2 = current->getPair();
							current->setPair(current->getNext()->getPair());
							current->getNext()->setPair(tmp2);
	
							//Swap Presence
							bool tmp3 = current->getPresence();
							current->setPresence(current->getNext()->getPresence());
							current->getNext()->setPresence(tmp3);
						}	
						 current = current->getNext();
					}
				}
			}
		}
		//Overload the next function to start recursing
		Student * getStudent(int x, int& tmp, Student* y) { //This function has no checks so everything must be sanitized before it gets here!
			tmp++;
			if(y == nullptr)
				return nullptr; //Failure
			else if(tmp == x-1 || y->getNext() == nullptr)
				return y;
			else
				return getStudent(x,tmp,y->getNext());
		}
		//Retrieve a specific student on the list
		Student * getStudent(int x) { //This function has no checks so everything must be sanitized before it gets here!
			int tmp = 0;
			if(head == nullptr) return nullptr; //Failure
			else if(tmp == x-1)
				return head;
			else
				return getStudent(x, tmp, head->getNext());
		}
		//Exercise 3.1 (Part 2): Create Student Instances of Student Objects for every student in the class
		//Exercise 3.13: Add or Remove the Last Student from the Student List
		//Exercise 3.12: Add or Remove First Student from the Student List 
		void insert(string fname, string lname, string initials, int seat, int team, int pair, string mjr)
		{

			if (seatTracker[(seat-1)] == true && !(seat > seatTrackerSize)) //Is the seat taken?
				cout << "Seat #" << seat << " is occupied by a student already!" << endl; 
			else{
				//Create a new student
				Student * newStudent = new Student(fname, lname, initials, seat, team, pair, mjr);
				if(size == 0){ //Start the list
					head = newStudent;
					tail = newStudent;
				
					delete [] seatTracker; //remove empty array
					seatTracker = nullptr; //point away
					seatTracker = new bool[seat](); //start tracking seats
					seatTrackerSize = seat;
					seatTracker[seat-1] = true; //make the only seat to mark as taken
				} else if(size > 0) {	 //Append to the list
					newStudent->setPrev(tail);
					tail->setNext(newStudent);
					tail = newStudent;
					if( seat > seatTrackerSize){ ///Is the given seat out of the range we track?
						bool * newSeatTracker = new bool[seat]; //Create a new tracker
						for(int i = 0; i < seat; i++) newSeatTracker[i] = false; //initialize everything to not taken
						newSeatTracker[seat-1] = true; //mark the seat we want as taken
						for(int i = 0; i < seatTrackerSize; i++) newSeatTracker[i] = seatTracker[i]; //copy the current seat tracker
						seatTrackerSize = seat; //update the size
						seatTracker = nullptr; //point away
						seatTracker = newSeatTracker; //inherit new data
					} else { ///No? Then don't increase the array tracker size, just update the value
						seatTracker[seat-1] = true;
					}
				}
				cout << "Seat #" << seat << " is now taken!" << endl;
				size++;
				verifyOrder(); //Let the user know if what they just did threw off the order of the DLL
			}
		}
		//Exercise 3.3: print out of Name, Initials, Seat, Pair, Team and Major. Students introduce themselves
		void introductions()
		{
			if(size == 0){
				cout << "The classroom is empty! Unable to print all students." << endl << endl;
				MessageBoxA(NULL, "The classroom is empty! Unable to print all students.", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
			}else{
				Student *tmp = head;
				cout << endl << "Start of list" << endl << "====================";
				for (int i = 0; i < size; i++) {
					tmp->printInfo();
					if(i < size-1)
						cout << endl << "--------------------";
					else
						cout << endl;
					if( tmp->getNext() != nullptr) {
						tmp = tmp->getNext();
					}
					else{
						cout << "====================" << endl
						<< "End of list" << endl << endl;
					}
				}
			}
		}
		//Exercise 3.4: Insert a Student into the Student List
		void makeStudent()
		{
			int seat, team, pair;
			string fname,lname, initials, mjr;
			cin.ignore();
			cout << endl << "Enter the student's first name: ";
			checkForBlankLine(fname);
			cout << endl << "Enter the student's last name: ";
			checkForBlankLine(lname);
			cout << endl << "Enter student's major: ";
			checkForBlankLine(mjr);
			cout <<  endl << "Enter the student's initials: ";
			cin >> initials;
			cout << endl << "Enter student's seat number: ";
			validateRange(seat, 1, maxSeats);
			while (seatTracker[seat - 1]) {
				if((getSeatTrackerSize() < seat) && ( seat <= 30) && (seat >= 1) ){ //It's fine if the seat num is bigger than the tracker's size
					increaseArraySize(seat);
					break;
				}
				cout << "That seat is taken! Try another seat instead." << endl << "Enter: " << endl;
				validateRange(seat, 1, maxSeats);
			}
			cout << endl << "Enter student's team number: ";
			validateRange(team, 1, maxTeams);
			cout << endl << "Enter student's pair number: ";
			validateRange(pair, 1, maxPairs);
			cout << endl << "++++++++++++++++++++"
			<< endl << "Student name: " << fname << ' ' << lname
			<< endl << "Student initials: " << initials
			<< endl << "Seat number: " << seat
			<< endl << "Team number: " << team
			<< endl << "Pair number: " << pair
			<< endl << "Major: " << mjr
			<< endl << "++++++++++++++++++++"<< endl;
			insert(fname, lname, initials, seat, team, pair, mjr);
		}
		void increaseArraySize(int seat)
		{
			//Now to increase the size of the array
			bool * newSeatTracker = new bool[seat]; //Create a new tracker
			for(int i = 0; i < seat; i++) newSeatTracker[i] = false; //initialize everything to not taken
			for(int i = 0; i < seatTrackerSize; i++) newSeatTracker[i] = seatTracker[i]; //copy the current seat tracker
			seatTrackerSize = seat; //update the size
			seatTracker = nullptr; //point away
			seatTracker = newSeatTracker; //inherit new data
		}
		void replaceStudent(Student * x)
		{
			int seat, team, pair;
			string fname,lname, initials, mjr;
			cin.ignore();
			cout << endl << "Enter the student's first name: ";
			checkForBlankLine(fname);
			cout << endl << "Enter the student's last name: ";
			checkForBlankLine(lname);
			cout << endl << "Enter student's major: ";
			checkForBlankLine(mjr);
			cout <<  endl << "Enter the student's initials: ";
			cin >> initials;
			cout << endl << "Enter student's seat number: ";
			validateRange(seat, 1, maxSeats);
			while (seatTracker[seat - 1]) {
				if(seat == x->getSeat()) break; //If it's the seat in question, that's OK
				if((getSeatTrackerSize() < seat) && ( seat <= 30) && (seat >= 1) ){ //It's fine if the seat num is bigger than the tracker's size
					break;
				}
				if(seatTracker[seat-1] == false) break;
				cout <<"That seat is taken! Try another seat instead." << endl << "Enter: " << endl;
				validateRange(seat, 1, maxSeats);
			}
				
			cout << endl << "Enter student's team number: ";
			validateRange(team, 1, maxTeams);
			cout << endl << "Enter student's pair number: ";
			validateRange(pair, 1, maxPairs);

			cout << endl << endl << "------Old Data-------"
				<< endl << "Student name: " << x->getFName() << ' ' << x->getLName()
				<< endl << "Student initials: " << x->getInitials()
				<< endl << "Seat number: " << x->getSeat()
				<< endl << "Team number: " << x->getTeam()
				<< endl << "Pair number: " << x->getPair()
				<< endl << "Presence: " << (x->getPresence() == true ? "yes" : "no")
				<< endl << "Major: " << x->getMajor()
				<< endl << "--------------------" << endl;

			cout << endl << "++++++New Data++++++"
				<< endl << "Student name: " << fname << ' ' << lname
				<< endl << "Student initials: " << initials
				<< endl << "Seat number: " << seat
				<< endl << "Team number: " << team
				<< endl << "Pair number: " << pair
				<< endl << "Presence: yes"
				<< endl << "Major: " << mjr
				<< endl << "++++++++++++++++++++"<< endl;
			string options[2] = {"Yes", "No"};
			int decide = prompt("Would you like to replace the old data with the new?", options, 2);
			if (decide == 1) {
				increaseArraySize(seat);
				x->setFName(fname);
				x->setLName(lname);
				x->setInitials(initials);
				seatTracker[(x->getSeat())-1] = false;
				x->setSeat(seat);
				seatTracker[(x->getSeat())-1] = true;
				x->setTeam(team);
				x->setPair(pair);
				x->setMajor(mjr);
				x->setPresence(true);
				cout << "Data replaced." << endl << endl;
			} else {
				cout << "No? Ok... Returning to menu..." << endl << endl;
				return;
			}
		}
		//Exercise 3.5: Remove Student from the Student List
		//Exercise 3.13: Add or Remove the Last Student from the Student List
		//Exercise 3.12: Add or Remove First Student from the Student List 
		void removeStudent(Student * curr)
		{
			if(size == 0){
				cout << "There is nothing to remove!" << endl << endl;
				MessageBoxA(NULL, "There is nothing to remove!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
			}else{
				cout << "Removing the following student: " << endl;
				curr->printInfo();
				cout << endl;

				Student * tmp1 = nullptr;
				int stNum = getStudentNum(curr);
				if(size > 1){ //More than 1 element?
					if (curr == head) { //Is the current student the head?
						tmp1 = curr->getNext(); //Get the next element
						tmp1->setPrev(curr->getPrev()); //Set its prev element to the prev element of the one to be deleted
						head = tmp1; //Make our new head this element.
					} else if(curr == tail){ //Is the current student the tail?
						tmp1 = curr->getPrev(); //Get the prev element
						tmp1->setNext(curr->getNext()); //Set the next element to the next element of the one to be deleted
						tail = tmp1; //Make our new tail this element.
					} else { //is it something on the list?
						Student * tmp2 = nullptr;
						tmp1 = curr->getNext(); //Get the next element
						tmp2 = curr->getPrev(); //Get the prev element
						tmp1->setPrev(curr->getPrev());
						tmp2->setNext(curr->getNext());
					}
				} else { //1 element or less???
					head = nullptr;
					tail = nullptr;
				}
				delete curr;
				size--;
				//Update array
				seatTracker[stNum-1] = false;
				cout << "Removed student #" << stNum << endl;
				verifyOrder(); //Let the user know if what they just did threw off the order of the DLL
			}
		}
		//Exercise 3.6: Find Student from the Student List
		void findStudent(int studentNum)
		{
			if(size == 0){
				cout << "There is nothing to find!" << endl << endl;
				MessageBoxA(NULL, "There is nothing to find!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
			}else if(size < studentNum || studentNum < 1)
				cout << "There is no such student #" << studentNum << "; The classroom has only " << size << " students." << endl;
			else{
				cout << "Finding student #"<< studentNum << endl;
				Student * tmp = getStudent(studentNum);
				if(tmp == nullptr)
					cout << "Student #" << studentNum << " is not present today!" << endl;
				else
					cout << "Student #" << studentNum << " is present today!" << endl;
			}
		}
		//Exercise 3.8: Assign a Student to a Team within the Student List
		void assignTeam(int studentNum)
		{
			if(size == 0){
				cout << "There is nothing to assign a team to!" << endl << endl;
				MessageBoxA(NULL, "There is nothing to assign a team to!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
			}else if(size < studentNum || studentNum < 1)
				cout << "There is no such student #" << studentNum << "; The classroom has only " << size << " students." << endl;
			else{
				int teamAssign = 0;
				cout << "Which team shall student #" << studentNum << " be assigned to?" << endl << "Enter: ";
				validateRange(teamAssign, 1, maxTeams);
				cout << "Assigning student #"<< studentNum << " to team #" << teamAssign << "..." << endl;
				Student * tmp = getStudent(studentNum);
				tmp->setTeam(teamAssign);
				cout << "Student #" << studentNum << " was successfully assigned to team #" << teamAssign << endl;
			}

		}
		void assignTeam(int studentNum, int teamNum)
		{
			if(size == 0){
				cout << "There is nothing to assign a team to!" << endl << endl;
				MessageBoxA(NULL, "There is nothing to assign a team to!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
			}else if(size < studentNum || studentNum < 1)
				cout << "There is no such student #" << studentNum << "; The classroom has only " << size << " students." << endl;
			else{
				cout << "Assigning student #"<< studentNum << " to team #" << teamNum << "..." << endl;
				Student * tmp = getStudent(studentNum);
				tmp->setTeam(teamNum);
				cout << "Student #" << studentNum << " was successfully assigned to team #" << teamNum << endl;
			}

		}
		//Exercise 3.16: Mark which Students are officially in Attendance but have physically left the classroom
		void markPresent(int studentNum)
		{
			getStudent(studentNum)->setPresence(true);
		}
		//Exercise 3.14: Mark a Student as Absent
		void markGone(int studentNum)
		{
			getStudent(studentNum)->setPresence(false);
		}
		//Exercise 3.10: Find Students of a given Team in the Student List 
		Student * findTeam(int teamNum, Student * tmp)
		{
			if (tmp->getTeam() == teamNum) {
				cout << endl << "Student Name: " << tmp->getFName() << ' ' << tmp->getLName()
					<< endl << "Student initials: " << tmp->getInitials()
					<< endl << "Seat number: " << tmp->getSeat()
					<< endl << "Team number: " << tmp->getTeam()
					<< endl << "Pair number: " << tmp->getPair()
					<< endl << "Major: " << tmp->getMajor()
					<< endl << "Prev Address: " << tmp->getPrev()
					<< endl << "Current Address: " << tmp
					<< endl << "Next Address: " << tmp->getNext() << endl << "------------------------------" << endl;
			}

			if(tmp->getNext() != nullptr){
				tmp = tmp->getNext();
				return findTeam(teamNum, tmp);
			} else { cout << endl; return nullptr;}
		}
		//Exercise 3.15: Which students are Absent?
		Student * findAbsent(Student * tmp)
		{
			if (tmp->getPresence() == false) {
				cout << endl << "Student Name: " << tmp->getFName() << ' ' << tmp->getLName()
					<< endl << "Student initials: " << tmp->getInitials()
					<< endl << "Seat number: " << tmp->getSeat()
					<< endl << "Team number: " << tmp->getTeam()
					<< endl << "Pair number: " << tmp->getPair()
					<< endl << "Major: " << tmp->getMajor()
					<< endl << "Prev Address: " << tmp->getPrev()
					<< endl << "Current Address: " << tmp
					<< endl << "Next Address: " << tmp->getNext() << endl << "------------------------------" << endl;
			}

			if(tmp->getNext() != nullptr){
				tmp = tmp->getNext();
				return findAbsent(tmp);
			} else { cout << endl; return nullptr;}
		}
		//Exercise 3.17: Which students are Physically in the classroom?
		Student * findPresent(Student * tmp)
		{
			if (tmp->getPresence() == true) {
				cout << endl << "Student Name: " << tmp->getFName() << ' ' << tmp->getLName()
					<< endl << "Student initials: " << tmp->getInitials()
					<< endl << "Seat number: " << tmp->getSeat()
					<< endl << "Team number: " << tmp->getTeam()
					<< endl << "Pair number: " << tmp->getPair()
					<< endl << "Major: " << tmp->getMajor()
					<< endl << "Prev Address: " << tmp->getPrev()
					<< endl << "Current Address: " << tmp
					<< endl << "Next Address: " << tmp->getNext() << endl << "------------------------------" << endl;
			}

			if(tmp->getNext() != nullptr){
				tmp = tmp->getNext();
				return findPresent(tmp);
			} else { cout << endl; return nullptr;}
		}
		//Exercise 3.20: Reverse Doubly Linked Classroom List of Students
		void reverseList()
		{
			if (size > 0) {
				//Start at the end...
				Student * current = head;
				Student * tmp = nullptr;
				while (current != nullptr)
				{
					tmp = current->getPrev();
					current->setPrev(current->getNext());
					current->setNext(tmp);
					current = current->getPrev();
				}
				if( tmp != nullptr )
					head = tmp->getPrev();
				cout << "Classroom has been successfully reversed!" << endl;
			}else{
				cout << "The classroom is empty! Unable to reverse list." << endl << endl;
				MessageBoxA(NULL, "The classroom is empty! Unable to reverse list.", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
			}	
		}
		Student * findByString(int x, string val)
		{
			Student * tmp = head;
			//Go through DLL and see if we can find the student
			for (int i = 0; i < size; i++)
			{
				if ( (x == 1 ? tmp->getInitials() : ( x == 2 ? tmp->getLName() : ( x == 3 ? tmp->getFName() : "ERROR" ) )) == val ) {
					return tmp; //Found!
				} else if(tmp->getNext() != nullptr)
					tmp = tmp->getNext(); //Keep going
				else
					return nullptr; //Failure
			}
			return nullptr; //Failure
		}
		Student * findBySeatNumber(int seatNum)
		{
			Student * tmp = head;
			//Go through DLL and see if we can find the student
			for (int i = 0; i < size; i++)
			{
				if ( tmp->getSeat() == seatNum) {
					return tmp; //Found!
				} else if(tmp->getNext() != nullptr)
					tmp = tmp->getNext(); //Keep going
				else
					return nullptr; //Failure
			}
			return nullptr; //Failure
		}
};

int main()
{
    cout << "Initializing..." << endl
    << "Creating doubly linked list object..." << endl;

    //Create the Classroom to store students in
    ClassroomList ClassroomList;
    int choice, tmp, tmp2;
	string tmpStr;
	bool tmp3 = false;
	const int defaultOptionsSize = 4;
	Student * tmpStudent = nullptr;
	string defaultOptions[defaultOptionsSize] = {"Initials", "Last Name", "First Name", "Seat Number"};
	string Case7[2] = {"Here","Not Here"};
	string Case8[8] = {"First Name", "Last Name", "Initials", "Seat Number", "Team Number", "Pair Number", "Major", "Presence"};
	string Case9[5] = {"Initials", "Last Name", "First Name", "Major", "Seat Number"};
    cout << "Opening menu..." << endl;

    do {
        tmp = 0;
        tmp2 = 0;
		tmpStr = "";
		tmpStudent = nullptr;
		tmp3 = false;
        cout << "--------------------" << endl
			<< "1) Add a set of students" << endl
			<< "2) Add a single student" << endl
			<< "3) Show all students" << endl
			<< "4) Remove a student" << endl
			<< "5) Find a student" << endl
			<< "6) Assign a student to a team" << endl
			<< "7) Mark a student present or not" << endl
			<< "8) Modify a student" << endl
			<< "9) Sort students by..." << endl
			<< "10) Dummy Data (15 students)" << ( ClassroomList.getSize() != 0 ? "[DISABLED]" : "" ) << endl
			<< "11) Test The Entire Program [Test Script]" << ( ClassroomList.getSize() == 0 ? "[Avaliable]": "[DISABLED, restart program]") << endl
			<< "12) Find Students in a given team" << endl
			<< "13) List all absent students" << endl
			<< "14) List all present students" << endl
			<< "15) Size of Student List" << endl
			<< "16) Reverse the classroom list" << endl
			<< "17) Replace a student" << endl
			<< "0) Exit" << endl
			<< "--------------------" << endl
			<< "Enter: ";

        checkForNumber(choice, "Invalid option, please enter a valid option: ");

        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                break;
            case 1:
                //Exercise 3.2: Fill Student Classroom List
                cout << "How many students will be added?" << endl << "Enter: ";
				validateRange(tmp, 1, maxStudents);
                for (int i = 0; i < tmp; i++) ClassroomList.makeStudent();
                cout << tmp << " students have been added." << endl;
                break;
            case 2:
                ClassroomList.makeStudent();
                break;
            case 3:
                ClassroomList.introductions();
                break;
            case 4:
				if(ClassroomList.getSize() > 0){
					tmp = prompt("Remove student by...?",defaultOptions,defaultOptionsSize);
					switch(tmp){
						case 1:
						case 2:
						case 3:
							cout << "Enter the " << (tmp == 1 ? "Initials" : (tmp == 2 ?  "Last Name" : (tmp == 3 ? "First Name" : "ERROR" ) ) ) << ": " << endl;
							cin.ignore();
							checkForBlankLine(tmpStr);
							cout << "Searching for '" << tmpStr << "'..." << endl;
							tmpStudent = ClassroomList.findByString(tmp,tmpStr);
							break;
						case 4:
							cout << "Enter the seat number: ";
							validateRange(tmp2, "Not a valid number, Try again: ", 1, maxSeats);
							tmpStudent = ClassroomList.findBySeatNumber(tmp2);
							break;
					}
					if (tmpStudent == nullptr)
						cout << "Student not found! Try again." << endl << endl;
					else
						ClassroomList.removeStudent(tmpStudent);
					break;
				}else{
					cout << "There are no students to remove!" << endl << endl;
					MessageBoxA(NULL, "There are no students to remove!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
            case 5:
				if(ClassroomList.getSize() > 0){
					tmp = prompt("Find student by...?",defaultOptions,defaultOptionsSize);
					switch(tmp){
						case 1:
						case 2:
						case 3:
							cout << "Enter the " << (tmp == 1 ? "Initials" : (tmp == 2 ?  "Last Name" : (tmp == 3 ? "First Name" : "ERROR" ) ) ) << ": " << endl;
							cin.ignore();
							checkForBlankLine(tmpStr);
							cout << "Searching for '" << tmpStr << "'..." << endl;
							tmpStudent = ClassroomList.findByString(tmp,tmpStr);
							break;
						case 4:
							cout << "Enter the seat number: ";
							validateRange(tmp2, "Not a valid number, Try again: ", 1, maxSeats);
							tmpStudent = ClassroomList.findBySeatNumber(tmp2);
							break;
					}
					if (tmpStudent == nullptr)
						cout << "Student not found! Try again." << endl << endl;
					else{
						cout << "Student found!" << endl << "- - - - - - - - - - - - - - - ";
						tmpStudent->printInfo();
						cout << endl << "- - - - - - - - - - - - - - - " << endl << endl;
					}
					break;
				}else{
					cout << "There are no students to find!" << endl << endl;
					MessageBoxA(NULL, "There are no students to find!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
                break;
            case 6:
				if(ClassroomList.getSize() > 0){
					tmp = prompt("Assign team to student by...?",defaultOptions,defaultOptionsSize);
					switch(tmp){
						case 1:
						case 2:
						case 3:
							cout << "Enter the " << (tmp == 1 ? "Initials" : (tmp == 2 ?  "Last Name" : (tmp == 3 ? "First Name" : "ERROR" ) ) ) << ": " << endl;
							cin.ignore();
							checkForBlankLine(tmpStr);
							cout << "Searching for '" << tmpStr << "'..." << endl;
							tmpStudent = ClassroomList.findByString(tmp,tmpStr);
							break;
						case 4:
							cout << "Enter the seat number: ";
							validateRange(tmp2, "Not a valid number, Try again: ", 1, maxSeats);
							tmpStudent = ClassroomList.findBySeatNumber(tmp2);
							break;
					}
					if (tmpStudent == nullptr)
						cout << "Student not found! Try again." << endl << endl;
					else{
						cout << "Student found!" << endl << "- - - - - - - - - - - - - - - ";
						tmpStudent->printInfo();
						cout << endl << "- - - - - - - - - - - - - - - " << endl << endl;
						cout << "What team to assign the above student to?" << endl << "Enter: ";
						validateRange(tmp, 1, maxTeams);
						
					}
					break;
				}else{
					cout << "There are no students to assign teams to!" << endl << endl;
					MessageBoxA(NULL, "There are no students to assign teams to!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
                break;
            case 7:
				if(ClassroomList.getSize() > 0){
					tmp = prompt("Mark presence of a student by...?",defaultOptions,defaultOptionsSize);
					switch (tmp)
					{
						case 1:
						case 2:
						case 3:
							cout << "Enter the " << (tmp == 1 ? "Initials" : (tmp == 2 ?  "Last Name" : (tmp == 3 ? "First Name" : "ERROR" ) ) ) << ": " << endl;
							cin.ignore();
							checkForBlankLine(tmpStr);
							cout << "Searching for '" << tmpStr << "'..." << endl;
							tmpStudent = ClassroomList.findByString(tmp,tmpStr);
							break;
						case 4:
							cout << "Enter the seat number: ";
							validateRange(tmp2, "Not a valid number, Try again: ", 1, maxSeats);
							tmpStudent = ClassroomList.findBySeatNumber(tmp2);
							break;
					}
					if (tmpStudent == nullptr)
						cout << "Student not found! Try again." << endl << endl;
					else{
						tmp2 = prompt("Is:\n---------------" + tmpStudent->getInfo() + "\n---------------\n\nhere or not here?...",Case7,2);
							tmp = ClassroomList.getStudentNum(tmpStudent);
							if(tmp2 == 1){
								ClassroomList.markPresent(tmp);
								cout << "Student #" << tmp << " marked present." << endl;
							}else if(tmp2 == 2){
								ClassroomList.markGone(tmp);
								cout << "Student #" << tmp << " marked not present." << endl;
							}else
								cout << "Invalid option! Returning to menu..." << endl;
					}
				}else{
					cout << "There are no students to mark their presence!" << endl << endl;
					MessageBoxA(NULL, "There are no students to mark their presence!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}                
				break;
			//Exercise 3.18: Change Data in a Student instance record
            case 8:
				if(ClassroomList.getSize() > 0){
					tmp = prompt("Find a student by...?",defaultOptions,defaultOptionsSize);
					switch(tmp){
						case 1:
						case 2:
						case 3:
							cout << "Enter the " << (tmp == 1 ? "Initials" : (tmp == 2 ?  "Last Name" : (tmp == 3 ? "First Name" : "ERROR" ) ) ) << ": " << endl;
							cin.ignore();
							checkForBlankLine(tmpStr);
							cout << "Searching for '" << tmpStr << "'..." << endl;
							tmpStudent = ClassroomList.findByString(tmp,tmpStr);
							break;
						case 4:
							cout << "Enter the seat number: ";
							validateRange(tmp2, "Not a valid number, Try again: ", 1, maxSeats);
							tmpStudent = ClassroomList.findBySeatNumber(tmp2);
							break;
					}
					if (tmpStudent == nullptr)
						cout << "Student not found! Try again." << endl << endl;
					else{
						cout << "Student found!" << endl << "- - - - - - - - - - - - - - - ";
						tmpStudent->printInfo();
						cout << endl << "- - - - - - - - - - - - - - - " << endl << endl;
						tmpStr = "";
						tmp = prompt("What would you like to modify?",Case8, 8);
						switch (tmp)
						{
							case 1:
								cout << "Enter the new First Name: ";
								cin.ignore();
								checkForBlankLine(tmpStr);
								tmpStudent->setFName(tmpStr);
								cout << "First Name successfully modified to '" << tmpStr << "'!" << endl;
								break;
							case 2:
								cout << "Enter the new Last Name: ";
								cin.ignore();
								checkForBlankLine(tmpStr);
								tmpStudent->setLName(tmpStr);
								cout << "Last Name successfully modified to '" << tmpStr << "'!" << endl;
								break;
							case 3:
								cout << "Enter the new Initials: ";
								cin >> tmpStr;
								tmpStudent->setInitials(tmpStr);
								cout << "Initials successfully modified to '" << tmpStr << "'!" << endl;
								break;
							case 4:
								cout << "Enter the new Seat Number: ";
								validateRange(tmp2, 1, maxSeats);
								while (ClassroomList.getSeatTracker()[tmp2 - 1] ) {
									if(tmpStudent->getSeat() == tmp2) break; //It's fine to pick the same team
									if((ClassroomList.getSeatTrackerSize() < tmp2) && ( tmp2 <= 30) && (tmp2 >= 1) ){
									 //It's fine if the seat num is bigger than the tracker's size
										ClassroomList.increaseArraySize(tmp2);
										break;
									}
									cout << "That seat is taken! Try another seat instead." << endl << "Enter: " << endl;
									validateRange(tmp2, 1, maxSeats);
								}
								ClassroomList.getSeatTracker()[(tmpStudent->getSeat())-1] = false;
								tmpStudent->setSeat(tmp2);
								ClassroomList.getSeatTracker()[(tmpStudent->getSeat())-1] = true;
								cout << "Seat Number successfully modified to '" << to_string(tmp2) << "'!" << endl;
								break;
							case 5:
								cout << "Enter the new Team Number: ";
								validateRange(tmp2, 1, maxTeams);
								tmpStudent->setTeam(tmp2);
								cout << "Team Number successfully modified to '" << to_string(tmp2) << "'!" << endl;
								break;
							case 6:
								cout << "Enter the new Pair Number: ";
								validateRange(tmp2, 1, maxPairs);
								tmpStudent->setPair(tmp2);
								cout << "Pair Number successfully modified to '" << to_string(tmp2) << "'!" << endl;
								break;
							case 7:
								cout << "Enter the new Major: ";	
								cin.ignore();
								checkForBlankLine(tmpStr);
								tmpStudent->setMajor(tmpStr);
								cout << "Major successfully modified to '" << tmpStr << "'!" << endl;
								break;
							case 8:
								tmp2 = prompt("Is the student here or not here?", Case7, 2);
								if (tmp2 == 1) {
									cout << "Presence set to true" << endl;
									tmpStudent->setPresence(true);
								} else {
									cout << "Presence set to false" << endl;
									tmpStudent->setPresence(false);
								}
								break;
						}
						
					}
					break;
				}else{
					cout << "There are no students to modify!" << endl << endl;
					MessageBoxA(NULL, "There are no students to modify!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
                break;
            case 9:
				if(ClassroomList.getSize() > 0){
						tmp = prompt("Sort Classroom by...?",Case9,5);
						ClassroomList.sortBy(tmp);
						cout << endl << "Complete!" << endl << endl;
				}else{
					cout << "There are no students to assign teams to!" << endl << endl;
					MessageBoxA(NULL, "There are no students to assign teams to!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
            case 10:
				if(ClassroomList.getSize() == 0){
					cout << "Adding 15 students in seats #1-15..." << endl;
					ClassroomList.insert("Fernando","Mendez","FCM",1,4,14,"Computer Science");
					ClassroomList.insert("Lauren","Chang","LDC",2,3,9,"Computer Science");
					ClassroomList.insert("Leigh","Salvador","LMS",3,2,6,"Computer Science");
					ClassroomList.insert("Kevin","Kheradvar","LMS",4,1,3,"Computer Engineering");
					ClassroomList.insert("Grace","Derderian","GBD",5,2,5,"Computer Science");
					ClassroomList.insert("Ayrton","Sparling","AVS",6,3,12,"Computer Science");
					ClassroomList.insert("Hassan","Hamod","HAH",7,4,15,"Computer Science");
					ClassroomList.insert("Raymond","Tang","RJT",8,2,8,"Computer Science");
					ClassroomList.insert("Steven","Harrison","STH",9,3,9,"Computer Science");
					ClassroomList.insert("Sergio","German Jr","SGJ",10,4,15,"Computer Science");
					ClassroomList.insert("Jonathan","Tran","JTT",11,3,10,"Computer Science");
					ClassroomList.insert("Fernando","Cuevas","FZC", 12,1,1, "Computer Science");
					ClassroomList.insert("Brian","Cabantug","BQC", 13,2,7, "Computer Science");
					ClassroomList.insert("Amanda","Nguyen","APN", 14,2,5, "Computer Science");
					ClassroomList.insert("Kevin","Cuevas","KBC", 15,13,4, "Computer Engineering");
					ClassroomList.setLastSortedBy("Seat Number");
				}
				else {
					cout << "Option disabled! Remove all elements or restart the program!" << endl << endl;
					MessageBoxA(NULL, "Option disabled! Remove all elements or restart the program!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
                break;
            case 11:
				if(ClassroomList.getSize() == 0){
					cout << endl << endl << endl << "Test Script v1.0" << endl << "- - - - - - - - - - - - - - - " << endl << endl
					 << "The following will be tested:" << endl << "= = = = = = = = = = = = " << endl
					 << "1) Creating and Inserting 5 Students" << endl
					 << "2) Deleting the first element, last element, middle element and \ndeleting until the list is empty" << endl
					 << "3) Inserting 5 more new Students" << endl
					 << "4) Printing out all avaliable student data" << endl
					 << "5) Attempting to insert a student in a seat that is already occupied" << endl
					 << "6) Finding a Student by Initials, Last Name, First Name, and Seat Number" << endl
					 << "7) Assign all 5 students team #4" << endl
					 << "8) Assign 2 students to Team #2" << endl
					 << "9) Display everyone on Team #4 then Team #2" << endl
					 << "10) Replace the first student, last student and middle student with\n new, fresh data" << endl
					 << "11) Remove the first element, then add to the first element" << endl
					 << "12) Remove the last element, then add to the last element" << endl
					 << "13) Mark a student absent" << endl
					 << "14) Display all absent students" << endl
					 << "15) Display all students present" << endl
					 << "16) Change 1 of 8 elements of for each Student" << endl
					 << "17) Display the size of the class (with absent students\nand present students)" << endl
					 << "18) Reverse the list" << endl
					 << "19) Bubble Sort by Initials, Last Name, First name,\n Major, Seat Number" << endl
					 << "20) Leave the user with 5 students in the list\n and the menu to their bidding" << endl
					 << "Further user investigation of the integrity of the program." << endl << endl;
					cout << "Press Enter to begin.";
					cin.ignore();
					getline(cin,tmpStr);
				ClassroomList.insert("Hassan","Hamod","HAH",1,4,15,"Computer Science");
				ClassroomList.insert("Raymond","Tang","RJT",2,2,8,"Computer Science");
				ClassroomList.insert("Steven","Harrison","STH",3,3,9,"Computer Science");
				ClassroomList.insert("Sergio","German Jr","SGJ",4,4,15,"Computer Science");
				ClassroomList.insert("Jonathan","Tran","JTT",5,3,10,"Computer Science");
				cout << endl << "1) 5 elements created; Press enter to display results." << endl;
					getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << endl << "2a) Removing first element... (Press Enter)" << endl;
					getline(cin,tmpStr);
				ClassroomList.removeStudent(ClassroomList.getHead());
				ClassroomList.introductions();
				cout << endl << "2b) Removing last element... (Press Enter)" << endl;
					getline(cin,tmpStr);
				ClassroomList.removeStudent(ClassroomList.getTail());
				ClassroomList.introductions();
				cout << endl << "2c) Removing middle element... (Press Enter)" << endl;
					getline(cin,tmpStr);
				ClassroomList.removeStudent(ClassroomList.getStudent(2));
				ClassroomList.introductions();
				cout << endl << "2d) Removing first element... (Press Enter)" << endl;
					getline(cin,tmpStr);
				ClassroomList.removeStudent(ClassroomList.getHead());
				ClassroomList.introductions();
				cout << endl << "2e) Removing last element standing... (Press Enter)" << endl;
					getline(cin,tmpStr);
				ClassroomList.removeStudent(ClassroomList.getHead());
				ClassroomList.introductions();
				cout << "-+-+--+-+--+-+--+-+--+-+--+-+-" << endl << "Did you see that? This program has Windows.h API hooks to send critically important\nMessages like that. They only appear when the user trys to\nRun items without first populating the list." << endl;
				cout << "-+-+--+-+--+-+--+-+--+-+--+-+-" << endl << "Press enter to continue on." << endl;
					getline(cin,tmpStr);
				ClassroomList.insert("Fernando","Mendez","FCM",1,4,14,"Computer Science");
				ClassroomList.insert("Lauren","Chang","LDC",2,3,9,"Computer Science");
				ClassroomList.insert("Leigh","Salvador","LMS",3,2,6,"Computer Science");
				ClassroomList.insert("Kevin","Kheradvar","KKH",4,1,3,"Computer Engineering");
				ClassroomList.insert("Grace","Derderian","GBD",5,2,5,"Computer Science");
				cout << endl << "3) 5 new students have been added. (Press Enter)" << endl;
					getline(cin,tmpStr);
				cout << endl << "4) Now to print out all avaliable data.\nPress enter to execute." << endl;
					getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << endl << "5) Now to attempt to insert a new student in seat #1 (although a student already exists!)\nPress enter to execute." << endl;
				cout << "ClassroomList.insert(\"Cake\",\"German\",\"CGJ\",3,2,9,\"Computer Security\");" << " will be executed directly" << endl;
					getline(cin,tmpStr);
				ClassroomList.insert("Cake","German","CGJ",3,2,9,"Computer Security");
				cout << endl << "This program is equipped with checks on ALL user inputs, warns if the list is no longer sorted from the previous\nSorting order and keeps check of all internal functions to prevent any crashes" << endl;
				cout << endl << "6) Now to find a each student using an Initial, Last Name, First Name, or Seat Number" << endl;
				cout << "Press enter to begin." << endl;
					getline(cin,tmpStr);
				cout << "Find By Seat Number 2" << endl;
				ClassroomList.findBySeatNumber(2);
				cout << "Find By Initials 'LMS'" << endl;
				ClassroomList.findByString(1,"LMS");
				cout << "Find By First Name 'Grace'" << endl;
				ClassroomList.findByString(2,"Grace");
				cout << "Find By Last Name 'Kheradvar'" << endl;
				ClassroomList.findByString(3,"Kheradvar");
				cout << "Find By Seat Number -1" << endl;
				ClassroomList.findBySeatNumber(-1);
				cout << "Find By Initials 'AAA'" << endl;
				ClassroomList.findByString(1,"LMS");
				cout << "Find By First Name 'Graec'" << endl;
				ClassroomList.findByString(2,"Graec");
				cout << "7) Assign everyone in the list to team #4 for optimal teamwork" << endl;
				ClassroomList.assignTeam(1,4);
				ClassroomList.assignTeam(2,4);
				ClassroomList.assignTeam(3,4);
				ClassroomList.assignTeam(4,4);
				ClassroomList.assignTeam(5,4);
				cout << "Results: " << endl;
				cout << "Press enter to show." << endl;
					getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << "8) It was a bad idea to make everyone on the same team\nTime to move Student #3 and #4 to another team like 2!" << endl;
				cout << "Press enter to continue." << endl;
					getline(cin,tmpStr);
				ClassroomList.assignTeam(3,2);
				ClassroomList.assignTeam(4,2);
				cout << "9a) Let's see how Team #2 looks like (Recursive function here/press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.findTeam( 2 , ClassroomList.getHead());
				cout << "9b) Let's see how Team #4 looks like now (Recursive function here/press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.findTeam( 4, ClassroomList.getHead());
				cout << endl << "10) Replace the first student, last student and middle student with\n new, fresh data" << endl << "Your input is required for this section\nPress enter to continue" << endl;
				getline(cin,tmpStr);
				tmpStudent = ClassroomList.findBySeatNumber(1);
				cout << "First student" << endl;
				ClassroomList.replaceStudent(tmpStudent);
				tmpStudent = ClassroomList.findBySeatNumber(5);
				cout << "Last student" << endl;
				ClassroomList.replaceStudent(tmpStudent);
				tmpStudent = ClassroomList.findBySeatNumber(3);
				cout << "Middle student" << endl;
				ClassroomList.replaceStudent(tmpStudent);
				cout << "\n\nThis is what the list looks like now... (Enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << endl << "11a) Removing first element... (Press enter)" << endl;
				getline(cin,tmpStr);
				tmpStudent = ClassroomList.findBySeatNumber(1);
				ClassroomList.removeStudent(tmpStudent);
				cout << endl << "11b) Adding to first element (to the first seat then resorting by seat number)... (Press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.insert("Fernando","Mendez","FCM",1,4,14,"Computer Science");
				ClassroomList.sortBy(5);
				cout << "Displaying... (enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << endl << "12a) Removing last element... (Press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.removeStudent(ClassroomList.getTail());
				cout << endl << "12b) Adding to last element (to the 5th seat then resorting by seat number)... (Press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.insert("Sergio","German Jr","SGJ",5,2,5,"Computer Science");
				ClassroomList.sortBy(5);
				cout << "Displaying... (enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << "13) It turns out, our last student on the list was actually absent today,\nmarking student #5 absent... (enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.markGone(5);
				ClassroomList.introductions();
				cout << "14) Now to see all absent students (recursive function/press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.findAbsent(ClassroomList.getHead());
				cout << "15) Now to display all present students (recursive function/press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.findPresent(ClassroomList.getHead());
				cout << "16) Change 1 of 8 elements for 3 people" << endl;
				cout << "16a) Find by initials 'FCM' then replace Major with 'Software Engineering' (Press enter)" << endl;
				getline(cin,tmpStr);
				tmpStudent = ClassroomList.findByString(1,"FCM");
				if(tmpStudent != nullptr){
					tmpStudent->setMajor("Software Engineering");
					tmpStudent->printInfo();
				}else {
					cout << endl << "*** Warning ***" << endl << endl << "You may have tampered with the test data back at 10)" << endl
						<< "That's ok, this message is here to catch an error that would have been thrown if not caught." << endl << endl;
				}
				cout << endl << "16b) Find by Last Name 'Salvador' then replace Initials with 'LLS' due to a middle initial change. (Press enter)" << endl;
				getline(cin,tmpStr);
				tmpStudent = ClassroomList.findByString(2,"Salvador");
				if(tmpStudent != nullptr){
					tmpStudent->setInitials("LLS");
					tmpStudent->printInfo();
				}else {
					cout << endl << "*** Warning ***" << endl << endl << "You may have tampered with the test data back at 10)" << endl
						<< "That's ok, this message is here to catch an error that would have been thrown if not caught." << endl << endl;
				}
				cout << "16c) Find by First Name 'Grace' then replace pair number to be 3. (Press enter)" << endl;
				getline(cin,tmpStr);
				tmpStudent = ClassroomList.findByString(3,"Grace");
				if(tmpStudent != nullptr){
					tmpStudent->setPair(3);
					tmpStudent->printInfo();
				}else {
					cout << endl << "*** Warning ***" << endl << endl << "You may have tampered with the test data back at 10)" << endl
						<< "That's ok, this message is here to catch an error that would have been thrown if not caught." << endl << endl;
				}
				cout << endl << "17) Display the size of the entire list" << endl;
				cout << "The size of the list (with absent and present people) is " << ClassroomList.getSize()  << " students.";
				cout << endl << "18) Reversing the list... (press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.reverseList();
				cout << "Displaying... (press enter)" << endl;
				getline(cin,tmpStr);
				ClassroomList.introductions();
				cout << endl << "19) Bubble sorting Initials, First Name, Last Name, Major, and Seat Number" << endl;
				cout << "Initials BBL Sort" << endl;
				getline(cin,tmpStr);
				ClassroomList.sortBy(1);
				ClassroomList.introductions();
				cout << "First Name BBL Sort" << endl;
				getline(cin,tmpStr);
				ClassroomList.sortBy(2);
				ClassroomList.introductions();
				cout << "Last Name BBL Sort" << endl;
				getline(cin,tmpStr);
				ClassroomList.sortBy(3);
				ClassroomList.introductions();
				cout << "Major BBL Sort" << endl;
				getline(cin,tmpStr);
				ClassroomList.sortBy(4);
				ClassroomList.introductions();
				cout << "Seat Number BBL Sort" << endl;
				getline(cin,tmpStr);
				ClassroomList.sortBy(5);
				ClassroomList.introductions();
				cout << "20) This concludes the Test Script. (Press enter to end)" << endl;
				getline(cin,tmpStr);
				cout << endl << endl << endl << "End of Test Script v1.0" << endl << endl; //End of test script.
					
				} else{
					cout << "The test script must be ran first before any other option to prevent any previous user entries from affecting the test script's uniform outcome!" << endl << endl;
					MessageBoxA(NULL, "The test script must be ran first before any other option to prevent any previous user entries from affecting the test script's uniform outcome!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
			case 12:
				if(ClassroomList.getSize() > 0){
					cout << "What is the team number to find?" << endl << "Enter: ";
					validateRange(tmp, "Not a valid number, try again: ", 1, maxTeams);
					cout << endl << "Start of team #" << tmp << " list" << endl << "====================";
					ClassroomList.findTeam(tmp, ClassroomList.getHead());
					cout << "====================" << endl << "End of list" << endl << endl;
				} else{
					cout << "There are no students to find by team!" << endl << endl;
					MessageBoxA(NULL, "There are no students to find by team!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
			case 13:
				if(ClassroomList.getSize() > 0)
					ClassroomList.findAbsent(ClassroomList.getHead());
				else {
					cout << "There are no students to replace!" << endl << endl;
					MessageBoxA(NULL, "There are no students to check if absent!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
			case 14:
				if(ClassroomList.getSize() > 0)
					ClassroomList.findPresent(ClassroomList.getHead());
				else {
					cout << "There are no students to replace!" << endl << endl;
					MessageBoxA(NULL, "There are no students to check if present!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
			case 15:
				//Exercise 3.19: Size of the Student List
				cout << "The Classroom has " << ClassroomList.getSize() << " students (absent + present)" << endl;
				break;
			case 16:
				ClassroomList.reverseList();
				break;
			case 17:
				//Exercise 3.11: Replace a Student by another Student within the Student List
				if(ClassroomList.getSize() > 0){
					tmp = prompt("Find student by...?",defaultOptions,defaultOptionsSize);
					switch(tmp){
						case 1:
						case 2:
						case 3:
							cout << "Enter the " << (tmp == 1 ? "Initials" : (tmp == 2 ?  "Last Name" : (tmp == 3 ? "First Name" : "ERROR" ) ) ) << ": " << endl;
							cin.ignore();
							checkForBlankLine(tmpStr);
							cout << "Searching for '" << tmpStr << "'..." << endl;
							tmpStudent = ClassroomList.findByString(tmp,tmpStr);
							break;
						case 4:
							cout << "Enter the seat number: ";
							validateRange(tmp2, "Not a valid number, Try again: ", 1, maxSeats);
							tmpStudent = ClassroomList.findBySeatNumber(tmp2);
							break;
					}
					if (tmpStudent == nullptr)
						cout << "Student not found! Try again." << endl << endl;
					else{
						cout << "Student found!" << endl << "- - - - - - - - - - - - - - - ";
						tmpStudent->printInfo();
						cout << endl << "- - - - - - - - - - - - - - - " << endl << endl;
						
						cout << "Creating new student to replace this with..." << endl;
						ClassroomList.replaceStudent(tmpStudent);
					}
					break;
				}else{
					cout << "There are no students to replace!" << endl << endl;
					MessageBoxA(NULL, "There are no students to replace!", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
				}
				break;
            default:
				cout << "Invalid Option! Try again." << endl << endl;
                MessageBoxA(NULL, "Invalid Option! Try again.", "Project 3 - Sergio German", MB_OK | MB_ICONEXCLAMATION| MB_SYSTEMMODAL);
                break;
        }
    } while (choice != 0);

    return 0;
}