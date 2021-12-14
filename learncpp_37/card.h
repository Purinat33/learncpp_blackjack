#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>


#ifndef CARD_H
#define CARD_H

extern enum class Ranks {
	rank_two,
	rank_three,
	rank_four,
	rank_five,
	rank_six,
	rank_seven,
	rank_eight,
	rank_nine,
	rank_ten,
	rank_jack,
	rank_queen,
	rank_king,
	rank_ace,

	max_ranks
};

extern enum class Suit {
	suit_spades,
	suit_clubs,
	suit_diamonds,
	suit_hearts,

	max_suits

};

extern struct Card {
	Ranks r{};
	Suit s{};
};


char getSuits(const Card& c);
char getRank(const Card& c);
void printCard(const Card& c);
std::array<Card, 52> createDeck();
void printDeck(const std::array<Card, 52>& deck);
std::array<Card, 52> shuffleDeck(std::array<Card, 52>& Deck);
int getCardValue(const Card& c);


#endif