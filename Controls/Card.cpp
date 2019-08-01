#include "Card.h"
#include <random>
#include <iostream>

using namespace std;

enum CARDS {TWO = 2,
			THREE = 3,
			FOUR = 4,
			FIVE = 5,
			SIX = 6,
			SEVEN = 7,
			EIGHT = 8,
			NINE = 9,
			TEN = 10,
			JACK = 11,
			QUEEN = 12,
			KING = 13,
			ACE = 14};

Card::Card(int name){
	this -> letter = '\0';
	this -> name = name;

	if(name < 11){
		this -> value = name;
	}

	switch(name){
		case JACK:
			this -> value = 10;
			this -> letter = 'J';
			break;
		case QUEEN:
			this -> value = 10;
			this -> letter = 'Q';
			break;
		case KING:
			this -> value = 10;
			this -> letter = 'K';
			break;
		case ACE:
			this -> value = 11;
			this -> letter = 'A';
			break;
	}

}

Card::~Card(){
}

int Card::GetValue(){
	return this->value;
}

void Card::print(){
	if(value < 10){
		cout << "+---------+" << endl;
		cout << "| " << value << "       |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|       " << value << " |" << endl;
		cout << "+---------+" << endl;
	}else if(letter == '\0' && value == 10){
		cout << "+---------+" << endl;
		cout << "| 10      |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|      10 |" << endl;
		cout << "+---------+" << endl;
	}else{
		cout << "+---------+" << endl;
		cout << "| " << letter << "       |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|   ***   |" << endl;
		cout << "|      " << letter << "  |" << endl;
		cout << "+---------+" << endl;
	}
}