#include "card.h"

#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>




char getSuits(const Card& c) {
	switch (c.s) {
	case Suit::suit_spades: return 'S';
	case Suit::suit_clubs: return 'C';
	case Suit::suit_diamonds: return 'D';
	case Suit::suit_hearts: return 'H';
	default: return ' ';
	}

}

char getRank(const Card& c) {
	switch (c.r) {
	case Ranks::rank_ace: return 'A';
	case Ranks::rank_eight: return '8';
	case Ranks::rank_five: return '5';
	case Ranks::rank_four: return '4';
	case Ranks::rank_jack: return 'J';
	case Ranks::rank_king: return 'K';
	case Ranks::rank_nine: return '9';
	case Ranks::rank_queen: return 'Q';
	case Ranks::rank_seven: return '7';
	case Ranks::rank_six: return '6';
	case Ranks::rank_ten: return 'T';
	case Ranks::rank_three: return '3';
	case Ranks::rank_two: return '2';
	default: return ' ';
	}
}

void printCard(const Card& c) {
	std::cout << getRank(c) << getSuits(c) << ' ';
}

std::array<Card, 52> createDeck() {
	std::array<Card, 52> Deck{};
	int i{ 0 };
	for (int rank{ 0 }; rank < static_cast<int>(Ranks::max_ranks); rank++) {
		for (int suit{ 0 }; suit < static_cast<int>(Suit::max_suits); suit++) {
			Deck[i].s = static_cast<Suit>(suit);
			Deck[i].r = static_cast<Ranks>(rank);
			i++;
		}
	}

	return Deck;
}

void printDeck(const std::array<Card, 52>& deck) {
	for (auto& i : deck) {
		printCard(i);
		std::cout << ' ';
	}
	std::cout << '\n';
}

std::array<Card, 52> shuffleDeck(std::array<Card, 52>& Deck) {

	std::array<Card, 52> buf{ createDeck() };

	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle<>(buf.begin(), buf.end(), mt);
	return buf;

}

int getCardValue(const Card& c) {

	switch (c.r) {
		case Ranks::rank_ace: return 11;
		case Ranks::rank_eight: return 8;
		case Ranks::rank_five: return 5;
		case Ranks::rank_four: return 4;
		case Ranks::rank_jack: return 10;
		case Ranks::rank_king: return 10;
		case Ranks::rank_nine: return 9;
		case Ranks::rank_queen: return 10;
		case Ranks::rank_seven: return 7;
		case Ranks::rank_six: return 6;
		case Ranks::rank_ten: return 10;
		case Ranks::rank_three: return 3;
		case Ranks::rank_two: return 2;
		default: return 0;
	}

}

void playBlackjack() {
	while (true) {
		/*
		The dealer gets one card to start (in real life, the dealer gets two, but one is face down so it doesn’t matter at this point).
		
		The player gets two cards to start.
		
		The player goes first.
		
		A player can repeatedly “hit” or “stand”.
		
		If the player “stands”, their turn is over, and their score is calculated based on the cards they have been dealt.
		
		If the player “hits”, they get another card and the value of that card is added to their total score.
		
		An ace normally counts as a 1 or an 11 (whichever is better for the total score). For simplicity, we’ll count it as an 11 here.
		
		If the player goes over a score of 21, they bust and lose immediately.
		
		The dealer goes after the player.
		
		The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
		 
		If the dealer goes over a score of 21, they bust and the player wins immediately.
		Otherwise, if the player has a higher score than the dealer, the player wins. Otherwise, the player loses (we’ll consider ties as dealer wins for simplicity).
		*/
	}
}