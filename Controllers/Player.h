#ifndef PLAYER_H
#define PLAYER_H

#include "../Controls/Die.h"
#include "../Controls/Deck.h"
#include <fstream>

class Player{
	public:
		Player();
		~Player();

		int GetBalance();
		void AdjustBalance(bool);
		void SetBet();
		void save();


		Die * die;
		Deck * deck;
	private:
		int balance;
		int bet;
};

#endif