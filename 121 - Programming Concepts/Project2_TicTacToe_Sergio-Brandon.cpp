/***************************************************
Sergio German Jr && Brandon Mogi
A simple C++ implementation of the classic 'Tic-Tac-Toe'
The main functions are: Board display, valid move checking, and winner checking.

What are the challenging aspects of the project?
 -> The challenging aspects of this project was trying to print out the board and making it work with a integer array.
 -> Also, finding a winner without using 8 if-statements/hard-coding the function.
****************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**************************************
displayBoard();
This function displays board game.

	Print X if the element == 1
	Print O if the element == 2
	Print "space" if element != 1 or != 2
		=============	
		|   | O |   |				
		-------------
		|   | X |   |
		-------------
		|   |   |   |
		=============
***************************************/
void displayBoard(const int board[][3]){
	cout << "=============" << endl;
	for(int j = 0; j < 3; j++){
		cout << "| ";
		for(int i = 0; i < 3; i++){
			if(board[j][i] == 1)
				cout << "X | ";
			else if(board[j][i] == 2)
				cout << "O | ";
			else{
				cout << "  | ";
			}
		}
		cout << endl;
		if(j != 2){ //Cosmetic exception in order to keep last line from being "-------------" and make it "============="
			cout << "-------------" << endl;
		}else{
			cout << "=============" << endl;
		}
	}
}

/***************************************************
bool isValidMove();
This function checks if user enters valid input.
	return false if row and column are not between 0 and 2
	return false if board[row][col] == 1 or 2
	return true otherwise 
****************************************************/
bool isValidMove(const int board[][3], int row, int col) {
	if((row >= 0 && row <= 2) && (col >=0 && col <= 2) && (board[row][col] != 1) && (board[row][col] != 2)){
		return true;
	} else {
		return false;
	}
}

/***************************************************
bool winnerFound();
This function checks if there is winner for the TicTacToe game
	return true if you find same match for horizontal, vertical, or diagonal lines
	return false otherwise
****************************************************/
bool winnerFound(const int board[][3]) {

	for (int i = 0; i < 3; i++)
    {	
		//Check all Verticals, Horizontals, and Diagonals for a win.
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }
	return false;

}

/***************************************************
main();
This function is the the main driver for the program
Please read through the main function first and understand
the flow of the program.
****************************************************/
int main() {

	const int MAX_TURN = 9;
	bool player1_turn;				//player turn
	string player;					//name of player
	int row, col;					//row and column that user can select
	int turn = 0;					//keeping count of the number of turn

	//create 3x3 board game
	//if there is no 1 or 2 then the board is empty
	int board[3][3] = {{3,4,5},{6,7,8},{9,10,11}};

	cout << "Welcome to TicTacToe game!!" << endl << endl; 
	displayBoard(board);			//display an empty board

	do {

		//if turn is even then it's first player's turn
		//turn is odd then it's second player's turn
		if (turn%2 == 0) {
			player1_turn = true;
			player = "Player 1";
		}
		else {
			player1_turn = false;
			player = "Player 2";
		}

		do {
			//select the slot of tictactoe game
			//we starts at index 0 which mean 0 0 is for the top left corner of tictactoe
			//1 0 is for the middle left.
			//Draws the board if you have trouble figuring out the location.
			cout << player << endl << "Please select slot by index (ex:0 0):";
			cin >> row >> col;

			//check if user's move is valid or not
			if (!isValidMove(board,row,col)) {
				cout << "Please pick the right slot!" <<endl;
			}
		} while(!isValidMove(board,row,col));

		//if player 1's turn then we use 1 else we use 2	
		if (player1_turn) {
			board[row][col] = 1;
			turn++;
		}
		else {
			board[row][col] = 2;
			turn++;
		}

		displayBoard(board);

		//We found a winner
		if (winnerFound(board)) {
			cout << "Congratulations." << endl;
			cout << player << " wins this game!!!" << endl;
			return 0;
		}
	} while (turn < MAX_TURN);

	//No winner :(
	cout << "We have a draw!!" <<endl;
	return 0;
}