#include "Player.h"
#include "../Controls/Card.h"
#include "../Controls/Deck.h"
#include <iostream>

using namespace std;

Player::Player(){
	ifstream file("../savefile/BankBalance.txt");
	if(file.good()){
		file >> balance;
	}else{
		balance = 100;
	}
	file.close();

	Deck * deck = new Deck();
	Die * die = new Die();
}

Player::~Player(){
	delete deck;
	delete die;
}

int Player::GetBalance(){
	return balance;
}

void Player::AdjustBalance(int changeInCash){
	balance = balance + changeInCash;
}

void Player::save(){
	//TODO:: MAKE IT SO THAT THIS CAN CREATE A NEW FILE
	ofstream file;
	file.open("../savefile/BankBalance.txt");
	file << balance;
	file.close();
	cout << balance << endl;
}



