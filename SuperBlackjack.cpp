#include "Controls/Deck.h"
#include "Controls/Die.h"
#include "Controllers/Player.h"

using namespace std;

int main(){
	Deck deck = Deck();

	cout << endl;
	deck.draw().print();

	Die die = Die();
	die.roll();
	die.print();

	Player player = Player();
	cout << player.GetBalance() << endl;
	player.save();
}