// CardList.h
#ifndef CARDLIST_H
#define CARDLIST_H

#include <vector>
#include <string>
#include <random>
#include "Card.h"

class CardList {
	std::vector<Card> cards;
	// Declare the random number generator as a member variable:
	std::mt19937 randomEngine;

public:
	// Constructors
	CardList();
	explicit CardList(const std::vector<Card>& initialCards);

	// Member functions for card management
	void add(const Card &card);
	void addAll(const CardList &other);
	void randomize();
	[[nodiscard]] bool contains(const Card &card) const;
	void removeCardAt(std::size_t index);
	Card draw();
	CardList drawNCards(int n);
	[[nodiscard]] int size() const;
	[[nodiscard]] std::vector<Card> getCards() const;
	[[nodiscard]] CardList copy() const;
	[[nodiscard]] std::string toString() const;
};

#endif // CARDLIST_H