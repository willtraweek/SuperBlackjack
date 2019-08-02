#include "Table.h"
#include "../Controls/Card.h"
#include "../Controls/Deck.h"
#include <iostream>

using namespace std;

Table::Table(){
	ifstream file("./savefiles/BankBalance.txt");
	if(file.good()){
		file >> balance;
	}else{
		balance = 100;
	}
	file.close();

	deck = new Deck();
	playerhand = new vector<GamePiece * >;
	dealerhand = new vector<GamePiece * >;

	bet = 0;
}

Table::~Table(){
	save();
	delete deck;
	delete playerhand;
	delete dealerhand;
}

int Table::GetBalance(){
	return balance;
}

void Table::AdjustBalance(bool win){
	if(win){
		balance += bet;
	}else{
		balance -= bet;
	}
}

void Table::SetBet(){
	cout << "How many dollars would you like to bet?\nYou have $" << this -> balance << " to bet\n";
	int bet;
	cin >> bet;
	bool betIsOkay = false;

	while(!betIsOkay){
		cin.clear();	//This prevents an infinite loop if the input is a string
		cin.ignore(1000, '\n');
		if(bet <= 0){
			cout << "\nPlease enter a positive number\n";
			cin >> bet;
		}else if(bet > balance){
			cout << "\nPlease enter an amount you can afford\nYour balance is: $" << this->balance <<"\n";
			cin >> bet;
		}else{
			betIsOkay = true;
		}
	}

	this->bet = bet;
	cout << "\n\n";
}

void Table::save(){
	ofstream file ("./savefiles/BankBalance.txt");

	file << balance;
	file.close();
}

int Table::deal(int numToDraw, vector<GamePiece * > * hand){
	int cardValue = 0;
	for(int i = 0; i < numToDraw; i++){
		hand -> push_back(deck -> draw());
		cardValue += hand -> back() -> GetValue();
	}

	return cardValue;
}

int Table::roll(){
	playerhand -> push_back(new Die());
	return playerhand -> back() -> GetValue();
}

void Table::TakeTurn(){
	cout << "Dealing Cards:\n\n";

	int dealerValue = deal(2, dealerhand);

	cout << "Dealer Shows:\n";
	dealerhand -> at(0) -> print();

	cout << "Player Hand:\n\n";

	int playerValue = deal(2, playerhand);
	playerhand -> at(0) -> print();
	playerhand -> at(1) -> print();

	bool isPlaying = true;
	
	cout << "Your hand value: " << playerValue << "\n\n";

	while(isPlaying){
		if(playerValue == 21){
			cout << "You got a blackjack!\nYou won $" << this -> bet << "\n\n";
			AdjustBalance(true);
			return;
		}else if(playerValue < 21){
			char playermove = 'q';

			while(playermove != 'h' && playermove != 's' && playermove != 'r'){
				cout << "\nWould you like to hit ('h'), stay ('s') or roll a die? ('r')\n";
				cin >> playermove;
				cout << "\n";
			}

			if(playermove == 'h'){
				playerValue += deal(1, playerhand);
				playerhand -> back() -> print();
				cout << "\nYour hand value: " << playerValue << "\n";
			}else if(playermove == 'r'){
				playerValue += roll();
				playerhand -> back() -> print();
				cout << "\nYour hand value: " << playerValue << "\n";
			}else{
				isPlaying = false;
			}
		}else{
			cout << "\nYour hand value: " << playerValue;
			cout << "\nYou busted out and lost $" << this -> bet << "\n";
			AdjustBalance(false);
			return;
		}
	}

	cout << "\nDealer Hand:\n";
	dealerhand -> at(0) -> print();
	dealerhand -> at(1) -> print();

	cout << "\nDealer Hand Value: " << dealerValue << "\n";

	cout << "\nYou had " << playerValue << " and the dealer had " << dealerValue << "\n";

	if(playerValue>dealerValue){
		cout << "You won $" << this -> bet << "\n";
		AdjustBalance(true);
	}else if(playerValue==dealerValue){
		cout << "You and the dealer tied.  No money changes hands\n";
	}else{
		cout << "The dealer won\nYou lost $" << this -> bet << "\n";
	}

}

