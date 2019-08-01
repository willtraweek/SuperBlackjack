#include "Controls/Deck.h"
#include "Controls/Die.h"
#include "Controllers/Player.h"
#include <vector>

using namespace std;

int main(){
	cout << "Welcome to Super Blackjack\n\n";

	int handNumber = 1;
	char playerMove = 'l';

	while(playerMove != 'q'){
		cout << "--- HAND " << handNumber << " ----";

		Player * player = new Player();

		player -> SetBet();

		cout << "Would you like to play again?\nPlease type 'q' to quit or any other letter to continue.\n";
		cin >> playerMove;
		handNumber++;

		delete player;
	}
}