#ifndef CARD_H
#define CARD_H

#include <iostream>
#include "GamePiece.h"

class Card :public GamePiece{
	public:
	    Card(int name);
	    ~Card();

	    int GetValue();

	    void print();
	private:
		int value;
		char letter;
};

#endif