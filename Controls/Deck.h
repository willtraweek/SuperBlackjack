#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck{
	public:
	    Deck();
	    ~Deck();

	    Card draw();
	private:
		std::vector<Card *> deck;
};

#endif