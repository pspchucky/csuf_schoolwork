// Project 4 - Fun with Words
// Sergio German Jr && Phoebe Chiu
// Nov 25, 2014
// Version 1.0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int letterScore(char letter);
void scoreFile(string file_name);
int getWordScore(string);
void showMenu();							//Define all prototype functions
void scoreWords(string file_name);
void longestSequence(string file_name);

/************************************
* letterScore takes a character and *
* returns its score based on the 	*
* default scrabble scoring rules	*
*************************************/
	
int letterScore(char letter)
{
	letter = toupper(letter);
	if( letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'R' || letter == 'S' || letter =='T' || letter == 'N' || letter == 'L' )
		return 1;
	else if( letter == 'D' || letter == 'G')
		return 2;
	else if( letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P' )
		return 3;
	else if( letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y' )
		return 4;
	else if( letter == 'K' )
		return 5;
	else if( letter ==  'J' || letter == 'X' )
		return 8;
	else if( letter == 'Q' || letter == 'Z' )
		return 10;
	else
		return 0;
}

/************************************
* scoreFile takes a filename and 	*
* opens it to read/score its		*
* contents and outputs the total	*
* score, number of letters, and 	*
* average score per letter			*
*************************************/

void scoreFile(string file_name)
{
	double score = 0;
	int lettercount = 0;
	double avg_score = score/lettercount;
	
	string contents = "";
	ifstream inputFile;
	inputFile.open(file_name);
	char ch = inputFile.get();
	
	while (ch != EOF)
	{
		contents+=ch;
		if( isalpha(ch) )
		{
			score = score + letterScore(ch);
			lettercount++;
		}
		ch = inputFile.get();
	}
	cout << "Here are the contents of your file:" << endl
		<< contents << endl << endl;
	cout << "Total Score: " << static_cast<int>(score) << endl; 
	cout << "Number of Letters: " << lettercount << endl;
	cout << "Average score per letter: " << fixed << 
		setprecision(2) << avg_score << endl << endl;
}

/************************************
* getWordScore takes a string and 	*
* reads/scores it by analyzing		*
* each character's value via the	*
* letterScore() function and returns*
* the score of the string			*
*************************************/

int getWordScore(string word)
{
	int score = 0;

	for(unsigned int i = 0; i < word.length(); i++)
	{
		char newCh = word[i];
		score = score + letterScore(newCh);
	}
	return score;
}

/************************************
* showMenu displays the text UI	 	*
*************************************/

void showMenu()
{
	cout << "Select from the below menu choices:" << endl
		<< "1. Scrabble score a file" << endl
		<< "2. Play best scrabble word" << endl 
		<< "3. Find longest sequence of a letter" << endl 
		<< "4. Exit" << endl << endl;
}


/************************************
* scoreWords takes a filename and 	*
* opens it to read/score its		*
* contents and outputs each word	*
* score and outputs the highest 	*
* scoring word out of the list		*
*************************************/

void scoreWords(string file_name)
{
	ifstream inputFile; //Define the file object
	ofstream outputFile;
	outputFile.open("out.txt");

	string line = "";
	string best_word = "";
	int best_word_score = 0;
	inputFile.open(file_name);

	while(!inputFile.eof()) //While NOT end of file
  	{
		
		getline(inputFile, line,'\n');

		if(line.length() == 7){
			cout << line << setw(9) << 
				right << getWordScore( line ) << "\n";
			outputFile << line << setw(9) << 
				right << getWordScore( line ) << "\n";
		}else{
			cout << line << setw(10) << 
				right << getWordScore( line ) << "\n";
			outputFile << line << setw(9) <<
				right << getWordScore( line ) << "\n";
		}
		
		if(getWordScore(line) > best_word_score){
			best_word_score = getWordScore( line );
			best_word = line;
		}
	}
	cout << endl << "Best word: " << best_word 
		<< "\t" << best_word_score << endl;
	
	outputFile << "Best word: " << best_word 
		<< "\t" << best_word_score << endl << endl;
	outputFile.close();
}

/************************************
* longestSequence takes a filename,	*
* opens it to read the DNA sequence,*
* prompts for a character to search	*
* for and outputs the number of		*
* times that character repeated		*
* at most in the sequence			*
*************************************/

void longestSequence(string file_name)
{
	ifstream inputFile;
	string line = "";
	char search_letter;
	int count = 0;
	bool repeated = false;
	int largest = 0;
	
	inputFile.open(file_name);
	getline(inputFile, line,'\n');
		
	cout << "DNA Pattern: " << line 
		<< endl << "Enter letter to search: ";
	cin >> search_letter;

	 for(int i = 0; i < line.length(); i++){
                if(repeated == true){
                        if (line[i] != line[i-1]){
                                if (largest < count){
                                        largest = count;
                                        count = 0;
                                        repeated = false;
                                }
                        }
                }
                if(line[i] == search_letter){
                        count++;
                        repeated = true;
                }
        }

	cout << "Longest sequence of letter '" << 
		search_letter << "' is " << largest;
}

int main()
{
	int option;
	do
	{
		showMenu();
		cin >> option;
			if(option == 1)
			{
				string file_name = "";
				cout << "\nScrabble score a file." << endl 
					<< "Enter file name: ";
				cin >> file_name;
				cout << endl;
				scoreFile(file_name);
			}else if (option == 2){
				string file_name = "";
				cout << "Play the best scrabble word." << endl
					<< "Enter the file name: ";
				cin >> file_name;
				scoreWords(file_name);
			}else if (option == 3){
				string file_name = "";
				cout << "Find longest sequence of a letter." << endl 
					<< "Enter the file name: "; 
				cin >> file_name;
				longestSequence(file_name);
				cout << endl;
			}else if (option == 4){
			}else{
				cout << "\nInvalid menu option! (Enter a number from 1 - 4)" << endl;
			}
	}while( option !=4 );
	
	return 0;
}