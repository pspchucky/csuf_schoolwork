//Sergio German & Phoebe Chiu
//CPSC 120

#include <iostream>
#include <string>
using namespace std;

// BLANK = 0
// X = CPU = 1
// O = USER = 2

int main()
{

    //Define the variables
    string cpu_move = "";
    string game_state = "";

    int TILE_ONE, TILE_TWO, TILE_THREE, TILE_FOUR, TILE_FIVE, TILE_SIX, TILE_SEVEN, TILE_EIGHT, TILE_NINE;
    TILE_ONE = TILE_TWO = TILE_THREE = TILE_FOUR = TILE_FIVE = TILE_SIX = TILE_SEVEN = TILE_EIGHT = TILE_NINE = 0;

    //Get user-input for the state of the board
    cout << "Enter the board state as 9 integers, 0-2:" << endl;
    cin >> TILE_ONE;
    cin >> TILE_TWO;
    cin >> TILE_THREE;
    cin >> TILE_FOUR;
    cin >> TILE_FIVE;
    cin >> TILE_SIX;
    cin >> TILE_SEVEN;
    cin >> TILE_EIGHT;
    cin >> TILE_NINE;

    //Print the Current Board
    cout << "+—+—+—+" << endl;
    cout << "|" << TILE_ONE << "|" << TILE_TWO << "|" << TILE_THREE << "|" << endl;
    cout << "+—+—+—+" << endl;
    cout << "|" << TILE_FOUR << "|" << TILE_FIVE << "|" << TILE_SIX << "|" << endl;
    cout << "+—+—+—+" << endl;
    cout << "|" << TILE_SEVEN << "|" << TILE_EIGHT << "|" << TILE_NINE << "|" << endl;
    cout << "+—+—+—+" << endl;
    
    //Computer computes next move with ydadiadada
    if ( TILE_ONE == 1 && TILE_TWO == 1 && TILE_THREE != 2){
        cpu_move = "X moves to C";
        TILE_THREE = 1;
        game_state = "X has chose a winning move and won the game! Better luck next time!";
    }else if ( TILE_FIVE == 2 && TILE_EIGHT == 2 ){
        cpu_move = "X moves to B";
      
        TILE_TWO = 1;
        game_state = "X has blocked a winning move! Smooth.";
    }else if ( TILE_ONE == 1 && TILE_TWO == 0 && TILE_THREE == 1 && TILE_FOUR == 2 && TILE_FIVE == 1 && TILE_SIX == 2 && TILE_SEVEN == 2 && TILE_EIGHT==1 && TILE_NINE == 2 ){
        cpu_move = "X moves to B";
        TILE_TWO = 1;
        game_state = "X has filled the last square and tied the game!";
    }else if ( (TILE_THREE == 2 && TILE_ONE == 0) && (TILE_ONE != 2 || TILE_ONE != 1) ){
        cpu_move = "X moves to A";
        TILE_ONE = 1;
        game_state = "X has made its move. Your turn.";
    }else if ( TILE_FOUR == 2 && TILE_SEVEN == 2 ){
        cpu_move = "X moves to A";
        TILE_ONE = 1;
        game_state = "X has blocked a winning move! Smooth.";
    }else if ( TILE_ONE == 1 && TILE_TWO == 0 && TILE_THREE == 0 ){
        cpu_move = "X moves to B";
        TILE_TWO = 1;
        game_state = "X has made its move. Your turn.";
    }else{
        cpu_move = "Error: I don't know what to do help me!";
    }
    cout << cpu_move << endl;
    
    
    //Print New Board
    cout << "New Board: " << endl;
    cout << "+—+—+—+" << endl;
    cout << "|" << TILE_ONE << "|" << TILE_TWO << "|" << TILE_THREE << "|" << endl;
    cout << "+—+—+—+" << endl;
    cout << "|" << TILE_FOUR << "|" << TILE_FIVE << "|" << TILE_SIX << "|" << endl;
    cout << "+—+—+—+" << endl;
    cout << "|" << TILE_SEVEN << "|" << TILE_EIGHT << "|" << TILE_NINE << "|" << endl;
    cout << "+—+—+—+" << endl;
    
    cout << game_state;
}