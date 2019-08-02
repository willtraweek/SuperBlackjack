#ifndef GAMEPIECE_H
#define GAMEPIECE_H

class GamePiece{
	public:
	    GamePiece();
	    ~GamePiece();

	    virtual void print();

	    virtual int GetValue();
	private:
		int value;
};

#endif