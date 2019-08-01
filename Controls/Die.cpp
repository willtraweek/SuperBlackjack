#include "Die.h"
#include <iostream>
#include <random>

using namespace std;

Die::Die(){
	roll();
}

Die::~Die(){

}

void Die::print(){
	switch(value){
		case 1:
			cout << "+---------------+" << endl;
			cout << "|               |" << endl;
			cout << "|               |" << endl;
			cout << "|       *       |" << endl;
			cout << "|               |" << endl;
			cout << "|               |" << endl;
			cout << "+---------------+" << endl;
			break;
		case 2:
			cout << "+---------------+" << endl;
			cout << "|   *           |" << endl;
			cout << "|               |" << endl;
			cout << "|               |" << endl;
			cout << "|               |" << endl;
			cout << "|           *   |" << endl;
			cout << "+---------------+" << endl;
			break;
		case 3:
			cout << "+---------------+" << endl;
			cout << "|   *           |" << endl;
			cout << "|               |" << endl;
			cout << "|       *       |" << endl;
			cout << "|               |" << endl;
			cout << "|           *   |" << endl;
			cout << "+---------------+" << endl;
			break;
		case 4:
			cout << "+---------------+" << endl;
			cout << "|   *       *   |" << endl;
			cout << "|               |" << endl;
			cout << "|               |" << endl;
			cout << "|               |" << endl;
			cout << "|   *       *   |" << endl;
			cout << "+---------------+" << endl;
			break;
		case 5:
			cout << "+---------------+" << endl;
			cout << "|   *       *   |" << endl;
			cout << "|               |" << endl;
			cout << "|       *       |" << endl;
			cout << "|               |" << endl;
			cout << "|   *       *   |" << endl;
			cout << "+---------------+" << endl;
			break;
		case 6:
			cout << "+---------------+" << endl;
			cout << "|   *       *   |" << endl;
			cout << "|               |" << endl;
			cout << "|   *       *   |" << endl;
			cout << "|               |" << endl;
			cout << "|   *       *   |" << endl;
			cout << "+---------------+" << endl;
			break;
	}
}

int Die::roll(){
	value = rand() % 6 + 1;

	return value;
}

int Die::GetValue(){
	return value;
}