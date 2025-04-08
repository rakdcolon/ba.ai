// CardList.cpp
#include "../include/CardList.h"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <sstream>

CardList::CardList() {
	std::random_device rd;
	randomEngine = std::mt19937(rd());
}

CardList::CardList(const std::vector<Card>& initialCards)
	: cards(initialCards)
{
	std::random_device rd;
	randomEngine = std::mt19937(rd());
}

void CardList::add(const Card &card) {
	cards.push_back(card);
}

void CardList::addAll(const CardList &other) {
	std::vector<Card> otherCards = other.getCards();
	cards.insert(cards.end(), otherCards.begin(), otherCards.end());
}

void CardList::randomize() {
	std::ranges::shuffle(cards, randomEngine);
}

bool CardList::contains(const Card &card) const {
	return std::ranges::find(cards, card) != cards.end();
}

void CardList::removeCardAt( const std::size_t index) {
	if (index < cards.size()) {
		cards.erase(cards.begin() + index);
	}
}

Card CardList::draw() {
	if (cards.empty()) {
		throw std::out_of_range("No cards to draw");
	}
	std::uniform_int_distribution<> dist(0, cards.size() - 1);
	const size_t index = dist(randomEngine);
	const Card card = cards[index];
	removeCardAt(index);
	return card;
}

CardList CardList::drawNCards(const int n) {
	const int count = std::min(n, static_cast<int>(cards.size()));
	CardList drawnCards;
	for (int i = 0; i < count; i++) {
		drawnCards.add(draw());
	}
	return drawnCards;
}

int CardList::size() const {
	return static_cast<int>(cards.size());
}

std::vector<Card> CardList::getCards() const {
	return cards;
}

CardList CardList::copy() const {
	return CardList(cards);
}

std::string CardList::toString() const {
	std::ostringstream oss;
	oss << "[ ";
	for (size_t i = 0; i < cards.size(); i++) {
		oss << cards[i].toString();
		if (i < cards.size() - 1) {
			oss << ", ";
		}
	}
	oss << " ]";
	return oss.str();
}