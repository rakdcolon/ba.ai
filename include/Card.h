// Card.h
#ifndef CARD_H
#define CARD_H

#include <string>
#include "Enums.h"

class Card {
public:
	// A flag that controls output format (could be made configurable)
	static constexpr bool verbose = false;

	// Constructors
	Card(Rank rank, Suit suit, Enhancement enhancement, Edition edition, Seal seal);
	Card(Rank rank, Suit suit);

	// Getters
	[[nodiscard]] Rank getRank() const;
	[[nodiscard]] Suit getSuit() const;
	[[nodiscard]] Enhancement getEnhancement() const;
	[[nodiscard]] Edition getEdition() const;
	[[nodiscard]] Seal getSeal() const;

	// Setters
	void setRank(Rank r);
	void setSuit(Suit s);
	void setEnhancement(Enhancement e);
	void setEdition(Edition ed);
	void setSeal(Seal s);

	// Convert the card to a string representation
	[[nodiscard]] std::string toString() const;

	// Equality operator (compares rank and suit)
	bool operator==(const Card &other) const;

private:
	// Declare the member variables
	Rank rank;
	Suit suit;
	Enhancement enhancement;
	Edition edition;
	Seal seal;
};

#endif // CARD_H