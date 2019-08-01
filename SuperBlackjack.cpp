#include "Controls/Deck.h"
#include "Controls/Die.h"
#include "Controllers/Player.h"

using namespace std;

int main(){
	cout << "Welcome to Super Blackjack\n\n";
	char continueGame = 'y';
	while(continueGame != 'q'){
		cout << "Would you like to play again?\nPlease type 'q' to quit or any other letter to continue.\n";
		cin >> continueGame;
	}
}