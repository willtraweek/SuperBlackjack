#include "Controls/Deck.h"
#include "Controls/Die.h"
#include "Controllers/Table.h"
#include <vector>

using namespace std;

int main(){
	cout << "Welcome to Super Blackjack\n\n";

	int handNumber = 1;
	char playerMove = 'l';

	

	while(playerMove != 'q'){
		cout << "--- HAND " << handNumber << " ----\n";
		Table * table = new Table();

		table -> SetBet();

		table -> TakeTurn();

		cout << "Would you like to play again?\nPlease type 'q' to quit or any other letter to continue.\n";
		cin >> playerMove;
		
		handNumber++;
		delete table;
	}
	
}