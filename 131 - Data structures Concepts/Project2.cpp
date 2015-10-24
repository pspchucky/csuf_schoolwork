/*

Sergio German Jr
Dr. Kent Palmer
CPSC 131-07
Project 2
10/05/2015

*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Settings in case the class spontaneously expands or shrinks
#define MAX_TEAM 4 //How many teams are there?
#define MAX_PRIORITY 5 //What's the highest priority assign-able?

/*
Dedicated universal function to check if an integer is truely an integer
Otherwise, outputs the given error and asks again for a valid integer
*/
void checkForNumber(int& num, string error)
{
	while (!(cin >> num)) {
		cout << error;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

//Also known as 'stories'
struct node
{
	string name;
	string text;
	int storyNum;
	int priority;
	int team;
	bool done;
	struct node *next = nullptr;
	
	//Debug to see when a node is created and deleted.
//	node() { cout << endl << "A node was created." << endl; };
//	~node(){ cout << endl << "A node was removed." << endl; };
};

//Also known as the 'story backlog' or 'story list'
class nodeList
{
	private:
		node* head;
		node* tail;
		int size;
	public:
		nodeList() {
			head = nullptr;
			tail = nullptr;
			size = 0;
			cout << "An empty nodeList object has been created!" << endl;
		}

		bool isEmpty() { if (size > 0) { return false; } return true; }; //If the list has more than 0 elements, it's not empty/return false for isEmpty().
		//Retrieve a specific node on the list
		node * getNode(int el) { //This function has no checks so everything must be sanitized before it gets here!
			node * tmp = head; //Start from the head
			for (int i = 0; i <= el; i++) { //Iterate down from the head to the desired node
				if (i == el-1) { //We have arrived, if we don't stop here, we'll miss the node!
					return tmp;
				}
				//cout << "Node not found! Moving further down the list..." << endl;
				tmp = tmp->next; //Move down the list one node.
			}
			return nullptr;
		}
		//Exersize 2.3
		void insert(string Name, string Text, int Priority, int Team, bool Done) {
			node *newStory = new node;
			node *prevStory;

			//Store all values into the newly created story
			newStory->name = Name;
			newStory->text = Text;
			newStory->priority = Priority;
			newStory->team = Team;
			newStory->done = Done;

			if (isEmpty()) {
				newStory->storyNum = 1;
				head = newStory;
				tail = newStory;
				size++;
			} else {
				tail = newStory;
				size++;
				newStory->storyNum = size;
				prevStory = getNode(size-1);
				prevStory->next = newStory;
			}
		}
		//Exersize 2.4
		void remove(int choice, string name, int number)
		{
			if (isEmpty()) { //Make sure the list is not empty
				cout << "The list is empty, nothing to remove..." << endl;
			} else {
				if (choice == 1) { //Choice 1 | Find by Name
					node * tmp = head; //Start at the top
					node * tmp2 = nullptr; //Cache to prevent recursive loop from deleting our next job
					int count = 0; //count how many elements to delete
					for (int i = 0; i < size; i++) {
						if (tmp->name == name) {
							count++;
						}
						tmp = tmp->next;
					}
					tmp = head; //reset back to head
					bool doDelete = false; //Should we use our cached result's next pointer or move down the list
					int hasFound = 0;
					for (int i = 0; i < count; i++) {
						if (tmp->name == name) {
							doDelete = true;
							tmp2 = tmp->next; //Cache our current node's next pointer before deleting it
							remove(2, "", tmp->storyNum); //Recursively remove by story number after concluding it needs to be deleted
							hasFound++;
						}

						if (doDelete)
							tmp = tmp2;
						else
							tmp = tmp->next;
						doDelete = false;
					}

					if (hasFound > 0)
						cout << "Success, " << hasFound << " result" << (hasFound > 1 ? "s " : " ") << "removed." << endl;
					else
						cout << "Found 0 results for '" << name << "'" << endl;
				} else { //Choice 2 | Find by Number
					node * tmp = getNode(number);
					if (size == 1) {
						head = nullptr;
						tail = nullptr;
						delete tmp;
						size--;
					}else{
						if(tmp == head){ //Are we targeting the head? 
							node * theNext = getNode(number + 1); //Get the element after the head
							cout << theNext << endl;
							delete tmp; //Remove the head
							size--;
							head = theNext; //The element next to the deleted head is our new head
							head->storyNum--;
							node * tmp2 = head->next;
							while (tmp2 != nullptr) {
								tmp2->storyNum--;
								tmp2 = tmp2->next;
							}
						}else if (tmp == tail) { //How about the tail?
							node * prev = getNode(number - 1);
							prev->next = nullptr;
							delete tmp; //Remove the tail
							size--;
							tail = prev; //Our new tail is the element before it
						} else { //It must be somewhere in between them...
							node * prev = getNode(number - 1); //get the node before the one being removed
							node * theNext = getNode(number + 1); //and then get the node after it so we can repoint prev->theNext
							delete tmp; //Remove the current node
							size--;
							prev->next = theNext; //The current element is gone and the list is rechained!
							theNext->storyNum--;
							node * tmp2 = theNext->next;
							while (tmp2 != nullptr) {
								tmp2->storyNum--;
								tmp2 = tmp2->next;
							}
						}
					}
				}
			}
		}
		//Exersize 2.5
		void find(int choice, string name, int number)
		{
			if (isEmpty()) { //Make sure the list is not empty
				cout << "The list is empty, nothing to remove..." << endl;
			} else {
				if (choice == 1) { //Choice 1 | Find by Name
					node * tmp = getNode(1); //Start at the top
					int hasFound = 0;
					for (int i = 0; i < size; i++) {
						if (tmp->name == name) {
							hasFound++;
							cout << endl << "====================" << endl
								<< "Story #" << tmp->storyNum << endl
								<< "Name: " << tmp->name << endl
								<< "Text: " << tmp->text << endl
								<< "Priority: " << tmp->priority << endl
								<< "Team: " << tmp->team << endl
								<< "Is Complete: " << ((tmp->done) == true ? "true" : "false") << endl
								<< "Current Story Mem. Location: " << tmp << endl
								<< "Next Story Mem. Location: " << (tmp->next) << endl
								<< endl << "====================" << endl;
						}
							tmp = tmp->next;
					}
					if (hasFound > 0)
						cout << "Success, " << hasFound << " result" << (hasFound > 1 ? "s " : " ") << "found." << endl;
					else
						cout << "Found 0 results for '" << name << "'" << endl; 
				} else { //Choice 2 | Find by Number
					node * tmp = getNode(number);
					if (tmp == nullptr) {
						cout << "Cannot find the specified story number!" << endl;
					} else {
						cout << endl << "====================" << endl
							<< "Story #" << tmp->storyNum << endl
							<< "Name: " << tmp->name << endl
							<< "Text: " << tmp->text << endl
							<< "Priority: " << tmp->priority << endl
							<< "Team: " << tmp->team << endl
							<< "Is Complete: " << ((tmp->done) == true ? "true" : "false") << endl
							<< "Current Story Mem. Location: " << tmp << endl
							<< "Next Story Mem. Location: " << (tmp->next) << endl
							<< endl << "====================" << endl;
					}
				}
			}
		}
		void setPriority(int choice, string name, int number, int priority)
		{
			if (isEmpty()) { //Make sure the list is not empty
				cout << "The list is empty, nothing to prioritize..." << endl;
			} else {
				if (choice == 1) { //Choice 1 | Prioritize by Name
					node * tmp = getNode(1); //Start at the top
					int hasFound = 0;
					for (int i = 0; i < size; i++) {
						if (tmp->name == name) {
							hasFound++;
							cout << "Modifiying Story #" << tmp->storyNum  << "..." << endl;
							tmp->priority = priority;
							cout << endl << "====================" << endl
								<< "Story #" << tmp->storyNum << endl
								<< "Priority: " << tmp->priority << endl
								<< "====================" << endl;
						}
						tmp = tmp->next;
					}
					if (hasFound > 0)
						cout << "Success, " << hasFound << " result" << (hasFound > 1 ? "s " : " ") << "updated." << endl;
					else
						cout << "Found 0 results for '" << name << "'" << endl;
				} else { //Choice 2 | Prioritize by Number
					node * tmp = getNode(number);
					if (tmp == nullptr) {
						cout << "Cannot find the specified story number!" << endl;
					}
					else {
						cout << "Modifiying Story #" << tmp->storyNum << "..." << endl;
						tmp->priority = priority;
						cout << endl << "====================" << endl
							<< "Story #" << tmp->storyNum << endl
							<< "Priority: " << tmp->priority << endl
							<< "====================" << endl;
					}
				}
			}
		}
		//Exersize 2.11
		void findByPriority(int priority)
		{
			node * tmp = head; //Start from the head
			int hasFound = 0;
			for (int i = 0; i < size; i++) { //Iterate down from the head to the desired node
				if (tmp->priority == priority)
				{
					cout << endl << "====================" << endl
						<< "Story #" << tmp->storyNum << endl
						<< "Name: " << tmp->name << endl
						<< "Text: " << tmp->text << endl
						<< "Priority: " << tmp->priority << endl
						<< "Team: " << tmp->team << endl
						<< "Is Complete: " << ((tmp->done) == true ? "true" : "false") << endl
						<< "Current Story Mem. Location: " << tmp << endl
						<< "Next Story Mem. Location: " << (tmp->next) << endl
						<< endl << "====================" << endl;
					hasFound++;
				}
				if(tmp->next != nullptr)
					tmp = tmp->next; //Move down the list one node.
				else
					break;
			}

			if (hasFound > 0)
				cout << endl <<"Success, " << hasFound << " result" << (hasFound > 1 ? "s " : " ") << "found." << endl;
			else
				cout << endl << "Found 0 results for priority level '" << priority << "'" << endl; 
		}
		//Part of Exersize 2.16
		void markDone(node * node) { node->done = true; };
		void markNotDone(node * node) { node->done = false; };
		void append()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to select..." << endl;
			} else {
				int choice = 0;
				node * tmp = nullptr;
				char ans;
			do {
				cout << "Which story to modify?" << endl
					<< "1) First Story" << endl
					<< "2) Last Story" << endl
					<< "0) Cancel" << endl;
				checkForNumber(choice, "Invalid choice, Try Again (1-2): ");

				switch (choice) {	
					case 0:
						cout << "Returning to menu..." << endl;
						break;
					case 1:
						cout << "Displaying first story: " << endl;
						tmp = head;
							cout << endl << "====================" << endl
								<< "Story #" << tmp->storyNum << endl
								<< "Name: " << tmp->name << endl
								<< "Text: " << tmp->text << endl
								<< "Priority: " << tmp->priority << endl
								<< "Team: " << tmp->team << endl
								<< "Is Complete: " << ((tmp->done) == true ? "true" : "false") << endl
								<< "Current Story Mem. Location: " << tmp << endl
								<< "Next Story Mem. Location: " << (tmp->next) << endl
								<< endl << "====================" << endl;
						cout << "Would you like to override this existing story with new data?" << endl << "Enter (y/n): ";
						cin >> ans;
						if(toupper(ans) == 'N')
							break;
						else if(toupper(ans) == 'Y') {
							string text = "";
							string name = "";
							int priority = 0;
							int team = 0;
							bool done = false;
							cout << "Enter the Story Name: ";
							cin.ignore();
							getline(cin,name);
							cout << endl << "Enter the Story Text: ";
							getline(cin, text);
							cout << endl << "Enter the Story's Priority: " << endl
								<< "Note: Enter 0 if the story has no priority or a priority from 1 to " << MAX_PRIORITY << endl
								<< "Enter (0-" << MAX_PRIORITY << "): ";
							checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
							while ((priority > MAX_PRIORITY || priority < 0)) { //Keep asking for numbers if they're out of the range
								if (priority > MAX_PRIORITY) {
									cout << "Value over the max priority! Try again" << endl << "Enter: ";
								}
								else if (priority < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter: ";
								}
								checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
							}
							cout << endl << "Enter the Story's assigned team" 
								<< endl << "Note: Enter 0 if no team is assigned this story" << endl
								<< "Enter (0-" << MAX_TEAM << "): ";
							checkForNumber(team, ("Invalid number, Try Again (0-" + to_string(MAX_TEAM) + "): "));
							while ((team > MAX_TEAM || team < 0)) { //Keep asking for numbers if they're out of the range
								if (team > MAX_TEAM) {
									cout << "There isn't a team #" << team << "! Try again" << endl << "Enter: ";
								}
								else if (team < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter: ";
								}
								checkForNumber(team, "Invalid number, Try Again (1-" + to_string(MAX_TEAM) + "): ");
							}
						//Create a new story and set all newly given values
						node * newStory = new node;
						newStory->name = name;
						newStory->text = text;
						newStory->priority = priority;
						newStory->team = team;
						newStory->done = done;
						//Get current head element
						node * oldStory = head;
						node * oldStoryNext = head->next;
						newStory->storyNum = oldStory->storyNum;
						//Repoint the head
						head = newStory;
						//Remove old head
						delete oldStory;
						//Point the newStory to the next element
						newStory->next = oldStoryNext;
						cout << "The first story has been overrided by the newly inputted story!" << endl;
						} else {
							cout << "Invalid choice, escaping to menu..." << endl;
							break;
						}
						break;
					case 2:
						cout << "Displaying last story: " << endl;
						tmp = tail;
							cout << endl << "====================" << endl
								<< "Story #" << tmp->storyNum << endl
								<< "Name: " << tmp->name << endl
								<< "Text: " << tmp->text << endl
								<< "Priority: " << tmp->priority << endl
								<< "Team: " << tmp->team << endl
								<< "Is Complete: " << ((tmp->done) == true ? "true" : "false") << endl
								<< "Current Story Mem. Location: " << tmp << endl
								<< "Next Story Mem. Location: " << (tmp->next) << endl
								<< endl << "====================" << endl;
						cout << "Would you like to override this existing story with new data?" << endl << "Enter (y/n): ";
						cin >> ans;
						if(toupper(ans) == 'N')
							break;
						else if(toupper(ans) == 'Y') {
							string text = "";
							string name = "";
							int priority = 0;
							int team = 0;
							bool done = false;
							cout << "Enter the Story Name: ";
							cin.ignore();
							getline(cin,name);
							cout << endl << "Enter the Story Text: ";
							getline(cin, text);
							cout << endl << "Enter the Story's Priority: " << endl
								<< "Note: Enter 0 if the story has no priority or a priority from 1 to " << MAX_PRIORITY << endl
								<< "Enter (0-" << MAX_PRIORITY << "): ";
							checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
							while ((priority > MAX_PRIORITY || priority < 0)) { //Keep asking for numbers if they're out of the range
								if (priority > MAX_PRIORITY) {
									cout << "Value over the max priority! Try again" << endl << "Enter: ";
								}
								else if (priority < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter: ";
								}
								checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
							}
							cout << endl << "Enter the Story's assigned team" 
								<< endl << "Note: Enter 0 if no team is assigned this story" << endl
								<< "Enter (0-" << MAX_TEAM << "): ";
							checkForNumber(team, ("Invalid number, Try Again (0-" + to_string(MAX_TEAM) + "): "));
							while ((team > MAX_TEAM || team < 0)) { //Keep asking for numbers if they're out of the range
								if (team > MAX_TEAM) {
									cout << "There isn't a team #" << team << "! Try again" << endl << "Enter: ";
								}
								else if (team < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter: ";
								}
								checkForNumber(team, "Invalid number, Try Again (1-" + to_string(MAX_TEAM) + "): ");
							}
						//Create a new story and set all newly given values
						node * AnewStory = new node;
						node * prevStory = getNode(size-1);
						AnewStory->name = name;
						AnewStory->text = text;
						AnewStory->priority = priority;
						AnewStory->team = team;
						AnewStory->done = done;
						//Get current tail element
						node * oldStory = getNode(size);
						AnewStory->storyNum = oldStory->storyNum;
						//Repoint the tail
						tail = AnewStory;
						//Remove old tail
						delete oldStory;
						//Point the newStory to null
						AnewStory->next = nullptr;
						prevStory->next = AnewStory;
						cout << "The first story has been overrided by the newly inputted story!" << endl; 
						}
						else {
							cout << "Invalid choice, escaping to menu..." << endl;
							break;
						}
						break;
					default:
						cout << "Invalid option! Try again: " << endl;
						break;
				}
				}while( !(choice != 1 || choice!= 2 || choice != 0) );
			}
		}
	
		//Exersize 2.1 
		void fill()
		{
			int n = 0;
			string text = "";
			string name = "";
			int priority = 0;
			int team = 0;
			bool done = false;
			cout << "Number of stories to be filled: ";
			checkForNumber(n, "Invalid option, please enter a valid option: ");

			if (n > 0) {
				cout << endl << n << " stories will be added." << endl;
				for (int i = 0; i < n; i++) {
					cout << "Entering Story #" << i+1 << endl
						<< "Enter the Story Name: ";
					cin.ignore();
					getline(cin,name);
					cout << endl << "Enter the Story Text: ";
					getline(cin, text);
					cout << endl << "Enter the Story's Priority: " << endl
						<< "Note: Enter 0 if the story has no priority or a priority from 1 to " << MAX_PRIORITY << endl
						<< "Enter (0-" << MAX_PRIORITY << "): ";
					checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
					while ((priority > MAX_PRIORITY || priority < 0)) { //Keep asking for numbers if they're out of the range
						if (priority > MAX_PRIORITY) {
							cout << "Value over the max priority! Try again" << endl << "Enter: ";
						}
						else if (priority < 0) {
							cout << "Value in the negatives! Try again" << endl << "Enter: ";
						}
						checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
					}
					cout << endl << "Enter the Story's assigned team" 
						<< endl << "Note: Enter 0 if no team is assigned this story" << endl
						<< "Enter (0-" << MAX_TEAM << "): ";
					checkForNumber(team, ("Invalid number, Try Again (0-" + to_string(MAX_TEAM) + "): "));
					while ((team > MAX_TEAM || team < 0)) { //Keep asking for numbers if they're out of the range
						if (team > MAX_TEAM) {
							cout << "There isn't a team #" << team << "! Try again" << endl << "Enter: ";
						}
						else if (team < 0) {
							cout << "Value in the negatives! Try again" << endl << "Enter: ";
						}
						checkForNumber(team, "Invalid number, Try Again (1-" + to_string(MAX_TEAM) + "): ");
					}
					//Insert all newly aquired data
					insert(name, text, priority, team, done);

					//Clear story data for next iteration
					name = "";
					text = "";
					priority = 0;
					team = 0;
					done = false;

				}
			} else {
				cout << endl << "Nothing to do with the stories" << endl;
			}
		}
		void dump()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to delete..." << endl;
			}else{
				int choice, num = 0;
				string name = "";
				do {
					cout << endl << "Remove by Story Name or Number?" << endl
						<< "1) Name" << endl
						<< "2) Number" << endl
						<< "0) Cancel" << endl
						<< "Enter (0-2): ";

					checkForNumber(choice, "Invalid option, please enter a valid option: ");

				switch (choice) {
					case 0:
						cout << "Returning to menu..." << endl;
						break;
					case 1:
						cout << "Enter a name: ";
						cin.ignore();
						getline(cin,name);
						remove(1, name, num); //Find by name! aka Choice 1
						cout << "Returning to menu..." << endl;
						break;
					case 2:
						cout << "Enter a number (1-" << size << "): ";
						checkForNumber(num, "Invalid number, please enter a valid number: ");
						while ((num > size || num <= 0)) { //Keep asking for numbers if they're out of the list's range
							if (num > size) {
								cout << "Value over the size of the list! Try again" << endl << "Enter (1-" << size << "): ";
							} else if (num < 0) {
								cout << "Value in the negatives! Try again" << endl << "Enter (1-" << size << "): ";
							} else if (num == 0) {
								cout << "The first element in a list is 1! Try again" << endl << "Enter (1-" << size << "): ";
							}
							checkForNumber(num, "Invalid number, please enter a valid number: ");
						}
						remove(2, name, num);//Find by number! aka Choice 2
						cout << "Returning to menu..." << endl;
						break;
					default:
						cout << "Invalid option! Try again: " << endl;
						break;
				}

				}while(!(choice == 0 || choice == 1 || choice == 2));
			}
		}
		void search()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to search for..." << endl;
			} else {
				int choice, num = 0;
				string name = "";
				do {
					cout << endl << "Find by Story Name or Number?" << endl
						<< "1) Name" << endl
						<< "2) Number" << endl
						<< "0) Cancel" << endl
						<< "Enter (0-2): ";

					checkForNumber(choice, "Invalid option, please enter a valid option: ");

					switch (choice) {
					case 0:
						cout << "Returning to menu..." << endl;
						break;
					case 1:
						cout << "Enter a name: ";
						cin.ignore();
						getline(cin, name);
						find(1, name, num); //Find by name! aka Choice 1
						cout << "Returning to menu..." << endl;
						break;
					case 2:
						cout << "Enter a number (1-" << size << ": ";
						checkForNumber(num, "Invalid number, please enter a valid number: ");
						while ((num > size || num <= 0)) { //Keep asking for numbers if they're out of the list's range
							if (num > size) {
								cout << "Value over the size of the list! Try again" << endl << "Enter (1-" << size << "): ";
							}
							else if (num < 0) {
								cout << "Value in the negatives! Try again" << endl << "Enter (1-" << size << "): ";
							}
							else if (num == 0) {
								cout << "The first element in a list is 1! Try again" << endl << "Enter (1-" << size << "): ";
							}
							checkForNumber(num, "Invalid number, please enter a valid number: ");
						}
						find(2, name, num);//Find by number! aka Choice 2
						cout << "Returning to menu..." << endl;
						break;
					default:
						cout << "Invalid option! Try again: " << endl;
						break;
					}

				} while (!(choice == 0 || choice == 1 || choice == 2));
			}
		}
		//Exersize 2.2
		void traverse()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to show..." << endl;
			} else {
				node *tmp = head;
				cout << "====================" << endl;
				for (int i = 0; i < size; i++) {
					cout << endl
						<< "Story #" << tmp->storyNum << endl
						<< "Name: " << tmp->name << endl
						<< "Text: " << tmp->text << endl
						<< "Priority: " << tmp->priority << endl
						<< "Team: " << tmp->team << endl
						<< "Is Complete: " << ((tmp->done) == true ? "true" : "false") << endl
						<< "Current Story Mem. Location: " << tmp << endl
						<< "Next Story Mem. Location: " << (tmp->next) << endl
						<< endl;
					tmp = tmp->next;
					if(i  == (size)){ tail = tmp; };
				}
				cout << "====================" << endl << endl;
			}
		}
		//Exersize 2.7
		void assignPriority()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to assign a priority to..." << endl;
			} else {
				int choice, num = 0, priority;
				string name = "";
				do {
					cout << endl << "Assign priority by Story Name or Number?" << endl
						<< "1) Name" << endl
						<< "2) Number" << endl
						<< "0) Cancel" << endl
						<< "Enter (0-2): ";

					checkForNumber(choice, "Invalid option, please enter a valid option: ");

					switch (choice) {
						case 0:
							cout << "Returning to menu..." << endl;
							break;
						case 1:
							cout << "Enter a name: ";
							cin.ignore();
							getline(cin, name);
							cout << endl << "Enter the Story's Priority: " << endl
								<< "Note: Enter 0 if the story has no priority or a priority from 1 to " << MAX_PRIORITY << endl
								<< "Enter (0-" << MAX_PRIORITY << "): ";
							cin >> priority;
							while ((priority > MAX_PRIORITY || priority < 0)) { //Keep asking for numbers if they're out of the range
								if (priority > MAX_PRIORITY) {
									cout << "Value over the max priority! Try again" << endl << "Enter: ";
								}
								else if (priority < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter: ";
								}
								checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
							}
							setPriority(1, name, num, priority);
							cout << "Returning to menu..." << endl;
							break;
						case 2:
							cout << "Enter a number (1-" << size << "): ";
							checkForNumber(num, "Invalid number, please enter a valid number: ");
							while ((num > size || num <= 0)) { //Keep asking for numbers if they're out of the list's range
								if (num > size) {
									cout << "Value over the size of the list! Try again" << endl << "Enter (1-" << size << "): ";
								}
								else if (num < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter (1-" << size << "): ";
								}
								else if (num == 0) {
									cout << "The first element in a list is 1! Try again" << endl << "Enter (1-" << size << "): ";
								}
								checkForNumber(num, "Invalid number, please enter a valid number: ");
							}
							cout << endl << "Enter the Story's Priority: " << endl
								<< "Note: Enter 0 if the story has no priority or a priority from 1 to " << MAX_PRIORITY << endl
								<< "Enter (0-" << MAX_PRIORITY << "): ";
							cin >> priority;
							while ((priority > MAX_PRIORITY || priority < 0)) { //Keep asking for numbers if they're out of the range
								if (priority > MAX_PRIORITY) {
									cout << "Value over the max priority! Try again" << endl << "Enter: ";
								}
								else if (priority < 0) {
									cout << "Value in the negatives! Try again" << endl << "Enter: ";
								}
								checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
							}
							setPriority(2, "", num, priority);
							cout << "Returning to menu..." << endl;
							break;
						default:
							cout << "Invalid option! Try again: " << endl;
							break;
						}

				} while (!(choice == 0 || choice == 1 || choice == 2));
			}
		}
		//Exersize 2.8
		void assignTeam()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to assign a team to..." << endl;
			} else {
				int num = 0;
						cout << "Enter a story number (1-" << size << "): ";
						checkForNumber(num, "Invalid number, please enter a valid number: ");
						while ((num > size || num <= 0)) { //Keep asking for numbers if they're out of the list's range
							if (num > size) {
								cout << "Value over the size of the list! Try again" << endl << "Enter (1-" << size << "): ";
							}
							else if (num < 0) {
								cout << "Value in the negatives! Try again" << endl << "Enter (1-" << size << "): ";
							}
							else if (num == 0) {
								cout << "The first element in a list is 1! Try again" << endl << "Enter (1-" << size << "): ";
							}
							checkForNumber(num, "Invalid number, please enter a valid story number: ");
						}

					int team = 0;
					cout << endl << "Enter the Story's assigned team"
						<< endl << "Note: Enter 0 if no team is assigned this story" << endl
						<< "Enter (0-" << MAX_TEAM << "): ";
					cin >> team;
					while ((team > MAX_TEAM || team < 0)) { //Keep asking for numbers if they're out of the range
						if (team > MAX_TEAM) {
							cout << "There isn't a team #" << team << "! Try again" << endl << "Enter: ";
						}
						else if (team < 0) {
							cout << "Value in the negatives! Try again" << endl << "Enter: ";
						}
						checkForNumber(team, "Invalid number, Try Again (1-" + to_string(MAX_TEAM) + "): ");
					}
					node * tmp = getNode(num);
					tmp->team = team;
					cout << "Assigned team #" << team << " with story #" << num
					    << "Returning to menu..." << endl;
			}
		}
		//Exersize 2.9
		void sortByPriorityTeam()
		{
			if (isEmpty()) { //Make sure the list is not empty
				cout << "The list is empty, nothing to remove..." << endl;
			} else {
				cout << "Bubble sorting by priority first..." << endl;
				//Sorting algorithm: Bubble Sort (Greatest -> Least)
				for (int i = 0; i < size; i++) {
					struct node* current = head;
					struct node* next = current->next;
					struct node* prev = nullptr;

					while(next != nullptr) {
						if ((current->priority < next->priority) > 0) {
							if (current == head)
								head = next;
							else
								prev->next = next;

							current->next = next->next;
							next->next = current; 

							prev = next;
							next = current->next;
						} else {
							prev = current;
							current = current->next;
							next = current->next;
						}
					}
				}
				cout << endl << "Now sorting by team..." << endl;
				//Sorting algorithm: Bubble Sort (Greatest -> Least)
				for (int i = 0; i < size; i++) {
					struct node* current = head;
					struct node* next = current->next;
					struct node* prev = nullptr;

					while(next != nullptr) {
						if ((current->team < next->team) > 0) {
							if (current == head)
								head = next;
							else
								prev->next = next;

							current->next = next->next;
							next->next = current; 

							prev = next;
							next = current->next;
						} else {
							prev = current;
							current = current->next;
							next = current->next;
						}
					}
				}
				cout << endl << "Returning to menu..." << endl;
			}
		}
		//Exersize 2.10
		void sortByTeamPriority()
		{
			if (isEmpty()) { //Make sure the list is not empty
				cout << "The list is empty, nothing to remove..." << endl;
			} else {
				cout << "Bubble sorting by team first..." << endl;
				//Sorting algorithm: Bubble Sort (Greatest -> Least)
				for (int i = 0; i < size; i++) {
					struct node* current = head;
					struct node* next = current->next;
					struct node* prev = nullptr;

					while(next != nullptr) {
						if ((current->team < next->team) > 0) {
							if (current == head)
								head = next;
							else
								prev->next = next;

							current->next = next->next;
							next->next = current; 

							prev = next;
							next = current->next;
						} else {
							prev = current;
							current = current->next;
							next = current->next;
						}
					}
				}
				cout << endl << "Now sorting by priority..." << endl;
				//Sorting algorithm: Bubble Sort (Greatest -> Least)
				for (int i = 0; i < size; i++) {
					struct node* current = head;
					struct node* next = current->next;
					struct node* prev = nullptr;

					while(next != nullptr) {
						if ((current->priority < next->priority) > 0) {
							if (current == head)
								head = next;
							else
								prev->next = next;

							current->next = next->next;
							next->next = current; 

							prev = next;
							next = current->next;
						} else {
							prev = current;
							current = current->next;
							next = current->next;
						}
					}
				}
				cout << endl << "Returning to menu..." << endl;
			}
		}
		void findPriority()
		{
			if (isEmpty()) { //Make sure the list is not empty
				cout << "The list is empty, nothing to find..." << endl;
			} else {
			int priority = 0;
			cout << endl << "Enter a Story's Priority: " << endl
				<< "Note: Enter 0 if the story has no priority or a priority from 1 to " << MAX_PRIORITY << endl
				<< "Enter (0-" << MAX_PRIORITY << "): ";
			cin >> priority;
			while ((priority > MAX_PRIORITY || priority < 0)) { //Keep asking for numbers if they're out of the range
				if (priority > MAX_PRIORITY) {
					cout << "Value over the max priority! Try again" << endl << "Enter: ";
				}
				else if (priority < 0) {
					cout << "Value in the negatives! Try again" << endl << "Enter: ";
				}
				checkForNumber(priority, ("Invalid number, Try Again (0-" + to_string(MAX_PRIORITY) + "): "));
			}
			findByPriority(priority);
			cout << "Returning to menu..." << endl;
			return;
			}
		}
		//Exersize 2.19
		int getSize(){ return size; };
		//Exersize 2.16
		void markStories()
		{
			if (isEmpty()) {
				cout << "The list is empty, nothing to mark as complete/incomplete..." << endl;
			} else {
				int num = 0, choice = 0; 
				cout << "Enter a story number (1-" << size << "): ";
				checkForNumber(num, "Invalid number, please enter a valid story number: ");
				while ((num > size || num <= 0)) { //Keep asking for numbers if they're out of the list's range
					if (num > size) {
						cout << "Value over the size of the list! Try again" << endl << "Enter (1-" << size << "): ";
					}
					else if (num < 0) {
						cout << "Value in the negatives! Try again" << endl << "Enter (1-" << size << "): ";
					}
					else if (num == 0) {
						cout << "The first element in a list is 1! Try again" << endl << "Enter (1-" << size << "): ";
					}
					checkForNumber(num, "Invalid number, please enter a valid story number: ");
				}

				cout << "Mark story #" << num << " as complete or incomplete?" << endl
						<< "1) Complete" << endl
						<< "2) Incomplete" << endl
						<< "Enter (1 or 2): ";

				checkForNumber(choice, "Invalid option, please enter a valid option: ");
				while ((choice > 2 || choice <= 0)) { //Keep asking for numbers if they're out of the list's range
					if (choice > 2) {
						cout << "Value over the size of the list! Try again" << endl << "Enter (1 or 2): ";
					}
					else if (choice < 0) {
						cout << "Value in the negatives! Try again" << endl << "Enter (1 or 2): ";
					}
					else if (choice == 0) {
						cout << "There is no option 0! Try again" << endl << "Enter (1 or 2): ";
					}
					checkForNumber(choice, "Invalid number, please enter a valid option: ");
				}
				//Mark story as complete/incomplete
				switch(choice)
				{ 
					case 1:
						markDone(getNode(num));
						cout << "Story #" << num << " marked as complete." << endl;
						break;
					case 2:
						markNotDone(getNode(num));
						cout << "Story #" << num << " marked as incomplete." << endl;
						break;
				}
			}
		}
		//Exersize 2.17
		void progress()
		{
			node * tmp = head; //Start from the head
			int hasFound = 0;
			for (int i = 0; i < size; i++) { //Iterate down from the head to the desired node
				if (tmp->done == true)
				{
					cout << endl << "Story #" << tmp->storyNum << " is done." << endl;
					hasFound++;
				}
				if(tmp->next != nullptr)
					tmp = tmp->next; //Move down the list one node.
				else
					break;
			}

			if (hasFound > 0)
				cout << endl <<"Success, " << hasFound << " result" << (hasFound > 1 ? "s " : " ") << "found." << endl;
			else
				cout << endl << "There are 0 completed stories!" << endl; 
		}   
		//Exersize 2.20
		void completion()
		{
			node * tmp = head; //Start from the head
			bool allDone = true;
			for (int i = 0; i < size; i++) { //Iterate down from the head to the desired node
				if (tmp->done == false)
					allDone = false;
			}

			if (allDone == true)
				cout << endl <<"Success! All stories are completed! *confetti*" << endl;
			else
				cout << endl << "Failure! Not all stories have been completed!" << endl; 
		}
		//As requested
		void testCases(int Case)
		{
			/*
			Use a constant seed that will return the following random numbers 
			(and 500 more in the stress test in every single run).
			1st 100 pseudo-random numbers from 0 to 5 FROM seed '1234' -> [(rand() % 6 + 0)] (Used to create 'random' priorities for stories)
			0, 5, 3, 3, 4, 3, 1, 2, 2, 1, 3, 3, 4, 5, 0, 5, 2, 1, 4, 3, 2, 2, 2, 1, 1, 0, 4, 4, 0, 2, 2, 0, 1, 3, 2, 3, 0, 3, 5, 0, 2, 3, 4, 4, 2, 2, 3, 4, 1, 0, 2, 4, 2, 2, 3, 1, 0, 5, 3, 1, 1, 0, 5, 0, 1, 5, 4, 2, 0, 3, 0, 1, 0, 2, 5, 1, 2, 3, 3, 4, 3, 5, 0, 3, 0, 1, 4, 0, 4, 1, 5, 3, 5, 3, 3, 1, 2, 1, 1, 1
			1st 100 pseudo-random numbers from 0 to 4 FROM seed '1234' -> [(rand() % 5 + 0)] (Used to create 'random' team assignments for stories)
			4, 4, 0, 2, 0, 1, 0, 3, 2, 3, 0, 1, 1, 3, 3, 1, 3, 0, 4, 1, 0, 4, 3, 4, 0, 0, 4, 2, 1, 1, 2, 0, 0, 4, 0, 2, 0, 0, 0, 4, 0, 1, 1, 3, 4, 1, 4, 2, 3, 1, 4, 4, 0, 4, 0, 2, 1, 1, 1, 3, 2, 4, 0, 4, 0, 2, 2, 1, 4, 2, 2, 2, 3, 0, 0, 0, 3, 0, 4, 2, 1, 3, 3, 3, 0, 0, 0, 1, 3, 1, 1, 2, 2, 4, 1, 3, 1, 3, 1, 3
			*/
			srand(1234); //pseudo-random num generator w/ seed 1234, returned values are shown above
			string randSubjects[10] = {"santa","pizza","tacos","family","computers","bananas","peaches","tables","cans"};
			string tmp = "";
			node * tmpNode = head;
			switch (Case)
			{
				case 1:
					//5 stories
					for (int i = 0; i < 5; i++)
					{
						insert("The great story volume #" + to_string(i+1), "A generic story about " + randSubjects[i%9], (rand() % 6 + 0), (rand() % 5 + 0), false);
					}
	
					cout << "5 generic stories were created." << endl;
					cout << "Press enter to transverse through the list" << endl;
					cin.ignore();
					getline(cin,tmp);
					traverse();
					cout << "Press enter to remove the 3rd story and traverse immediately to see results." << endl;
					getline(cin,tmp);
					remove(2,"",3);
					traverse();	
					cout << "Press enter to mark all stories done and see if all stories are completed." << endl;
					getline(cin,tmp);
					for (int i = 1; i < 5; i++)
					{	
						markDone(getNode(i));
					}
					completion();
					cout << "Press enter to find story number 2 and display it." << endl;
					getline(cin,tmp);
					find(2, "", 2);
					cout << "Press enter to sort the list by Priority then Team and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByPriorityTeam();
					traverse();
					cout << "Press enter to sort the list by Team then Priority and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByTeamPriority();
					traverse();
					cout << "Press enter to display the size while transversing to verify the list is the expected size" << endl;
					getline(cin, tmp);
					cout << "Checking list size..." << endl;
					cout << "List size = " << getSize() << endl;
					cout << "Traversing to verify..." << endl;
					traverse();
					cout << "Verified! All stories present." << endl;
					cout << "Every single input is sanitized and checked to prevent any malfunctions to the list." << endl
					<< "Press enter to explore the rest of the program. " << endl
					<< "The test cases can be ran multiple times over and over and mixed and matched without failure." << endl;
					getline(cin, tmp);
					break;
				case 2:
					//20 stories
					for (int i = 0; i < 20; i++)
					{
						insert("The great story volume #" + to_string(i+1), "A generic story about " + randSubjects[i%9], (rand() % 6 + 0), (rand() % 5 + 0), false);
					}
					cout << "20 generic stories were created." << endl;
					cout << "Press enter to transverse through the list" << endl;
					cin.ignore();
					getline(cin,tmp);
					traverse();
					cout << "Press enter to remove the 12th story and traverse immediately to see results." << endl;
					getline(cin,tmp);
					remove(2,"",12);
					traverse();	
					cout << "Press enter to mark all stories done and see if all stories are completed." << endl;
					getline(cin,tmp);
					for (int i = 1; i < 20; i++)
					{	
						markDone(getNode(i));
					}
					completion();
					cout << "Press enter to find story number 18 and display it." << endl;
					getline(cin,tmp);
					find(2, "", 18);
					cout << "Press enter to sort the list by Priority then Team and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByPriorityTeam();
					traverse();
					cout << "Press enter to sort the list by Team then Priority and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByTeamPriority();
					traverse();
					cout << "Press enter to display the size while transversing to verify the list is the expected size" << endl;
					getline(cin, tmp);
					cout << "Checking list size..." << endl;
					cout << "List size = " << getSize() << endl;
					cout << "Traversing to verify..." << endl;
					traverse();
					cout << "Verified! All stories present." << endl;
					cout << "Every single input is sanitized and checked to prevent any malfunctions to the list." << endl
					<< "Press enter to explore the rest of the program. " << endl
					<< "The test cases can be ran multiple times over and over and mixed and matched without failure." << endl;
					getline(cin, tmp);
					break;
				case 3:
					//50 stories
					for (int i = 0; i < 50; i++)
					{
						insert("The great story volume #" + to_string(i+1), "A generic story about " + randSubjects[i%9], (rand() % 6 + 0), (rand() % 5 + 0), false);
					}
					cout << "50 generic stories were created." << endl;
					cout << "Press enter to transverse through the list" << endl;
					cin.ignore();
					getline(cin,tmp);
					traverse();
					cout << "Press enter to remove the 32nd story and traverse immediately to see results." << endl;
					getline(cin,tmp);
					remove(2,"",32);
					traverse();	
					cout << "Press enter to mark all stories done and see if all stories are completed." << endl;
					getline(cin,tmp);
					for (int i = 1; i < 50; i++)
					{	
						markDone(getNode(i));
					}
					completion();
					cout << "Press enter to find story number 32 and display it." << endl;
					getline(cin,tmp);
					find(2, "", 32);
					cout << "Press enter to sort the list by Priority then Team and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByPriorityTeam();
					traverse();
					cout << "Press enter to sort the list by Team then Priority and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByTeamPriority();
					traverse();
					cout << "Press enter to display the size while transversing to verify the list is the expected size" << endl;
					getline(cin, tmp);
					cout << "Checking list size..." << endl;
					cout << "List size = " << getSize() << endl;
					cout << "Traversing to verify..." << endl;
					traverse();
					cout << "Verified! All stories present." << endl;
					cout << "Every single input is sanitized and checked to prevent any malfunctions to the list." << endl
					<< "Press enter to explore the rest of the program. " << endl
					<< "The test cases can be ran multiple times over and over and mixed and matched without failure." << endl;
					getline(cin, tmp);
					break;
				case 4:
					//600 stories (woah)
					for (int i = 0; i < 600; i++)
					{
						insert("The great story volume #" + to_string(i+1), "A generic story about " + randSubjects[i%9], (rand() % 6 + 0), (rand() % 5 + 0), false);
					}
					cout << "600 generic stories were created." << endl;
					cout << "Press enter to transverse through the list" << endl;
					cin.ignore();
					getline(cin,tmp);
					traverse();
					cout << "Press enter to remove the 233rd story and traverse immediately to see results." << endl;
					getline(cin,tmp);
					remove(2,"",233);
					traverse();	
					cout << "Press enter to mark all stories done and see if all stories are completed." << endl;
					getline(cin,tmp);
					for (int i = 1; i < 600; i++)
					{	
						markDone(getNode(i));
					}
					completion();
					cout << "Press enter to find story number 422 and display it." << endl;
					getline(cin,tmp);
					find(2, "", 422);
					cout << "Press enter to sort the list by Priority then Team and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByPriorityTeam();
					traverse();
					cout << "Press enter to sort the list by Team then Priority and transverse afterwards" << endl;
					getline(cin, tmp);	
					sortByTeamPriority();
					traverse();
					cout << "Press enter to display the size while transversing to verify the list is the expected size" << endl;
					getline(cin, tmp);
					cout << "Checking list size..." << endl;
					cout << "List size = " << getSize() << endl;
					cout << "Traversing to verify..." << endl;
					traverse();
					cout << "Verified! All stories present." << endl;
					cout << "Every single input is sanitized and checked to prevent any malfunctions to the list." << endl
					<< "Press enter to explore the rest of the program. " << endl
					<< "The test cases can be ran multiple times over and over and mixed and matched without failure." << endl;
					getline(cin, tmp);
					break;
			}
		}
};

int main()
{
	cout << "Initializing..." << endl
		<< "Creating singly linked list object..." << endl;

	//Create the list of nodes
	nodeList nodeList;

	cout << "Opening menu..." << endl << endl;

	int choice;
	do {
		cout << "--------------------" << endl
			<< "1) Fill in stories" << endl
			<< "2) Traverse the list" << endl
			<< "3) Insert/Append a story (start/end)" << endl
			<< "4) Remove a story" << endl
			<< "5) Find a story" << endl
			<< "6) Set a story's priority" << endl
			<< "7) Assign a story to a team" << endl
			<< "8) Sort list by priorty then team" << endl
			<< "9) Sort list by team then priority" << endl
			<< "10) Find a story by Priority" << endl
			<< "11) Mark a story complete or incomplete" << endl
			<< "12) Display completed stories" << endl
			<< "13) Display size of list" << endl
			<< "14) Check if all stories are compeleted" << endl
			<< "15) == Test Mode 1 [5 stories] ==" << endl
			<< "16) == Test Mode 2 [20 stories] ==" << endl
			<< "17) == Test Mode 3 [50 stories] ==" << endl
			<< "18) == STRESS test [600 stories] ==" << endl
			<< "0) Exit" << endl
			<< "--------------------" << endl
			<< "Enter: ";

		checkForNumber(choice, "Invalid option, please enter a valid option: ");

		switch (choice) {
			case 0:
				cout << "Exiting..." << endl;
				break;
			case 1:
				nodeList.fill();
				break;
			case 2:
				nodeList.traverse();
				break;
			case 3:
				nodeList.append();
				break;
			case 4:
				nodeList.dump();
				break;
			case 5:
				nodeList.search();
				break;
			case 6:
				nodeList.assignPriority();
				break;
			case 7:
				nodeList.assignTeam();
				break;
			case 8:
				nodeList.sortByPriorityTeam();
				break;
			case 9:
				nodeList.sortByTeamPriority();
				break;
			case 10:
				nodeList.findPriority();
				break;
			case 11:
				nodeList.markStories();
				break;
			case 12:
				cout << "Displaying all completed stories..." << endl;
				nodeList.progress();
				break;
			case 13:
				//Exersize 2.19
				cout << "Checking list size..." << endl;
				cout << "List size = " << nodeList.getSize() << endl;
				cout << "Traversing to verify..." << endl;
				nodeList.traverse();
				cout << "Verified! All stories present." << endl;
				break;
			case 14:
				cout << "Checking if all stories are complete..." << endl;
				nodeList.completion();
				break;
			case 15:
				nodeList.testCases(1);
				break;
			case 16:
				nodeList.testCases(2);
				break;
			case 17:
				nodeList.testCases(3);
				break;
			case 18:
				nodeList.testCases(4);
				break;
			default:
				cout << "Invalid option! Try again." << endl;
				break;
		}
	} while (choice != 0);

	return 0;
}