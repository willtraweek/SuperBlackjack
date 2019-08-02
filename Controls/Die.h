#ifndef DIE_H
#define DIE_H

#include <vector>
#include "GamePiece.h"

class Die : public GamePiece{
	public:
	    Die();
	    ~Die();

	    void print();
	    int roll();
	    int GetValue();
	private:
		int value;
};

#endif