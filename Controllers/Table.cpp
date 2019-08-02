#include "Table.h"
#include "../Controls/Card.h"
#include "../Controls/Deck.h"
#include <iostream>

using namespace std;

Table::Table(){
	cout << "\nLoading Bank Balance\n\n";
	ifstream file("./savefiles/BankBalance.txt");
	if(file.good()){
		file >> balance;
	}else{
		balance = 100;
	}
	file.close();

	cout << "You have $" << balance <<"\n\n";

	deck = new Deck();
	die = new Die();

	bet = 0;
}

Table::~Table(){
	save();
	delete this -> die;
	delete this -> deck;
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
	cout << "How many dollars would you like to bet?\n";
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
	
	if(file.is_open()){
		cout << "\nFILE OPENED\n";
	}else{
		cout << "\nFAILED TO OPEN\n";
	}

	file << balance;
	file.close();
	cout << balance << endl;
}

int Table::deal(int numToDraw, vector<GamePiece * > hand){
	int cardValue = 0;
	for(int i = 0; i < numToDraw; i++){
		hand.push_back(deck -> draw());
		hand.at(i) -> print();
		cardValue += hand.at(i) -> GetValue();
	}

	return cardValue;
}

void Table::TakeTurn(vector<GamePiece * > hand){
	cout << "Player Hand:\n\n";

	int handValue = deal(2, hand);
	bool isPlaying = true;

	while(isPlaying){
		cout << "Your hand value: " << handValue << "\n\n";
		if(handValue == 21){
			cout << "You got a blackjack!\nYou won $" << this -> bet << "\n\n";
			AdjustBalance(true);
			isPlaying = false;
		}else if(handValue < 21){
			
		}
	}
}

