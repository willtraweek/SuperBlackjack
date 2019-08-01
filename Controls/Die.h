#ifndef DIE_H
#define DIE_H

#include <vector>

class Die{
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