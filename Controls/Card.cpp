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

Card::Card(int value){
	this -> letter = '\0';

	if(value < 11){
		this -> value = value;
	}

	switch(value){
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
		cout << "+---------+\n";
		cout << "| " << value << "       |\n";
		cout << "|   ***   |\n";
		cout << "|   ***   |\n";
		cout << "|   ***   |\n";
		cout << "|       " << value << " |\n";
		cout << "+---------+\n";
	}else if(letter == '\0' && value == 10){
		cout << "+---------+\n";
		cout << "| 10      |\n";
		cout << "|   ***   |\n";
		cout << "|   ***   |\n";
		cout << "|   ***   |\n";
		cout << "|      10 |\n";
		cout << "+---------+\n";
	}else{
		cout << "+---------+\n";
		cout << "| " << letter << "       |\n";
		cout << "|   ***   |\n";
		cout << "|   ***   |\n";
		cout << "|   ***   |\n";
		cout << "|      " << letter << "  |\n";
		cout << "+---------+\n";
	}
}