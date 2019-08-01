#ifndef PLAYER_H
#define PLAYER_H

#include "../Controls/Die.h"
#include "../Controls/Deck.h"
#include <fstream>

class Player{
	public:
		Player();

		int GetBalance();
		void PlayerTurn();
		void save();
	private:
		int balance;
		Die die;
		Deck deck;
};

#endif