#ifndef TABLE_H
#define TABLE_H

#include "../Controls/Die.h"
#include "../Controls/Deck.h"
#include <fstream>
#include <vector>


class Table{
	public:
		Table();
		~Table();

		int GetBalance();
		void AdjustBalance(bool);
		void SetBet();
		void save();

		int deal(int, std::vector<GamePiece * > *);
		int roll();

		void TakeTurn();
		
	private:
		int balance;
		int bet;
		Deck * deck;
		std::vector<GamePiece *> * playerhand;
		std::vector<GamePiece *> * dealerhand;
};

#endif