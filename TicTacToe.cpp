#include <iostream>
#include <cstring>
using namespace std;
//Methods
void printBoard(char board[3][3]);

void resetBoard(char (&board)[3][3], int &turn);

void move(char (&board)[3][3], int &turn);

bool checkWin(char (&board)[3][3], int &turn);

bool checkTie(char (&board)[3][3], int &turn);

void playAgain(bool &playAgain, int xWins, int oWins, int ties, int &turn);

int main(){
  //Variables 
  bool playAgainBool = true;
  char board[3][3];
  int turn = 0;
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  resetBoard(board, turn);//Set up board for play
  while(playAgainBool){//While players want to play
    move(board, turn);//Get ready for a move
    printBoard(board);//Print new move
    if(checkWin(board, turn)){//Check for win
      if(turn == 0){
        xWins++;
      }
      else{
        oWins++;
      }
      playAgain(playAgainBool, xWins, oWins, ties, turn);
      if(playAgainBool){//If players still want to play
          resetBoard(board, turn);//Reset board
        }
        else{//Players dont want to play
          return 0;//Stop the program
        }
    }
    else if(checkTie(board, turn)){//Check for tie
      ties++;
      playAgain(playAgainBool, xWins, oWins, ties, turn);
      if(playAgainBool){
          resetBoard(board, turn);
        }
      else{
        return 0;
      }
    }
    
  }
  return 0;
}


void resetBoard(char (&board)[3][3] , int &turn){//Reset Board
  for(int i = 0; i <3; i++){
    for(int j = 0; j< 3; j++){
      board[i][j] = ' ';//Set all places on the board to empty
      turn = 0;
    }
  }
  printBoard(board);//print the board
  
 // cout <<  turn <<endl;
}



void printBoard(char board[3][3]){//Print board in proper array format
  cout << " 123" << endl;
  cout << "a" << board[0][0] << board[0][1] << board[0][2] << endl;
  cout << "b" << board[1][0] << board[1][1] << board[1][2] << endl;
  cout << "c" << board[2][0] << board[2][1] << board[2][2] << endl;
}


void move(char (&board)[3][3], int &turn){//Get a move
  char input[3];
  int x = -1;//Initialize x to an imposssible number
  int y = -1;//Initialize y to an impossible number
  bool notAnInput = true;
  cout << "Input a move (ex: a1)" << endl;
  cin >> input;
  while(notAnInput){//check if input is valid
     if(input[0] == 'a'){
        x = 0;
      }
      else if(input[0] == 'b'){
        x = 1;
      }
      else if(input[0] == 'c'){
        x = 2;
      }
      if(input[1] == '1'){
        y = 0;
      }
      else if(input[1] == '2'){
        y = 1;
      }
      else if(input[1] == '3'){
        y = 2;
      }

    if(input[0] == 'a' || input[0] == 'b' || input[0] == 'c'){
      if(input[1] == '1' || input[1] == '2' || input[1] == '3'){
	      if(board[x][y] == ' '){
            notAnInput = false;
        }
      }
    }

    if(notAnInput == true){//prompt user for a proper move
      cout << "Input a valid move to an empty spot(ex: a1)" << endl;
      cin >> input;
      cout << input;
    }
    notAnInput = false;
  }
  if(turn == 0){//Set move to X
    board[x][y] = 'X';
    return;
  }
  if(turn == 1){//Set move to y
    board[x][y] = 'O';
    return;
  }
}

bool checkWin(char (&board)[3][3], int &turn){//Check win
  char turnChar = ' ';  
  if(turn == 0){
    turnChar = 'X';
  }
  else{
    turnChar = 'O';
  }
  if(board[0][0] == turnChar && board[0][1] == turnChar && board[0][2] == turnChar) { // top row full
			return true;
		}
		if (board[0][0] == turnChar && board[1][1] == turnChar && board[2][2] == turnChar) { // diagonal from top left to bottom right
			return true;
		}
		if (board[1][0] == turnChar && board[1][1] == turnChar && board[1][2] == turnChar) { // middle row
			return true;
		}
		if (board[2][0] == turnChar && board[2][1] == turnChar && board[2][2] == turnChar) { // bottom row
			return true;
		}
		if (board[0][0] == turnChar && board[1][0] == turnChar && board[2][0] == turnChar) { // leftmost column
			return true;
		}
		if (board[0][1] == turnChar && board[1][1] == turnChar && board[2][1] == turnChar) { // middle column
			return true;
		}
		if (board[0][2] == turnChar && board[1][2] == turnChar && board[2][2] == turnChar) { // rightmost column
			return true;
		}
		if (board[2][0] == turnChar && board[1][1] == turnChar && board[2][1] == turnChar) { // diagonal from bottom left to top right
			return true;
		}
    return false;
}

bool checkTie(char (&board)[3][3], int &turn){//Cehck if all places on the board are filled up
  if(turn == 0){
    turn = 1;
  }
  else{
    turn = 0;
  }
  for (int i = 0 ; i < 3; i++) {
	for (int j= 0 ; j < 3; j++) {
		if (board[i][j] == ' ') {
			return false;
		}
	}
  }
return true;
}

void playAgain(bool &playAgainBool, int xWins, int oWins, int ties, int &turn){//Check if player wants to win
  char input[2];
  cout << "X wins: " << xWins << endl;//print X wins
  cout << "O wins: " << oWins << endl;//print O wins
  cout << "Ties: " << ties << endl;
  cout << "Do you want to play again(y/n)" << endl;
  cin >> input;
  if(input[0] == 'n'){//Check if user wants to play
    playAgainBool = false;
  }
}
