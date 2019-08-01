#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
	public:
	    Card(int name);
	    ~Card();

	    int GetValue();

	    void print();
	private:
		int value;
		int name;
		char letter;
};

#endif