#include "Controls/Deck.h"
#include "Controls/Die.h"
#include "Controllers/Table.h"
#include <vector>

using namespace std;

int main(){
	cout << "Welcome to Super Blackjack\n\n";

	int handNumber = 1;
	char playerMove = 'l';

	Table * table = new Table();

	while(playerMove != 'q'){
		cout << "--- HAND " << handNumber << " ----\n";

		table -> SetBet();

		//TODO: ADD PlayerTurn() where Player can choose what to draw,roll, or stay on.

		cout << "Would you like to play again?\nPlease type 'q' to quit or any other letter to continue.\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> playerMove;
		
		handNumber++;

	}
	delete table;
}