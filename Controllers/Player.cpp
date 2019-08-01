#include "Player.h"
#include "../Controls/Card.h"
#include "../Controls/Deck.h"
#include <iostream>

using namespace std;

Player::Player(){
	cout << "Loading Bank Balance\n";
	ifstream file("../savefile/BankBalance.txt");
	if(file.good()){
		file >> balance;
	}else{
		balance = 100;
	}
	file.close();

	cout << "You have $" << balance <<".";

	Deck * deck = new Deck();
	Die * die = new Die();

	bet = 0;
}

Player::~Player(){
	delete deck;
	delete die;
}

int Player::GetBalance(){
	return balance;
}

void Player::AdjustBalance(bool win){
	if(win){
		balance += bet;
	}else{
		balance -= bet;
	}
}

void Player::SetBet(int bet){
	this -> bet = bet;
}

void Player::save(){
	//TODO:: MAKE IT SO THAT THIS CAN CREATE A NEW FILE
	ofstream file;
	file.open("../savefile/BankBalance.txt");
	file << balance;
	file.close();
	cout << balance << endl;
}



