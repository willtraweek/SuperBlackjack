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
			cout << "+---------------+\n";
			cout << "|               |\n";
			cout << "|               |\n";
			cout << "|       *       |\n";
			cout << "|               |\n";
			cout << "|               |\n";
			cout << "+---------------+\n";
			break;
		case 2:
			cout << "+---------------+\n";
			cout << "|   *           |\n";
			cout << "|               |\n";
			cout << "|               |\n";
			cout << "|               |\n";
			cout << "|           *   |\n";
			cout << "+---------------+\n";
			break;
		case 3:
			cout << "+---------------+\n";
			cout << "|   *           |\n";
			cout << "|               |\n";
			cout << "|       *       |\n";
			cout << "|               |\n";
			cout << "|           *   |\n";
			cout << "+---------------+\n";
			break;
		case 4:
			cout << "+---------------+\n";
			cout << "|   *       *   |\n";
			cout << "|               |\n";
			cout << "|               |\n";
			cout << "|               |\n";
			cout << "|   *       *   |\n";
			cout << "+---------------+\n";
			break;
		case 5:
			cout << "+---------------+\n";
			cout << "|   *       *   |\n";
			cout << "|               |\n";
			cout << "|       *       |\n";
			cout << "|               |\n";
			cout << "|   *       *   |\n";
			cout << "+---------------+\n";
			break;
		case 6:
			cout << "+---------------+\n";
			cout << "|   *       *   |\n";
			cout << "|               |\n";
			cout << "|   *       *   |\n";
			cout << "|               |\n";
			cout << "|   *       *   |\n";
			cout << "+---------------+\n";
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