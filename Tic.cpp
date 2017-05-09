/*
 Reynold Frank Dmello
*/

#include<iostream>
#include<string>
#include"ticheader.h"

using namespace std;

Player::Player() {

	won = 0;
	draw = 0;
	lost = 0;

}

Deck::Deck() {

	game = 0;
	repeat = 0;

}

Tictactoe::Tictactoe() {


}

int Player::getscore(){

	return ((won * 2) + draw - lost);

}

int Tictactoe::startGame(Tictactoe t1, Tictactoe t2)
{ 

	char tic;
	Player p1;
	Player p2;

 	cout <<endl<<endl<< "********         WELCOME TO THE GAME OF  TIC-TAC-TOE         *******" << endl;
	cout << "                            COPYRIGHT  PDR                " <<endl<<endl<<endl;
	cout << "Player 1, Please type your name!!" <<endl;
	getline(cin, p1.playername); // accepting line of characters using getline method

	cout <<endl<< "Player2, Please type  your name!!" << endl;
	getline(cin, p2.playername);   // accepting line of characters using getline method



start:  // Label where game basically starts

		for (int i = 0; i <= 9; i++)    // this is for clearing the board and setting decklist to different number for a new game
		{
			charboard[i] = char(0);
			decklist[i] = 100 + 1;
		}
		print();

		while (game == 0)
		{
			getPlayerMove(t1,t2,p1,p2);
		}

		cout << "Press Y if you want to continue with the game : " << endl;  // asking user to play game after a gameover 
		cin >> tic;
		
		if ( tic == 'Y')
		{
			game = 0;
			goto start;
		}
		else
		{  
			cout << p1;

			cout << p2;


			cout << "COMPARING SCORES OF TWO PLAYERS  ..............." << endl;

			if (p1 > p2)
			{
				cout <<endl<<"      The overall winner of the game is " << p1.playername << endl;
			}
			
			else if(p1 == p2)
			{

				cout <<endl<< "      Both of the Players have the same score, it's a tie !! " << endl;
			}

			else
			{
				cout<<endl<< "      The overall winner of the game is " << p2.playername << endl;
			}
					
			cout <<endl<<endl<< "SEE YOU NEXT TIME  .....               " << endl<<endl<<endl;

			exit(0);
		}
		
		return 1;

}

int Tictactoe::getPlayerMove(Tictactoe t1, Tictactoe t2, Player &p1, Player &p2)
{
	cout << p1.playername<<"....  Enter your choice from the above table:" << endl;
	cin >> player1;

	player1=validatePlayerInput(player1);// validating the userinput if the number is between 0 to 8 


	// Checking the board with decklist whether the number has been previously entered
	while (player1 == decklist[0] || player1 == decklist[1] || player1 == decklist[2] || player1 == decklist[3] || player1 == decklist[4] || player1 == decklist[5] || player1 == decklist[6] || player1 == decklist[7] || player1 == decklist[8] || player1 == decklist[9] )
	{
		cout <<p1.playername<<"....The number has already been entered. Please enter another number" << endl;
        cin >> player1;
		player1=validatePlayerInput(player1);  // again calling validation function because user might press anything anytime
	}
	for (int j = 0; j <= 9;j++)    // assigning input of player1 to charboard, player1choices and decklist with their proper datas
		{
			if (player1 == j)
			{
				charboard[j] = 'X';     // setting the player1 input to X for displaying in the board
				player1choices[j] = player1;
				decklist[j] = player1;
			}
		}
	 print1();

	 if (isGameOver(t1,t2,p1,p2))
	 {
		 game = 1;
		 return game;

	 }



	cout << p2.playername<<"...  Enter your choice from the above table:" << endl;
	cin >> player2;

	player2=validatePlayerInput(player2);  // validating the userinput if the number is between 0 to 8

	// Checking the board with decklist whether the number has been previously entered

	while (player2 == decklist[0] || player2 == decklist[1] ||  player2 == decklist[2] || player2 == decklist[3] || player2 == decklist[4] || player2 == decklist[5] || player2 == decklist[6] || player2 == decklist[7] || player2 == decklist[8] || player2 == decklist[9])
	{
		cout <<p2.playername<< "....The number has already been entered. Please enter another number" << endl;
		cin >> player2;
		player2=validatePlayerInput(player2);  // again calling validation function because user might press anything anytime
	}
	for (int k = 0; k <= 9; k++)  // assigning input of player1 to charboard, player1choices and decklist with their proper datas
	{
		if (player2 == k)
		{
			charboard[k] = 'O';         // setting the player2 input to o for displaying in the board
			player2choices[k] = player2;
			decklist[k] = player2;
		}
	}

	print1();
	if ( isGameOver(t1,t2,p1,p2) ) 
	{
		game = 1;
		return game;

	}
	return 1;
	



}

int Tictactoe::isGameOver(Tictactoe t1, Tictactoe t2, Player &p1, Player &p2) {

	if ((player1choices[0] == 0 && player1choices[1] == 1 && player1choices[2] == 2) ||
		(player1choices[3] == 3 && player1choices[4] == 4 && player1choices[5] == 5) ||
		(player1choices[6] == 6 && player1choices[7] == 7 && player1choices[8] == 8) ||
		(player1choices[0] == 0 && player1choices[3] == 3 && player1choices[6] == 6) ||
		(player1choices[1] == 1 && player1choices[4] == 4 && player1choices[7] == 7) ||
		(player1choices[2] == 2 && player1choices[5] == 5 && player1choices[8] == 8) ||
		(player1choices[0] == 0 && player1choices[4] == 4 && player1choices[8] == 8) ||
		(player1choices[0] == 0 && player1choices[4] == 4 && player1choices[8] == 8) ||
		(player1choices[6] == 6 && player1choices[4] == 4 && player1choices[2] == 2))
	{

		cout << "Game won by "<<p1.playername<<"....." << endl<<endl;
		p1.won = p1.won + 1;
		p2.lost = p2.lost - 1;

		for (int i = 0; i <= 9; i++)
		{
			player1choices[i] = 100+i;
			decklist[i] = 300 + i;
			player2choices[i] = 200 + i;
			charboard[i] = char(0);
		}


		return true;

	}



	else if ((player2choices[0] == 0 && player2choices[1] == 1 && player2choices[2] == 2) ||
		(player2choices[3] == 3 && player2choices[4] == 4 && player2choices[5] == 5) ||
		(player2choices[6] == 6 && player2choices[7] == 7 && player2choices[8] == 8) ||
		(player2choices[0] == 0 && player2choices[3] == 3 && player2choices[6] == 6) ||
		(player2choices[1] == 1 && player2choices[4] == 4 && player2choices[7] == 7) ||
		(player2choices[2] == 2 && player2choices[5] == 5 && player2choices[8] == 8) ||
		(player2choices[0] == 0 && player2choices[4] == 4 && player2choices[8] == 8) ||
		(player2choices[0] == 0 && player2choices[4] == 4 && player2choices[8] == 8) ||
		(player2choices[6] == 6 && player2choices[4] == 4 && player2choices[2] == 2))
	{

		cout << "Game won by "<<p2.playername<<"...." << endl<<endl;
		p2.won = p2.won + 1;
		p1.lost = p1.lost - 1;

		for (int i = 0; i <= 9; i++)
		{
			player2choices[i] = 100 + i;
			decklist[i] = 300 + i;
			player2choices[i] =200 + i;
			charboard[i] = char(0);
		}

		return true;




	}

	else if (decklist[0] == 0 && decklist[1] == 1 && decklist[2] == 2 && decklist[3] == 3 &&
		 decklist[4] == 4 && decklist[5] == 5 && decklist[6] == 6 && decklist[7] == 7 &&
		decklist[8] == 8 )
	{

		cout << "The DECK is FULL.......The game is considered as draw:" << endl;
		p1.draw = p1.draw + 1;
		p2.draw = p2.draw + 1;

		for (int i = 0; i <= 9; i++)
		{
			player2choices[i] = 100 + i;
			decklist[i] = 300 + i;
			player2choices[i] = 200 + i;
			charboard[i] = char(0);
		}
		return true;
	}

	else

		return false;

}

int Tictactoe::validatePlayerInput(int choice) {

	while (!(choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8))
	{
		cout << "Please enter the valid number:";
		cin >> choice;
	}

	return choice;
}

void Tictactoe::print()
{

	cout <<endl<< "******            TIC    TAC    TOE         *****" << endl;

	cout << "  _________________" << endl;
	cout << " |     |     |     |" << endl;
	cout << " |  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |" << endl;
	cout << " |_____|_____|_____|" << endl;

	cout << " |     |     |     |" << endl;
	cout << " |  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  |" << endl;
	cout << " |_____|_____|_____|" << endl;


	cout << " |     |     |     |" << endl;
	cout << " |  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  |" << endl;
	cout << " |_____|_____|_____|" << endl << endl << endl;

}

void Tictactoe::print1() {


	cout << "  _________________" << endl;
	cout << " |     |     |     |" << endl;
	cout << " |  " << charboard[0] << "  |  " << charboard[1] << "  |  " << charboard[2] << "  |" << endl;
	cout << " |_____|_____|_____|" << endl;

	cout << " |     |     |     |" << endl;
	cout << " |  " << charboard[3] << "  |  " << charboard[4] << "  |  " << charboard[5] << "  |" << endl;
	cout << " |_____|_____|_____|" << endl;


	cout << " |     |     |     |" << endl;
	cout << " |  " << charboard[6] << "  |  " << charboard[7] << "  |  " << charboard[8] << "  |" << endl;
	cout << " |_____|_____|_____|" << endl << endl << endl;



}

ostream & operator<<(ostream & out, Player & m)
{

	out << "                          GAME STATISTICS                        "<<endl<<endl;

	m.score1 = m.getscore();


	out <<"Overall Score Table of "<< m.playername<<":"<<endl<<endl;
	out << "             1) Win = " << m.won << endl;
	out << "             2) Lost= " << m.lost << endl;
	out << "             3) Draw= " << m.draw << endl<<endl;
	out << "       Total Score of " << m.playername << " is = " << m.score1<<endl<<endl;


	return out;
}

bool operator >(Player m1, Player m2)
{

	if (m1.score1 > m2.score1) {
		return true;

	}

	else
	{

		return false;
	}


}

bool operator ==(Player m1, Player m2)
{
	if (m1.score1 == m2.score1)
	{
		return true;
	}
	else
	{

		return  false;

	}
}