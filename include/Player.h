// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "CardList.h"

class Player {
	CardList absoluteDeck;
	CardList deck;
	CardList hand;
	int handSize;

public:
	// Constructor that initializes a full deck and a starting hand.
	Player();

	// Getters
	[[nodiscard]] CardList getAbsoluteDeck() const;
	[[nodiscard]] CardList getDeck() const;
	[[nodiscard]] CardList getHand() const;
	[[nodiscard]] int getHandSize() const;

	// Setters
	void setAbsoluteDeck(const CardList &deck);
	void setDeck(const CardList &deck);
	void setHand(const CardList &hand);
	void setHandSize(int handSize);

	// Player action: select cards to play from hand.
	CardList selectCardsToPlay();
};

#endif // PLAYER_H