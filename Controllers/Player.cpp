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
}

void Player::save(){
	//TODO:: MAKE IT SO THAT THIS CAN CREATE A NEW FILE
	ofstream file;
	file.open("../savefile/BankBalance.txt");
	file << balance;
	file.close();
	cout << balance << endl;
}

int Player::GetBalance(){
	return balance;
}

