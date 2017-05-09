/*

Assingmnet Name : TIC-TAC-TOE

                  
                   Reynold Frank Dmello
*/

#include<iostream>
#include<string>
using namespace std;


class Player {

public:
	int won, draw, lost;
	int score1 = 0, score2=0;
	string playername;
	char charboard[10]; // an array of characters for storing 'X' or 'O'


	Player();

	int getscore();

	friend ostream  & operator <<(ostream & myoutputStream, Player & m);

	friend bool  operator > (Player, Player);

	friend bool  operator == (Player, Player);

};


// Player class is inherited to Deck class using publice specifier
class Deck: public Player {

public:
	int board[10] = { 0,1,2,3,4,5,6,7,8,9 };  
	
	int player1choices[9];  // all the inputs of player1choices will be saved in this array

	int player2choices[9];  // all the inputs of player2choices will be saved in this array

	int game ;

	int repeat ;

	Deck();

};

// Deck class is inherited to Tictactoe class using public specifier

class Tictactoe : public Deck
{
public:

	int player1, player2;

	int decklist[9];    // an array of int datatype for storing  inputs from the users that is used for validation of input 
	
	Tictactoe();

	//Tictactoe(int, int);

	int validatePlayerInput(int);  // function for validating inputs from userss

	int isGameOver(Tictactoe, Tictactoe, Player &, Player &); // function that checks whether a game is over by  win, lost or a draw

	//int isDraw();

	int getPlayerMove(Tictactoe, Tictactoe, Player &, Player &);  // This method is for accepting inputs and calling the print and print1 methods

    int startGame(Tictactoe, Tictactoe);  // The game initially starts from this method

	void print();   // This is for printing the Board displaying in the begining with choices of numbers to enter

	void print1();   // This is the board that display 'X' and 'O', while users start to enter their choice


};