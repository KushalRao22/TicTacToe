#include <iostream>
#include <cstring>
using namespace std;

void printBoard(char board[3][3]);

void resetBoard(char (&board)[3][3]);

void move(char (&board)[3][3], int &turn);

int main(){
  bool playAgain = true;
  char board[3][3];
  int turn = 0;
  resetBoard(board);
  printBoard(board);
  move(board, turn);
  //while(playAgain){
    
  //}
  return 0;
}


void resetBoard(char (&board)[3][3]){
  for(int i = 0; i <3; i++){
    for(int j = 0; j< 3; j++){
      board[i][j] = ' ';
    }
  }
}



void printBoard(char board[3][3]){
  cout << " 123" << endl;
  cout << "a" << board[0][0] << board[0][1] << board[0][2] << endl;
  cout << "b" << board[1][0] << board[1][1] << board[1][2] << endl;
  cout << "c" << board[2][0] << board[2][1] << board[2][2] << endl;
}


void move(char (&board)[3][3], int &turn){
  char input[3];
  int x = -1;
  int y = -1;
  bool notAnInput = true;
  cout << "Input a move (ex: a1)" << endl;
  cin.get(input, 3);
  while(notAnInput){
    if(input[0] == 'a' || input[0] == 'b' || input[0] == 'c'){
      if(input[1] == '1' || input[1] == '2' || input[1] == '3'){
	notAnInput = false;
      }
    }
    if(notAnInput == true){
      cout << "Input a valid move (ex: a1)" << endl;
      cin >> input;
      cout << input;
    }
    notAnInput = false;
  }
  
  if(input[0] == 'a'){
    y = 0;
  }
  else if(input[0] == 'b'){
    y = 1;
  }
  else if(input[0] == 'c'){
    y = 2;
  }
  if(input[1] == '1'){
    x = 0;
  }
  else if(input[1] == '2'){
    x = 1;
  }
  else if(input[1] == '3'){
    x = 2;
  }
  cout << x <<  y << endl;
}
