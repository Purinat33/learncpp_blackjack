#include "card.h"

int main() {

	std::array<Card, 52> Deck{ createDeck() };
	printDeck(Deck);

	std::cout << "\n\nShuffling\n\n";
	Deck = shuffleDeck(Deck);

	printDeck(Deck);

	//TODO: blackjack
	
	std::cin.get(); 
	return 0;

}