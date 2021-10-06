#include <iostream>
#include <cstring>
using namespace std;

int main(){
  /*
A two player TicTacToe game that keeps track of wins and losses aswell as multiple rounds
By Kushal Rao
9/22/2020
*/
	int[][] board = new int[3][3];
	final int BLANK = 0;
	final int X_MOVE = 1;
	final int O_MOVE = 2;
	final int X_TURN = 0;
	final int O_TURN = 1;
	int turn = X_TURN;
	int O_wins = 0;
	int X_wins = 0;
	int Ties = 0;
	
	Scanner scanner;
	String input = "";
	
	public TicTacToe() {
		scanner = new Scanner(System.in);// To check for input from console
		boolean stillPlaying = true;
		while(stillPlaying == true) { // to monitor if the players want to play again 
		
			while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false){ // to make sure the round has not ended already
				printBoard();
				input = scanner.nextLine();
				if(input.length() != 2) {// to check for a valid input
					System.out.println("Enter a letter followed by a number");
				}
				else if(input.charAt(0) != 'a' && // to check for a valid input
						input.charAt(0) != 'b' &&
						input.charAt(0) != 'c') {
					System.out.println("Row must be an a, b, or c");
				}
				else if(input.charAt(1) != '1' && // to check for a valid input
						input.charAt(1) != '2' &&
						input.charAt(1) != '3') {
					System.out.println("Column must be an 1, 2, or 3");
				}
				else {
					int row = input.charAt(0) - 'a';// converting input into a point in the array
					int column = input.charAt(1) - '1';
					if (board[row][column] == BLANK) {
						if (turn == X_TURN) {
							board [row][column] = X_MOVE;
							turn = O_TURN;
							
						}
						else {
							board[row][column] = O_MOVE;
							turn = X_TURN;
						}
						
					}
					else {
						System.out.println("There is already a peice there!");
					}
				}
			}
		
			if (checkWin(X_MOVE) == true) {
				printBoard();
				System.out.println("X wins!");
				X_wins += 1;
				stillPlaying = false;
				System.out.println("Do you want to play again?(y/n)");
				String yesno = scanner.nextLine();// input to figure out if the players want to play again
				if (yesno.equals("yes")||yesno.equals("y")) {
					stillPlaying = true;
					turn = X_TURN;
					board[0][0] = BLANK;
					board[0][1] = BLANK;
					board[0][2] = BLANK;
					board[1][0] = BLANK;
					board[1][1] = BLANK;
					board[1][2] = BLANK;
					board[2][0] = BLANK;
					board[2][1] = BLANK;
					board[2][2] = BLANK;
					System.out.println(" ");//Line for spacing 
					System.out.println("X wins: " + X_wins);
					System.out.println("O wins: " + O_wins);
					System.out.println("Ties: " + Ties);
					System.out.println(" ");//Line for spacing 
				}
				else {
					System.out.println(" ");//Line for spacing 
					System.out.println("X wins: " + X_wins);
					System.out.println("O wins: " + O_wins);
					System.out.println("Ties: " + Ties);
					System.out.println("Thanks for playing");
				}
			}
			else if (checkWin(O_MOVE) == true){
				printBoard();
				System.out.println("O wins!");
				O_wins += 1;
				stillPlaying = false;
				System.out.println("Do you want to play again?(y/n)");
				String yesno = scanner.nextLine(); // input to figure out if the players want to play again
				if (yesno.equals("yes")||yesno.equals("y")) {
					stillPlaying = true;
					turn = X_TURN;
					board[0][0] = BLANK;
					board[0][1] = BLANK;
					board[0][2] = BLANK;
					board[1][0] = BLANK;
					board[1][1] = BLANK;
					board[1][2] = BLANK;
					board[2][0] = BLANK;
					board[2][1] = BLANK;
					board[2][2] = BLANK;
					System.out.println(" ");//Line for spacing 
					System.out.println("X wins: " + X_wins);
					System.out.println("O wins: " + O_wins);
					System.out.println("Ties: " + Ties);
					System.out.println(" ");//Line for spacing 
				}
				else {
					System.out.println(" ");//Line for spacing 
					System.out.println("X wins: " + X_wins);
					System.out.println("O wins: " + O_wins);
					System.out.println("Ties: " + Ties);
					System.out.println("Thanks for playing");
				}
			}
			else if (checkTie() == true){
				printBoard();
				System.out.println("There was a tie.");
				Ties += 1;
				stillPlaying = false;
				System.out.println("Do you want to play again?(y/n)");
				String yesno = scanner.nextLine();// input to figure out if the players want to play again
				if (yesno.equals("yes")||yesno.equals("y")) {
					stillPlaying = true;
					turn = X_TURN;
					board[0][0] = BLANK;
					board[0][1] = BLANK;
					board[0][2] = BLANK;
					board[1][0] = BLANK;
					board[1][1] = BLANK;
					board[1][2] = BLANK;
					board[2][0] = BLANK;
					board[2][1] = BLANK;
					board[2][2] = BLANK;
					System.out.println(" ");//Line for spacing 
					System.out.println("X wins: " + X_wins);
					System.out.println("O wins: " + O_wins);
					System.out.println("Ties: " + Ties);
					System.out.println(" ");//Line for spacing 
				}
				else {
					System.out.println(" ");//Line for spacing 
					System.out.println("X wins: " + X_wins);
					System.out.println("O wins: " + O_wins);
					System.out.println("Ties: " + Ties);
					System.out.println("Thanks for playing");
				}
			}
		}
		 
	}
	
	
	public void printBoard() {// This is what prints the board and gives a representation of the game in the console
		System.out.println(" \t1\t2\t3");
		for (int row = 0; row < board.length; row++) {
			String output = (char)('a' + row) + "\t";
			
			for(int column = 0; column < board[0].length; column++) {
				if(board[row][column] == BLANK) {
					output += " \t";
				}
				else if (board[row][column] == X_MOVE){
					output += "X\t";
				}
				else if (board[row][column] == O_MOVE) {
					output += "O\t";
				}
				
			}
			System.out.println(output);
			
			
		}
	}

	public boolean checkWin(int player) { // This is a boolean to check if a player has 3 in a row
		if(board[0][0] == player && board[0][1] == player && board[0][2] == player) { // top row full
			return true;
		}
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player) { // diagonal from top left to bottom right
			return true;
		}
		if (board[1][0] == player && board[1][1] == player && board[1][2] == player) { // middle row
			return true;
		}
		if (board[2][0] == player && board[2][1] == player && board[2][2] == player) { // bottom row
			return true;
		}
		if (board[0][0] == player && board[1][0] == player && board[2][0] == player) { // leftmost column
			return true;
		}
		if (board[0][1] == player && board[1][1] == player && board[2][1] == player) { // middle column
			return true;
		}
		if (board[0][2] == player && board[1][2] == player && board[2][2] == player) { // rightmost column
			return true;
		}
		if (board[2][0] == player && board[1][1] == player && board[2][1] == player) { // diagonal from bottom left to top right
			return true;
		}
		return false;
	}
	
	public boolean checkTie() {// This is a boolean to check if there is a tie 
		for (int row = 0 ; row < board.length; row++) {
			for (int column = 0 ; column < board[0].length; column++) {
				if (board[row][column] == BLANK) {
					return false;
				}
			}
		}
		return true;
	}
	
}

  return 0;
}
