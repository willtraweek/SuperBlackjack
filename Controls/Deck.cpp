#include "Card.h"
#include "Deck.h"
#include <random>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

Deck::Deck(){
	for(int i = 2; i < 15; i++){
		deck.push_back(new Card(i));
	}
}

Deck::~Deck(){
	for(int i = 0; i < deck.size(); i++){
		delete deck.at(i);
	}
	    
}

Card * Deck::draw(){
	srand(time(NULL));
	Card * card = deck.at(rand() % 13);

	return card;
}